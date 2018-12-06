/*! \file */
#ifndef MOVESHAPE_H
#define MOVESHAPE_H
#include "vector.h"
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "ellipse.h"
#include "polygon.h"
#include "polyline.h"
#include "text.h"
#include <string>

#include <QMainWindow>

namespace Ui {
class MoveShape;
}

/*!
 * \brief The MoveShape class provides the interface and functionality for moving shapes
 */
class MoveShape : public QMainWindow
{
    Q_OBJECT


signals:
    /*!
     * \brief Updates window whenever a shape is added
     */
    void update_win();
public:
    /*!
     * \brief MoveShape constructor
     * \param parent window
     * \param shapes pointer vector
     */
    explicit MoveShape(QWidget *parent, myStd::vector<Shape *> & shapes);
    ~MoveShape();

private slots:
    /*!
     * \brief Tells program to add shape
     */
    void on_pushButton_clicked();

private:
    Ui::MoveShape *ui;
    myStd::vector<Shape *> * vecPointer;
};

#endif // MOVESHAPE_H
