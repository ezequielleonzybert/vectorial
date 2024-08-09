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

    // penPen.setWidthF(1);
    // penPen.setColor(Qt::black);
    // nodePen.setWidthF(1);
    // nodePen.setColor(Qt::blue);
    // nodeBrush = QBrush(Qt::white);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if(activeTool == "penTool"){
        if(event->button() == Qt::LeftButton){
            QPoint mousePosition = event->pos();
            if(isDrawingPath){
                paths.last().append(mousePosition);
            }
            else{
                isDrawingPath = true;
                Path path;
                path.append(mousePosition);
                paths.append(path);
            }
        }
        if(event->button() == Qt::RightButton){
            isDrawingPath = false;
        }
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    mousePosition = event->pos();
    update();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for(Path p : paths){
        p.render(&painter);
    }

    if(isDrawingPath){
        QPoint p = paths.last().last();
        painter.setPen(penPen);
        painter.drawLine(p, mousePosition);
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
