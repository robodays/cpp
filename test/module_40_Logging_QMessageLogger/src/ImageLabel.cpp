
#include "../include/ImageLabel.h"

//logging
#include <QLoggingCategory>
#include <QPainter>

Q_DECLARE_LOGGING_CATEGORY(Change)

Q_LOGGING_CATEGORY(Change, "Change");

ImageLabel::ImageLabel(QWidget *parent) {
    setParent(parent); // метод родительского класса, туда передаем родителя
    //setToolTip("Стоп"); // подсказка при наведении мышки на кнопку
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // устанавливаем фиксированный размер виджета
    mRedCircle = QPixmap(":/img/red_git.png"); // устанавливаем путь к файлу
    mGreenCircle = QPixmap(":/img/green_git.png");
    mYellowCircle = QPixmap(":/img/yellow_git.png");
/*
    mRedCircle = QPixmap("/img/red_git.png"); // устанавливаем путь к файлу
    mGreenCircle = QPixmap("/img/green_git.png");
    mYellowCircle = QPixmap("/img/yellow_git.png");
*/

    setGreen();
    currentColor = "green";
    //setPixmap(mCurrentCircle);
    setGeometry(mGreenCircle.rect()); // устанавливаем геометрию кнопки по размеру картинки
    //connect(this, &QPushButton::clicked, this, &ImageButton::setDown); // обработка слота
}

void ImageLabel::setRed() {
    if (currentColor == "red") return;
    setPixmap(mRedCircle);
    currentColor = "red";
    update();
    qDebug(Change()) << Q_FUNC_INFO;
}

void ImageLabel::setGreen() {
    if (currentColor == "green") return;
    setPixmap(mGreenCircle);
    currentColor = "green";
    update();
    qDebug(Change()) << Q_FUNC_INFO;
}

void ImageLabel::setYellow() {
    if (currentColor == "yellow") return;
    setPixmap(mYellowCircle);
    currentColor = "yellow";
    update();
    qDebug(Change()) << Q_FUNC_INFO;
}