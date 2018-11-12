#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QPixmap>
#include <unistd.h>

#include <QDialog>

namespace Ui {
class ContactUs;
}

class ContactUs : public QDialog
{
    Q_OBJECT

public:
    explicit ContactUs(QWidget *parent = nullptr);
    ~ContactUs();

private:
    Ui::ContactUs *ui;
};

#endif // CONTACTUS_H
