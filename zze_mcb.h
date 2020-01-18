#ifndef ZZE_MCB_H
#define ZZE_MCB_H
#include "zze.h"

class ZZE_MCB :public ZZE
{
public:
    ZZE_MCB();
    void setData(QString content);
    void decodeData();
     QString getZZEData();
     int getIndex();

};

#endif // ZZE_MCB_H
