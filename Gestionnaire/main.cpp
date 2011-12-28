#include <QtGui/QApplication>
#include "gestionnaire.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gestionnaire w;
    w.initGestionnaire();
    w.show();

    return a.exec();
}
