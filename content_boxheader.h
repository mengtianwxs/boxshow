#ifndef CONTENT_BOXHEADER_H
#define CONTENT_BOXHEADER_H
#include<QObject>

//用来获取配电箱头部信息数据
class Content_BoxHeader
{
public:
    Content_BoxHeader();

    void setData(QString data);
    QString getBianhao();
    int getTaishu();
private:

    QString bianhao;
    int taishu;
    QString txt;
    int space_index;
};

#endif // CONTENT_BOXHEADER_H
