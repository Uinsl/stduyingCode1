#include "mymainwindow3.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myMainWindow3 w;
    w.show();
    return a.exec();
}
