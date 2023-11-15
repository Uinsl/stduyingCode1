#ifndef MYMAINWINDOW3_H
#define MYMAINWINDOW3_H

#include <QMainWindow>

#include "mew.h"
#include "gitlf.h"

QT_BEGIN_NAMESPACE
namespace Ui { class myMainWindow3; }
QT_END_NAMESPACE

class myMainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    myMainWindow3(QWidget *parent = nullptr);
    ~myMainWindow3();


    // 添加hungryBtn的槽函数
    void hungrySlot();

private:
    Ui::myMainWindow3 *ui;

    //
    mew* me;
    GitlF* gf;
};






#endif // MYMAINWINDOW3_H
