#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "login.h"
#include <QPainter>
#include <shape.h>
#include "ellipse.h"
#include "rectangle.h"

#include <QtWidgets>
#include "drawwt.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    logIn *l = new logIn();
    l->show();
    */
}

MainWindow::~MainWindow()
{
    delete ui;
    delete currentShape;
}

void MainWindow::on_contactUs_btn_clicked()
{
    contact *c = new contact();
    c->show();
}

void MainWindow::on_draw_btn_clicked()
{
    shapeV.parser();
    shapeV.parser();

    /*
     *Main window can hold our vector, we can then pass to current shape pointer the shape we want to display.
     *
     */
    //test for line.
    //currentShape = new Line;
    //test for ellipse.        getline(shapesFile, data, ' ');
    //currentShape = new Ellipse;
    //test for rectangle
    //currentShape = new Rectangle;
    currentShape = shapeV.getShapeV(0);

    drawWt * draw = new drawWt;
    draw->setShape(currentShape);
    draw->show();

}
