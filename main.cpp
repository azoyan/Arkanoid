#include <QtGui/QApplication>
#include "arkanoid.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Arkanoid arkanoid;

    arkanoid.show();
//    a.setOverrideCursor( QCursor( Qt::BlankCursor ) );  //скрыть мышь

    return a.exec();
}
