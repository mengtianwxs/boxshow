#include "zze_mcb.h"

ZZE_MCB::ZZE_MCB()
{

}

void ZZE_MCB::setData(QString content)
{
    this->content=content;
}

void ZZE_MCB::decodeData()
{
   QString t=this->content;
   switch (t) {
   case "mc":
       this->zze_content="MCB CA 1P";
       this->index=4;
       break;
   case "mc2":
       this->zze_content="MCB CA 2P";
       this->index=4;
       break;
    case "mc3":
       this->zze_content="MCB CA 3P";
       this->index=4;
       break;
   case "mc4":
       this->zze_content="MCB CA 4P";
       this->index=4;
       break;




   }


   if(content=="mcn"){
       le_content->setText("MCB CA 1P+N");
       le_content->cursorBackward(false,6);
   }
   if(content=="mc3n"){
       le_content->setText("MCB CA 3P+N");
       le_content->cursorBackward(false,6);
   }

   if(content=="md"){
       le_content->setText("MCB DA 1P");
       le_content->cursorBackward(false,4);
   }

   if(content=="md2"){
       le_content->setText("MCB DA 2P");
       le_content->cursorBackward(false,4);
   }

   if(content=="md3"){
       le_content->setText("MCB DA 3P");
       le_content->cursorBackward(false,4);
   }
   if(content=="md4"){
       le_content->setText("MCB DA 4P");
       le_content->cursorBackward(false,4);
   }
   if(content=="mdn"){
       le_content->setText("MCB DA 1P+N");
       le_content->cursorBackward(false,6);
   }
   if(content=="md3n"){
       le_content->setText("MCB DA 3P+N");
       le_content->cursorBackward(false,6);
   }

}

int ZZE_MCB::getIndex()
{

}

QString ZZE_MCB::getData()
{
    this->decodeData();
    return this->content;
}
