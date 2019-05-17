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
#include <QtGui/QIcon>
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
    QPushButton *run_bot;
    QPushButton *Traj;
    QLabel *label_2;
    QLineEdit *lab_y;
    QLabel *label;
    QLineEdit *lab_x;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *Velx;
    QPushButton *Accx;
    QPushButton *Posx;
    QPushButton *Posy;
    QPushButton *Accy;
    QPushButton *Vely;
    QLabel *label_3;
    QPushButton *Posrel;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *oranela)
    {
        if (oranela->objectName().isEmpty())
            oranela->setObjectName(QString::fromUtf8("oranela"));
        oranela->resize(1024, 768);
        oranela->setMinimumSize(QSize(1024, 768));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../imagens/ouroboros.png"), QSize(), QIcon::Normal, QIcon::Off);
        oranela->setWindowIcon(icon);
        centralWidget = new QWidget(oranela);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        run_bot = new QPushButton(centralWidget);
        run_bot->setObjectName(QString::fromUtf8("run_bot"));
        run_bot->setGeometry(QRect(330, 20, 131, 71));
        Traj = new QPushButton(centralWidget);
        Traj->setObjectName(QString::fromUtf8("Traj"));
        Traj->setGeometry(QRect(800, 10, 84, 91));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 82, 18));
        lab_y = new QLineEdit(centralWidget);
        lab_y->setObjectName(QString::fromUtf8("lab_y"));
        lab_y->setGeometry(QRect(110, 60, 161, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 82, 18));
        lab_x = new QLineEdit(centralWidget);
        lab_x->setObjectName(QString::fromUtf8("lab_x"));
        lab_x->setGeometry(QRect(110, 20, 161, 32));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 0, 282, 116));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Velx = new QPushButton(layoutWidget);
        Velx->setObjectName(QString::fromUtf8("Velx"));

        gridLayout->addWidget(Velx, 1, 1, 1, 1);

        Accx = new QPushButton(layoutWidget);
        Accx->setObjectName(QString::fromUtf8("Accx"));

        gridLayout->addWidget(Accx, 2, 1, 1, 1);

        Posx = new QPushButton(layoutWidget);
        Posx->setObjectName(QString::fromUtf8("Posx"));

        gridLayout->addWidget(Posx, 1, 0, 1, 1);

        Posy = new QPushButton(layoutWidget);
        Posy->setObjectName(QString::fromUtf8("Posy"));

        gridLayout->addWidget(Posy, 2, 0, 1, 1);

        Accy = new QPushButton(layoutWidget);
        Accy->setObjectName(QString::fromUtf8("Accy"));

        gridLayout->addWidget(Accy, 2, 2, 1, 1);

        Vely = new QPushButton(layoutWidget);
        Vely->setObjectName(QString::fromUtf8("Vely"));

        gridLayout->addWidget(Vely, 1, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 160, 981, 551));
        Posrel = new QPushButton(centralWidget);
        Posrel->setObjectName(QString::fromUtf8("Posrel"));
        Posrel->setGeometry(QRect(910, 10, 84, 91));
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
        oranela->setWindowTitle(QApplication::translate("oranela", "Ouroboros", nullptr));
        run_bot->setText(QApplication::translate("oranela", "Run", nullptr));
        Traj->setText(QApplication::translate("oranela", "Trajet\303\263rias", nullptr));
        label_2->setText(QApplication::translate("oranela", "Coordenada Y", nullptr));
        lab_y->setText(QApplication::translate("oranela", "0", nullptr));
        label->setText(QApplication::translate("oranela", "Coordenada X", nullptr));
        lab_x->setText(QApplication::translate("oranela", "0", nullptr));
        Velx->setText(QApplication::translate("oranela", "Velocidade X", nullptr));
        Accx->setText(QApplication::translate("oranela", "Acelera\303\247\303\243o X", nullptr));
        Posx->setText(QApplication::translate("oranela", "Posi\303\247\303\243o X", nullptr));
        Posy->setText(QApplication::translate("oranela", "Posi\303\247\303\243o Y", nullptr));
        Accy->setText(QApplication::translate("oranela", "Acelera\303\247\303\243o Y", nullptr));
        Vely->setText(QApplication::translate("oranela", "Velocidade Y", nullptr));
        label_3->setText(QApplication::translate("oranela", "Graficos", nullptr));
        Posrel->setText(QApplication::translate("oranela", "Pos rel.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class oranela: public Ui_oranela {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORANELA_H
