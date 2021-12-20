#include <QApplication>
#include <QPushButton>

//no work, WebEngineWidgets absent in MinGW

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
