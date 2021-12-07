#pragma once

#include <QLabel>

class ImageLabel : public  QLabel {
    //Q_OBJECT // необходимость в наследовании класса QObject no work
public:
    ImageLabel() = default;
    explicit ImageLabel(QWidget *parent);
    public slots:
    void setRed();
    void setGreen();
    void setYellow();

private:
    QPixmap mRedCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
};