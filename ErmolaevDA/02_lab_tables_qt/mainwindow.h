#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <sstream>
#include <string>
#include "include/HashTable.h"
#include "include/SortTable.h"
#include "include/ScanTable.h"
#include "include/polinom.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; class choose; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_pushButton_4_released();

    void on_pushButton_5_released();

    void on_pushButton_7_released();

    void on_pushButton_3_released();

    void on_pushButton_6_released();

    void on_pushButton_8_released();

    void on_pushButton_9_released();

    void on_pushButton_10_released();

private:
    void updateHash();
    void updateSort();
    void updateScan();
    int S=0;
    int R=0;
    Polinom AB;
    Polinom START;
    int i=0;
    //Polinom A;
    HashTable<Polinom,std::string> HS;
    int j=0;
    //Polinom B;
    SortTable<Polinom,std::string> SR;
    int k=0;
    Polinom C;
    ScanTable<Polinom,std::string> ST;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
