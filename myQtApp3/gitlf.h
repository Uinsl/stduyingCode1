#ifndef GITLF_H
#define GITLF_H

//gf说饿了，me带她吃饭
#include <QObject>

class GitlF : public QObject
{
    Q_OBJECT
public:
    explicit GitlF(QObject *parent = nullptr);

signals: //一般会自动添加
    void hungry();//只需要声明,不需要实现
};

#endif // GITLF_H
