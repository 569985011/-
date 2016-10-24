#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include<QDebug>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon("://doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);



    closeAction = new QAction(QIcon("://doc-open"), tr("&Close..."), this);
    closeAction->setShortcuts(QKeySequence::Close);
    closeAction->setStatusTip(tr("Close the file"));

    connect(closeAction, &QAction::triggered, this,&MainWindow::close);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(closeAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(closeAction);


    statusBar() ;
}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
    QDialog dialog(this);
    dialog.setWindowTitle(tr("Hello,dialog!"));
    dialog.exec();
    qDebug()<<dialog.result();
}
