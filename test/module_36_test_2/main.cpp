#include <QApplication>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *slider = new QSlider(Qt::Horizontal); // slider в горизонтальном положение
    auto *spinBox = new QSpinBox();
    slider->setMinimum(0);
    slider->setMaximum(100);
    spinBox->setMinimum(0); // min значение
    spinBox->setMaximum(100); // max значение
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue); // событие из slider -> spinBox
    //QObject::connect(spinBox, &QSpinBox::valueChanged, slider, &QSlider::setValue); // work
    QObject::connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue); // событие из spinBox -> slider

    slider->resize(100,50); // размеры
    spinBox->resize(50,50);
    slider->move(700, 500); // положение на экране
    spinBox->move(900,500);

    slider->show(); // показать
    spinBox->show();

/*
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
*/
    QApplication::exec();
}
