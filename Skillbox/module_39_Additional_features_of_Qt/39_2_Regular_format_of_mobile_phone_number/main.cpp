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
    window->setWindowTitle("Mobile phone number input format");
    auto *vBoxLayout = new QVBoxLayout();

    auto *textLabel = new QLabel;
    auto *lineEdit = new QLineEdit;
    lineEdit->resize(window->width(), 30);
    auto *resultLabel = new QLabel;

    vBoxLayout->addWidget(textLabel);
    vBoxLayout->addWidget(lineEdit);
    vBoxLayout->addWidget(resultLabel);

    textLabel->setText("Enter the data according to the template: +789012345678");

    QObject::connect(lineEdit, &QLineEdit::textEdited, [lineEdit, resultLabel]()
    {
        QRegularExpression exp("^\\+[0-9]{11}$");

        if (exp.match(lineEdit->text()).hasMatch()) {
            resultLabel->setText("Has Match: OK");
            resultLabel->setStyleSheet("QLabel { background-color : green; color : white; }");
        } else {
            resultLabel->setText("Has Match: NO");
            resultLabel->setStyleSheet("QLabel { background-color : red; color : white; }");
        }
    });

    window->setLayout(vBoxLayout);

    window->show();
    return QApplication::exec();
}
