#include "arrayhashtable.h"

void Test_CreateEmptyTable()
{
	cout << "/*/ Test <Create empty Table> /*/" << endl << endl;

	cout << "ArrayHash table:" << endl;

	TArrayHashTable<string, int> table(7, 3);
	cout << table << endl << endl;
};

void Test_InsertRecords()
{
	cout << "/*/ Test <Insert records> /*/" << endl << endl;

	cout << "ArrayHash table:" << endl;

	TArrayHashTable<string, int> table(8, 3);
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

void Test_InsertRecordsInFullTable()
{
	cout << "/*/ Test <Insert records> /*/" << endl << endl;

	cout << "ArrayHash table:" << endl;

	TArrayHashTable<string, int> table(8, 3);
	table.InsertRecord("First");
	table.InsertRecord("Second");
	table.InsertRecord("Third");
	table.InsertRecord("Fourth");
	table.InsertRecord("Fifth");
	table.InsertRecord("Sixth");
	table.InsertRecord("Seventh");
	table.InsertRecord("Eighth");
	cout << table << endl << endl;

	cout << "Table after inserting <Ninth>: " << endl;
	table.InsertRecord("Ninth");
	cout << table << endl << endl;
};

void Test_InsertRecordIsAlreadyInTable()
{
	cout << "/*/ Test <Insert records> /*/" << endl << endl;

	cout << "ArrayHash table:" << endl;

	TArrayHashTable<string, int> table(9, 3);
	table.InsertRecord("First");
	table.InsertRecord("Second");
	table.InsertRecord("Third");
	table.InsertRecord("Fourth");
	table.InsertRecord("Fifth");
	table.InsertRecord("Sixth");
	table.InsertRecord("Seventh");
	table.InsertRecord("Eighth");
	cout << table << endl << endl;

	cout << "Table after inserting <First>: " << endl;
	table.InsertRecord("First");
	cout << table << endl << endl;
};

void Test_FindRecords()
{
	cout << "/*/ Test <Find records> /*/" << endl << endl;

	cout << "ArrayHash table:" << endl;

	TArrayHashTable<string, int> table(8, 3);
	table.InsertRecord("First");
	table.InsertRecord("Second");
	table.InsertRecord("Third");
	table.InsertRecord("Fourth");
	table.InsertRecord("Fifth");
	table.InsertRecord("Sixth");
	table.InsertRecord("Seventh");
	table.InsertRecord("Eighth");
	cout << table << endl << endl;

	cout << "Record <First>: " << table.FindRecord("First") << endl;
	cout << "Record <Ninth>: " << table.FindRecord("Ninth") << endl;
};

void Test_RemoveRecords()
{
	cout << "/*/ Test <Remove records> /*/" << endl << endl;

	cout << "ArrayHash table:" << endl;

	TArrayHashTable<string, int> table(8, 3);
	table.InsertRecord("First");
	table.InsertRecord("Second");
	table.InsertRecord("Third");
	table.InsertRecord("Fourth");
	table.InsertRecord("Fifth");
	table.InsertRecord("Sixth");
	table.InsertRecord("Seventh");
	table.InsertRecord("Eighth");
	cout << table << endl << endl;

	cout << "Table after removing <First>: " << endl;
	table.RemoveRecord("First");
	cout << table << endl << endl;

	cout << "Table after removing <Ninth>: " << endl;
	table.RemoveRecord("Ninth");
	cout << table << endl << endl;
};

void Test_RemoveRecordsInEmptyTable()
{
	cout << "/*/ Test <Remove records in empty table> /*/" << endl << endl;

	cout << "ArrayHash table:" << endl;

	TArrayHashTable<string, int> table(8, 3);
	table.InsertRecord("First");
	cout << table << endl << endl;

	cout << "Table after removing <First>: " << endl;
	table.RemoveRecord("First");
	cout << table << endl << endl;

	cout << "Table after removing <Ninth>: " << endl;
	table.RemoveRecord("Ninth");
	cout << table << endl << endl;
};

void main()
{
	cout << "##### ARRAY HASH TREE TABLE #####" << endl << endl;

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
		Test_InsertRecordsInFullTable();
	}
	catch (const Exception& ex)
	{
		cout << "[ERROR] " << ex.what() << endl << endl;
	}

	try
	{
		Test_InsertRecordIsAlreadyInTable();
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
};