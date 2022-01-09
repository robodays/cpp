#include <QApplication>
#include <QPushButton>
//#include <QtGui/QtGui>
//#include <QtWebEngineWidgets/QWebEngineView>
//#include <QtWebEngineWidgets/>

#include <QWebEngineView>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *webView = new QWebEngineView;
    //webView->setHtml("");
    webView->setHtml("<h1>Hello</h1>");
    //webView->setUrl(QUrl("http://skillbox.ru"));

    webView->show();

/*    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();*/
    return a.exec();
}
