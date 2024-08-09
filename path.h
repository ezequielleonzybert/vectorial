#ifndef PATH_H
#define PATH_H

#include <QList>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QString>

class Path : public QPolygon
{
public:
    Path();
    void render(QPainter *painter, QString activeTool, QPoint mousePosition);

    QPen linePen;
    QBrush lineBrush;
    QPen nodePen;
    QBrush nodeBrush;
};

#endif // PATH_H
