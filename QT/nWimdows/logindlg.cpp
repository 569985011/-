#include "logindlg.h"
#include "ui_logindlg.h"
#include<QObject>
#include<QMessageBox>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);

}

LoginDlg::~LoginDlg()
{
    delete ui;
}


void LoginDlg::on_loginButton_clicked()
{
    if(ui->userLineEdit->text()==tr("Administrator").trimmed()//trimmed忽略字符串收尾空白符
            &&ui->pwdLineEdit->text()==tr("0").trimmed()){
        QMessageBox::warning(this,tr("Welcome!"),tr("长江长江，我是黄河~"),QMessageBox::NoButton);
        this->accept();
    }else{
        QMessageBox::warning(this,tr("Waring!"),
                             tr("user name or password error!\n"),QMessageBox::Yes);
        ui->userLineEdit->setText(tr("Administrator"));
        ui->pwdLineEdit->setText(tr("0"));

        ui->userLineEdit->setFocus();//获得焦点
    }

    printf("验证密码!\n") ;
}
