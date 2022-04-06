#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::SubWindow);
}

InputDialog::~InputDialog()
{
    delete ui;
}

QString InputDialog::key() const
{
    return ui->lineKey->text();
}

QString InputDialog::poly() const
{
    return ui->linePoly->text();
}
