#include "mainwindow.h"  // write INI
#include "mainwindow2.h" // read INI
#include "mainwindow3.h" // Create XML
#include "mainwindow4.h" // read XML
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow4 w;
    w.show();
    return a.exec();
}
