#ifndef RENDERAREA_H
#define RENDERAREA_H
#include <QWidget>
#include "shape.h"
#include "vector.h"
#include <iostream>

class RenderArea : public QWidget
{
    Q_OBJECT

  public:
    RenderArea(QWidget* parent): QWidget(parent){setBackgroundRole(QPalette::Base); setAutoFillBackground(true);}
    virtual ~RenderArea()
    {
        shapesList.deallocPtrData();//delete all of the shapes
    }
    myStd::vector<Shape*> shapesList;//global vector to draw shapes
  protected:
    void paintEvent(QPaintEvent* event) override
    {
        QPainter nothing(this); //qt best practice
        nothing.setBrush(QBrush(Qt::white));//clear the canvas
        nothing.drawRect(rect());           //with the color white

        //nothing.drawLine(QPointF(),QPointF(qreal(60),qreal(60)));
      Shape ** ptr =  shapesList.begin();
      for(int i = 0; i < shapesList.size(); ++i)
      {
          ptr[i]->draw(nothing);
      }
    }
};

#endif // RENDERAREA_H
