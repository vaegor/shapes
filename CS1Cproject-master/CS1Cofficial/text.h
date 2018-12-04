#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <QPen>
#include <QFont>
#include <QPainter>
#include "shape.h"
using namespace std;

class Text : public Shape
{
private:
    int x1;
    int y1; //(x1,y1) top left point
    int l; //length
    int w; //width
    //dimensions for a textbox-rectangle
public:
    void draw()
    {
        //painter.drawText()
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
};


#endif // TEXT_H
