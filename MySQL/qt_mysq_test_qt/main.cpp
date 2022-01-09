#include <QCoreApplication>
#include <QSqlDriverPlugin>
//#include <QtSql/QSql>
//#include <QtSql/QSqlDatabase>
#include <QtSql>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("tcp://127.0.0.1:3306");
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();

    return a.exec();
}
