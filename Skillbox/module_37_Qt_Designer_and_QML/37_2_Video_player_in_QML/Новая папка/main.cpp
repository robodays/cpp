#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QWindow>

int main(int argc, char *argv[]) {
    QGuiApplication  app(argc, argv);

    QQmlComponent component(new QQmlApplicationEngine(), "qrc:/main.qml");
    QWindow *window = (QWindow*)component.create();
    window->show();

    return app.exec();
}
/*
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}*/
