#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
    {
        //QRegularExpression exp("\\d+"); // 55
        //QRegularExpression exp("\\d\\d \\w+"); // 55 tygfh
        //QRegularExpression exp("^(\\d\\d)\\.(\\d\\d)\\.(\\d\\d\\d\\d)$"); // 22.12.1986
        //QRegularExpression exp(R"(^\d\d:\d\d$")"); // 22:12 don't work "R"
        QRegularExpression exp("^(.+)@(.+)$"); // wew@wee
        // ^ начало строки
        // $ конец строки

        if (exp.match(currentText).hasMatch())
        {
            SetOkLabel();
        }
        else
        {
            SetNonOkLabel();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetOkLabel()
{
    ui->label->setText("OK");
    ui->label->setStyleSheet("QLabel {color: green;}");
}

void MainWindow::SetNonOkLabel()
{
    ui->label->setText("Fail");
    ui->label->setStyleSheet("QLabel {color: red;}");

}

