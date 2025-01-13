#pragma once

#include <QQmlApplicationEngine>

#include "Gui_stream_object.h"

class Gui_application
{
public:
    Gui_application();
    void init(std::string camera);

private:
    QQmlApplicationEngine _engine;
    Gui_stream_object* _gui_stream_object=nullptr;
};
