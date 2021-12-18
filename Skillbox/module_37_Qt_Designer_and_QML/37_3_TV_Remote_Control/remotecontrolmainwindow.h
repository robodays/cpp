#ifndef INC_37_3_TV_REMOTE_CONTROL_REMOTECONTROLMAINWINDOW_H
#define INC_37_3_TV_REMOTE_CONTROL_REMOTECONTROLMAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QProgressBar>
//#include <QLabel> // for test

class RemoteControlMainWindow : public QMainWindow {
    Q_OBJECT
public:
    RemoteControlMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {}

    QLCDNumber *channelLcd = nullptr;
    QProgressBar *volumeProgress = nullptr;
    //QLabel *channelNowLabel = nullptr; // for test
public slots:
    void key0() {channelLcd->display(0);};
    void key1() {channelLcd->display(1);};
    void key2() {channelLcd->display(2);};
    void key3() {channelLcd->display(3);};
    void key4() {channelLcd->display(4);};
    void key5() {channelLcd->display(5);};
    void key6() {channelLcd->display(6);};
    void key7() {channelLcd->display(7);};
    void key8() {channelLcd->display(8);};
    void key9() {channelLcd->display(9);};
    void channelUp() {
        //bool ok;
        //channelNowLabel->setText(QString::number(channelNowLabel->text().toInt(&ok) + 1)); // for test
        if (channelLcd->value() < 9) {
            channelLcd->display(channelLcd->value() + 1);
        }
    };
    void channelDown() {
        if (channelLcd->value() > 0) {
            channelLcd->display(channelLcd->value() - 1);
        }
    };
    void volumeUp() {volumeProgress->setValue(volumeProgress->value() + 10);};
    void volumeDown() {volumeProgress->setValue(volumeProgress->value() - 10);};

};
#endif //INC_37_3_TV_REMOTE_CONTROL_REMOTECONTROLMAINWINDOW_H