#include "mymainwindow3.h"
#include "./ui_mymainwindow3.h"
#include <QDebug>

myMainWindow3::myMainWindow3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myMainWindow3)//UI 对应UI文件
{
    ui->setupUi(this);
    // ui->closeBtn;
    me = new mew;
    gf = new GitlF;
    // 用指针定义me gf 然后 new 分配内存
    // 类似 C++ int* p ; p = new int; *p=88;
    // mew me;
    // GitlF gf;
    // 就是一定要new 分配内存
    connect(gf,&GitlF::hungry,me,&mew::eat); //怎么触发hungry?
    connect(ui->hungryBtn,&QPushButton::clicked,this,&myMainWindow3::hungrySlot);

    connect(ui->closeBtn,&QPushButton::clicked,this,&myMainWindow3::close);
    qDebug() << "wohenshuai*********" << "123456" << 10000;

}

myMainWindow3::~myMainWindow3()
{
    delete ui;
}

void myMainWindow3::hungrySlot()
{
    // 触发gf_gfhungry
    emit gf->hungry();
}

