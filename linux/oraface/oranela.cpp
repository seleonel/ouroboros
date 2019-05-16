#include "oranela.h"
#include "ui_oranela.h"
#include <QPushButton>
#include <stdlib.h>
#include <QLineEdit>
#include <stdio.h>
static double rob_x = 0.0;
static double rob_y = 0.0;
oranela::oranela(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::oranela)
{
    ui->setupUi(this);

    QString botao = "run_bot";
    QPushButton * botao_run = findChild<QPushButton *>(botao);
    connect(botao_run ,SIGNAL(released()),this, SLOT(iniciarProg()));
}

oranela::~oranela()
{
    delete ui;
}

void oranela::iniciarProg()
{
    char param[100];
    rob_x = (ui->lab_x->text()).toDouble();
    rob_y = (ui->lab_y->text()).toDouble();
    sprintf(param, " cd .. && %s %lf %lf", "./ouroboros.out", rob_x, rob_y);
    system(param);

}
