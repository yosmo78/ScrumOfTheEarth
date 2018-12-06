/*! \file */
#ifndef RENDERAREA_H
#define RENDERAREA_H
#include <QWidget>
#include "shape.h"
#include "vector.h"
#include <iostream>
/*!
 * \brief The RenderArea class provides the environment for drawing shapes
 */
class RenderArea : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief RenderArea constructor
     * \param parent widget
     */
    RenderArea(QWidget* parent): QWidget(parent){setBackgroundRole(QPalette::Base); setAutoFillBackground(true);}
    virtual ~RenderArea()
    {
        shapesList.deallocPtrData();//delete all of the shapes
    }
    /*!
     * \brief shapesList vector of Shape* that RenderArea draws
     */
    myStd::vector<Shape*> shapesList;//global vector to draw shapes
    /*!
     * \brief Gets a bool of whether to show the ids when rendering or not
     * \return
     */
    bool getShowId(){return showId;} const
    /*!
     * \brief Sets the bool to signify if the shapes should be rendered with an id or not
     * \param t bool of showId condition
     */
    void setShowId(bool t){showId = t;}
  protected:
    /*!
     * \brief paintEvent calls draw on all of the shapes and draws them inside the RenderArea
     * \param event QPaintEvent used to signify that it is a paint event
     */
    void paintEvent(QPaintEvent* event) override
    {
        QPainter nothing(this); //qt best practice
        nothing.setBrush(QBrush(Qt::white));//clear the canvas
        nothing.drawRect(rect());           //with the color white

        //nothing.drawLine(QPointF(),QPointF(qreal(60),qreal(60)));
      Shape ** ptr =  shapesList.begin();
      for(int i = 0; i < shapesList.size(); ++i)
      {
          ptr[i]->draw(nothing,showId);
      }
    }
private:
        bool showId;
};

#endif // RENDERAREA_H
