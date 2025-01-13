#include "Gui_stream_object.h"

Gui_stream_object::Gui_stream_object(QQuickItem* parent): QQuickPaintedItem(parent)
{
    QImage image(400, 400, QImage::Format_RGB32);
    image.fill(Qt::red);
    this->_m_image = image;
}

Gui_stream_object::~Gui_stream_object()
{
    if (this->gstreamer_camera_capture)
        delete this->gstreamer_camera_capture;
}

void Gui_stream_object::updateImage(QImage* image)
{
    this->_m_image = *image;
    delete image;
    update();
}

void Gui_stream_object::paint(QPainter* painter)
{
    painter->drawImage(this->boundingRect(), this->_m_image);
}

void Gui_stream_object::init(std::string camera)
{
    if (this->gstreamer_camera_capture == nullptr)
    {
        this->gstreamer_camera_capture = new Gstreamer_camera_capture(camera);
        qRegisterMetaType<QImage*>("QImage*");
        connect(this->gstreamer_camera_capture, &Gstreamer_camera_capture::emit_image, this, &Gui_stream_object::updateImage, Qt::QueuedConnection);
    }
}
