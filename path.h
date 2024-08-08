#ifndef PATH_H
#define PATH_H

#include <QList>
#include <QPainterPath>
#include <QPolygon>
#include "node.h"

class Path
{
public:
    Path();
    void addNode(Node node);
    QList<Node> nodes;
};

#endif // PATH_H
