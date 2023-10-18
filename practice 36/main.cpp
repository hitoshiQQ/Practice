#include <QPaintEvent>
#include <QApplication>
#include <QSlider>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QVBoxLayout>

class Circle : public QWidget{
private:
    QPixmap currentColorCircle;
    QPixmap greenColorCircle;
    QPixmap yellowColorCircle;
    QPixmap redColorCircle;

public:
    Circle() = default;
    explicit Circle(QWidget* parent);

    void paintEvent(QPaintEvent* event) override;
    [[nodiscard]] QSize minimumSizeHint() const override;

public slots:
    void setGreen();
    void setYellow();
    void setRed();

};

// Functions
Circle::Circle(QWidget* parent){

    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    greenColorCircle = QPixmap("F:/C++/circle_green.png");
    yellowColorCircle = QPixmap("F:/C++/circle_yellow.png");
    redColorCircle = QPixmap("F:/C++/circle_red.png");
    currentColorCircle = greenColorCircle;
    setGeometry(currentColorCircle.rect());
}

void Circle::paintEvent(QPaintEvent* event){

    QPainter p(this);
    p.drawPixmap(event->rect(),currentColorCircle);
}

QSize Circle::minimumSizeHint() const{

    return {100,100};
}

void Circle::setGreen(){

    currentColorCircle = greenColorCircle;
    update();
}

void Circle::setYellow(){

    currentColorCircle = yellowColorCircle;
    update();
}

void Circle::setRed(){

    currentColorCircle = redColorCircle;
    update();
}



int main(int argc, char *argv[]){

    QApplication app(argc,argv);

    QWidget* window = new QWidget(nullptr);
    Circle circle(window);
    circle.setFixedSize(200,200);

    QSlider* slider = new QSlider(Qt::Horizontal);
    slider->setMaximum(0);
    slider->setMaximum(100);

    QVBoxLayout* layout = new QVBoxLayout(window);
    layout->addWidget(&circle);
    layout->addWidget(slider);

    QObject::connect(slider,&QSlider::valueChanged,[&circle] (int newValue){

        if(newValue >= 0 && newValue <= 32){
            circle.setGreen();

        }  else if (newValue >= 33 && newValue <= 66){
            circle.setYellow();

        }else{
            circle.setRed();
        }

    });

    window->show();

    QApplication::exec();
}
