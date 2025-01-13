#pragma once

#include <gst/gst.h>
#include <QObject>

class Gstreamer_camera_capture: public QObject
{
    Q_OBJECT

public:
    Gstreamer_camera_capture(std::string camera);
    ~Gstreamer_camera_capture();
    void process_image(QImage* image);

signals:
    void emit_image(QImage* image);

private:
    GstElement* _pipeline;
    GstElement* _app_sink;
};
