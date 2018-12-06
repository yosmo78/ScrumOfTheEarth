/*! \file */
#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "contactus.h"
#include "mainwindow.h"
#include <string>

namespace Ui {
class Window;
}

/*!
 * \brief The Window class displays the login window and provides functionality for it
 */
class Window : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Window constructor
     * \param parent window
     */
    explicit Window(QWidget *parent = nullptr);

    /*!
     * \brief Window destructor
     */
    ~Window();

private slots:
    /*!
     * \brief Attempts to login with entered username and password when clicked
     */
    void on_pushButton_clicked();

    /*!
     * \brief Attempts to login with entered username and password when enter pressed
     */
    void on_PassText_returnPressed();

    /*!
     * \brief Displays contact info when clicked
     */
    void on_Contact_clicked();

    /*!
     * \brief Log in as guest when clicked
     */
    void on_GuestLogin_clicked();

    /*!
     * \brief Check_Admin verifies if the username and password correspond to being an admin
     * \return
     */
    bool Check_Admin(std::string, std::string, std::string);

    /*!
     * \brief Creates a login file with the internal string
     */
    void create_login_file();
private:
    Ui::Window *ui;
    ContactUs * contactus;
    MainWindow * mainwindow;
};

#endif // WINDOW_H
