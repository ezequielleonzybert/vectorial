#include "toolbar.h"

Toolbar::Toolbar(QWidget *parent)
    : QWidget{parent}
{
    selectTool = new QRadioButton("Select");
    selectTool->setObjectName("selectTool");
    selectTool->setChecked(true);

    penTool = new QRadioButton("Pen");
    penTool->setObjectName("penTool");

    toolsGroup = new QButtonGroup();
    toolsGroup->addButton(selectTool);
    toolsGroup->addButton(penTool);

    vLayout = new QVBoxLayout(this);

    vLayout->addWidget(selectTool);
    vLayout->addWidget(penTool);
    vLayout->addStretch();
}
