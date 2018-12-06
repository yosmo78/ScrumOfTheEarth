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
/*!
 * \brief AddShape class that provides functionality for the add shape button
 */
class AddShape : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor for creating the pop-up for the AddShape button
     * \param parent of the addshape window
     */
    explicit AddShape(QWidget *parent,myStd::vector<Shape *> &, bool &);

    /*!
     * \brief Destructor of AddShape
     *
     */
    ~AddShape();

private slots:
    /*!
     * \brief Adds a square to the list
     */
    void on_AddSquare_clicked();
    /*!
     * \brief Adds a rectangle to the list
     */
    void on_RAddRectangle_clicked();
    /*!
     * \brief Adds a circle to the list
     */
    void on_CAddCircle_clicked();
    /*!
     * \brief Adds an ellipse to the list
     */
    void on_EAddEllipse_clicked();
    /*!
     * \brief Adds a polygon to the list
     */
    void on_GAddPolygon_clicked();
    /*!
     * \brief Adds a polyline to the list
     */
    void on_PAddPolyline_clicked();
    /*!
     * \brief Adds a line to the list
     */
    void on_LAddLine_clicked();
    /*!
     * \brief Adds text to the list
     */
    void on_TAddText_clicked();

signals:
    /*!
     * \brief This calls an update in the window
     */
    void update_Window();

private:
    Ui::AddShape *ui; /*!< AddShape pointer ui */
    myStd::vector<Shape *> * vecPointer; /*!< Vector pointer vecPointer*/
    bool* var; /*!< Bool pointer var*/
};

#endif // ADDSHAPE_H
