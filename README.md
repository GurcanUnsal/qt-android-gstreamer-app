# Qt Android Gstreamer App
Video Streaming App for Android Devices

# Dependencies
- Qt 5.15
- Gstreamer prebult binaries for android (1.18.6)

# Usage
Clone the repo.
```bash

git clone https://github.com/GurcanUnsal/qt-android-gstreamer-app

```
Launch Qt Creator. Import the project using the qt-android-gstreamer-app.pro file.
Download prebuilt binaries for [gstreamer 1.18.6](https://gstreamer.freedesktop.org/data/pkg/android/1.18.6/) for android. Extract the tar.xz to your home directory. Edit the path for gstreamer root.
Edit the RTSP stream URL in main.cpp using your ip.
Build and open the apk on an android device.

Start RTSP stream.

```bash

cd ~/qt-android-gstreamer-app/rtsp_stream

python3 stream.py
```
You should now be able to see the broadcast.
