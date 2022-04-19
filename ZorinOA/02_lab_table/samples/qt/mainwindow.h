#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "HashTable.h"
#include "SortTable.h"
#include "polinom.h"
#include <sstream>
#include <string>
#include <QMainWindow>
#include <QStatusBar>
#include "inputdialog.h"
#include "deletedialog.h"
#include "selectdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ADD_clicked();

    void on_pushButton_SUB_clicked();

    void on_pushButton_MULT_clicked();

    void on_pushButton_toHash_clicked();

    void on_lineKey_textChanged(const QString &arg1);

    void on_pushButton_toSort_clicked();

    void on_pushButton_toScan_clicked();

    void on_pushButton_Hash_add_clicked();

    void on_pushButton_Hash_del_clicked();

    void on_pushButton_Hash_clear_clicked();

    void on_pushButton_Sort_add_clicked();

    void on_pushButton_Sort_del_clicked();

    void on_pushButton_Sort_clear_clicked();

    void on_pushButton_Scan_add_clicked();

    void on_pushButton_Scan_del_clicked();

    void on_pushButton_Scan_clear_clicked();

    void on_pushButton_toAll_clicked();

    void on_select1Poly_clicked();

    void on_select2Poly_clicked();

    void on_pushButton_calculate_clicked();

    void on_addToAll_clicked();

    void on_delFromAll_clicked();

    void on_ClearAll_clicked();

private:
    HashTable<std::string, Polinom> H;
    SortTable<std::string, Polinom> S;
    ScanTable<std::string, Polinom> T;
    std::string poly1_str;
    std::string poly2_str;
    std::string res_str;
    std::string key;

    void updateHash();
    void updateSort();
    void updateScan();
    void updatePolyStr();
    void updateRes(const Polinom& poly);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
