#ifndef BRICK_H
#define BRICK_H
#include "element.h"
#include <QPainter>
#include <QColor>
#include "properties/health.h"

class Brick: public Element
{

public:
    Brick(int x, int y);
    Brick(int x, int y, int hp);
    Brick(int x, int y, int width, int height);
    Brick(int x, int y, int width, int height, int hp);

    void update();

    Id getId();

    void show(QPainter& painter);
    enum { Width = 40, Height = 20 };



private:
    static QImage& texture();
};

#endif // BRICK_H
