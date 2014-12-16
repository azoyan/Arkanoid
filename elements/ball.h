#ifndef BALL_H
#define BALL_H
#include "element.h"
#include <QPainter>
#include "properties/health.h"

class Ball : public Element
{
public:    
    Ball(int x, int y, int width, int height);
    void show(QPainter& painter);
    void update();
    Id getId();
    enum { Step = 4 };        
    enum { RightAngle = 90, HalfCircle = RightAngle + RightAngle, Circle = HalfCircle + HalfCircle };
    int innerDegree;
private:
    void move();   
};

#endif // BALL_H
