#include "path.h"
#include <QDebug>

Path::Path() : QPolygon() {
    pen.setWidthF(1);
    pen.setColor(Qt::black);
}

void Path::render(QPainter *painter, QString activeTool, QPoint mousePosition)
{
    for(int i = 0; i < size()-1; i++){
        painter->drawLine(point(i), point(i+1));
        qDebug() << this->point(i);
    }
}
