#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "zze_mcb.h"

#include <QMainWindow>
#include<QStandardItemModel>
#include<QTableView>
#include<QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //var
    int desktop_width;
    int desktop_heigth;
    QStandardItemModel* model_right;
     QStandardItemModel* model_left;
    QTableView* view_right;
    QTableView* view_left;
    QLineEdit* le_content;
    QPushButton* pb_insertBox;
    QPushButton* pb_clear;
    int couter_boxheader=0;
    int couter=0;

    ZZE_MCB* zze_mcb;


//    QString

    //method
    void initUIElement();
    void initWidgetSize();
    void initTableView();
    void initLeftAndRightArea();
    void initConnectEvent();
    void resetCounterBox();
    void initZZE();



private:
    Ui::MainWindow *ui;

public slots:
    void onContentreturnPressed();
    void onInsertBox();
    void onClearContentText();
};

#endif // MAINWINDOW_H
