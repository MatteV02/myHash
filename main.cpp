#include "myHash.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myHash w;
    w.show();
    return a.exec();
}
