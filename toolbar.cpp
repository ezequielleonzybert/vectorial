#include "toolbar.h"

Toolbar::Toolbar(QWidget *parent)
    : QWidget{parent}
{
    toolsGroup = new QButtonGroup();
    selectTool = new QRadioButton("Select");
    penTool = new QRadioButton("Pen");

    toolsGroup->addButton(selectTool);
    toolsGroup->addButton(penTool);

    vLayout = new QVBoxLayout(this);

    vLayout->addWidget(selectTool);
    vLayout->addWidget(penTool);
    vLayout->addStretch();
}
