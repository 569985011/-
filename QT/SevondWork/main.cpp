#include "mainwindow.h"
#include <QApplication>
#include<QWidget>
#include<QSpinBox>
#include<QString>
#include<QSlider>
#include<QHBoxLayout>
#include <QAction>
#include<QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Enter your age");
    {   if(QMessageBox::Yes==QMessageBox::question(&window,QObject::tr("Question"),
                                                   QObject::tr("Are you sure?"),
                                                   QMessageBox::Yes|QMessageBox::Retry,
                                                   QMessageBox::Retry)){
            QMessageBox::information(&window,QObject::tr("Hmmm..."),QObject::tr("I'm glad to hear that!"));
        }else{
            QMessageBox::information(&window,QObject::tr("Hmmm..."),QObject::tr("I'm sorry."));
        }

    }

    QSpinBox *spinBox = new QSpinBox(&window);
    QSlider *slider = new QSlider(Qt::Horizontal, &window);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
    spinBox->setValue(35);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(spinBox);
    window.setLayout(layout);

    window.show();

    return app.exec();
}
