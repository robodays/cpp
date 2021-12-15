// copy from QT Creator main.cpp
/*#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}*/


// copy from https://russianblogs.com/article/8896872563/
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
