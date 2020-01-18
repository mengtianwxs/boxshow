#include "box.h"

Box::Box()
{

}

void Box::setBoxName(QString name)
{
    this->box_name=name;

}

void Box::setBoxNum(int num)
{
    this->box_num=num;
}

QList<Element> Box::getElementList()
{
    return this->element_list;
}


void Box::addElement(Element element)
{
    element_list.append(element);

}
