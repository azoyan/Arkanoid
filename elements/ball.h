#ifndef BALL_H
#define BALL_H
#include "element.h"
#include <QPainter>
#include "properties/health.h"

class Ball : public Element
{
public:
    Ball(int x, int y);
    Ball(int x, int y, int width, int height);
    void show(QPainter& painter);

    int width();
    int height();

    void update();

    Id getId();

    enum { Step = 4 };
    void go(int frameWidth, int frameHeight);
    enum BallSize { Width = 16, Height = 16  };
    enum { RightAngle = 90, HalfCircle = RightAngle + RightAngle, Circle = HalfCircle + HalfCircle };
    int innerDegree;
private:
    void move();
    static QImage& texture();
};

#endif // BALL_H
