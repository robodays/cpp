#include <QApplication>
#include "ui_remote_control.h"
#include "remotecontrolmainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RemoteControlMainWindow window(nullptr);
    Ui::MainWindow remoteControl;
    remoteControl.setupUi(&window);
    window.channelLcd = remoteControl.channelLcd;
    //window.channelNowLabel = remoteControl.channelNowLabel; // for test
    window.volumeProgress = remoteControl.volumeProgress;
    window.resize(200, 100);
    window.show();
    return QApplication::exec();
}
