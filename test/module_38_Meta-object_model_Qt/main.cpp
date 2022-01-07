#include <QApplication>
#include <QPushButton>
#include <QObject>
#include <iostream>

class MyClass : public QObject
{
    Q_OBJECT
    int mAge;
public:
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged);
    void setAge(int nAge) {mAge = nAge;}
    int age() {return mAge;}

signals:
    void ageChanged(int);
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MyClass hero;

    hero.setAge(30);
    std::cout << "Age: " << hero.age() << std::endl;

    hero.setProperty("Height", 180);
    std::cout << "Height: " << hero.property("Height").toUInt() << std::endl;

    return QApplication::exec();
}

#include <main.moc>