#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    ui->pushButtonAddition->setCheckable(true);
    ui->pushButtonSubtraction->setCheckable(true);
    ui->pushButtonMultiplying->setCheckable(true);
    ui->pushButtonDivision->setCheckable(true);
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

    if (ui->result->text().contains(".") && button->text() == "0") {
        new_string = ui->result->text() + button->text();
    } else {
        all_numbers = (ui->result->text() + button->text()).toDouble();
        new_string = QString::number(all_numbers,'g',11);
    }
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
    ui->pushButtonAddition->setChecked(false);
    ui->pushButtonSubtraction->setChecked(false);
    ui->pushButtonMultiplying->setChecked(false);
    ui->pushButtonDivision->setChecked(false);
    ui->result->setText("0");
}

void MainWindow::on_pushButtonEqual_clicked()
{
    double equal, numSecond;

    numSecond = ui->result->text().toDouble();

    if(ui->pushButtonAddition->isChecked()) {
        equal = numFirst + numSecond;

        ui->pushButtonAddition->setChecked(false);
        ui->result->setText(QString::number(equal,'g',11));
    } else if(ui->pushButtonSubtraction->isChecked()) {
        equal = numFirst - numSecond;

        ui->pushButtonSubtraction->setChecked(false);
        ui->result->setText(QString::number(equal,'g',11));
    } else if(ui->pushButtonDivision->isChecked()) {
        if (numSecond == 0) {
            ui->result->setText("Err: division by zero");
        } else {
            equal = numFirst / numSecond;

            ui->pushButtonDivision->setChecked(false);
            ui->result->setText(QString::number(equal,'g',11));
        }
    } else {
        equal = numFirst * numSecond;

        ui->pushButtonMultiplying->setChecked(false);
        ui->result->setText(QString::number(equal,'g',11));
    }

}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    numFirst = ui->result->text().toDouble();

    ui->result->setText("0");

    button->setCheckable(true);


}
