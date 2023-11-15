#ifndef MAINWINDOW5_H
#define MAINWINDOW5_H

#include <QMainWindow>

#include <QDebug>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QPixmap>
#include <QDateTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow5; }
QT_END_NAMESPACE

class MainWindow5 : public QMainWindow
{
    Q_OBJECT

public:
    // 添加一个输出
    void showNowFunc(const QString& a){ qDebug() << " ** now function is ----------- " << a << "---------------"; }

    MainWindow5(QWidget *parent = nullptr);
    ~MainWindow5();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnCapture_clicked();

    void show_pic(int id,const QImage &preview);
private:
    Ui::MainWindow5 *ui;
    //摄像头对象指针
    QCamera* Camera;
    //摄像头的取景器
    QCameraViewfinder* CameraViewFinder;
    //存储摄像机设备信息
    QList<QCameraInfo> CameraInfoList;
    //记录摄像头内容
    QCameraImageCapture* CameraImageCapture;
    //照片的名字
    QString ImageName;
};

/*
void showNowFunc(const QString& a){
    qDebug() << " ** now function is ----------- " << a << "---------------";
}*/


#endif // MAINWINDOW5_H
