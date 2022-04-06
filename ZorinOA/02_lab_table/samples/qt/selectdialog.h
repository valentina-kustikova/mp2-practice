#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(QWidget *parent = nullptr);
    ~SelectDialog();
    QString key() const;
    int table_choise() const;

private:
    Ui::SelectDialog *ui;
};

#endif // SELECTDIALOG_H
