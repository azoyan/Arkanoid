#ifndef PLATFORM_H
#define PLATFORM_H
#include "element.h"
#include <QPainter>

class Platform : public Element
{
public:
    Platform(int x, int y);
    Platform(int x, int y, int width, int height);
    void show(QPainter& painter);

    int width();
    int height();

    Id getId();

    void update();
    enum { Right = 5, Left = - Right };
    enum PlatformSize { Width = 90, Height = 10 };
private:
    static QImage& texture();
};

#endif // PLATFORM_H
