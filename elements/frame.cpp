#include "frame.h"

Frame::Frame(int x, int y, int width, int height) : Element(x, y), innerWidth(width), innerHeight(height)
{

}

void Frame::show(QPainter &painter)
{
    painter.drawRect(x(), y(), width(), height());
}

int Frame::width() { return innerWidth; }
int Frame::height() { return innerHeight; }

void Frame::update()
{

}





