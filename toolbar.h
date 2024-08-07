#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QButtonGroup>
#include <QRadioButton>
#include <QVBoxLayout>

class Toolbar : public QWidget
{
    Q_OBJECT
public:
    explicit Toolbar(QWidget *parent = nullptr);
    QButtonGroup *toolsGroup;
    QRadioButton *selectTool;
    QRadioButton *penTool;
    QVBoxLayout *vLayout;

signals:
};

#endif // TOOLBAR_H
