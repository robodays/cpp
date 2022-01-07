#ifndef INC_38_3_BLUR_EFFECT_OVERLAY_APPLICATION_BLURMAINWINDOW_H
#define INC_38_3_BLUR_EFFECT_OVERLAY_APPLICATION_BLURMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSlider>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include <QDir>
#include <QFileDialog>

class BlurMainWindow : public QMainWindow {
    Q_OBJECT
public:
    BlurMainWindow(QWidget *parent = nullptr) : QMainWindow(parent){};

    QLabel *picture = nullptr;
    QSlider *blurRadius = nullptr;

private:
    QString filePath;

    QImage blurImage(QImage source)
    {
        if (source.isNull()) return QImage();
        QGraphicsScene scene;
        QGraphicsPixmapItem item;
        item.setPixmap(QPixmap::fromImage(source));

        auto *blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(blurRadius->value());
        item.setGraphicsEffect(blur);
        scene.addItem(&item);
        QImage result(source.size(),QImage::Format_ARGB32);
        result.fill(Qt::transparent);
        QPainter painter(&result);
        scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
        return result;
    }

    void setPicture()
    {
        QImage image = blurImage(QImage(filePath)).scaled(picture->width(),picture->height(),Qt::KeepAspectRatio);
        picture->setPixmap(QPixmap::fromImage(image));
    }

public slots:
    void openFile() {
        filePath = QFileDialog::getOpenFileName(nullptr,
                                                "Open images",
                                                "img/",
                                                "Images (*.jpg *.png);;All files (*.*)");
        setPicture();

    };

    void setBlurRadius() {
        setPicture();
    }
};



#endif //INC_38_3_BLUR_EFFECT_OVERLAY_APPLICATION_BLURMAINWINDOW_H
