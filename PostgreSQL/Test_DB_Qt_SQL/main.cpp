#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test_db");
    db.setUserName("postgres");
    db.setPassword("root");
    bool ok = db.open();
    std::cout << ok;




    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
