#ifndef ZZE_H
#define ZZE_H
#include<QObject>
#include<QRegExp>

//正则表达式 此类主要用来翻译简写的信息子类可以实现补全功能
class ZZE
{


public:
    ZZE();
    QString content;
    QString zze_content;
    int index;
    virtual void getIndex();
    virtual void setData(QString content);
    virtual void decodeData();
    virtual QString getZZEData();
};

#endif // ZZE_H
