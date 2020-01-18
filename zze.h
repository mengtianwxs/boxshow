#ifndef ZZE_H
#define ZZE_H
#include<QObject>
#include<QRegExp>

//正则表达式 此类主要用来翻译简写的信息子类可以实现补全功能
class ZZE
{


public:
    ZZE();

public:
    QString content;
    QString zze_content;
    int index;
    int num;

    virtual int getIndex()=0;
    virtual void setData(QString content)=0;
    virtual void decodeData(QString content)=0;
    virtual QString getZZEData()=0;
    virtual int getNum()=0;


};

#endif // ZZE_H
