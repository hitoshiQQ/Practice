#include "include/mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QPushButton>
#include <QTableWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w = new MainWindow;

    w.show();


    return a.exec();
}
