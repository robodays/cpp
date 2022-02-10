#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double numFirst;

private slots:
    void digits_numbers();
    void on_pushButtonPoint_clicked();
    void operations();
    void on_pushButtonReset_clicked();
    void on_pushButtonEqual_clicked();
    void math_operations();
};
#endif // MAINWINDOW_H
