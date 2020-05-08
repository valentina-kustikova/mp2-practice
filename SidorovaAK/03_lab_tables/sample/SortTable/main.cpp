#include "sorttable.h"

#include <string>

void Test_CreateTableOfRightSize()
{
    cout << "/*/ Test <Create Table of right size (10)> /*/" << endl << endl;

    cout << "Sort table:" << endl;

    TSortTable<string, int> table(10);
    cout << table << endl << endl;
};

void Test_CreateTableOfWrongSize()
{
    cout << "/*/ Test <Create Table of wrong size (-105)> /*/" << endl << endl;

    cout << "Sort table:" << endl;

    TSortTable<string, int> table(-150);
    cout << table << endl << endl;
};

void Test_InsertRecords()
{
    cout << "/*/ Test <Insert records> /*/" << endl << endl;

    cout << "Sort table:" << endl;

    TSortTable<string, int> table(6);

    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");

    cout << table << endl << endl;
};

void Test_InsertRecordsInFullTable()
{
    cout << "/*/ Test <Insert records in full table> /*/" << endl << endl;

    cout << "Sort table:" << endl;

    TSortTable<string, int> table(5);

    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");
    table.InsertRecord("Sixth");

    cout << table << endl << endl;
};

void Test_FindRecords()
{
    cout << "/*/ Test <Find records> /*/" << endl << endl;

    cout << "Sort table:" << endl;

    TSortTable<string, int> table(5);

    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");

    cout << table << endl;
    cout << "Search record with <Third>: " << table.FindRecord("Third") << endl;
    cout << "Search record with <Zero>: " << table.FindRecord("Zero") << endl << endl;
};

void Test_RemoveRecords()
{
    cout << "/*/ Test <Remove records> /*/" << endl << endl;

    cout << "Sort table:" << endl;

    TSortTable<string, int> table(5);

    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");

    cout << table << endl << endl;

    cout << "Remove record <Fourth>:" << endl;
    table.RemoveRecord("Fourth");
    cout << table << endl;

    cout << "Remove record <Seventh>:" << endl;
    table.RemoveRecord("Seventh");
    cout << table << endl;
};

void Test_RemoveRecordsInEmptyTable()
{
    cout << "/*/ Test <Remove records> /*/" << endl << endl;

    cout << "Sort table:" << endl;

    TSortTable<string, int> table(5);

    cout << table << endl;

    cout << "Remove record <Zero>:" << endl;
    table.RemoveRecord("Zero");
    cout << table << endl;
};

void Test_InsertSort()
{
    cout << "/*/ Test <Insert sort> /*/" << endl << endl;

    cout << "Scan table:" << endl;

    TScanTable<string, int> table(5);
    
    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");

    cout << table << endl;

    cout << "Sort table of Scan table:" << endl;
    
    TSortTable<string, int> sortTable(table);

    cout << sortTable << endl;
};

void Test_MergeSort()
{
    cout << "/*/ Test <Merge sort> /*/" << endl << endl;

    cout << "Scan table:" << endl;

    TScanTable<string, int> table(10);

    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");
    table.InsertRecord("Sixth");
    table.InsertRecord("Seventh");
    table.InsertRecord("Eighth");

    cout << table << endl;

    cout << "Sort table of Scan table:" << endl;

    TSortTable<string, int> sortTable(table, TSortType::MERGE_SORT);

    cout << sortTable << endl;
};

void Test_QuickSort()
{
    cout << "/*/ Test <Quick sort> /*/" << endl << endl;

    cout << "Scan table:" << endl;

    TScanTable<string, int> table(10);

    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");
    table.InsertRecord("Sixth");
    table.InsertRecord("Seventh");
    table.InsertRecord("Eighth");

    cout << table << endl;

    cout << "Sort table of Scan table:" << endl;

    TSortTable<string, int> sortTable(table, TSortType::QUICK_SORT);

    cout << sortTable << endl;
};

void main()
{
    cout << "##### SORT TABLE #####" << endl << endl;

    try
    {
        Test_CreateTableOfRightSize();
    }
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }

    try
    {
        Test_CreateTableOfWrongSize();
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
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }

    try
    {
        Test_InsertSort();
    }
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }

    try
    {
        Test_MergeSort();
    }
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }

    try
    {
        Test_QuickSort();
    }
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }
};