/*! \file */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "addshape.h"
#include "moveshape.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class provides the environment for the RenderArea, Tables, and Buttons
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow constructor
     * \param parent window
     * \param admin bool
     */
    explicit MainWindow(QWidget *parent = nullptr, bool admin = false);
    /*!
     * \brief MainWindow Destructor
     */
    ~MainWindow();
public slots:
    /*!
     * \brief Slot update_window updates the render area and the tables from its vector
     */
    void update_window();
private slots:

    /*!
     * \brief Prompts user for file and loads that file when clicked
     */
    void on_FileButton_clicked();
    /*!
     * \brief Writes the vector to the file loaded previously
     */
    void on_Save_clicked();
    /*!
     * \brief Prompts user for shape to add and adds that to the vector
     */
    void on_AddShape_clicked();
    /*!
     * \brief Prompts user for shape to delete and deletes shape from vector
     */
    void on_DeleteShape_clicked();
    /*!
     * \brief Hides/Displays the Id of the shapes being rendered
     */
    void on_checkBox_clicked();
    /*!
     * \brief Creates a MoveShape window for the user to move the shape
     */
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AddShape * addshape;
    MoveShape * moveshape;
    bool isAdmin;
    QString file;
};

#endif // MAINWINDOW_H
