#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
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
	tmp << H;
	ui->tableHash->setText(QString::fromStdString(tmp.str()));
}

void MainWindow::updateSort()
{
	std::stringstream tmp;
	tmp << S;
	ui->tableSort->setText(QString::fromStdString(tmp.str()));
}

void MainWindow::updateScan()
{
	std::stringstream tmp;
	tmp << T;
	ui->tableScan->setText(QString::fromStdString(tmp.str()));
}

void MainWindow::updatePolyStr()
{
	poly1_str = ui->line1Poly->text().toStdString();
	poly2_str = ui->line2Poly->text().toStdString();
}

void MainWindow::updateRes(const Polinom& poly)
{
	std::stringstream tmp;
	tmp << poly;
	res_str = tmp.str();
	ui->lineResPoly->setText(QString::fromStdString(res_str));
}

void MainWindow::on_pushButton_SUB_clicked()
{
	try {
		updatePolyStr();
		Polinom res = Polinom(poly1_str) - Polinom(poly2_str);
		updateRes(res);
	}
	catch (const std::exception& ex) {
		statusBar()->showMessage(ex.what(), 3000);
	}
}

void MainWindow::on_pushButton_ADD_clicked()
{
	try {
		updatePolyStr();
		Polinom res = Polinom(poly1_str) + Polinom(poly2_str);
		updateRes(res);
	}
	catch (const std::exception& ex) {
		statusBar()->showMessage(ex.what(), 3000);
	}
}

void MainWindow::on_pushButton_MULT_clicked()
{
	try {
		updatePolyStr();
		Polinom res = Polinom(poly1_str) * Polinom(poly2_str);
		updateRes(res);
	}
	catch (const std::exception& ex) {
		statusBar()->showMessage(ex.what(), 3000);
	}
}

void MainWindow::on_lineKey_textChanged(const QString& arg1)
{
	key = arg1.toStdString();
}

void MainWindow::on_pushButton_toHash_clicked()
{
	H.Insert(key, res_str);
	updateHash();
}

void MainWindow::on_pushButton_toSort_clicked()
{
	S.Insert(key, res_str);
	updateSort();
}

void MainWindow::on_pushButton_toScan_clicked()
{
	T.Insert(key, res_str);
	updateScan();
}

void MainWindow::on_pushButton_Hash_add_clicked()
{
	InputDialog* pID = new InputDialog;
	if (pID->exec() == QDialog::Accepted)
	{
		try {
			bool tmp = H.Insert(pID->key().toStdString(), pID->poly().toStdString());
			if (!tmp)
				QMessageBox::warning(this, "Warning!", "Polynomial with this key already exists in the HashTable, insertion is not possible.");
		}
		catch (const std::exception& ex) {
			statusBar()->showMessage(ex.what(), 3000);
		}
		updateHash();
	}
	delete pID;
}

void MainWindow::on_pushButton_Hash_del_clicked()
{
	DeleteDialog* pDD = new DeleteDialog;
	if (pDD->exec() == QDialog::Accepted)
	{
		if (!(H.Delete(pDD->key().toStdString())))
			QMessageBox::warning(this, "Warning!", "Polynomial with such key is not find in HashTable, there is nothing to delete.");
		updateHash();
	}
	delete pDD;
}

void MainWindow::on_pushButton_Hash_clear_clicked()
{
	H.Clear();
	updateHash();
}

void MainWindow::on_pushButton_Sort_add_clicked()
{
	InputDialog* pID = new InputDialog;
	if (pID->exec() == QDialog::Accepted)
	{
		try {
			bool tmp = S.Insert(pID->key().toStdString(), pID->poly().toStdString());
			if (!tmp)
				QMessageBox::warning(this, "Warning!", "Polynomial with this key already exists in the SortTable, insertion is not possible.");
		}
		catch (const std::exception& ex) {
			statusBar()->showMessage(ex.what(), 3000);
		}
		updateSort();
	}
	delete pID;
}

void MainWindow::on_pushButton_Sort_del_clicked()
{
	DeleteDialog* pDD = new DeleteDialog;
	if (pDD->exec() == QDialog::Accepted)
	{
		if (!(S.Delete(pDD->key().toStdString())))
			QMessageBox::warning(this, "Warning!", "Polynomial with such key is not find in SortTable, there is nothing to delete.");
		updateSort();
	}
	delete pDD;
}

void MainWindow::on_pushButton_Sort_clear_clicked()
{
	S.Clear();
	updateSort();
}

void MainWindow::on_pushButton_Scan_add_clicked()
{
	InputDialog* pID = new InputDialog;
	if (pID->exec() == QDialog::Accepted)
	{
		try {
			bool tmp = T.Insert(pID->key().toStdString(), pID->poly().toStdString());
			if (!tmp)
				QMessageBox::warning(this, "Warning!", "Polynomial with this key already exists in the ScanTable, insertion is not possible.");
		}
		catch (const std::exception& ex) {
			statusBar()->showMessage(ex.what(), 3000);
		}
		updateScan();
	}
	delete pID;
}

void MainWindow::on_pushButton_Scan_del_clicked()
{
	DeleteDialog* pDD = new DeleteDialog;
	if (pDD->exec() == QDialog::Accepted)
	{
		if (!(T.Delete(pDD->key().toStdString())))
			QMessageBox::warning(this, "Warning!", "Polynomial with such key is not find in ScanTable, there is nothing to delete.");
		updateScan();
	}
	delete pDD;
}

void MainWindow::on_pushButton_Scan_clear_clicked()
{
	T.Clear();
	updateScan();
}

void MainWindow::on_pushButton_toAll_clicked()
{
	H.Insert(key, Polinom(res_str));
	S.Insert(key, Polinom(res_str));
	T.Insert(key, Polinom(res_str));
	updateHash();
	updateSort();
	updateScan();
}

void MainWindow::on_select1Poly_clicked()
{
	SelectDialog* pSD = new SelectDialog;
	if (pSD->exec() == QDialog::Accepted)
	{
		std::string tmp_key = pSD->key().toStdString();
		int table_choise = pSD->table_choise();
		Polinom* tmp_poly;
		if (table_choise == 1)
			tmp_poly = H.Find(tmp_key);
		else if (table_choise == 2)
			tmp_poly = S.Find(tmp_key);
		else
			tmp_poly = T.Find(tmp_key);

		if (tmp_poly != nullptr)
		{
			std::stringstream tmp;
			tmp << *tmp_poly;
			poly1_str = tmp.str();
			ui->line1Poly->setText(QString::fromStdString(poly1_str));
		}
		else
			QMessageBox::warning(this, "Warning!", "Polynomial with such key is not find.");
	}
	delete pSD;
}

void MainWindow::on_select2Poly_clicked()
{
	SelectDialog* pSD = new SelectDialog;
	if (pSD->exec() == QDialog::Accepted)
	{
		std::string tmp_key = pSD->key().toStdString();
		int table_choise = pSD->table_choise();
		Polinom* tmp_poly;
		if (table_choise == 1)
			tmp_poly = H.Find(tmp_key);
		else if (table_choise == 2)
			tmp_poly = S.Find(tmp_key);
		else
			tmp_poly = T.Find(tmp_key);

		if (tmp_poly != nullptr)
		{
			std::stringstream tmp;
			tmp << *tmp_poly;
			poly2_str = tmp.str();
			ui->line2Poly->setText(QString::fromStdString(poly2_str));
		}
		else
			QMessageBox::warning(this, "Warning!", "Polynomial with such key is not find.");
	}
	delete pSD;
}

void MainWindow::on_pushButton_calculate_clicked()
{
	try {
		poly1_str = ui->line1Poly->text().toStdString();
		double x = ui->lineX->text().toDouble();
		double y = ui->lineY->text().toDouble();
		double z = ui->lineZ->text().toDouble();
		double value = Polinom(poly1_str)(x, y, z);
		ui->lineValue->setText(QString::number(value));
	}
	catch (const std::exception& ex) {
		statusBar()->showMessage(ex.what());
	}
}

void MainWindow::on_addToAll_clicked()
{
	InputDialog* pID = new InputDialog;
	if (pID->exec() == QDialog::Accepted)
	{
		try {
			std::string _key = pID->key().toStdString();
			Polinom _poly(pID->poly().toStdString());
			bool tmp1 = H.Insert(_key, _poly);
			bool tmp2 = T.Insert(_key, _poly);
			bool tmp3 = S.Insert(_key, _poly);
			if (!tmp1)
				QMessageBox::warning(this, "Warning!", "Polynomial with this key already exists in the HashTable, insertion is not possible.");
			if (!tmp2)
				QMessageBox::warning(this, "Warning!", "Polynomial with this key already exists in the ScanTable, insertion is not possible.");
			if (!tmp3)
				QMessageBox::warning(this, "Warning!", "Polynomial with this key already exists in the SortTable, insertion is not possible.");
		}
		catch (const std::exception& ex) {
			statusBar()->showMessage(ex.what(), 3000);
		}
		updateHash();
		updateSort();
		updateScan();
	}
	delete pID;
}

void MainWindow::on_delFromAll_clicked()
{
	DeleteDialog* pDD = new DeleteDialog;
	if (pDD->exec() == QDialog::Accepted)
	{
		std::string _key = pDD->key().toStdString();
		bool bH = H.Delete(_key);
		bool bT = T.Delete(_key);
		bool bS = S.Delete(_key);
		if (!bH) QMessageBox::warning(this, "Warning!", "Polynomial with such key is not found in the HashTable, there is nothing to delete.");
		if (!bT) QMessageBox::warning(this, "Warning!", "Polynomial with such key is not found in the ScanTable, there is nothing to delete.");
		if (!bS) QMessageBox::warning(this, "Warning!", "Polynomial with such key is not found in the SortTable, there is nothing to delete.");
		updateHash();
		updateSort();
		updateScan();
	}
	delete pDD;
}

void MainWindow::on_ClearAll_clicked()
{
	H.Clear();
	S.Clear();
	T.Clear();
	updateHash();
	updateSort();
	updateScan();
}