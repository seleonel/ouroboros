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

private:
    Ui::oranela *ui;



};

#endif // ORANELA_H
