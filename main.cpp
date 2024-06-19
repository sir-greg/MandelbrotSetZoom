#include "drawerholderwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawerHolderWidget w;
    w.show();
    return a.exec();
}
