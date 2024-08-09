#include "path.h"
#include <QDebug>

Path::Path() {
    linePen.setWidthF(1);
    linePen.setColor(Qt::black);
    nodePen.setWidthF(1);
    nodePen.setColor(Qt::blue);
    nodeBrush = QBrush(Qt::white);
}

void Path::render(QPainter *painter, QString activeTool, QPoint mousePosition)
{
    painter->setPen(linePen);
    for(int i = 0; i < size()-1; i++){
        painter->drawLine(point(i), point(i+1));
    }
    painter->setPen(nodePen);
    painter->setBrush(nodeBrush);
    for(QPoint &p : *this){
        painter->drawEllipse(p, 3, 3);
    }
    if(activeTool == "selectTool"){
        for(QPoint &p : *this){
            float distance =
                abs(p.x() - mousePosition.x()) +
                abs(p.y() - mousePosition.y());
            if(abs(distance) < 10){
                painter->setPen(nodePen);
                painter->setBrush(nodeBrush);
                painter->drawEllipse(p, 4, 4);
            }
        }
    }
}
