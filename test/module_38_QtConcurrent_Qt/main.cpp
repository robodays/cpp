//windeployqt через CMD для работы jpg

#include <QtGui/QtGui>
#include <QApplication>
#include <QPushButton>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>

#include <QDir>
#include <iostream>
#include <QPainter>

QImage blurImage(QImage source)
{
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(8);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(),QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return result;
}

void processSingleImage(QString sourceFile, QString destFile)
{
    auto blured = blurImage(QImage(sourceFile));
    blured.save(destFile);
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    processSingleImage("D:/github/cpp/test/module_38_QtConcurrent_Qt/buffy.jpg", "D:/github/cpp/test/module_38_QtConcurrent_Qt/blured_buffy.jpg");
//    processSingleImage("D:/github/cpp/test/module_38_QtConcurrent_Qt/buffy.png", "D:/github/cpp/test/module_38_QtConcurrent_Qt/blured_buffy.png");


//    QDir sourceDir("D:/github/cpp/test/module_38_QtConcurrent_Qt/img");
//    QDir destinationDir("D:/github/cpp/test/module_38_QtConcurrent_Qt/new_img");

/*
    QDir sourceDir("./img"); // cmake-build-debug/img
    QDir destinationDir("./new_img"); // cmake-build-debug/new_img
*/
    QDir sourceDir("img"); // cmake-build-debug/img
    QDir destinationDir("new_img"); // cmake-build-debug/new_img
    auto images = sourceDir.entryList(QStringList() << "*.png" << "*.jpg" << "*.JPG", QDir::Files);
    QElapsedTimer timer;
    timer.start();

    // параллельными потоками // создаем List Future
    QList<QFuture<void>> handlers;

    for(auto &fileName : images)
    {
        // последовательно
        //processSingleImage(sourceDir.path() + "/" + fileName,
        //                   destinationDir.path() + "/" + "blured_" + fileName);

        // параллельными потоками // создаем потоки и кладем в List Future
        handlers.append(QtConcurrent::run(processSingleImage, sourceDir.path() + "/" + fileName,
                          destinationDir.path() + "/" + "blured_" + fileName));
    }

    // параллельными потоками// закрываем Future
    for (auto f : handlers)
    {
        f.waitForFinished();
    }

    std::cout << "Calc time: " << timer.elapsed() << "mseconds" << std::endl;

    return a.exec();
}
