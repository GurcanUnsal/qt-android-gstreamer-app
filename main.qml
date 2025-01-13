import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Window 2.15
import CustomObjects 1.0

Window {
    // @disable-check M16
    visible: true
    // @disable-check M16
    width: 640
    // @disable-check M16
    height: 480
    // @disable-check M16
    title: qsTr("RTSP Stream")

    property var refToStreamObj: stream_object
    Gui_stream_object {
        id: stream_object
        // @disable-check M16
        anchors.left: parent.left
        // @disable-check M16
        anchors.top: parent.top

        // @disable-check M16
        width: parent.width
        // @disable-check M16
        height: parent.height
    }

}
