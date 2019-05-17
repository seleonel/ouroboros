#include "oranela.h"
#include "ui_oranela.h"
#include <QPushButton>
#include <iostream>
#include <QPixmap>
#include <stdlib.h>
#include <QLineEdit>
#include <stdio.h>
#include <QMessageBox>
#include <sstream>
#include <QLocale>
static double rob_x = 0.0;
static double rob_y = 0.0;

oranela::oranela(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::oranela)
{
    ui->setupUi(this);
    //botao de run
    QString botao = "run_bot";
    QPushButton * botao_run = findChild<QPushButton *>(botao);
    connect(botao_run ,SIGNAL(released()),this, SLOT(iniciarProg()));

    QPushButton * botao_traj = findChild<QPushButton *>("Traj");
    connect(botao_traj, SIGNAL(released()), this, SLOT(abrirImgPos()));

    QPushButton * botao_accx = findChild<QPushButton *>("Accx");
    connect(botao_accx, SIGNAL(released()), this, SLOT(abrirAccx()));

    QPushButton * botao_accy = findChild<QPushButton *>("Accy");
    connect(botao_accy, SIGNAL(released()), this, SLOT(abrirAccy()));

    QPushButton * botao_velx = findChild<QPushButton *>("Velx");
    connect(botao_velx, SIGNAL(released()), this, SLOT(abrirVelx()));

    QPushButton * botao_vely = findChild<QPushButton *>("Vely");
    connect(botao_vely, SIGNAL(released()), this, SLOT(abrirVely()));

    QPushButton * botao_pos = findChild<QPushButton *>("Posrel");
    connect(botao_pos, SIGNAL(released()), this, SLOT(posRel()));

    QPushButton * botao_x = findChild<QPushButton *>("Posx");
    connect(botao_x, SIGNAL(released()), this, SLOT(posX()));

    QPushButton * botao_y= findChild<QPushButton *>("Posy");
    connect(botao_y, SIGNAL(released()), this, SLOT(posY()));

}

oranela::~oranela()
{
    delete ui;
}

void oranela::iniciarProg()
{
    //char param[100];
    rob_x = (ui->lab_x->text()).toDouble();
    rob_y = (ui->lab_y->text()).toDouble();
    std::cout << rob_x << std::endl << rob_y << std::endl;

    if((rob_x < 0 || rob_x > 9) || (rob_y < 0 || rob_y > 6))
    {
        QMessageBox::about(this, "PRERIGO", "Digite um valor válido");
    }else{
        //sprintf(param, " cd .. && %s %lf %lf" , "./ouroboros.out", rob_x,  rob_y);
        std::ostringstream stream_param;
        stream_param << "cd .. && " << "oralin.exe " << rob_x << " " << rob_y;
        std::string param = (stream_param.str());
        const char *teste = param.c_str();
        system(teste);
}
}
void oranela::abrirImgPos()
{
    QPixmap pont_img("../../graficos/posicaoBola.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
void oranela::abrirAccx(){
    QPixmap pont_img("../../graficos/AccelxPorTempo.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
void oranela::abrirAccy(){
    QPixmap pont_img("../../graficos/AccelyPorTempo.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
void oranela::abrirVelx(){
    QPixmap pont_img("../../graficos/VelxPorTempo.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
void oranela::abrirVely(){
    QPixmap pont_img("../../graficos/VelyPorTempo.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
void oranela::posRel(){
    QPixmap pont_img("../../graficos/DistRelativa.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
void oranela::posX(){
    QPixmap pont_img("../../graficos/xPorTempo.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
void oranela::posY(){
    QPixmap pont_img("../../graficos/yPorTempo.png");
    ui->label_3->setPixmap(pont_img);
    ui->label_3->setScaledContents(true);

}
