/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *cerrar;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(651, 445);
        login->setMinimumSize(QSize(400, 300));
        login->setMaximumSize(QSize(1000, 700));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(400, 200));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Bienvenidos.png")));
        label->setScaledContents(true);

        horizontalLayout_3->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_2 = new QSpacerItem(10, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_3->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_3->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");

        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 5, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cerrar = new QPushButton(centralwidget);
        cerrar->setObjectName("cerrar");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ProcessStop")));
        cerrar->setIcon(icon);

        horizontalLayout->addWidget(cerrar);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::MailReplySender")));
        pushButton->setIcon(icon1);

        horizontalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        login->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label->setText(QString());
        lineEdit_2->setText(QString());
        lineEdit->setText(QString());
        cerrar->setText(QCoreApplication::translate("login", "Cancel", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
