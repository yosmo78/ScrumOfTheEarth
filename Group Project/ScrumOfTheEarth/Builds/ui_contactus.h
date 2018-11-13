/********************************************************************************
** Form generated from reading UI file 'contactus.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTUS_H
#define UI_CONTACTUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactUs
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;

    void setupUi(QDialog *ContactUs)
    {
        if (ContactUs->objectName().isEmpty())
            ContactUs->setObjectName(QStringLiteral("ContactUs"));
        ContactUs->resize(400, 300);
        label = new QLabel(ContactUs);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 231));
        label->setPixmap(QPixmap(QString::fromUtf8("SCRUM LOGO.png")));
        layoutWidget = new QWidget(ContactUs);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 250, 220, 42));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        retranslateUi(ContactUs);

        QMetaObject::connectSlotsByName(ContactUs);
    } // setupUi

    void retranslateUi(QDialog *ContactUs)
    {
        ContactUs->setWindowTitle(QApplication::translate("ContactUs", "Dialog", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QApplication::translate("ContactUs", "Email: SrumOfTheEarth@gmail.com", Q_NULLPTR));
        label_2->setText(QApplication::translate("ContactUs", "Phone: (949) 715-2749", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContactUs: public Ui_ContactUs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTUS_H
