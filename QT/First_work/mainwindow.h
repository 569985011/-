#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QTimer>
#include <QMainWindow>
#include"cxtime.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 CXTime Num;
private slots:

private:
    Ui::MainWindow *ui;
//    QTimer timer;

};

#endif // MAINWINDOW_H
