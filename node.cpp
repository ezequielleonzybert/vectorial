#include "node.h"


Node::Node() : QPoint()
{
    pen.setWidthF(1);
    pen.setColor(Qt::blue);
    brush = QBrush(Qt::white);
}

Node::Node(int x, int y) : QPoint(x, y)
{
    pen.setWidthF(1);
    pen.setColor(Qt::blue);
    brush = QBrush(Qt::white);
}

Node::Node(const QPoint &p) : QPoint (p)
{
    pen.setWidthF(1);
    pen.setColor(Qt::blue);
    brush = QBrush(Qt::white);
}

void Node::render(QPainter *painter, QString activeTool, QPoint mousePosition)
{
    painter->drawEllipse(*this, 3, 3);
    if(activeTool == "selectTool"){
        float distance =
            abs(x() - mousePosition.x()) +
            abs(y() - mousePosition.y());
        if(distance < 10){
            painter->setPen(pen);
            painter->setBrush(brush);
            painter->drawEllipse(*this, 4, 4);
        }
    }
}
