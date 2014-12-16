#include "touchstate.h"
#include <QDebug>

TouchState::TouchState() {
    reset();
}

Element* TouchState::element() {
    if (innerElement == 0) throw std::logic_error("No element in TouchState::getElement()!");
    return innerElement;
}

void TouchState::touch(Element* e) {
    innerElement = e;
    if (e == 0) throw std::logic_error("Null pointer!");
    else touched = true;
}

void TouchState::reset() {
    touched = false;
    innerElement = 0;
}

bool TouchState::isTouched() { return touched; }
