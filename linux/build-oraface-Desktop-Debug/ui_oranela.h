/********************************************************************************
** Form generated from reading UI file 'oranela.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORANELA_H
#define UI_ORANELA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_oranela
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lab_y;
    QLabel *label_2;
    QLineEdit *lab_x;
    QPushButton *run_bot;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *oranela)
    {
        if (oranela->objectName().isEmpty())
            oranela->setObjectName(QString::fromUtf8("oranela"));
        oranela->resize(491, 278);
        centralWidget = new QWidget(oranela);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 251, 181));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lab_y = new QLineEdit(layoutWidget);
        lab_y->setObjectName(QString::fromUtf8("lab_y"));

        gridLayout->addWidget(lab_y, 3, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lab_x = new QLineEdit(layoutWidget);
        lab_x->setObjectName(QString::fromUtf8("lab_x"));

        gridLayout->addWidget(lab_x, 1, 0, 1, 1);

        run_bot = new QPushButton(centralWidget);
        run_bot->setObjectName(QString::fromUtf8("run_bot"));
        run_bot->setGeometry(QRect(290, 60, 181, 121));
        oranela->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(oranela);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        oranela->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(oranela);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        oranela->setStatusBar(statusBar);

        retranslateUi(oranela);

        QMetaObject::connectSlotsByName(oranela);
    } // setupUi

    void retranslateUi(QMainWindow *oranela)
    {
        oranela->setWindowTitle(QApplication::translate("oranela", "oranela", nullptr));
        label->setText(QApplication::translate("oranela", "Coordenada X", nullptr));
        lab_y->setText(QApplication::translate("oranela", "0", nullptr));
        label_2->setText(QApplication::translate("oranela", "Coordenada Y", nullptr));
        lab_x->setText(QApplication::translate("oranela", "0", nullptr));
        run_bot->setText(QApplication::translate("oranela", "Run", nullptr));
    } // retranslateUi

};

namespace Ui {
    class oranela: public Ui_oranela {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORANELA_H
