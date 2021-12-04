#include <QApplication>
#include <QPixmap>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextBlock>
#include <QLCDNumber>
#include <QSpinBox>
//#include <QPushButton>

class ImageLabel : public  QLabel {
    //Q_OBJECT // необходимость в наследовании класса QObject no work
public:
    ImageLabel() = default;
    ImageLabel(QWidget *parent);  // встраивает в родительский виджет
    //void setPixmap(const QPixmap &);
    //void paintEvent(QPaintEvent *e) override; // перегружаем метод обработки события рисования
    //QSize sizeHint() const override; // размер кнопки
    //QSize minimumSizeHint() const override; // минимальный размер
    //void keyPressEvent(QKeyEvent *e) override; // обработка нажатия
    public slots:
    void setRed();
    void setGreen();
    void setYellow();


private:
    QPixmap mCurrentCircle;
    QPixmap mRedCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
};

ImageLabel::ImageLabel(QWidget *parent) {
    setParent(parent); // метод родительского класса, туда передаем родителя
    //setToolTip("Стоп"); // подсказка при наведении мышки на кнопку
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // устанавливаем фиксированный размер виджета
    mRedCircle = QPixmap("img/red_git.png"); // устанавливаем путь к файлу
    mGreenCircle = QPixmap("img/green_git.png");
    mYellowCircle = QPixmap("img/yellow_git.png");
    mCurrentCircle = mGreenCircle;
    setPixmap(mCurrentCircle);
    setGeometry(mCurrentCircle.rect()); // устанавливаем геометрию кнопки по размеру картинки
    //connect(this, &QPushButton::clicked, this, &ImageButton::setDown); // обработка слота
}


/*!
    \property QLabel::pixmap
    \brief the label's pixmap.

    Setting the pixmap clears any previous content. The buddy
    shortcut, if any, is disabled.
*/
/*
void QLabel::setPixmap(const QPixmap &pixmap)
{
    Q_D(QLabel);
    if (!d->pixmap || d->pixmap->cacheKey() != pixmap.cacheKey()) {
        d->clearContents();
        d->pixmap = new QPixmap(pixmap);
    }

    if (d->pixmap->depth() == 1 && !d->pixmap->mask())
        d->pixmap->setMask(*((QBitmap *)d->pixmap));

    d->updateLabel();
}
*/


/*
void ImageButton::paintEvent(QPaintEvent *e) { // рисуем картинку
    QPainter p(this); // на чем рисуем картинку
    p.drawPixmap(e->rect(), mCurrentButtonPixmap); // рисуем картинку
}

QSize ImageButton::sizeHint() const { // указываем размер виджета
    return QSize(100,100);
}

QSize ImageButton::minimumSizeHint() const { // указываем минимальный размер виджета
    return sizeHint();
}
*/



void ImageLabel::setRed() {
    mCurrentCircle = mRedCircle;
    setPixmap(mCurrentCircle);
    update();
}

void ImageLabel::setGreen() {
    mCurrentCircle = mGreenCircle;
    setPixmap(mCurrentCircle);
    update();
}

void ImageLabel::setYellow() {
    mCurrentCircle = mYellowCircle;
    setPixmap(mCurrentCircle);
    update();
}




int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto *window = new QWidget;

    ImageLabel *imageLabel = new ImageLabel(nullptr);

    auto *slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);

    auto *layout = new QVBoxLayout(window);

    layout->addWidget(imageLabel);
    layout->addWidget(slider);
    //layout->addWidget(spinBox);

    QObject::connect(slider, &QSlider::valueChanged, imageLabel, &ImageLabel::setYellow);
/*
    auto *redCircle = new QPixmap("img/red_git.png");
    auto *greenCircle = new QPixmap("img/green_git.png");
    auto *yellowCircle = new QPixmap("img/yellow_git.png");

    //auto *nowCircle = greenCircle;
    QLabel *label = new QLabel();
    label->setPixmap(*greenCircle);

    auto *slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);

    auto *text = new QLabel();
    text->setText("0");

    auto *lcd = new QLCDNumber;
    lcd->display(0);

    auto *spinBox = new QSpinBox();
    spinBox->setValue(0);
    spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

    auto *layout = new QVBoxLayout(window);

    layout->addWidget(label);
    layout->addWidget(slider);
    layout->addWidget(spinBox);
*/
    //layout->addWidget(text);
    //layout->addWidget(lcd);

    //QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
/*    QObject::connect(&slider, &QSlider::valueChanged, [&slider, &label, yellowCircle](int newValue)
    { //Тут проверка диапазона и установка цвета круга
        if (newValue > 33) label->setPixmap(*yellowCircle);
        });*/


    //QObject::connect(slider, &QSlider::valueChanged, lcd, &QLCDNumber::display);
    //QObject::connect(slider, QOverload<QString>::of(&QSlider::valueChanged), text, QOverload<QString>::of(&QLabel::setText));

/*
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
*/
    window->resize(200,250);
    window->move(500,250);
    window->show();
    return QApplication::exec();
}


/*
 Задача
Цель задания
 Повторить работу с виджетами, которые были изучены в модуле.

(Отработать применение виджетов, которые были изучены в модуле.)



Что нужно сделать
Давайте соберём все знания, полученные в данном модуле в одной программе. Для этого создадим приложение, которое
 содержит в окне круг, меняющий свой цвет в зависимости от положения ползунка. Если ползунок установлен в положение
 0—33,  то круг имеет зелёный цвет, если 33—66 — жёлтый, далее красный. Такое приложение показано на следующем снимке:





Виджет, который рисует круг, можно сделать наследником QWidget. Теперь не надо переопределять keyPressEvent, как мы это
 сделали для кнопки во время урока. Мы лишь хотим рисовать виджет особым образом, реагировать на нажатия он не будет.
Нам потребуется три png-файла, которые соответствуют трём кружкам разных цветов (можете самостоятельно нарисовать их в
 Paint или взять готовые в материалах к уроку).
Чтобы расположить вертикально круг и ползунок (QSlider), нам потребуется добавить эти два виджета в QVBoxLayout (оба
 виджета расположены в каком-либо родительском QWidget, как было в примере с менеджерами компоновки).
Рекомендуем сделать для окна setFixedSize (200, 250), чтобы круг оставался кругом.
Метод minimumSizeHint может возвращать QSize(100, 100), а вот метод sizeHint можно не переопределять.
Удобно будет иметь три метода для смены цвета. Они будут напоминать методы опускания/поднятия кнопки из примера с
 красной кнопкой. Один из них может выглядеть так:
void ColorfulCircle::setYellow() {
   mCurrentCircle = mYellowCircle;
   update();
}
Чтобы связать изменения значений слайдера с цветом круга, можно написать небольшую лямбда-функцию. Она будет проверять
 диапазон, в который попадает новое значение, и устанавливать соответствующий ему цвет, меняя картинку на одну из трёх.
 Пример такого связывания и заголовок функции могут выглядеть так:
QObject::connect(&slider, &QSlider::valueChanged, [&slider, &circle](int newValue)
{ //Тут проверка диапазона и установка цвета круга });
Где circle — это ваш виджет. Обратите внимание, что мы захватываем адреса ползунка и круга. Так же мы обрабатываем
 новое значение от ползунка, указав в аргументах функции int newValue. Это значение мы будем проверять на попадание в
 диапазон при помощи if/else.



Критерии оценки
Приложение отображает одно окно, в котором есть цветной круг и ползунок.
При перемещении ползунка цвет круга меняется: первая треть диапазона ползунка — зелёный цвет круга, вторая — жёлтый,
 третья — красный.
На проверку необходимо отправить один .cpp-файл и один CMakeLists.txt-файл. За основу желательно взять проект с кнопкой,
 который был разобран в модуле.
 */