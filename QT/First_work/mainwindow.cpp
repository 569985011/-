#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QObject>
#include<QLCDNumber>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
