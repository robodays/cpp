#include <QApplication>
#include <QPushButton> // кнопка
#include <QPixmap> // загрузка картинки из файла
#include <iostream>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
//#include "main.moc" // необходимость в наследовании класса QObject no work

class ImageButton : public  QPushButton {
    //Q_OBJECT // необходимость в наследовании класса QObject no work
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);  // встраивает в родительский виджет
    void paintEvent(QPaintEvent *e) override; // перегружаем метод обработки события рисования
    QSize sizeHint() const override; // размер кнопки
    QSize minimumSizeHint() const override; // минимальный размер
    void keyPressEvent(QKeyEvent *e) override; // обработка нажатия
public slots:
    void setUp(); // слот, чтобы установить не нажатое положение кнопки
    void setDown(); // слот, чтобы установить нажатое положение кнопки
    bool isDown = false; // текущее состояние кнопки

private:
    QPixmap mCurrentButtonPixmap; // Вид кнопки на данный момент
    QPixmap mButtonDownPixmap; // Вид кнопки в нажатом состояние
    QPixmap mButtonUpPixmap; // Вид кнопки в не нажатом состояние
};

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent); // метод родительского класса, туда передаем родителя
    setToolTip("Стоп"); // подсказка при наведении мышки на кнопку
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // устанавливаем фиксированный размер виджета
    mButtonUpPixmap = QPixmap("img/button1_git.png"); // устанавливаем путь к файлу
    mButtonDownPixmap = QPixmap("img/button2_git.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect()); // устанавливаем геометрию кнопки по размеру картинки
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown); // обработка слота
}

void ImageButton::paintEvent(QPaintEvent *e) { // рисуем картинку
    QPainter p(this); // на чем рисуем картинку
    p.drawPixmap(e->rect(), mCurrentButtonPixmap); // рисуем картинку
}

QSize ImageButton::sizeHint() const { // указываем размер виджета
    return QSize(100,100);
}

QSize ImageButton::minimumSizeHint() const { // указываем минимальный размер виджета
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e) { // как кнопка реагирует на нажатие
    setDown();
}

void ImageButton::setDown() { // перерисовываем картинку
    mCurrentButtonPixmap = mButtonDownPixmap;
    update(); // обновляем
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp() { // перерисовываем картинку
    mCurrentButtonPixmap = mButtonUpPixmap;
    update(); // обновляем
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ImageButton myButton(nullptr); // nullptr - указывает, что будет главным окном приложения
    myButton.setFixedSize(100, 100); // размер виджета
    myButton.move(1000,400); // положение виджета на экране

    QObject::connect(&myButton, &QPushButton::clicked, [](){std::cout << "clicked" << std::endl;});

    myButton.show();

    return QApplication::exec();
}
