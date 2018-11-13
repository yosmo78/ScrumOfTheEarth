/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Username;
    QLineEdit *UserText;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Password;
    QLineEdit *PassText;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *Contact;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(400, 300);
        centralWidget = new QWidget(Window);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(-1, -21, 401, 281));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 210, 80, 25));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 90, 281, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Username = new QLabel(layoutWidget);
        Username->setObjectName(QStringLiteral("Username"));

        horizontalLayout->addWidget(Username);

        UserText = new QLineEdit(layoutWidget);
        UserText->setObjectName(QStringLiteral("UserText"));

        horizontalLayout->addWidget(UserText);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 130, 281, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Password = new QLabel(layoutWidget1);
        Password->setObjectName(QStringLiteral("Password"));

        horizontalLayout_2->addWidget(Password);

        PassText = new QLineEdit(layoutWidget1);
        PassText->setObjectName(QStringLiteral("PassText"));

        horizontalLayout_2->addWidget(PassText);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 151, 20));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 210, 101, 25));
        Contact = new QPushButton(centralWidget);
        Contact->setObjectName(QStringLiteral("Contact"));
        Contact->setGeometry(QRect(300, 250, 101, 31));
        Window->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Window);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        Window->setMenuBar(menuBar);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Window", "Log In", Q_NULLPTR));
        Username->setText(QApplication::translate("Window", "Username", Q_NULLPTR));
        Password->setText(QApplication::translate("Window", "Password ", Q_NULLPTR));
        label->setText(QApplication::translate("Window", "Scrum of the Earth", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Window", "Guest Login", Q_NULLPTR));
        Contact->setText(QApplication::translate("Window", "Contact", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
