#include "mainwindow.h"
#include <QAbstractButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,400);
    container = new QWidget();
    toolbar = new Toolbar();
    canvas = new Canvas(toolbar->toolsGroup);

    hLayout = new QHBoxLayout(container);
    setCentralWidget(container);

    hLayout->addWidget(toolbar);
    hLayout->addWidget(canvas);

    hLayout->setStretch(1,1);

    connect(toolbar->toolsGroup, &QButtonGroup::buttonClicked, canvas, &Canvas::updateSlot);
}
