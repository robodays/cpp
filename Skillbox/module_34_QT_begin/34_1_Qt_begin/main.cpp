#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    QPushButton button2("ТЕСТ!", nullptr);
    button2.resize(100, 100);
    button2.show();
    return QApplication::exec();
}
