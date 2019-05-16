#include "oranela.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    oranela w;
    w.show();

    return a.exec();
}
