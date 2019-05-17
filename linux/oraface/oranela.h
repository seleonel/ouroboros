#ifndef ORANELA_H
#define ORANELA_H

#include <QMainWindow>

namespace Ui {
class oranela;
}

class oranela : public QMainWindow
{
    Q_OBJECT

public:
    explicit oranela(QWidget *parent = nullptr);
    ~oranela();

public slots:
    void iniciarProg();
    void abrirImgPos();
    void abrirAccx();
    void abrirAccy();
    void abrirVelx();
    void abrirVely();
    void posRel();
    void posX();
    void posY();

private:
    Ui::oranela *ui;



};

#endif // ORANELA_H
