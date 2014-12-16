#ifndef PLATFORM_H
#define PLATFORM_H
#include "element.h"
#include <QPainter>

class Platform : public Element
{
public:    
    Platform(int x, int y, int width, int height);
    void show(QPainter& painter);
    Id getId();
    void update();
    enum { Right = 5, Left = - Right };
};

#endif // PLATFORM_H
