#include "canvas.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPalette>
#include <QColor>
#include <QAbstractButton>
#include <QLine>

Canvas::Canvas(QButtonGroup *toolsGroup, QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);

    this->toolsGroup = toolsGroup;

    nodePen.setWidthF(1);
    nodePen.setColor(Qt::blue);
    nodeBrush = QBrush(Qt::white);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if(activeTool == "penTool"){
        if(event->button() == Qt::LeftButton){
            QPoint mousePosition = event->pos();
            if(isDrawingPath){
                paths.last().nodes.append(Node(mousePosition));
            }
            else{
                isDrawingPath = true;
                Path path;
                path.nodes.append(Node(mousePosition));
                paths.append(path);
            }
        }
        if(event->button() == Qt::RightButton){
            isDrawingPath = false;
        }
    }
    else if(activeTool == "selectTool"){
        for(Path &p : paths){
            for(Node &n : p.nodes){
                if (n.highlighted){
                    mousePositionOrigin = mousePosition;
                    n.draggingFrom = n.position;
                    n.dragging = true;
                }
            }
        }
    }
    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    for(Path &p : paths){
        for(Node &n : p.nodes){
            n.dragging = false;
        }
    }
    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    mousePosition = event->pos();
    update();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    painter.begin(this);
    // painter.setRenderHint(QPainter::Antialiasing, true);

    for(Path &p : paths){
        p.update(activeTool, mousePosition, mousePositionOrigin); //TODO send whole canvas as argument
        p.render(&painter, activeTool, mousePosition, mousePositionOrigin);
    }

    if(isDrawingPath){
        QPoint p = paths.last().nodes.last().position;
        painter.setPen(pen);
        painter.drawLine(p, mousePosition);
        painter.setPen(nodePen);
        painter.setBrush(nodeBrush);
        painter.drawEllipse(p, 3, 3);;
    }
    painter.end();
}

void Canvas::updateSlot(QAbstractButton *button)
{
    if(activeTool == "penTool"){
        isDrawingPath = false;
    }
    activeTool = button->objectName();
    update();
}
