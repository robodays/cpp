#include <QApplication>
#include "./ui_blur.h"
#include "blurmainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    BlurMainWindow window(nullptr);
    Ui::MainWindow blur;
    blur.setupUi(&window);
    window.picture = blur.picture;
    window.blurRadius = blur.blurRadius;

    window.resize(500, 500);
    window.show();
    return QApplication::exec();
}
