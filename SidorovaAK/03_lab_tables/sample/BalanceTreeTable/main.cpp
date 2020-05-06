#include "balancetreetable.h"

void Test_CreateEmptyTable()
{
	cout << "/*/ Test <Create empty Table> /*/" << endl << endl;

	cout << "BalanceTree table:" << endl;

	TBalanceTreeTable<string, int> table;
	cout << table << endl << endl;
};

void Test_InsertRecords()
{
	cout << "/*/ Test <Insert records> /*/" << endl << endl;

	cout << "BalanceTree table:" << endl;

	TBalanceTreeTable<string, int> table;
	table.InsertRecord("First");
	table.InsertRecord("Second");
	table.InsertRecord("Third");
	table.InsertRecord("Fourth");
	table.InsertRecord("Fifth");
	table.InsertRecord("Sixth");
	table.InsertRecord("Seventh");
	table.InsertRecord("Eighth");
	cout << table << endl << endl;
};

void main()
{
	cout << "##### BALANCE TREE TABLE #####" << endl << endl;

	try
	{
		Test_CreateEmptyTable();
	}
	catch (const Exception & ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}

	try
	{
		Test_InsertRecords();
	}
	catch (const Exception & ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}
}