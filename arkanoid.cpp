#include "arkanoid.h"
#include "elements/ball.h"
#include "elements/brick.h"
#include "elements/platform.h"
#include <QPainter>
#include <QTimer>
#include <ctime>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QApplication>

Arkanoid::Arkanoid(QWidget *parent) : QWidget(parent) {
    createMap( qApp->applicationDirPath() + "\\map.txt" );
    QTimer* timer = new QTimer(this);
    timer->setInterval(1000/600);
    timer->setSingleShot(false);
    setMouseTracking(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start();
}

void Arkanoid::createMap(QString filePath) {
    lastMap = filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {        
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd())  {
        QString line = in.readLine();
        if (line.startsWith("#")) continue;
        QStringList list = line.simplified().split(",");
        if (list.size() < 5) QMessageBox::information(this, "Parse Error", "Parse ERROR");
        createElement(list.at(0).toInt(), list.at(1).toInt(), list.at(2).toInt(), list.at(3).toInt(), list.at(4).toInt());
    }
}

void Arkanoid::paintEvent(QPaintEvent *event) {
    unsigned int start_time =  clock(); // начальное время

    QWidget::paintEvent(event);
    changeWorld();
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time;
    this->setWindowTitle("speed: x" +  QString::number(search_time / 1000.0 * 60.0)  );
}

void Arkanoid::keyPressEvent(QKeyEvent* e) {
    QWidget::keyPressEvent(e);
    switch(e->key()) {
    case Qt::Key_R: restart();
    }
}

void Arkanoid::mouseMoveEvent(QMouseEvent* e) {
    platform->moveToX(e->x());
    platform->moveToY(e->y());
}

void Arkanoid::restart() {
    clearMap();
    createMap(lastMap);
}

void Arkanoid::clearMap() {
    for(std::list<Element*>::iterator  it = blocks.begin(); it != blocks.end(); ++it) {
        Element* currentElement = *it;
        delete currentElement;
    }
    for(std::list<Element*>::iterator  it = balls.begin(); it != balls.end(); ++it) {
        Element* currentElement = *it;
        delete currentElement;
    }
    balls.clear();
    blocks.clear();
}

void Arkanoid::createElement(Element::Id id, int x, int y, int width, int height) {
    switch(id) {
        case Element::Brick: {
            Brick* createdElement = new Brick(x, y, width, height);
            blocks.push_back(createdElement);
            break;
        }
        case Element::Ball: {
            Ball* createdElement = new Ball(x, y, width, height);
            balls.push_back(createdElement);
            break;
        }
        case Element::Platform: {
            Platform* createdElement = new Platform(x, y, width, height);
            blocks.push_back(createdElement);
            platform = createdElement;
            break;
        }
    }
}

void Arkanoid::changeWorld() {
    collide();
//    bot();
    QPainter painter(this);
    for(std::list<Element*>::iterator  it = blocks.begin(); it != blocks.end(); ++it) {
        Element* currentElement = *it;
        if(currentElement->isDead()) it = blocks.erase(it);
        else {
            currentElement->show(painter);
            currentElement->update();
            currentElement->resetTouchStates();
        }
    }

    for(std::list<Element*>::iterator  it = balls.begin(); it != balls.end(); ++it) {
        Element* currentElement = *it;

        if(currentElement->isDead()) it = blocks.erase(it);
        else {
            currentElement->show(painter);
            currentElement->update();
            currentElement->resetTouchStates();
        }
    }
}

void Arkanoid::collide() {
    for(std::list<Element*>::iterator  it1 = blocks.begin(); it1 != blocks.end(); ++it1) {
        for(std::list<Element*>::iterator  it2 = balls.begin(); it2 != balls.end(); ++it2) {
            collide(*it1, *it2);
        }
    }
}

void Arkanoid::collide(Element* e1, Element* e2) {
    int x1 = e1->x();
    int x2 = e1->x() + e1->width();
    int y1 = e1->y();
    int y2 = e1->y() + e1->height();

    int x3 = e2->x();
    int x4 = e2->x() + e2->width();
    int y3 = e2->y();
    int y4 = e2->y() + e2->height();

    if ( (x3 <= x2) && (x4 >= x1 ) && (y4 >= y1) && (y3 <= y2) ) {
        int x_mid = x1 + e1->width() / 2;  //центр стены  Х
        int y_mid = y1 + e1->height() / 2; //центр стены  Y

        bool isInRightSide = ((x4 - x_mid) > (x_mid - x3));
        bool isInTopSide =  ((y4 - y_mid) < (y_mid - y3));

        if (isInRightSide) {
            int delta_x = x4 - x2;
            if (isInTopSide) {
                int delta_y = y1 - y3;
                if (delta_x > delta_y) { e2->left().touch(e1); e1->right().touch(e2); }
                else { e2->bottom().touch(e1); e1->top().touch(e2); }
            }
            else {
                int delta_y = y4 - y2;
                if (delta_x > delta_y) { e2->left().touch(e1); e1->right().touch(e2); }
                else { e2->top().touch(e1); e1->bottom().touch(e2); }
            }
        }

        else {
            int delta_x = x1 - x4;
            if (isInTopSide) {
                int delta_y = y1 - y3;
                if (delta_x > delta_y) { e2->right().touch(e1); e1->left().touch(e2); }
                else { e2->bottom().touch(e1); e1->top().touch(e2); }
            }
            else {
                int delta_y = y4 - y2;
                if (delta_x > delta_y) { e2->right().touch(e1); e1->left().touch(e2); }
                else { e2->top().touch(e1); e1->bottom().touch(e2); }
            }
        }
    }
}


void Arkanoid::bot() {
    int ball_mid = balls.front()->x() + balls.front()->width() / 2;

    int botPlatform_mid = botPlatform->width() / 2;


    platform->moveToX(1.08 * (ball_mid - botPlatform_mid));
    botPlatform->moveToX(0.95 * (ball_mid - botPlatform_mid));

}

Arkanoid::~Arkanoid() {
    clearMap();
}




