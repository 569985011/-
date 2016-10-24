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
    QAction *actionMore;
    QAction *actionBy_E_mail;
    QAction *actionBy_Facebook;
    QAction *action2_3;
    QAction *action1_3;
    QAction *action_2;
    QAction *action3_3;
    QAction *action2_4;
    QAction *actionDaochu;
    QAction *actionTXT;
    QAction *actionXML;
    QAction *actionEXCEL;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu1;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(455, 322);
        actionMore = new QAction(MainWindow);
        actionMore->setObjectName(QStringLiteral("actionMore"));
        actionBy_E_mail = new QAction(MainWindow);
        actionBy_E_mail->setObjectName(QStringLiteral("actionBy_E_mail"));
        actionBy_Facebook = new QAction(MainWindow);
        actionBy_Facebook->setObjectName(QStringLiteral("actionBy_Facebook"));
        action2_3 = new QAction(MainWindow);
        action2_3->setObjectName(QStringLiteral("action2_3"));
        action1_3 = new QAction(MainWindow);
        action1_3->setObjectName(QStringLiteral("action1_3"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action3_3 = new QAction(MainWindow);
        action3_3->setObjectName(QStringLiteral("action3_3"));
        action2_4 = new QAction(MainWindow);
        action2_4->setObjectName(QStringLiteral("action2_4"));
        actionDaochu = new QAction(MainWindow);
        actionDaochu->setObjectName(QStringLiteral("actionDaochu"));
        actionTXT = new QAction(MainWindow);
        actionTXT->setObjectName(QStringLiteral("actionTXT"));
        actionXML = new QAction(MainWindow);
        actionXML->setObjectName(QStringLiteral("actionXML"));
        actionEXCEL = new QAction(MainWindow);
        actionEXCEL->setObjectName(QStringLiteral("actionEXCEL"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 455, 23));
        menu1 = new QMenu(menuBar);
        menu1->setObjectName(QStringLiteral("menu1"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu1->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu->menuAction());
        menu1->addAction(action1_3);
        menu1->addAction(action2_3);
        menu1->addSeparator();
        menu1->addAction(action2_4);
        menu1->addAction(action3_3);
        menu1->addAction(actionMore);
        menu->addAction(action_2);
        menu->addAction(actionBy_E_mail);
        menu->addAction(actionBy_Facebook);
        menu_2->addAction(actionTXT);
        menu_2->addAction(actionXML);
        menu_2->addAction(actionEXCEL);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionMore->setText(QApplication::translate("MainWindow", "More", 0));
        actionBy_E_mail->setText(QApplication::translate("MainWindow", "By Gmail", 0));
        actionBy_Facebook->setText(QApplication::translate("MainWindow", "By Facebook", 0));
        action2_3->setText(QApplication::translate("MainWindow", "2.click \"Pause\" to mark the time", 0));
        action1_3->setText(QApplication::translate("MainWindow", "1.click \"start\" to run the clock", 0));
        action_2->setText(QApplication::translate("MainWindow", "By QQmail", 0));
        action3_3->setText(QApplication::translate("MainWindow", "3.save the List over right", 0));
        action2_4->setText(QApplication::translate("MainWindow", "2.click \"stop\" to reset the clock", 0));
        actionDaochu->setText(QApplication::translate("MainWindow", "daochu ", 0));
        actionTXT->setText(QApplication::translate("MainWindow", "TXT", 0));
        actionXML->setText(QApplication::translate("MainWindow", "XML", 0));
        actionEXCEL->setText(QApplication::translate("MainWindow", "EXCEL", 0));
        menu1->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\350\201\224\347\263\273\344\275\234\350\200\205", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\257\274\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
