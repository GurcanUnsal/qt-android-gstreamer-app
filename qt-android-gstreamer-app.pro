QT += quick widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

GST_ROOT = /home/rossim1/gstreamer-1.0-android-universal-1.18.6/armv7

LIBS += -L$$GST_ROOT/lib/gstreamer-1.0 \
-lgstvideo-1.0 \
-lgstvideotestsrc \
-lgstaudioconvert \
-lgstvideoconvert \
-lgstautodetect \
-lgstgio \
-lgstapp \
-lgstavi \
-lgstaudioparsers \
-lgstcoreelements \
-lgsttypefindfunctions \
-lgstplayback \
-lgstudp \
-lgstrtp \
-lgstrtsp \
-lgstx264 \
-lgstlibav \
-lgstsdpelem \
-lgstvideoparsersbad \
-lgstrtpmanager \
-lgstisomp4 \
-lgstmatroska \
-lgstmpegtsdemux \
-lgstandroidmedia \
-lgstopengl \
-lgsttcp \

# Rest of GStreamer dependencies
LIBS += -L$$GST_ROOT/lib \
-lgraphene-1.0 -ljpeg -lpng16 \
-lgstfft-1.0 -lm \
-lgstnet-1.0 -lgio-2.0  \
-lgstphotography-1.0 -lgstgl-1.0 -lEGL \
-lgstaudio-1.0 -lgstcodecparsers-1.0 -lgstbase-1.0 \
-lgstreamer-1.0 -lgstrtp-1.0 -lgstpbutils-1.0 -lgstrtsp-1.0 -lgsttag-1.0 \
-lgstvideo-1.0 -lavformat -lavcodec -lavutil -lx264 -lavfilter -lswresample \
-lgstriff-1.0 -lgstcontroller-1.0 -lgstapp-1.0 \
-lgstsdp-1.0 -lbz2 -lgobject-2.0 -lgstmpegts-1.0 \
-Wl,--export-dynamic -lgmodule-2.0 -pthread -lglib-2.0 -lorc-0.4 -liconv -lffi -lintl \

INCLUDEPATH += \
$$GST_ROOT/include/gstreamer-1.0 \
$$GST_ROOT/lib/gstreamer-1.0/include \
$$GST_ROOT/include/glib-2.0 \
$$GST_ROOT/lib/glib-2.0/include

SOURCES += \
        Gstreamer_camera_capture.cpp \
        Gui_application.cpp \
        Gui_stream_object.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Gstreamer_camera_capture.h \
    Gui_application.h \
    Gui_stream_object.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
