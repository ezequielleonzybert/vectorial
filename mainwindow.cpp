#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,400);
    container = new QWidget();
    toolbar = new Toolbar();
    canvas = new Canvas();

    hLayout = new QHBoxLayout(container);
    setCentralWidget(container);

    hLayout->addWidget(toolbar);
    hLayout->addWidget(canvas);

    hLayout->setStretch(1,1);
}
