#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QButtonGroup>
#include <QPainter>
#include <QList>
#include <QPen>
#include <QBrush>
#include <QString>
#include "path.h"
#include <QPolygon>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QButtonGroup *toolsGroup, QWidget *parent = nullptr);
    QButtonGroup *toolsGroup;
    QString activeTool;
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent * event);

    QPainter painter;
    QList<Path> paths;
    QPoint mousePosition;

    QPen penPen;
    QPen nodePen;
    QBrush nodeBrush;

    bool isDrawingPath = false;

public slots:
    void updateSlot(QAbstractButton *button);
};

#endif // CANVAS_H
