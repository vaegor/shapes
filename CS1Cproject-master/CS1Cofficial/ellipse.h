
#ifndef ELLIPSE_H
#define ELLIPSE_H
#define PI 3.14159

#include <string>
#include <math.h>
#include <QPen>
#include <QFont>
#include <QPainter>
#include "shape.h"
using std::string;
//ellipse
//ellispe
class Ellipse : public Shape
{
private:
    int x1;
    int y1; //(x1,y1) top left point
    int a; //semi-major axis
    int b; //semi-minor axis
public:
    Ellipse(): Shape()
    {
      a = 0;
      b = 0;
    }
    
    Ellipse(int a1, int b1): Shape()
    {
      a = a1;
      b = b1;
    }

    Ellipse(const Ellipse & other): Shape()
    {
      this->a = other.a;
      this->b = other.b;
    }
    
    void draw(QPainter &p)
    {
        x1 = 10;
        y1 = 1000;
        a = 500;
        b = 800;
        p.setPen(getPen());

        p.drawEllipse( QRect( 110, 10, 80, 80 ) );
    }

    void move()
    {

    }

    void perimeter()
    {
      double p=0,h=0;
      double base1 = (a-b), base2 = (a+b), power = 2;
      h = pow(base1, power)/pow(base2, power);
      double square = sqrt(4-3*h);
      p = PI*base2*(1+3*h/10+square);
    //cout no allowed in qt
      //cout << "The perimeter is: " << p << endl;


    }

    void area()
    {
      double area = 0;
      area = PI * a * b;
     // cout << "The area is: " << area << endl;

    }
    void getData()
    {
     // cout << "What is the semi-major axis? ";
        //no cin in qt creates
      //cin >> a;
      //cout << "What is the semi-minor axis? ";
     // cin >> b;
    }
};



#endif // ELLIPSE_H
