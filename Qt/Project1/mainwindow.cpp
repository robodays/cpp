#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Вы нажали на Ok");
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::aboutQt(this,"Заголовок");
    QMessageBox::about(this,"Заголовок", "Текстовый блок");
    QMessageBox::critical(this,"Заголовок", "Текстовый блок");
    QMessageBox::warning(this,"Заголовок", "Текстовый блок");
    QMessageBox::question(this,"Заголовок", "Текстовый блок");
    QMessageBox::StandardButton answer = QMessageBox::question(this,"Заголовок", "Текстовый блок", QMessageBox::No | QMessageBox::Yes);
    if (answer == QMessageBox::Yes) {
        QApplication::quit(); // Закрытие окна
    } else {
        qDebug() << "Кнопка NO была нажата!"; // вывод в консоль
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    secondwindow window;
    window.setModal(true);
    window.exec();
}
