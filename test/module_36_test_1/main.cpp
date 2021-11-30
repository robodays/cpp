#include <QApplication>
#include <iostream>
#include <QTimer>


class Printer : public QObject {
    //Q_OBJECT // непонятно для чего
public slots:
    void printFinished() {
        std::cout << "finished" << std::endl;
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // класс приложения

    QTimer myTimer;
    Printer myPrinter;
    QObject::connect(&myTimer, &QTimer::timeout, &myPrinter, &Printer::printFinished); // connect ссылок
    // myTimer отправитель сигнала
    // QTimer::timeout вид сигнала
    // myPrinter принимает сигнала
    // Printer::printFinished что вызывает

    myTimer.start(2000);

    return QApplication::exec(); // execut - выполнить приложение

}
//#include <main.moc> // непонятно для чего