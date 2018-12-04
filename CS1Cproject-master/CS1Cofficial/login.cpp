#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

logIn::logIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logIn)
{
    ui->setupUi(this);
}

logIn::~logIn()
{
    delete ui;
}

void logIn::on_pushButton_clicked()
{
    QString username = ui->userName_le->text();
           QString password = ui->password_le->text();

           if(username == "admin" && password == "test")
           {
           QMessageBox::information(this, "Login", "Username and passoword are correct");

           access = true;
           this->close();
           }
           else
              {
           QMessageBox::information(this, "Login", "Username and passoword are NOT correct");
           access = false;
           }
}
