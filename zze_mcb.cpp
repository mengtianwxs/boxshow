#include "zze_mcb.h"

ZZE_MCB::ZZE_MCB()
{

}

void ZZE_MCB::setData(QString content)
{
    this->content=content;


    QRegExp re_mcb("[1-9][0-9]?[0-9]?[0-9]?[0-9]?m[c|d][2|3|4|n]?n?");


    //用正则表达式判断有没有台数，如果有台数 则保存台数
    if(re_mcb.exactMatch(this->content)){
        decodeData(this->content.mid(this->content.indexOf("m"),this->content.count()-1));
        this->num=this->content.mid(0,this->content.indexOf("m")).toInt();
    }else{
         decodeData(this->content);
        this->num=1;
    }
}

void ZZE_MCB::decodeData(QString t)
{

  if(t=="mc"){
      this->zze_content="MCB CA 1P";
      this->index=4;
  }else if(t=="mc2"){

      this->zze_content="MCB CA 2P";
      this->index=4;
  }
  else if(t=="mc3"){
      this->zze_content="MCB CA 3P";
      this->index=4;}
  else if(t=="mc4"){
      this->zze_content="MCB CA 4P";
      this->index=4;
  }else if(t=="mcn")
  {
      this->zze_content="MCB CA 1P+N";
      this->index=6;
  }else if(t=="mc3n"){
      this->zze_content="MCB CA 3P+N";
      this->index=6;

  }else if(t=="md"){
      this->zze_content="MCB DA 1P";
      this->index=4;

  }else if(t=="md2"){
      this->zze_content="MCB DA 2P";
      this->index=6;

  }else if(t=="md3"){
      this->zze_content="MCB DA 3P";
      this->index=6;

  }else if(t=="md4"){
      this->zze_content="MCB DA 4P";
      this->index=6;

  }else if(t=="mdn"){
      this->zze_content="MCB DA 1P+N";
      this->index=6;

  }else if(t=="md3n"){
      this->zze_content="MCB DA 3P+N";
      this->index=6;

  }




}

QString ZZE_MCB::getZZEData()
{
    return this->zze_content;
}

int ZZE_MCB::getIndex()
{
    return this->index;
}

int ZZE_MCB::getNum()
{
    return this->num;
}


