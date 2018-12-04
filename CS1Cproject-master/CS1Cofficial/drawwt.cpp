#include "drawwt.h"
#include <QPainter>
#include "line.h"

using namespace std;
drawWt::drawWt(QWidget *parent) : QWidget(parent)
{
}

void drawWt::paintEvent(QPaintEvent * /* event */)
{
    QPainter p(this);

    shape->draw(p);
}

void drawWt::setShape(Shape * currentShape)
{
    shape = currentShape;
}
