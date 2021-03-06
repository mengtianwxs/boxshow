#include "content_boxheader.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QDesktopWidget>
#include<QGroupBox>
#include<QRegExp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUIElement();
    initWidgetSize();
    initTableView();
    initLeftAndRightArea();
    initConnectEvent();
    initZZE();







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUIElement()
{

    le_content=ui->le_content;
    pb_insertBox=ui->pb_insertBox;
    pb_clear=ui->pb_clear;

}

void MainWindow::initWidgetSize()
{
    QDesktopWidget* desktop=QApplication::desktop();
    desktop_width=desktop->screen()->width();
    desktop_heigth=desktop->screen()->height();
    int margindistance=60;
    this->setFixedSize(QSize(desktop_width,desktop_heigth-margindistance));

    this->move(0,desktop_heigth/2-(desktop_heigth-margindistance)/2-margindistance/2);

    this->setWindowTitle("配电箱成套预算V1.0");
}

void MainWindow::initTableView()
{
    view_right=ui->tv_list;

    model_right=new QStandardItemModel();
    model_right->setColumnCount(8);
    model_right->setHeaderData(0,Qt::Horizontal,"柜号");
    model_right->setHeaderData(1,Qt::Horizontal,"序号");
    model_right->setHeaderData(2,Qt::Horizontal,"元件名称");
    model_right->setHeaderData(3,Qt::Horizontal,"型号规格");
    model_right->setHeaderData(4,Qt::Horizontal,"单位");
    model_right->setHeaderData(5,Qt::Horizontal,"数量");
    model_right->setHeaderData(6,Qt::Horizontal,"台数");
    model_right->setHeaderData(7,Qt::Horizontal,"备注");
//    model->setItem(0,0,new QStandardItem("AL1"));
//    model->setItem(0,1,new QStandardItem("微型断路器"));
//    model->setItem(0,2,new QStandardItem("MCB C20A 2P"));
//    model->setItem(0,3,new QStandardItem("aa3"));
    view_right->setModel(model_right);
    view_left=ui->tv_box;

     model_left=new QStandardItemModel();
     model_left->setColumnCount(3);
     model_left->setHeaderData(0,Qt::Horizontal,"名称");
     model_left->setHeaderData(1,Qt::Horizontal,"规格型号");
     model_left->setHeaderData(2,Qt::Horizontal,"数量");

//     for(int i=0;i<1000;i++){
//         model_left->setItem(i,0,new QStandardItem(QString::number(i)));
//     }

    view_left->setModel(model_left);

    qDebug()<<model_right->data(model_right->index(0,1)).toString();
}

void MainWindow::initLeftAndRightArea()
{
   QGroupBox* box_left=ui->box_left;
   box_left->setFixedWidth(600);
}

void MainWindow::initConnectEvent()
{

    //用来快速翻译成其他对应
    connect(le_content,SIGNAL(returnPressed()),this,SLOT(onContentreturnPressed()));
    connect(pb_insertBox,SIGNAL(clicked()),this,SLOT(onInsertBox()));
    connect(pb_clear,SIGNAL(clicked()),this,SLOT(onClearContentText()));

}

void MainWindow::resetCounterBox()
{
    couter_boxheader=0;

}

void MainWindow::initZZE()
{
    zze_mcb=new ZZE_MCB();


}

void MainWindow::onContentreturnPressed()
{
    QString content=le_content->text();


    //关于mcb的正则表达式
    QRegExp re_mcb("([1-9][0-9]?[0-9]?[0-9]?[0-9]?)?m[c|d][2|3|4|n]?n?");
    if(re_mcb.exactMatch(content)){
qDebug()<<"this is zze";
        zze_mcb->setData(content);
        le_content->setText(zze_mcb->getZZEData());
        le_content->cursorBackward(false,zze_mcb->getIndex());


qDebug()<<zze_mcb->getZZEData()<<"num"<<zze_mcb->getNum();

    }




}

void MainWindow::onInsertBox()
{
    QString content=le_content->text();
    //配电箱编号的正则表达式
//    QRegExp re_boxbianhao("\\S*\\s[1-9]([0-9]*)?");
//    if(re_boxbianhao.exactMatch(content)){}

    //插入按2种模式进行第一种为mode_header，第二种为mode_item
    QRegExp re_mode_header("\\s\\S*\\s?[1-9]?[0-9]?[0-9]?[0-9]?[0-9]?[0-9]?");//判断配电箱的台数，如果后面没有数字默认为1台，如果有数字取后面的数字为台数
    if(re_mode_header.exactMatch(content) and content!=""){
        qDebug()<<"this herer";

     Content_BoxHeader* box_header=new Content_BoxHeader();
     box_header->setData(content);
     model_left->setItem(couter,0,new QStandardItem("箱体编号"));
     model_left->setItem(couter,1,new QStandardItem(box_header->getBianhao().toUpper()));
     if(box_header->getTaishu()==0){

        model_left->setItem(couter,2,new QStandardItem(QString::number(1)));
     }else {

         model_left->setItem(couter,2,new QStandardItem(QString::number(box_header->getTaishu())));
}

     couter_boxheader=couter_boxheader+1;




    }

    //mode_item
    QRegExp re_mcb_all("MCB [C|D][1-9][0-9]?[0-9]?A [1|2|3|4]P(\\+N)?");
 couter=couter+1;
 qDebug()<<content<<"///";
    if(re_mcb_all.exactMatch(content)){
        qDebug()<<"pipei";

        model_left->setItem(couter,0,new QStandardItem("微型断路器"));
        model_left->setItem(couter,1,new QStandardItem(content));
        model_left->setItem(couter,2,new QStandardItem(QString::number(zze_mcb->getNum())));


    }





}

void MainWindow::onClearContentText()
{
    this->le_content->clear();
    this->le_content->setFocus();

}
