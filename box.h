#ifndef BOX_H
#define BOX_H

#include <QObject>
#include <element.h>
class Box
{
private:
    QString box_name;
    int box_num;
    QList<Element> element_list;

public:
    Box();
    void setBoxName(QString name);
    void setBoxNum(int num);
    QList<Element> getElementList();
    void addElement(Element element);
};

#endif // BOX_H
