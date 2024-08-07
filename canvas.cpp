#include "canvas.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPalette>

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::black);

    setAutoFillBackground(true);
    setPalette(pal);


}

void Canvas::mousePressEvent(QMouseEvent *event)
{

}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{

}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    // qDebug() << event->pos();
}
