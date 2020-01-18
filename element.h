#ifndef ELEMENT_H
#define ELEMENT_H
#include<QObject>

class Element
{
public:
    Element();

public:
    int element_serialNum;
    QString element_name;
    QString element_guige;
    QString element_danwei="台";
    int element_num=1;
    double element_price;
    double element_totalPrice;
    QString element_beizhu;

};

#endif // ELEMENT_H
