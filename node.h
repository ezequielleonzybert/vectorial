#ifndef NODE_H
#define NODE_H

#include <QPoint>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QString>

class Node
{
public:
    Node();
    Node(int x, int y);
    Node(const QPoint &p);
    void render(QPainter *painter, QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin);
    void update(QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin);

    bool highlighted = false;
    bool dragging = false;
    QPoint draggingFrom;
    QPoint position;
    QPen pen;
    QBrush brush;
};

#endif // NODE_H
