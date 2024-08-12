#include "node.h"
#include <QDebug>

Node::Node()
{
    pen.setWidthF(1);
    pen.setColor(Qt::blue);
    brush = QBrush(Qt::white);
}

Node::Node(int x, int y)
{
    position = QPoint(x,y);
    pen.setWidthF(1);
    pen.setColor(Qt::blue);
    brush = QBrush(Qt::white);
}

Node::Node(const QPoint &p)
{
    position = p;
    pen.setWidthF(1);
    pen.setColor(Qt::blue);
    brush = QBrush(Qt::white);
}

void Node::render(QPainter *painter, QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(position, 3, 3);

    if(activeTool == "selectTool"){
        float distance =
            abs(position.x() - mousePosition.x()) +
            abs(position.y() - mousePosition.y());
        if(distance < 10){
            painter->drawEllipse(position, 4, 4);
            highlighted = true;
        }
        else{
            highlighted = false;
        }
    }
}

void Node::update(QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin)
{
    if(dragging){
        position = draggingFrom + mousePosition - mousePositionOrigin;
    }
}
