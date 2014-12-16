#ifndef TOUCHSTATE_H
#define TOUCHSTATE_H
#include <stdexcept>

class Element;

class TouchState {
public:
    TouchState();
    bool isTouched();
    Element* element();
    void touch(Element* e);
    void reset();

private:
    bool touched;
    Element* innerElement;
};

#endif // TOUCHSTATE_H
