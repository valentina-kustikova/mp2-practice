#include "binarytreetable.h"

void Test_CreateEmptyTable()
{
    cout << "/*/ Test <Create empty Table> /*/" << endl << endl;

    cout << "BinaryTree table:" << endl;

    TBinaryTreeTable<string, int> table;
    cout << table << endl << endl;
};

void Test_InsertRecords()
{
    cout << "/*/ Test <Insert records> /*/" << endl << endl;

    cout << "BinaryTree table:" << endl;

    TBinaryTreeTable<string, int> table;
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

void Test_FindRecord()
{
    cout << "/*/ Test <Find record> /*/" << endl << endl;

    cout << "BinaryTree table:" << endl;

    TBinaryTreeTable<string, int> table;
    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");
    table.InsertRecord("Sixth");
    table.InsertRecord("Seventh");
    table.InsertRecord("Eighth");
    cout << table << endl << endl;

    cout << "Record <Sixth>: " << table.FindRecord("Sixth") << endl;
    cout << "Record <Zero>: " << table.FindRecord("Zero") << endl << endl;
};

void Test_SearchMinAndMaxKeys()
{
    cout << "/*/ Test <Search Min and Max keys> /*/" << endl << endl;

    cout << "BinaryTree table:" << endl;

    TBinaryTreeTable<string, int> table;
    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");
    table.InsertRecord("Sixth");
    table.InsertRecord("Seventh");
    table.InsertRecord("Eighth");
    cout << table << endl << endl;

    cout << "Record with Min key: " << *table.SearchMinKey(table.GetRoot()) << endl;
    cout << "Record with Max key: " << *table.SearchMaxKey(table.GetRoot()) << endl << endl;
};

void Test_SearchNextAndPrevRecords()
{
    cout << "/*/ Test <Search Next and Previous records for root> /*/" << endl << endl;

    cout << "BinaryTree table:" << endl;

    TBinaryTreeTable<string, int> table;
    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");
    table.InsertRecord("Sixth");
    table.InsertRecord("Seventh");
    table.InsertRecord("Eighth");
    cout << table << endl << endl;

    cout << "Next record for root: " << *table.SearchNext(table.GetRoot()) << endl;
    cout << "Previous record for root: " << *table.SearchPrev(table.GetRoot()) << endl << endl;
};

void Test_RemoveRecords()
{
    cout << "/*/ Test <Remove Records> /*/" << endl << endl;

    cout << "BinaryTree table:" << endl;

    TBinaryTreeTable<string, int> table;
    table.InsertRecord("First");
    table.InsertRecord("Second");
    table.InsertRecord("Third");
    table.InsertRecord("Fourth");
    table.InsertRecord("Fifth");
    table.InsertRecord("Sixth");
    table.InsertRecord("Seventh");
    table.InsertRecord("Eighth");
    cout << table << endl << endl;

    cout << "BinaryTree table after removing <Third>: " << endl;
    table.RemoveRecord("Third");
    cout << table << endl << endl;

    cout << "BinaryTree table after removing root: " << endl;
    table.RemoveRecord(table.GetRoot()->GetKey());
    cout << table << endl << endl;
};

void Test_RemoveRecordsInEmptyTable()
{
    cout << "/*/ Test <Remove Records in empty table> /*/" << endl << endl;

    cout << "BinaryTree table:" << endl;

    TBinaryTreeTable<string, int> table;
    table.InsertRecord("First");
    cout << table << endl << endl;

    cout << "BinaryTree table after removing <First>: " << endl;
    table.RemoveRecord("First");
    cout << table << endl << endl;

    cout << "BinaryTree table after removing <Zero>: " << endl;
    table.RemoveRecord("Zero");
    cout << table << endl << endl;
};

void main()
{
    cout << "##### BINARY TREE TABLE #####" << endl << endl;

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
        Test_FindRecord();
    }
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }

    try
    {
        Test_SearchMinAndMaxKeys();
    }
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }

    try
    {
        Test_SearchNextAndPrevRecords();
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
}

