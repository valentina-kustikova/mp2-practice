#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::DeleteDialog)
{
	ui->setupUi(this);
	setWindowFlags(Qt::SubWindow);
}

DeleteDialog::~DeleteDialog()
{
	delete ui;
}

QString DeleteDialog::key() const
{
	return ui->lineKey->text();
}