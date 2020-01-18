#include "content_boxheader.h"

Content_BoxHeader::Content_BoxHeader()
{

}

void Content_BoxHeader::setData(QString data)
{
    this->txt=data;
    space_index=txt.indexOf(" ",2);
}

QString Content_BoxHeader::getBianhao()
{
    return this->txt.mid(0,space_index);
}

int Content_BoxHeader::getTaishu()
{
    return this->txt.mid(space_index,txt.count()-1).toInt();
}
