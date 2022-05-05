
#include "map.h"
#include <mainwindow/mainwindow.h>

#include <QApplication>

#include "map.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    addMap();

}
