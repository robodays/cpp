#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QLabel *lab = new QLabel("Привет");
//    lab->resize(400, 200);
//    lab->show();

//    QLabel lab = QLabel("Привет");
//    lab.resize(400, 200);
//    lab.show();

    return a.exec();
}
