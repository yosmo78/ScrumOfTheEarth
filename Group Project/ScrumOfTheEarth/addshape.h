/*! \file */

#ifndef ADDSHAPE_H
#define ADDSHAPE_H
#include "vector.h"
#include "shape.h"
#include <QMainWindow>

class MainWindow;
namespace Ui {
class AddShape;
}
//! \class AddShape
/*!
 * AddShape window class
*/
class AddShape : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     *
     * This function will instantiate an AddWindow for adding a
     * new shape to the shape vector
    */
    explicit AddShape(QWidget *parent,myStd::vector<Shape *> &, bool &);
     /*!
     * This function will destroy AddWindow
    */
    ~AddShape();

private slots:
    /*!
     * Will add a square to our shape list
     */
    void on_AddSquare_clicked();
    void on_RAddRectangle_clicked();

    void on_CAddCircle_clicked();

    void on_EAddEllipse_clicked();

    void on_GAddPolygon_clicked();

    void on_PAddPolyline_clicked();

    void on_LAddLine_clicked();

    void on_TAddText_clicked();

signals:
    /*!
     * This will call an update in the window when emitted
     */
    void update_Window();

private:
    Ui::AddShape *ui; /*!< AddShape pointer ui */
    myStd::vector<Shape *> * vecPointer; /*!< Vector pointer vecPointer*/
    bool* var; /*!< Bool pointer var*/
};

#endif // ADDSHAPE_H
