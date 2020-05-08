#include "listhashtable.h"

void Test_CreateEmptyTable()
{
	cout << "/*/ Test <Create empty Table> /*/" << endl << endl;

	cout << "ListHash table:" << endl;

	TListHashTable<string, int> table(8);
	cout << table << endl << endl;
};

void Test_InsertRecords()
{
	cout << "/*/ Test <Insert records> /*/" << endl << endl;

	cout << "ListHash table:" << endl;

	TListHashTable<string, int> table(8);
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

void Test_FindRecords()
{
	cout << "/*/ Test <Find records> /*/" << endl << endl;

	cout << "ListHash table:" << endl;

	TListHashTable<string, int> table(8);
	table.InsertRecord("First");
	table.InsertRecord("Second");
	table.InsertRecord("Third");
	table.InsertRecord("Fourth");
	table.InsertRecord("Fifth");
	table.InsertRecord("Sixth");
	table.InsertRecord("Seventh");
	table.InsertRecord("Eighth");
	cout << table << endl << endl;

	cout << "Record with <Fifth>" << table.FindRecord("Fifth") << endl;
	cout << "Record with <Zero>" << table.FindRecord("Zero") << endl << endl;
};

void Test_RemoveRecords()
{
	cout << "/*/ Test <Remove records> /*/" << endl << endl;

	cout << "ListHash table:" << endl;

	TListHashTable<string, int> table(8);
	table.InsertRecord("First");
	table.InsertRecord("Second");
	table.InsertRecord("Third");
	table.InsertRecord("Fourth");
	table.InsertRecord("Fifth");
	table.InsertRecord("Sixth");
	table.InsertRecord("Seventh");
	table.InsertRecord("Eighth");
	cout << table << endl << endl;

	cout << "Table after removing record with <Fifth>" << endl;
	table.RemoveRecord("Fifth");
	cout << table << endl << endl;

	cout << "Table after removing record with <Zero>" << endl;
	table.RemoveRecord("Zero");
	cout << table << endl << endl;
};

void Test_RemoveRecordsInEmptyTable()
{
	cout << "/*/ Test <Remove records> /*/" << endl << endl;

	cout << "ListHash table:" << endl;

	TListHashTable<string, int> table(8);
	table.InsertRecord("First");
	cout << table << endl << endl;

	cout << "Table after removing record with <First>" << endl;
	table.RemoveRecord("First");
	cout << table << endl << endl;

	cout << "Table after removing record with <Zero>" << endl;
	table.RemoveRecord("Zero");
	cout << table << endl << endl;
};

void main()
{
	cout << "##### LIST HASH TREE TABLE #####" << endl << endl;

	try
	{
		Test_CreateEmptyTable();
	}
	catch (const Exception& ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}

	try
	{
		Test_InsertRecords();
	}
	catch (const Exception& ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}

	try
	{
		Test_FindRecords();
	}
	catch (const Exception& ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}

	try
	{
		Test_RemoveRecords();
	}
	catch (const Exception& ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}

	try
	{
		Test_RemoveRecordsInEmptyTable();
	}
	catch (const Exception & ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}
}