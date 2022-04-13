#include "mainwindow.h"
#include <string>
#include "choose.h"
#include "ui_choose.h"
#include "lab_02_autogen/include/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateHash()
{
    std::stringstream tmp;
    tmp << HS;
    ui->textBrowser_2->setText(QString::fromStdString(tmp.str()));
}
void MainWindow::updateSort()
{
    std::stringstream tmp;
    tmp << SR;
    ui->textBrowser_3->setText(QString::fromStdString(tmp.str()));
}
void MainWindow::updateScan()
{
    std::stringstream tmp;
    tmp << ST;
    ui->textBrowser_4->setText(QString::fromStdString(tmp.str()));
}

void MainWindow::on_pushButton_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    Polinom A;
    if((ui->comboBox->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома A в выбранную таблицу...");
    A.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    HS.Insert(A,strig2.toStdString());
    updateHash();
    }
    else{
        i++;
        HS.Insert(A,to_string(i));
        updateHash();
    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }

    if((ui->comboBox->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома A в выбранную таблицу...");
    A.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    SR.Insert(A,strig2.toStdString());
    updateSort();
    }
    else{
        j++;
        SR.Insert(A,to_string(j));
        updateSort();
    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }


    if((ui->comboBox->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома A в выбранную таблицу...");
    A.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    ST.Insert(A,strig2.toStdString());
    updateScan();
    }
    else{
        k++;
        ST.Insert(A,to_string(k));
        updateScan();
    }
     }
     else{
         ui->textBrowser->append("Полином A пустой");
     }

    }
}


void MainWindow::on_pushButton_2_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    Polinom B;
    if((ui->comboBox_2->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранную таблицу...");
    B.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    HS.Insert(B,strig2.toStdString());
    updateHash();
    }
    else{
        i++;
        HS.Insert(B,to_string(i));
        updateHash();
    }
     }
     else{
         ui->textBrowser->append("Полином B пустой");
     }

    }

    if((ui->comboBox_2->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранную таблицу...");
    B.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    SR.Insert(B,strig2.toStdString());
    updateSort();
    }
    else{
        j++;
        SR.Insert(B,to_string(j));
        updateSort();
    }
     }
     else{
         ui->textBrowser->append("Полином B пустой");
     }

    }


    if((ui->comboBox_2->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома B в выбранную таблицу...");
    B.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    ST.Insert(B,strig2.toStdString());
    updateScan();
    }
    else{
        k++;
        ST.Insert(B,to_string(k));
        updateScan();
    }
     }
     else{
         ui->textBrowser->append("Полином B пустой");
     }

    }
}


void MainWindow::on_pushButton_4_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;

    if((ui->comboBox->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома A из выбранной таблицы...");

    if (strig2!=nullptr){
    HS.Delete(strig2.toStdString());
    updateHash();
    }
    else{
         ui->textBrowser->append("Впишите в ключ А, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином А, который хотите удалить");
     }
    }

    if((ui->comboBox->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома A из выбранной таблицы...");

    if (strig2!=nullptr){
    SR.Delete(strig2.toStdString());
    updateSort();
    }
    else{
         ui->textBrowser->append("Впишите в ключ А, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином А, который хотите удалить");
     }
    }

    if((ui->comboBox->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома A");
     QString strig = ui->textEdit->toPlainText().trimmed();
     QString strig2 = ui->textEdit_4->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома A из выбранной таблицы...");

    if (strig2!=nullptr){
    ST.Delete(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ А, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином А, который хотите удалить");
     }

    }
}


void MainWindow::on_pushButton_5_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    if((ui->comboBox_2->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома B из выбранной таблицы...");

    if (strig2!=nullptr){
    HS.Delete(strig2.toStdString());
    updateHash();
    }
    else{
         ui->textBrowser->append("Впишите в ключ B, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином B, который хотите удалить");
     }
    }

    if((ui->comboBox_2->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома B из выбранной таблицы...");

    if (strig2!=nullptr){
    SR.Delete(strig2.toStdString());
    updateSort();
    }
    else{
         ui->textBrowser->append("Впишите в ключ B, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином B, который хотите удалить");
     }
    }

    if((ui->comboBox_2->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома B");
     QString strig = ui->textEdit_2->toPlainText().trimmed();
     QString strig2 = ui->textEdit_5->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома B из выбранной таблицы...");

    if (strig2!=nullptr){
    ST.Delete(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ B, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином B, который хотите удалить");
     }

    }
}


void MainWindow::on_pushButton_7_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
Polinom A;
Polinom B;
AB*=0;
std::stringstream tmp;
QString stA = ui->textEdit->toPlainText().trimmed();
QString stB = ui->textEdit_2->toPlainText().trimmed();

if ((stA==nullptr)||(stB==nullptr)){
    if (stA==nullptr) ui->textBrowser->append("Полином A пуст,нечего считать");
    if (stB==nullptr) ui->textBrowser->append("Полином B пуст,нечего считать");
}
else {
    A.str_to_poly(stA.toStdString());
    B.str_to_poly(stB.toStdString());

if((ui->comboBox_3->currentText())== "A +B"){
    AB=A+B;
    ui->textBrowser->append("Расчёт суммы A+B");
    tmp << AB;
    ui->textEdit_3->setText(QString::fromStdString(tmp.str()));
}
if((ui->comboBox_3->currentText())== "A - B"){
    AB=A-B;
    ui->textBrowser->append("Расчёт разности A-B");
    tmp << AB;
    ui->textEdit_3->setText(QString::fromStdString(tmp.str()));
}
if((ui->comboBox_3->currentText())== "A * B"){
    AB=A*B;
    ui->textBrowser->append("Расчёт произведения A*B");
    tmp << AB;
    ui->textEdit_3->setText(QString::fromStdString(tmp.str()));
}

}

}


void MainWindow::on_pushButton_3_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    if((ui->comboBox_4->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома AB в выбранную таблицу...");
    //AB.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    HS.Insert(AB,strig2.toStdString());
    updateHash();
    }
    else{
        i++;
        HS.Insert(AB,to_string(i));
        updateHash();
    }
     }
     else{
         ui->textBrowser->append("Полином AB пустой, сосчитайте его");
     }

    }

    if((ui->comboBox_4->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома AB в выбранную таблицу...");
    //AB.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    SR.Insert(AB,strig2.toStdString());
    updateSort();
    }
    else{
        j++;
        SR.Insert(AB,to_string(j));
        updateSort();
    }
     }
     else{
          ui->textBrowser->append("Полином AB пустой, сосчитайте его");
     }

    }


    if((ui->comboBox_4->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Помещение полинома AB в выбранную таблицу...");
    //AB.str_to_poly(strig.toStdString());
    if (strig2!=nullptr){
    ST.Insert(AB,strig2.toStdString());
    updateScan();
    }
    else{
        k++;
        ST.Insert(AB,to_string(k));
        updateScan();
    }
     }
     else{
          ui->textBrowser->append("Полином AB пустой, сосчитайте его");
     }

    }

}


void MainWindow::on_pushButton_6_released()
{
    ui->textBrowser->append("Действие №"+QString::number(S)+"_____________________________________________");
    S++;
    if((ui->comboBox_4->currentText())== "Hash Table")
    {
    ui->textBrowser->append("Выбрана Hash таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома AB из выбранной таблицы...");

    if (strig2!=nullptr){
    HS.Delete(strig2.toStdString());
    updateHash();
    }
    else{
         ui->textBrowser->append("Впишите в ключ AB, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином AB, который хотите удалить");
     }
    }

    if((ui->comboBox_4->currentText())== "Sort Table")
    {
    ui->textBrowser->append("Выбрана Sort таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома AB из выбранной таблицы...");

    if (strig2!=nullptr){
    SR.Delete(strig2.toStdString());
    updateSort();
    }
    else{
         ui->textBrowser->append("Впишите в ключ AB, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином AB, который хотите удалить");
     }
    }

    if((ui->comboBox_4->currentText())== "Scan Table")
    {
    ui->textBrowser->append("Выбрана Scan таблица для полинома AB");
     QString strig = ui->textEdit_3->toPlainText().trimmed();
     QString strig2 = ui->textEdit_6->toPlainText().trimmed();
     if (strig!=nullptr)
     {
    ui->textBrowser->append("Удаление полинома AB из выбранной таблицы...");

    if (strig2!=nullptr){
    ST.Delete(strig2.toStdString());
    updateScan();
    }
    else{
         ui->textBrowser->append("Впишите в ключ AB, который хотите удалить");
    }
     }
     else{
         ui->textBrowser->append("Впишите в полином AB, который хотите удалить");
     }

    }
}


void MainWindow::on_pushButton_8_released()
{
    ui->textBrowser_6->append("Действие №"+QString::number(R)+"_____________________________________________");
    R++;
    Polinom RAS;
    QString stx = ui->textEdit_7->toPlainText().trimmed();
    QString sty = ui->textEdit_8->toPlainText().trimmed();
    QString stz = ui->textEdit_9->toPlainText().trimmed();
    QString stPol = ui->textEdit_10->toPlainText().trimmed();
    if ((stx==nullptr)||(sty==nullptr)||(stz==nullptr)||(stPol==nullptr))  ui->textBrowser_6->append("Нехватка данных для расчёта полинома");
    else{
    ui->textBrowser_6->append("Расчёт полинома...");
    RAS.str_to_poly(stPol.toStdString());
    RAS(stx.toDouble(),sty.toDouble(),stz.toDouble());
    ui->textBrowser_5->setText(QString::number(RAS(stx.toDouble(),sty.toDouble(),stz.toDouble()),'f',10));
    ui->textBrowser_6->append("Готово!");
    }
}


void MainWindow::on_pushButton_9_released()
{
    Choose wind;
        wind.setModal(true);
        wind.exec();
}


void MainWindow::on_pushButton_10_released()
{
    Choose wind;
        wind.setModal(true);
        wind.exec();
}

