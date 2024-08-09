#ifndef PATH_H
#define PATH_H

#include <QList>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QBrush>

class Path : public QPolygon
{
public:
    Path();
    void render(QPainter *painter);

    QPen linePen;
    QBrush lineBrush;
    QPen nodePen;
    QBrush nodeBrush;
};

#endif // PATH_H
