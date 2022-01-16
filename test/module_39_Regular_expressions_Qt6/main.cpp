#include <QApplication>
#include <QPushButton>


#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *window = new QMainWindow;
    window->resize(400, 100);

    auto vBoxLayout = new QVBoxLayout

    auto *lineEdit = new QLineEdit(window);
    lineEdit->resize(window->width(), 30);
    auto *label = new QLabel(window);
    label->setText("Hello!!!");


    window->show();
    return QApplication::exec();
}
