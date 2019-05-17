#include "oranela.h"
#include <QApplication>
#include <locale.h>
int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    QApplication a(argc, argv);
    oranela w;
    w.show();

    return a.exec();
}
