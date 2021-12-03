#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton("One", window);
    QPushButton *button2 = new QPushButton("Two", window);
    QPushButton *button3 = new QPushButton("Three", window);
    QPushButton *button4 = new QPushButton("Four", window);
    QPushButton *button5 = new QPushButton("Five", window);

/*  // 1
    button1->move(50,50);
    button2->move(150,150);
    button3->move(250,250);
*/
      //2,3
//    auto *layout = new QVBoxLayout(window); // выравнивание по вертикали
//    auto *layout = new QHBoxLayout(window); // выравнивание по горизонтали

//    layout->addWidget(button1);
//    layout->addWidget(button2);
//    layout->addWidget(button3);
    //4
    auto *layout2 = new QGridLayout(window);

    layout2->addWidget(button1,0,0);
    layout2->addWidget(button2,0,1);
    layout2->addWidget(button3,1,0,1,2);
    layout2->addWidget(button4,2,0);
    layout2->addWidget(button5,2,1);

    window->resize(400,400);
    window->move(500,250);
    window->show();
    return app.exec();

}
