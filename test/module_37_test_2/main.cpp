#include <QApplication>
#include <QPushButton>
#include "./ui_caller.h" // нажимаем сборка

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.resize(480, 640);
    window.show();
    return QApplication::exec();
}