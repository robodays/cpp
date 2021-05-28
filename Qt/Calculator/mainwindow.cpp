#include "mainwindow.h"
#include "ui_mainwindow.h"

double numFirst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonNum0,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum1,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum2,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum3,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum4,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum5,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum6,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum7,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum8,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonNum9,SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButtonAddSub,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButtonPercent,SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButtonAddition,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButtonSubtraction,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButtonMultiplying,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButtonDivision,SIGNAL(clicked()), this, SLOT(math_operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_string;

    all_numbers = (ui->result->text() + button->text()).toDouble();
    new_string = QString::number(all_numbers,'g',11);

    ui->result->setText(new_string);
}


void MainWindow::on_pushButtonPoint_clicked()
{
    if(!(ui->result->text().contains("."))){
        ui->result->setText(ui->result->text() + ".");
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_string;

    if (button->text() == "+/-"){
        all_numbers = ui->result->text().toDouble() * -1;
        new_string = QString::number(all_numbers,'g',11);
        ui->result->setText(new_string);
    } else if (button->text() == "%"){
        all_numbers = ui->result->text().toDouble() * 0.01;
        new_string = QString::number(all_numbers,'g',11);
        ui->result->setText(new_string);
    }
}


void MainWindow::on_pushButtonReset_clicked()
{
    ui->result->setText("0");
}

void MainWindow::on_pushButtonEqual_clicked()
{

}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    if (numFirst == 0) {
        numFirst = ui->result->text().toDouble();
    } else {
        double numSecond = ui->result->text().toDouble();

        //QString new_string;

        if (button->text() == "+"){

        } else if (button->text() == "-"){

        }

        //all_numbers = ui->result->text().toDouble() * 0.01;
        //new_string = QString::number(all_numbers,'g',11);
        //ui->result->setText(new_string);


    }
}
