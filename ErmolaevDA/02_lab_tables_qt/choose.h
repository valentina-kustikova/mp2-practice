#ifndef CHOOSE_H
#define CHOOSE_H

#include "qabstractbutton.h"
#include <QDialog>

namespace Ui {
class Choose;
}

class Choose : public QDialog
{
    Q_OBJECT

public:
    explicit Choose(QWidget *parent = nullptr);
    int on_buttonBox_clicked(QAbstractButton *button);

    ~Choose();

private slots:
    //int on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Choose *ui;
};

#endif // CHOOSE_H
