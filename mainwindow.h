#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include "canvas.h"
#include "toolbar.h"

QT_BEGIN_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QWidget *container;
    Toolbar *toolbar;
    Canvas *canvas;

    QHBoxLayout *hLayout;

};
#endif // MAINWINDOW_H
