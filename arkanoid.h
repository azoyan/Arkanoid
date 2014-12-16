#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <vector>
#include "elements/element.h"
#include "QPaintEvent"



class Platform;

class Arkanoid : public QWidget
{
    Q_OBJECT
    
public:
    Arkanoid(QWidget *parent = 0);
    ~Arkanoid();

    void paintEvent(QPaintEvent* event);    
    void loadMap(QString filePath);
private:
    void changeWorld();
    void collide();
    void collide(Element* e1, Element* e2);
    Platform* platform;
    Platform* botPlatform;
    void keyPressEvent(QKeyEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void restart();
    void clearMap();
    std::list<Element*> balls;
    std::list<Element*> blocks;
    void createMap(QString filePath);
    void createElement(Element::Id, int x, int y, int width, int height);
    void bot();
    QString lastMap;
};

#endif // WIDGET_H
