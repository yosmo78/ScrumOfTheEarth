/*! \file */
#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QPixmap>
#include <unistd.h>

#include <QDialog>
namespace Ui {
class ContactUs;
}

/*!
 * \brief The ContactUs class provides functionality for the contact us window
 */
class ContactUs : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief ContactUs constructor creates a window for the contact us information
     * \param parent window
     */
    explicit ContactUs(QWidget *parent = nullptr);
    /*!
     * \brief Destructor for ContactUs
     */
    ~ContactUs();

private:
    Ui::ContactUs *ui;
};

#endif // CONTACTUS_H
