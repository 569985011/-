#include<QtGui/QApplicationStateChangeEvent>
#include<QApplication>
#include"mainwindow.h"
#include<QString>
#include<QTextCodec>
#include<QSpinBox>
#include<QSlider>

#include<QHBoxLayout>
#include<QStackedLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    w.show();

    return app.exec();
}
