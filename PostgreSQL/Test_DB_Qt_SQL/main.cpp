//Переменные среды, path C:\Program Files\PostgreSQL\14\bin
//К exe файлу кладем папку с драйверами sqldrivers из E:\Qt\6.2.1\mingw81_64\plugins\
//Могут понадобятся какие-нибудь dll из PostgreSQL
//https://doc.qt.io/qt-5/qsqlquery.html


#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <iostream>
#include <windows.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    SetConsoleOutputCP(CP_UTF8);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test_db");
    db.setUserName("postgres");
    db.setPassword("root");
    bool ok = db.open();
    std::cout << (ok ? "Connect Yes" : "Connect NO") << std::endl;


/*    QSqlQuery query1("SELECT product_id, product_name, price, categories_name, price as p "
                    "FROM goods "
                    "JOIN categories ON category = categories_id "
                    "WHERE category IN (3, 4) "
                    "ORDER BY product_id;");
    while (query.next()) {
    QString product_id = query.value(0).toString();
    QString product_name = query.value(1).toString();
    std::cout << "product: " << product_id.toStdString() << " product_name: " << product_name.toStdString() << std::endl;
    }*/

    //QSqlQuery queryInsert("INSERT INTO goods (product_name, price, category) VALUES ('Лёд', 444.55, 3);");
    //QSqlQuery queryInsert2;
    //queryInsert2.exec("INSERT INTO goods (product_name, price, category) VALUES ('Лёд', 444.55, 3);");

    QSqlQuery query2("SELECT * "
                    "FROM goods "
                    "JOIN categories ON category = categories_id "
                    "WHERE category IN (3, 4) "
                    "ORDER BY product_id;");



    int field2 = query2.record().indexOf("product_name");
    while (query2.next()) {
        QString product_name = query2.value(field2).toString();
        std::cout << " product_name: " << product_name.toStdString() << std::endl;
    }




    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
