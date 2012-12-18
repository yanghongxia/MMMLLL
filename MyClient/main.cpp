#include <QtGui/QApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client w;
    QStringList l;
    w.PLCDiscovery(l);
    w.show();

    return a.exec();
}
