#include "contact.h"
#include "ui_contact.h"
#include <QPixmap>

contact::contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contact)
{
    ui->setupUi(this);
    QPixmap pix("/home/cs1c/Documents/CS1Cproject-master/CS1Cofficial/logo.png");
    ui->logo_pic->setPixmap(pix);
}

contact::~contact()
{
    delete ui;
}
