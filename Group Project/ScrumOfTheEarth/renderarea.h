#ifndef RENDERAREA_H
#define RENDERAREA_H
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT

  public:
    RenderArea(QWidget* parent = nullptr): QWidget(parent){}
    virtual ~RenderArea(){}
};

#endif // RENDERAREA_H
