#include "arrayhashtable.h"
#include "balancetreetable.h"
#include "binarytreetable.h"
#include "listhashtable.h"
#include "scantable.h"
#include "sorttable.h"
#include "table.h"

#include <iostream>

using namespace std;

void main()
{
    cout << "########## PROGRAM <TABLES> ##########" << endl << endl;

    try
    {
        cout << "Choose the type of table:" << endl << "1. Scan table" << endl
            << "2. Sort table" << endl << "3. Binary tree table" << endl
            << "4. Balance binary tree (AVL - tree) table" << endl
            << "5. Array hash table" << endl << "6. List hash table" << endl
            << "0. Exit" << endl << "Enter number of type: ";
        
        TTable<string, int>* table;

        int size;
        int hashStep;
        int choiceType;
        int choiceAction;
        cin >> choiceType;

        switch (choiceType)
        {
        case 0:
            return;
        case 1:
            cout << "Size: ";
            cin >> size;
            table = new TScanTable<string, int>(size);
            break;
        case 2:
            cout << "Size: ";
            cin >> size;
            table = new TSortTable<string, int>(size);
            break;
        case 3:
            table = new TBinaryTreeTable<string, int>;
            break;
        case 4:
            table = new TBalanceTreeTable<string, int>;
            break;
        case 5:
            cout << "Size: ";
            cin >> size;
            cout << "Hash step: ";
            cin >> hashStep;
            table = new TArrayHashTable<string, int>(size, hashStep);
            break;
        case 6:
            cout << "Size: ";
            cin >> size;
            table = new TListHashTable<string, int>(size);
            break;
        default:
            throw Exception("Incorrect type of table!");
        }
        
        cout << "Table is created!" << endl << endl;

        while (true)
        {
            cout << "Choose action:" << endl << "1. Insert record" << endl
                << "2. Remove record" << endl << "3. Find record" << endl
                << "4. Print table" << endl << "0. Exit" << endl << "Your choice: ";

            string key;
            cin >> choiceAction;

            switch (choiceAction)
            {
            case 0:
                delete table;
                return;
            case 1:
                cout << endl << "*Insert*" << endl;
                cout << "Enter key: ";
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, key);
                
                table->InsertRecord(key);
                cout << "Inserted succesfully!" << endl << endl;
                key.clear();
                break;
            case 2:
                cout << endl << "*Remove*" << endl;
                cout << "Enter key: ";
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, key);
                
                table->RemoveRecord(key);
                cout << "Removed succesfully!" << endl << endl;
                key.clear();
                break;
            case 3:
                cout << endl << "*Find*" << endl;
                cout << "Enter key: ";
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, key);
                
                cout << "Found record: " << table->FindRecord(key) << endl << endl;
                key.clear();
                break;
            case 4:
                cout << endl << "*Print table*" << endl;
                cout << *table << endl << endl;
                break;
            default:
                throw Exception("Incorrect type of action!");
            }
        }
    }
    catch (const Exception& ex)
    {
        cout << "[ERROR] " << ex.what() << endl << endl;
    }
}