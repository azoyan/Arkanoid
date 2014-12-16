#ifndef ELEMENT_H
#define ELEMENT_H
#include <QPainter>
#include <QColor>
#include "properties/health.h"
#include "properties/touchstate.h"

class Element
{
public:
    Element(int x, int y, int width, int height, int hp);
    Element(int x, int y, int width, int height);
    enum Id { NoId, Platform, Brick, Ball };

private:
    int innerX;
    int innerY;

    int innerWidth;
    int innerHeight;

    int innerId;

    TouchState innerTop;
    TouchState innerBottom;
    TouchState innerLeft;
    TouchState innerRight;

protected:
    Health hp;


public:    
    int x();
    int y();    

    int width();
    int height();

    void setWidth(int width);
    void setHeight(int height);


    bool isDead();

    void moveX(int x);
    void moveY(int y);
    void moveToX(int x);
    void moveToY(int y);
    virtual void update() = 0;

    typedef int Id;
    virtual Id getId() = 0;

    void resetTouchStates();

    TouchState &top();
    TouchState &bottom();
    TouchState &left();
    TouchState &right();

    virtual ~Element();

    virtual void show(QPainter& painter) = 0;
};

#endif // ELEMENT_H
