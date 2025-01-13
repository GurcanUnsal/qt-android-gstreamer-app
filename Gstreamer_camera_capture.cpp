#include "Gstreamer_camera_capture.h"

#include <QImage>

static GstFlowReturn new_sample(GstElement *sink, gpointer data)
{
    GstSample *sample;

    g_signal_emit_by_name(sink, "pull-sample", &sample);
    if (sample)
    {
        GstCaps *caps = gst_sample_get_caps(sample);
        GstStructure *structure = gst_caps_get_structure(caps, 0);
        const gchar *format = gst_structure_get_string(structure, "format");

        if (g_strcmp0(format, "RGB") != 0) {
            g_warning("Unsupported format: %s", format);
            gst_sample_unref(sample);
            return GST_FLOW_ERROR;
        }

        GstBuffer *buffer = gst_sample_get_buffer(sample);
        GstMapInfo map;
        gst_buffer_map(buffer, &map, GST_MAP_READ);

        int width, height;
        gst_structure_get_int(structure, "width", &width);
        gst_structure_get_int(structure, "height", &height);

        QImage image((const uchar *)map.data, width, height, QImage::Format_RGB888);

        reinterpret_cast<Gstreamer_camera_capture *>(data)->process_image(new QImage(image));

        gst_buffer_unmap(buffer, &map);
        gst_sample_unref(sample);
        return GST_FLOW_OK;
    }

    return GST_FLOW_ERROR;
}
void Gstreamer_camera_capture::process_image(QImage* image)
{
    emit emit_image(image);
}

Gstreamer_camera_capture::Gstreamer_camera_capture(std::string camera)
{
    std::string pipeline_str = "rtspsrc location=" + camera + " latency=0 ! rtpjitterbuffer latency=10 ! rtph264depay ! avdec_h264 ! videoconvert ! video/x-raw,format=RGB ! appsink name=app_sink sync=false";


    this->_pipeline = gst_parse_launch(pipeline_str.c_str(), NULL);

    this->_app_sink = gst_bin_get_by_name(GST_BIN(_pipeline), "app_sink");

    g_object_set(this->_app_sink, "emit-signals", TRUE, NULL);
    g_signal_connect(this->_app_sink, "new-sample", G_CALLBACK(new_sample), this);

    gst_element_set_state(_pipeline, GST_STATE_PLAYING);
}

Gstreamer_camera_capture::~Gstreamer_camera_capture()
{
    gst_element_set_state(_pipeline, GST_STATE_NULL);
    gst_object_unref(_pipeline);
}
