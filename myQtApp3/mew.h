#ifndef MEW_H
#define MEW_H

#include <QObject>

class mew : public QObject
{
    Q_OBJECT
public:
    explicit mew(QObject *parent = nullptr);

// signals:
// me带gf去吃饭，只需要处理信号
// 槽函数
public slots:
    void eat();
};

#endif // MEW_H
