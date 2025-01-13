#include "Gui_application.h"

Gui_application::Gui_application()
{
    qmlRegisterType<Gui_stream_object>("CustomObjects", 1, 0, "Gui_stream_object");
    this->_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    this->_gui_stream_object = reinterpret_cast<Gui_stream_object*>(this->_engine.rootObjects()[0]->property("refToStreamObj").value<QObject*>());
}

void Gui_application::init(std::string camera)
{
    this->_gui_stream_object->init(camera);
}
