#ifndef PATH_H
#define PATH_H

#include <QList>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QString>
#include "node.h"

class Path : public QPolygon
{
public:
    Path();
    void render(QPainter *painter, QString activeTool, QPoint mousePosition);

    QPen pen;
    QBrush brush;
};

#endif // PATH_H
