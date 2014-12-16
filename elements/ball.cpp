#include "ball.h"
#include <cmath>
#include <QDebug>
#include "element.h"
#include <cassert>
#include <QApplication>

Ball::Ball(int x, int y) : Element(x, y, Width, Height), innerDegree(0) {
}

Ball::Ball(int x, int y, int width, int height) : Element(x, y, width, height), innerDegree(0) {

}

void Ball::show(QPainter &painter) {


//    painter.drawImage(x(), y(), texture());
    painter.drawEllipse(x(), y(), Width, Height);
}

int Ball::width() { return Width; }
int Ball::height() { return Height; }

void Ball::update() {
    if (bottom().isTouched() && bottom().element()->getId() == Element::Platform) {
        Element* platform = bottom().element();

        int ball_mid = x() + width() / 2;
        int platform_mid = platform->x() + platform->width() / 2;

        double slice = platform->width() / static_cast<double>(HalfCircle);
        qDebug() << "slice " << slice;

        innerDegree = static_cast<int>( ( - RightAngle + ( ball_mid - platform->x() ) / slice ) / 2 ) % Circle;
    }
    else {
        if (top().isTouched()) innerDegree = (HalfCircle - innerDegree) % Circle;
        if (bottom().isTouched()) innerDegree = (HalfCircle - innerDegree) % Circle;
        if (left().isTouched()) innerDegree = (Circle - innerDegree) % Circle;
        if (right().isTouched()) innerDegree = (Circle - innerDegree) % Circle;
    }

    if (top().isTouched()) qDebug() << "Top" << innerDegree;
    if (bottom().isTouched()) qDebug() << "Bottom" << innerDegree;
    if (left().isTouched()) qDebug() << "Left" << innerDegree;
    if (right().isTouched()) qDebug() << "Right" << innerDegree;

    move();
}

void Ball::move() {

    double degreeRad = innerDegree * (M_PI / static_cast<double>(HalfCircle));
    moveY( -Step * cos(degreeRad) );
    moveX(  Step * sin(degreeRad) );
}

QImage& Ball::texture() {
    static QImage data(QString(qApp->applicationDirPath() + "\\ball.png"));
    return data;
}

Element::Id Ball::getId() {
    return Element::Ball;
}



