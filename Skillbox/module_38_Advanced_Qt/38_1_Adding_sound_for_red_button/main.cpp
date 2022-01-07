// work qt5
// don't work qt6
#include <QApplication>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

//media
#include <QMediaPlayer>


class ImageButton : public  QPushButton {
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();
    void play();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    QMediaPlayer *player;
};

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("img/button1_git.png");
    mButtonDownPixmap = QPixmap("img/button2_git.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);

    //media
    player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("sound/button_git.mp3"));  // Qt5
    QObject::connect(this, &QPushButton::clicked, this, &ImageButton::play);
/*  // work
    QMediaPlayer *player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("sound/button_git.mp3"));

    QObject::connect(this, &QPushButton::clicked, [player]()
    {
        player->play(); // sound clicked mouse
    });*/

}

void ImageButton::play() {
    player->play(); // sound clicked mouse
}

void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this); // на чем рисуем картинку
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const {
    return QSize(100,100);
}

QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e) {
    setDown();
}

void ImageButton::setDown() {
    mCurrentButtonPixmap = mButtonDownPixmap;
    update(); // обновляем
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp() {
    mCurrentButtonPixmap = mButtonUpPixmap;
    update(); // обновляем
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ImageButton myButton(nullptr);
    myButton.setFixedSize(100, 100);
    myButton.move(1000,400);

    myButton.show();

    return QApplication::exec();
}

#include <main.moc>