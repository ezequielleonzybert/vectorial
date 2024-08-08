#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QButtonGroup>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QMouseEvent>
#include "canvas.h"

class Toolbar : public QWidget
{
    Q_OBJECT
public:
    explicit Toolbar(QWidget *parent = nullptr);

    QButtonGroup *toolsGroup;
    QRadioButton *selectTool;
    QRadioButton *penTool;
    QVBoxLayout *vLayout;
};

#endif // TOOLBAR_H
