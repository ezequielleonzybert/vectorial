#include "path.h"
#include <QDebug>

Path::Path() {
    pen.setWidthF(1);
    pen.setColor(Qt::black);
}

void Path::update(QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin)
{
    for(Node &n : nodes){
        n.update(activeTool, mousePosition, mousePositionOrigin);
    }
}

void Path::render(QPainter *painter, QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin)
{
    for(int i = 0; i < nodes.size()-1; i++){
        painter->setPen(pen);
        painter->drawLine(nodes[i].position, nodes[i+1].position);
    }
    for(Node &n : nodes){
        n.render(painter, activeTool, mousePosition, mousePositionOrigin);
    }
}
