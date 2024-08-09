#include "canvas.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPalette>
#include <QColor>
#include <QAbstractButton>
#include "node.h"

Canvas::Canvas(QButtonGroup *toolsGroup, QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);

    this->toolsGroup = toolsGroup;

    penPen.setWidthF(1);
    penPen.setColor(Qt::black);
    nodePen.setWidthF(1);
    nodePen.setColor(Qt::blue);
    nodeBrush = QBrush(Qt::white);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    activeTool = toolsGroup->checkedButton()->objectName(); //TODO, solve active tool when change tool
    if(activeTool == "penTool"){
        if(event->button() == Qt::LeftButton){
            QPoint mousePosition = event->pos();
            if(isDrawingPath){
                paths.last().addNode(mousePosition);

            }
            else{
                isDrawingPath = true;
                Path path;
                path.addNode(mousePosition);
                paths.append(path);
            }
        }
        if(event->button() == Qt::RightButton){
            isDrawingPath = false;
        }
        update();
    }
    else if(activeTool == "selectTool"){
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
        for(int i = 0; i < p.nodes.size()-1; i++){
            QPoint p1 = p.nodes[i].position;
            QPoint p2 = p.nodes[i+1].position;

            painter.setPen(penPen);
            painter.drawLine(p1, p2);

            painter.setPen(nodePen);
            painter.setBrush(nodeBrush);
            painter.drawEllipse(p1,3,3);
            painter.drawEllipse(p2,3,3);
        }
    }
    if(isDrawingPath && activeTool == "penTool"){
        QPoint p = paths.last().nodes.last().position;
        painter.setPen(penPen);
        painter.drawLine(p, mousePosition);
        painter.setPen(nodePen);
        painter.setBrush(nodeBrush);
        painter.drawEllipse(p,3,3);
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
