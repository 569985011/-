#include<QtGui>
#include<QTextCodec>
#include "mainwindow.h"
#include <QApplication>
#include"logindlg.h"

#include <stdio.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
     MainWindow w;
     LoginDlg dlg;
    if(dlg.exec()==LoginDlg::Accepted){//利用accepted返回值判断按钮是否被按下
        printf("Login\n");
        w.show();
        return a.exec();
    }else return 0;

}
