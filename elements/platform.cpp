#include "platform.h"
#include <QApplication>

Platform::Platform(int x, int y, int width, int height) : Element(x, y, width, height, Element::Platform) {

}

void Platform::show(QPainter &painter) {
    painter.setBrush(QBrush("#000"));
    painter.drawRect(x(), y(), width(), height());
}

void Platform::update() {

}

Element::Id Platform::getId() {
    return Element::Platform;
}
