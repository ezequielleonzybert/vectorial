#include "path.h"
#include <QDebug>

Path::Path() {
    linePen.setWidthF(1);
    linePen.setColor(Qt::black);
    nodePen.setWidthF(1);
    nodePen.setColor(Qt::blue);
    nodeBrush = QBrush(Qt::white);
}

void Path::render(QPainter *painter)
{
    painter->setPen(linePen);
    for(int i = 0; i < size()-1; i++){
        painter->drawLine(point(i), point(i+1));
    }

    painter->setPen(nodePen);
    painter->setBrush(nodeBrush);
    for(const QPoint &p : *this){
        painter->drawEllipse(p, 3, 3);
    }
}
