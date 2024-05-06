#include <iostream>
#include "ScanTable.h"
#include "TabRecord.h"
#include "SortTable.h"
#include "ArrayHashTable.h"
#include "Polynom.h"

using namespace std;
void Insert(const string& k, TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable) {
    try {
        int n = 0;

        TPolynom* p = new TPolynom(k);

        cout << "Select a table:" << endl;
        cout << "1. ScanTable" << endl;
        cout << "2. SortTable" << endl;
        cout << "3. HashTable" << endl;
        cout << "4. To all tables" << endl;
        do {
            cout << "Enter a number: ";
            cin >> n;
        } while (n > 4 || n < 1);
        if (n == 1) {
            table.Insert(k, p);
        }
        else if (n == 2) {
            stable.Insert(k, p);
        }
        else if (n == 3) {
            htable.Insert(k, p);
        }
        else {
            table.Insert(k, p);
            stable.Insert(k, p);
            htable.Insert(k, p);
        }
        //cout << "Successfully" << endl;
    }
    catch (const string msg) {
        cout << msg << endl;
    }
}
void Remove(const string& input, TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable) {
    try {
        int n = 0;
        string k;
        cout << "Enter key: "; // ввод полинома
        cin >> k;

        cout << "Select a table:" << endl;
        cout << "1. ScanTable" << endl;
        cout << "2. SortTable" << endl;
        cout << "3. HashTable" << endl;
        cout << "4. To all tables" << endl;
        do {
            cout << "Enter a number: ";
            cin >> n;
        } while (n > 4 || n < 1);
        if (n == 1) {
            try {
                table.Remove(k);
            }
            catch (const string msg) {
                cout << msg << endl;
            }
        }
        else if (n == 2) {
            stable.Remove(k);
        }
        else if (n == 3) {
            htable.Remove(k);
        }
        else {
            table.Remove(k);
            stable.Remove(k);
            htable.Remove(k);
        }
        //cout << "Successfully" << endl;
    }
    catch (const string msg) {
        cout << msg << endl;
    }
}
void Dif(TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable)
{
    string k;
    cout << "Enter a polynom: ";
    cin >> k;

    if (table.Find(k) != nullptr && stable.Find(k) != nullptr && htable.Find(k) != nullptr)
    {
        TabRecord<string, TPolynom> rec = *table.Find(k);
        TPolynom p = *rec.GetData();
        string v = "";
        do {
            cout << "Select  a variable: ";
            cin >> v;
        } while (v != "x" && v != "y" && v != "z");
        TPolynom pd;
        if (v == "x")
            pd = p.difx();
        else if (v == "y")
            pd = p.dify();
        else if (v == "z")
            pd = p.difz();
        string in = pd.ToString();
        Insert(in, table, stable, htable);
    }
}
void Arithmetic(TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable)
{
    string k;
    cout << "Enter first polynom: ";
    cin >> k;
    if (table.Find(k) != nullptr && stable.Find(k) != nullptr && htable.Find(k) != nullptr)
    {
        string k2;
        cout << "Enter second polynom: ";
        cin >> k2;
        if (table.Find(k2) != nullptr && stable.Find(k2) != nullptr && htable.Find(k2) != nullptr)
        {
            TabRecord<string, TPolynom> rec = *table.Find(k);
            TabRecord<string, TPolynom> rec2 = *table.Find(k2);
            TPolynom p1 = *rec.GetData();
            TPolynom p2 = *rec2.GetData();
            TPolynom pd;
            string o = "";
            do {
                cout << "Select  an operation:" << endl;
                cout << "Enter '+' if you want to add polynomials" << endl;
                cout << "Enter '-' if you want to subtrsct polynomials" << endl;
                cout << "Enter '+' if you want to multiply polynomials" << endl;
                cin >> o;
            } while (o != "+" && o != "-" && o != "*");
            if (o == "+")
            {
                pd = p1 + p2;
            }
            else if (o == "-")
            {
                pd = p1 - p2;
            }
            else if (o == "*")
            {
                pd = p1 * p2;
            }
            string in = pd.ToString();
            Insert(in, table, stable, htable);
        }
    }
}
void Operations(TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable)
{
    string s = "";
    do{
        cout << "Choose an action:" << endl;
        cout << "Enter 'arithmetic' if you want to add, subtract or multiply polynomials" << endl;
        cout << "Enter 'dif' if you want to take the derivative of a polynomial" << endl;
        cin >> s;
    } while (s != "arithmetic" && s != "dif");

    if (s == "arithmetic")
    {
        Arithmetic(table, stable, htable);
    }
    else if (s == "dif")
    {
        Dif(table, stable, htable);
    }
}
void Print(TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable) {
    cout << "ScanTable:" << endl;
    cout << table;
    cout << endl;
    cout << "SortTable:" << endl;
    cout << stable;
    cout << endl;
    cout << "HashTable:" << endl;
    htable.Print();
}
int main() 
{ 
    TScanTable<string, TPolynom> table(5);
    TSortTable<string, TPolynom> stable(5);
    TArrayHashTable<string, TPolynom> htable(5,1);

    string input = "";

    while (input != "exit")
    {
        cout << "Choose an action:" << endl;
        cout << "Enter 'insert' if you want to insert an element into the table" << endl;
        cout << "Enter 'remove' if you want to remove an element from the table" << endl;
        cout << "Enter 'operations' if you want to perform arithmetic operations on polynomials" << endl;
        cout << "Enter 'print' to print tables" << endl;
        cout << "Enter 'exit' to exit the program" << endl;
        cout << "Input: ";
        cin >> input;

        if (input == "insert")
        {
            string k;

            cout << "Enter key: "; // ввод полинома
            cin >> k;
            Insert(k, table, stable, htable);
        }
        else if (input == "remove")
            Remove(input, table, stable, htable);
        else if (input == "operations")
            Operations(table, stable, htable);
        else if (input == "print")
            Print(table, stable, htable);
    }

    return 0;
}