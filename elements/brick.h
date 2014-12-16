#ifndef BRICK_H
#define BRICK_H
#include "element.h"
#include <QPainter>
#include <QColor>
#include "properties/health.h"

class Brick: public Element
{

public:    
    Brick(int x, int y, int width, int height);
    Brick(int x, int y, int width, int height, int hp);
    void update();
    Id getId();
    void show(QPainter& painter);
};

#endif // BRICK_H
