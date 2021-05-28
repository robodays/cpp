#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *item1 = new QListWidgetItem(QIcon(":/img/img/auto.png"),"Audi");
    ui->listWidget->addItem(item1);
    QListWidgetItem *item2 = new QListWidgetItem(QIcon(":/img/img/auto.png"),"BMW");
    ui->listWidget->addItem(item2);
    QListWidgetItem *item3 = new QListWidgetItem(QIcon(":/img/img/auto.png"),"Volvo");
    ui->listWidget->addItem(item3);
    ui->listWidget->addItem("Ford");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    ui->statusbar->showMessage("Новый проект");
}

void MainWindow::on_action_2_triggered()
{
    ui->statusbar->showMessage("Открыть проект");
}

void MainWindow::on_action_3_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->showMessage(ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackground(Qt::blue);
    ui->listWidget->currentItem()->setForeground(Qt::white);
}
