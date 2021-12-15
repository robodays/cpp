#include <QApplication>
#include <QPushButton>
#include <QtSql/QtSql>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("127.0.0.1:3306");
//    db.setDatabaseName("sakila");
//    db.setUserName("root");
//    db.setPassword("root");
//    bool ok1 = db.open();


    button.show();
    return QApplication::exec();
}
