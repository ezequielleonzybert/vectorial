#ifndef PATH_H
#define PATH_H

#include <QList>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QString>
#include "node.h"

class Path
{
public:
    Path();
    void update(QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin);
    void render(QPainter *painter, QString activeTool, QPoint mousePosition, QPoint mousePositionOrigin);

    QList<Node> nodes;
    QPen pen;
    QBrush brush;
};

#endif // PATH_H
