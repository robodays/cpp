#include <QCoreApplication>
#include <QDebug>
#include <sql.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    return QCoreApplication::exec();
}
