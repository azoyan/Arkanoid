#include "brick.h"
#include <QImage>
#include <QApplication>

Brick::Brick(int x, int y, int width, int height) : Element(x, y,  width, height) {

}

Brick::Brick(int x, int y, int width, int height, int hp) : Element(x, y,  width, height, hp) {

}

void Brick::show(QPainter &painter) {
    painter.drawRect(x(), y(), width(), height());
}

void Brick::update() {
    if (top().isTouched()) hp.hit();
    if (bottom().isTouched()) hp.hit();
    if (left().isTouched()) hp.hit();
    if (right().isTouched()) hp.hit();

}

Element::Id Brick::getId() {
    return Element::Brick;
}
