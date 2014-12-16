#include "platform.h"
#include <QApplication>

Platform::Platform(int x, int y) : Element(x, y, Width, Height, Element::Platform) {

}

Platform::Platform(int x, int y, int width, int height) : Element(x, y, width, height, Element::Platform) {

}

void Platform::show(QPainter &painter) {
    painter.setBrush(QBrush("#000"));
    painter.drawRect(x(), y(), Width, Height);
}

int Platform::width() { return Width; }
int Platform::height() { return Height; }

void Platform::update() {

}

Element::Id Platform::getId() {
    return Element::Platform;
}

QImage& Platform::texture() {
    static QImage data(QString(qApp->applicationDirPath() + "\\platform.png"));
    return data;
}
