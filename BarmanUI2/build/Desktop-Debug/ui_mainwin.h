/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *image_barmanautomatico;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_buttons;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *butto_VN;
    QPushButton *button_CN;
    QPushButton *button_RN;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(976, 799);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(500, 500));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(210, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        image_barmanautomatico = new QLabel(frame);
        image_barmanautomatico->setObjectName("image_barmanautomatico");
        image_barmanautomatico->setMinimumSize(QSize(500, 500));
        image_barmanautomatico->setMaximumSize(QSize(500, 500));
        image_barmanautomatico->setAutoFillBackground(false);
        image_barmanautomatico->setStyleSheet(QString::fromUtf8("background-image: url(:/bg/bg_barmanautomatico.png);"));
        image_barmanautomatico->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/bg_barmanautomatico.png")));
        image_barmanautomatico->setScaledContents(true);

        horizontalLayout->addWidget(image_barmanautomatico);

        horizontalSpacer_2 = new QSpacerItem(210, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(frame, 1, 0, 2, 2);

        frame_buttons = new QFrame(centralwidget);
        frame_buttons->setObjectName("frame_buttons");
        frame_buttons->setMinimumSize(QSize(200, 200));
        frame_buttons->setFrameShape(QFrame::Shape::StyledPanel);
        frame_buttons->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_buttons);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, -1, -1, -1);
        label = new QLabel(frame_buttons);
        label->setObjectName("label");
        label->setMaximumSize(QSize(200, 30));

        verticalLayout->addWidget(label);

        butto_VN = new QPushButton(frame_buttons);
        butto_VN->setObjectName("butto_VN");
        butto_VN->setMinimumSize(QSize(150, 50));
        butto_VN->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(butto_VN);

        button_CN = new QPushButton(frame_buttons);
        button_CN->setObjectName("button_CN");
        button_CN->setMinimumSize(QSize(150, 50));
        button_CN->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(button_CN);

        button_RN = new QPushButton(frame_buttons);
        button_RN->setObjectName("button_RN");
        button_RN->setMinimumSize(QSize(150, 50));
        button_RN->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(button_RN);


        horizontalLayout_2->addLayout(verticalLayout);

        tableWidget = new QTableWidget(frame_buttons);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::UserAvailable")));
        QFont font;
        font.setPointSize(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setIcon(icon);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::Phone")));
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        __qtablewidgetitem1->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::ViewRefresh")));
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(true);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        __qtablewidgetitem2->setForeground(brush);
        __qtablewidgetitem2->setIcon(icon2);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(325, 200));
        tableWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setMidLineWidth(0);
        tableWidget->setDragEnabled(true);

        horizontalLayout_2->addWidget(tableWidget);


        gridLayout->addWidget(frame_buttons, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        image_barmanautomatico->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Bienvenido #username", nullptr));
        butto_VN->setText(QCoreApplication::translate("MainWindow", "Vodka con naranja", nullptr));
        button_CN->setText(QCoreApplication::translate("MainWindow", "Campari con naranja", nullptr));
        button_RN->setText(QCoreApplication::translate("MainWindow", "Ron con naranja", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Trago", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Estado", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
