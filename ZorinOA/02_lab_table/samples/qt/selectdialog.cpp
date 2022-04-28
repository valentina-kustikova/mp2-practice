#include "selectdialog.h"
#include "ui_selectdialog.h"

SelectDialog::SelectDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::SelectDialog)
{
	ui->setupUi(this);
	setWindowFlags(Qt::SubWindow);
}

SelectDialog::~SelectDialog()
{
	delete ui;
}

QString SelectDialog::key() const
{
	return ui->lineKey->text();
}

int SelectDialog::table_choise() const
{
	if (ui->radioButtonHash->isChecked())
		return 1;
	else if (ui->radioButtonSort->isChecked())
		return 2;
	else
		return 3;
}