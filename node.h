#ifndef NODE_H
#define NODE_H

#include <QPoint>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QString>

class Node : public QPoint
{
public:
    Node();
    Node(int x, int y);
    Node(const QPoint &p);
    void render(QPainter *painter, QString activeTool, QPoint mousePosition);

    bool highlighted = false;

    QPen pen;
    QBrush brush;
};

#endif // NODE_H
