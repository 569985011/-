/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QPushButton *loginButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *exitButton;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->setEnabled(true);
        LoginDlg->resize(265, 215);
        loginButton = new QPushButton(LoginDlg);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(10, 130, 101, 41));
        label = new QLabel(LoginDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 54, 12));
        label_2 = new QLabel(LoginDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 54, 12));
        userLineEdit = new QLineEdit(LoginDlg);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        userLineEdit->setGeometry(QRect(70, 40, 113, 20));
        pwdLineEdit = new QLineEdit(LoginDlg);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(70, 80, 113, 20));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        exitButton = new QPushButton(LoginDlg);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(130, 130, 101, 41));
        QWidget::setTabOrder(loginButton, exitButton);
        QWidget::setTabOrder(exitButton, pwdLineEdit);
        QWidget::setTabOrder(pwdLineEdit, userLineEdit);

        retranslateUi(LoginDlg);
        QObject::connect(exitButton, SIGNAL(clicked()), LoginDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "Dialog", 0));
        loginButton->setText(QApplication::translate("LoginDlg", "Log in", 0));
        loginButton->setShortcut(QApplication::translate("LoginDlg", "Space", 0));
        label->setText(QApplication::translate("LoginDlg", "\350\264\246\345\217\267", 0));
        label_2->setText(QApplication::translate("LoginDlg", "\345\257\206\347\240\201", 0));
        exitButton->setText(QApplication::translate("LoginDlg", "Exit", 0));
        exitButton->setShortcut(QApplication::translate("LoginDlg", "Space", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
