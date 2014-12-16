#include "element.h"

Element::Element(int x, int y, int width, int height)
  : innerX(x),
    innerY(y),
    innerWidth(width),
    innerHeight(height) {
    resetTouchStates();
}

Element::Element(int x, int y, int width, int height, int hp)
  : innerX(x),
    innerY(y),
    innerWidth(width),
    innerHeight(height),
    hp(hp) {
    resetTouchStates();
}

Element::~Element() {

}

int Element::x() {
    return innerX;
}

int Element::y() {
    return innerY;
}

int Element::width() {
    return innerWidth;
}

int Element::height() {
  return innerHeight;
}

void Element::show(QPainter &painter)
{
}

void Element::setWidth(int width) {
    innerWidth = width;
}


bool Element::isDead(){
    return hp.isNull();
}

void Element::moveX(int x) {
 innerX += x;
}

void Element::moveY(int y) {
    innerY += y;
}

void Element::moveToX(int x) {
    innerX = x;
}

void Element::moveToY(int y) {
    innerY = y;
}


void Element::resetTouchStates() {
    top().reset();
    bottom().reset();
    left().reset();
    right().reset();
}

TouchState& Element::top() {
    return innerTop;
}

TouchState& Element::bottom() {
    return innerBottom;
}

TouchState& Element::left() {
    return innerLeft;
}

TouchState& Element::right() {
    return innerRight;
}

