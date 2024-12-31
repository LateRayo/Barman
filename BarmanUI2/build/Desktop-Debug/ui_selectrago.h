/********************************************************************************
** Form generated from reading UI file 'selectrago.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTRAGO_H
#define UI_SELECTRAGO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelecTrago
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *Bebida1;
    QPushButton *Bebida2;
    QPushButton *Bebida3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SelecTrago)
    {
        if (SelecTrago->objectName().isEmpty())
            SelecTrago->setObjectName("SelecTrago");
        SelecTrago->resize(639, 560);
        verticalLayout = new QVBoxLayout(SelecTrago);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");

        verticalLayout->addLayout(verticalLayout_5);

        label = new QLabel(SelecTrago);
        label->setObjectName("label");
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/selectTrag.png")));
        label->setScaledContents(true);

        verticalLayout->addWidget(label);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        tableView = new QTableView(SelecTrago);
        tableView->setObjectName("tableView");

        verticalLayout_4->addWidget(tableView);


        verticalLayout->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Bebida1 = new QPushButton(SelecTrago);
        Bebida1->setObjectName("Bebida1");
        Bebida1->setMinimumSize(QSize(40, 50));

        horizontalLayout->addWidget(Bebida1);

        Bebida2 = new QPushButton(SelecTrago);
        Bebida2->setObjectName("Bebida2");
        Bebida2->setMinimumSize(QSize(40, 50));

        horizontalLayout->addWidget(Bebida2);

        Bebida3 = new QPushButton(SelecTrago);
        Bebida3->setObjectName("Bebida3");
        Bebida3->setMinimumSize(QSize(40, 50));

        horizontalLayout->addWidget(Bebida3);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(SelecTrago);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SelecTrago);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SelecTrago, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SelecTrago, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SelecTrago);
    } // setupUi

    void retranslateUi(QDialog *SelecTrago)
    {
        SelecTrago->setWindowTitle(QCoreApplication::translate("SelecTrago", "Dialog", nullptr));
        label->setText(QString());
        Bebida1->setText(QCoreApplication::translate("SelecTrago", "Vodka con Naranja", nullptr));
        Bebida2->setText(QCoreApplication::translate("SelecTrago", "Ron con naranja", nullptr));
        Bebida3->setText(QCoreApplication::translate("SelecTrago", "Campari con naranja", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelecTrago: public Ui_SelecTrago {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTRAGO_H
