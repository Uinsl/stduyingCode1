#include "mew.h"
#include <QDebug>

mew::mew(QObject *parent)
    : QObject{parent}
{

}

void mew::eat()
{
    qDebug() << "tk u to lunch 9999999" ;
}
