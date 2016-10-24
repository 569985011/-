/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBy_QQ;
    QAction *actionBy_Gmail;
    QAction *actionBy_Facebook;
    QAction *actionVisit_Blog;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionBy_QQ = new QAction(MainWindow);
        actionBy_QQ->setObjectName(QStringLiteral("actionBy_QQ"));
        actionBy_QQ->setCheckable(false);
        actionBy_QQ->setEnabled(true);
        actionBy_Gmail = new QAction(MainWindow);
        actionBy_Gmail->setObjectName(QStringLiteral("actionBy_Gmail"));
        actionBy_Gmail->setEnabled(true);
        actionBy_Facebook = new QAction(MainWindow);
        actionBy_Facebook->setObjectName(QStringLiteral("actionBy_Facebook"));
        actionBy_Facebook->setEnabled(true);
        actionVisit_Blog = new QAction(MainWindow);
        actionVisit_Blog->setObjectName(QStringLiteral("actionVisit_Blog"));
        actionVisit_Blog->setEnabled(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionBy_QQ);
        menu->addAction(actionBy_Gmail);
        menu->addAction(actionBy_Facebook);
        menu->addAction(actionVisit_Blog);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionBy_QQ->setText(QApplication::translate("MainWindow", "By QQmail", 0));
        actionBy_Gmail->setText(QApplication::translate("MainWindow", "By Gmail", 0));
        actionBy_Facebook->setText(QApplication::translate("MainWindow", "By Facebook", 0));
        actionVisit_Blog->setText(QApplication::translate("MainWindow", "Visit Blog", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\350\201\224\347\263\273\344\275\234\350\200\205", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
