#include <QApplication>

#include <QMediaPlayer>
//#include <QMediaContent> // The class has been removed in Qt6. Use QUrl for individual media files instead.
#include <QAudioOutput>
#include <QUrl>
#include <QVideoWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QFileDialog>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //Gui
    QWidget playerWindow;
    QVBoxLayout vbox(&playerWindow);
    QHBoxLayout buttons;

    //video
    //auto videoWidget = new QVideoWidget(&playerWindow);
    //vbox.addWidget(videoWidget);

    QSlider *songSlider = new QSlider(&playerWindow);
    songSlider->setOrientation(Qt::Horizontal);
    vbox.addWidget(songSlider);

    auto *openFileButton = new QPushButton("Open", &playerWindow);
    auto *playMediaButton = new QPushButton("Play", &playerWindow);
    auto *pauseMediaButton = new QPushButton("Pause", &playerWindow);

    buttons.addWidget(openFileButton);
    buttons.addWidget(playMediaButton);
    buttons.addWidget(pauseMediaButton);

    vbox.addLayout(&buttons);


    QString filePath;

    auto *player = new QMediaPlayer(&playerWindow);
    //QMediaPlayer player;

    //video
/*    player->setVideoOutput(videoWidget);

    bool isPlaying = false;

    QObject::connect(openFileButton, &QPushButton::clicked, [&filePath, player, &isPlaying]
    {
        filePath = QFileDialog::getOpenFileName(nullptr,
                                                "Open media",
                                                "D:/",
                                                "Media files (*.mp3, *.mp4, *.avi)");
        player->stop();
        isPlaying = false;
    });

    QObject::connect(playMediaButton, &QPushButton::clicked, [&isPlaying, songSlider, player, &filePath]() {
        if (!isPlaying)
        {
            //player->setMedia(QUrl::fromLocalFile(filePath)); // for Qt5
            player->setSource(QUrl::fromLocalFile(filePath)); // for Qt6
            //player->setVolume(75); // for Qt5
            auto audioOutput = new QAudioOutput; // for Qt6
            player->setAudioOutput(audioOutput); //
            audioOutput->setVolume(75);   //
            QObject::connect(player, &QMediaPlayer::durationChanged, [songSlider](qint64 duration)
            {
                songSlider->setMinimum(0);
                songSlider->setMaximum(duration);
            });

            QObject::connect(player, &QMediaPlayer::positionChanged, [songSlider](qint64 pos)
            {
                songSlider->setValue(pos);
            });
            player->play();
        }
    });

    QObject::connect(songSlider, &QSlider::valueChanged, player, &QMediaPlayer::setPosition);
    QObject::connect(pauseMediaButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
*/
    playerWindow.show();

    return QApplication::exec();
}
