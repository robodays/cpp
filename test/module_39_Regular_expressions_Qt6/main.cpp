#include <QApplication>
#include <QPushButton>

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

#include <QRegularExpression>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *window = new QWidget;
    window->resize(400, 100);

    auto *vBoxLayout = new QVBoxLayout();

    auto *label = new QLabel;
    auto *lineEdit = new QLineEdit;
    lineEdit->resize(window->width(), 30);
    auto *label2 = new QLabel;


    vBoxLayout->addWidget(label);
    vBoxLayout->addWidget(lineEdit);
    vBoxLayout->addWidget(label2);

    QString pattern = "^(.+)@(.+)$";

    label->setText("Enter the data according to the template: " + pattern);

    QObject::connect(lineEdit, &QLineEdit::textEdited, [lineEdit, pattern, label2]()
    {
        QRegularExpression exp(pattern);

        if (exp.match(lineEdit->text()).hasMatch()) {
            label2->setText("Has Match: OK");
            label2->setStyleSheet("QLabel { background-color : green; color : white; }");
        } else {
            label2->setText("Has Match: NO");
            label2->setStyleSheet("QLabel { background-color : red; color : white; }");
        }
    });

    window->setLayout(vBoxLayout);

    window->show();
    return QApplication::exec();
}
