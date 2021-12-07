
#include "../include/ImageLabel.h"

ImageLabel::ImageLabel(QWidget *parent) {
    setParent(parent); // метод родительского класса, туда передаем родителя
    //setToolTip("Стоп"); // подсказка при наведении мышки на кнопку
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // устанавливаем фиксированный размер виджета
    mRedCircle = QPixmap("img/red_git.png"); // устанавливаем путь к файлу
    mGreenCircle = QPixmap("img/green_git.png");
    mYellowCircle = QPixmap("img/yellow_git.png");
    setPixmap(mGreenCircle);
    setGeometry(mGreenCircle.rect()); // устанавливаем геометрию кнопки по размеру картинки
    //connect(this, &QPushButton::clicked, this, &ImageButton::setDown); // обработка слота
}

void ImageLabel::setRed() {
    setPixmap(mRedCircle);
    update();
}

void ImageLabel::setGreen() {
    setPixmap(mGreenCircle);
    update();
}

void ImageLabel::setYellow() {
    setPixmap(mYellowCircle);
    update();
}