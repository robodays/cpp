//#include "mainwindow.h"
//#include <QMainWindow>
#include <QtGui/QtGui>
#include <QApplication>

#include <QWebEngineView>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>

class BrowserTabWidget : public QWidget
{
    Q_OBJECT
signals:
    void tabLoadingFinished(QString tabTitle);
};

BrowserTabWidget* createNewBrowserWindow()
{
    auto *browserWindow = new BrowserTabWidget;
    auto *urlLineEdit = new QLineEdit;
    auto *webView = new QWebEngineView;
    auto *vBox = new QVBoxLayout(browserWindow);
    //webView->setHtml("<H1>Hello World</H1>");
    //webView->setUrl(QUrl("http://skillbox.ru"));

    vBox->addWidget(urlLineEdit);
    vBox->addWidget(webView);

    // загружаем сайт из LineEdit по нажатию Enter
    QObject::connect(urlLineEdit, &QLineEdit::returnPressed, [webView, urlLineEdit]()
    {
        auto urlToOpen = urlLineEdit->text();
        webView->load(urlToOpen);
    });
    // захватываем название сайта после полной загрузки
    QObject::connect(webView, &QWebEngineView::loadFinished, [webView, browserWindow](bool ok)
    {
        if (ok)
        {
            emit browserWindow->tabLoadingFinished(webView->title());
        }
    });

    return browserWindow;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTabWidget tabs;

    //tabs.addTab(createNewBrowserWindow(),"Tab1");
    //tabs.addTab(createNewBrowserWindow(), "Tab2");

    QPushButton newTabButton("+");
    tabs.setTabsClosable(true);
    tabs.setCornerWidget(&newTabButton, Qt::BottomLeftCorner);

    // добавляем вкладки по плюсику
    QObject::connect(&newTabButton, &QPushButton::clicked, [&tabs]()
    {
        auto newTab = createNewBrowserWindow();

        // устанавливаем имя вкладки по названию сайта
        QObject::connect(newTab, &BrowserTabWidget::tabLoadingFinished, [&tabs](QString newTitle)
        {
            tabs.setTabText(tabs.currentIndex(), newTitle);
            tabs.setWindowTitle(newTitle);
        });

        tabs.addTab(newTab, "tab " + QString::number(tabs.count() + 1)); // устанавливаем имя вкладки
    });

    newTabButton.click();

    // закрытие вкладки по нажатию крестика
    QObject::connect(&tabs, &QTabWidget::tabCloseRequested, [&tabs](int indexToRemove)
    {
        if (tabs.count() > 1)
        {
            auto widgetToDelete = tabs.widget(indexToRemove);
            delete widgetToDelete;
        }
    });

    // устанавливаем имя окна по имени вкладки
    QObject::connect(&tabs, &QTabWidget::currentChanged, [&tabs](int currentIndex)
    {
        tabs.setWindowTitle(tabs.tabText(currentIndex));
    });

    tabs.show();
    return a.exec();
}

#include <main.moc>
