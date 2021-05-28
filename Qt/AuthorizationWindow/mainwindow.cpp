#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resource/img/age3ymcLogo.bmp");
    QPixmap pix2(":/resource/img/age3ymcLogo.bmp");
    ui->images->setPixmap(pix);
    int w = ui->images_2->width();
    int h = ui->images_2->height();
    ui->images_2->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
    //ui->images_2->setPixmap(pix2.scaled(200,200,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();
    if (login == "root" && password == "1234") {
        ui->statusbar->showMessage("Вы успешно авторизовались!");
        QMessageBox::information(this, "Ура", "Вы успешно авторизовались!");
    } else {
        ui->statusbar->showMessage("Не верный логин или пароль!");
        QMessageBox::warning(this, "Ошибка!", "Не верный логин или пароль!");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (ui->checkBox->isChecked()) {
        ui->statusbar->showMessage("Галочка поставлена!");
    } else {
        ui->statusbar->showMessage("Галочка не поставлена!");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked()) {
        ui->statusbar->showMessage("Галочка поставлена!");
    } else {
        ui->statusbar->showMessage("Галочка не поставлена!");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QString str = "";
    if (ui->radioButton->isChecked()) {
        str += "Выбрано 1.1! ";
    }
    if (ui->radioButton_2->isChecked()) {
        str += "Выбрано 1.2! ";
    }
    if (ui->radioButton_3->isChecked()) {
        str += "Выбрано 2.1! ";
    }
    if (ui->radioButton_4->isChecked()) {
        str += "Выбрано 2.2! ";
    }
    ui->statusbar->showMessage(str);
}
