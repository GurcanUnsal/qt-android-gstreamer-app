import gi
gi.require_version('Gst', '1.0')
from gi.repository import GObject, Gst, GstRtspServer

Gst.init(None)

mainloop = GObject.MainLoop()

server = GstRtspServer.RTSPServer()

mounts = server.get_mount_points()

factory = GstRtspServer.RTSPMediaFactory()
factory.set_launch('( v4l2src device=/dev/video0 ! video/x-raw,framerate=30/1 ! videoconvert ! x264enc speed-preset=ultrafast tune=zerolatency ! rtph264pay name=pay0 pt=96 )')

mounts.add_factory("/stream", factory)

server.attach(None)


mainloop.run()