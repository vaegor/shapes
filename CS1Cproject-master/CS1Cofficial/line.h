#ifndef LINE_H
#define LINE_H

#include <string>
#include <QPen>
#include <QFont>
#include <QPainter>
#include <QPoint>
#include "shape.h"
#include <QPainter>
#include "drawwt.h"


class Line : public Shape
{
private:
    int x1;
    int y1;
    int x2;
    int y2;
public:
 Line() : Shape()
 {
     x1 = 10;
     y1 = 50;
     x2 = 50;
     y2 = 300;
 }

Line(int a1, int b1, int a2, int b2)
{
    x1 = a1;
    y1 = b1;
    x2 = a2;
    y2 = b2;
}

void setCord(int a1, int b1, int a2, int b2)
{
    x1 = a1;
    y1 = b1;
    x2 = a2;
    y2 = b2;
}

Line(const Line & other) : Shape()
{
    this->x1 = other.x1;
    this->y1 = other.y1;
    this->x2 = other.x2;
    this->y2 = other.y2;
}
 void draw(QPainter &p)
 {
    // painter(e);

     p.setPen(getPen());
     p.drawLine(x1,y1,x2,y2);



 }

 void move()
 {

 }

 void perimeter()
 {

 }

 void area()
 {

 }

void getData()
{

}

};

#endif // LINE_H
