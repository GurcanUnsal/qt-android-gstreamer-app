#include <QApplication>
#include <gst/gst.h>
#include <gst/gstplugin.h>
#include "Gui_application.h"

extern "C" {
GST_PLUGIN_STATIC_DECLARE(coreelements);
GST_PLUGIN_STATIC_DECLARE(playback);
GST_PLUGIN_STATIC_DECLARE(libav);
GST_PLUGIN_STATIC_DECLARE(rtp);
GST_PLUGIN_STATIC_DECLARE(rtsp);
GST_PLUGIN_STATIC_DECLARE(udp);
GST_PLUGIN_STATIC_DECLARE(videoparsersbad);
GST_PLUGIN_STATIC_DECLARE(x264);
GST_PLUGIN_STATIC_DECLARE(rtpmanager);
GST_PLUGIN_STATIC_DECLARE(isomp4);
GST_PLUGIN_STATIC_DECLARE(matroska);
GST_PLUGIN_STATIC_DECLARE(mpegtsdemux);
GST_PLUGIN_STATIC_DECLARE(opengl);
GST_PLUGIN_STATIC_DECLARE(tcp);
GST_PLUGIN_STATIC_DECLARE(videotestsrc);
GST_PLUGIN_STATIC_DECLARE(audioconvert);
GST_PLUGIN_STATIC_DECLARE(videoconvert);
GST_PLUGIN_STATIC_DECLARE(autodetect);
GST_PLUGIN_STATIC_DECLARE(gio);
GST_PLUGIN_STATIC_DECLARE(app);
GST_PLUGIN_STATIC_DECLARE(isomp4);
GST_PLUGIN_STATIC_DECLARE(avi);
GST_PLUGIN_STATIC_DECLARE(audioparsers);
GST_PLUGIN_STATIC_DECLARE(typefindfunctions);
GST_PLUGIN_STATIC_DECLARE(androidmedia);
};

int main(int argc, char** argv)
{
    // RTSP stream address
    std::string camera_mount = "rtsp://192.168.237.122:8554/stream";

    // Start QT application
    QApplication app(argc, argv);

    gst_init(&argc, &argv);

    GST_PLUGIN_STATIC_REGISTER(coreelements);
    GST_PLUGIN_STATIC_REGISTER(playback);
    GST_PLUGIN_STATIC_REGISTER(libav);
    GST_PLUGIN_STATIC_REGISTER(rtp);
    GST_PLUGIN_STATIC_REGISTER(rtsp);
    GST_PLUGIN_STATIC_REGISTER(udp);
    GST_PLUGIN_STATIC_REGISTER(videoparsersbad);
    GST_PLUGIN_STATIC_REGISTER(x264);
    GST_PLUGIN_STATIC_REGISTER(rtpmanager);
    GST_PLUGIN_STATIC_REGISTER(isomp4);
    GST_PLUGIN_STATIC_REGISTER(matroska);
    GST_PLUGIN_STATIC_REGISTER(mpegtsdemux);
    GST_PLUGIN_STATIC_REGISTER(opengl);
    GST_PLUGIN_STATIC_REGISTER(tcp);
    GST_PLUGIN_STATIC_REGISTER(videotestsrc);
    GST_PLUGIN_STATIC_REGISTER(audioconvert);
    GST_PLUGIN_STATIC_REGISTER(videoconvert);
    GST_PLUGIN_STATIC_REGISTER(autodetect);
    GST_PLUGIN_STATIC_REGISTER(gio);
    GST_PLUGIN_STATIC_REGISTER(app);
    GST_PLUGIN_STATIC_REGISTER(isomp4);
    GST_PLUGIN_STATIC_REGISTER(avi);
    GST_PLUGIN_STATIC_REGISTER(audioparsers);
    GST_PLUGIN_STATIC_REGISTER(typefindfunctions);
    GST_PLUGIN_STATIC_REGISTER(androidmedia);

    Gui_application gui_application;
    gui_application.init(camera_mount);
    return app.exec();
}


