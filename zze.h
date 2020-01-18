#ifndef ZZE_H
#define ZZE_H
#include<QObject>
#include<QRegExp>

//正则表达式
class ZZE
{
private:
    QString content;


public:
    ZZE();

    void setContent(QString content);
};

#endif // ZZE_H
