#ifndef CONTENT_MCB_H
#define CONTENT_MCB_H
#include<QObject>

class Content_MCB
{
public:
    Content_MCB();
    void setData(QString data);
    QString getGuiGeXingHao();
    int getNum();
private:

    QString guigexinghao;
    int num;
    QString txt;
    int space_index;
};

#endif // CONTENT_MCB_H
