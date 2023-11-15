#include "mainwindow5.h"
#include "ui_mainwindow5.h"
#include <QDebug>

MainWindow5::MainWindow5(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow5)
{
    ui->setupUi(this);
    showNowFunc("MainWindow5::MainWindow5(QWidget *parent)");
    QList<QCameraInfo> infos = QCameraInfo::availableCameras();
    foreach (QCameraInfo info, infos) {
        qDebug() << " QCameraInfo::availableCameras()*************** : "<<info.deviceName();
        ui->comboBox->addItem(info.deviceName());
    }
}

MainWindow5::~MainWindow5()
{

    delete ui;

}


void MainWindow5::on_btnStart_clicked()
{
    Camera = new QCamera(ui->comboBox->currentText().toUtf8(),this);
    //显示摄像头取景器
    ui->widget->show();
    //
    CameraImageCapture = new QCameraImageCapture(Camera);
    //
    // connect(CameraImageCapture, &QCameraImageCapture::imageCaptured, this, &MainWindow::take_photo);
    connect(CameraImageCapture,SIGNAL(imageCaptured(int,QImage)),this,SLOT(show_pic(int,Qimage)));
    // connect(CameraImageCapture, &QCameraImageCapture::imageCaptured, this, &MainWindow5::show_pic);
    CameraViewFinder = new QCameraViewfinder(ui->widget);

    CameraViewFinder->resize(ui->widget->size());

    Camera->setViewfinder(CameraViewFinder);

    CameraViewFinder->show();

    Camera->start();
}


void MainWindow5::on_btnStop_clicked()
{
    Camera->stop();
    ui->widget->hide();
}


void MainWindow5::on_btnCapture_clicked()
{
    //qDebug() << "------------- on_btnCapture_clicked -----------------";
    showNowFunc("on_btnCapture_clicked()");
    CameraImageCapture->capture("D:\\qtpic\a1"); //
}

void MainWindow5::show_pic(int id,QImage &preview)
{
    //没有进来，槽函数没绑定
    showNowFunc("show_pic(int id,QImage &preview)");
    qDebug() << "id = " << id;
    QPixmap pix = QPixmap::fromImage(preview);
    pix = pix.scaled(ui->label->size());
    ui->label->setPixmap(pix);
}

/*
// 添加一个输出
void showNowFunc(const QString& a){
    qDebug() << "----------- " << a << "---------------";
}*/














