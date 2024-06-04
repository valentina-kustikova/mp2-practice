#include <iostream>
#include <cstdlib>
#include <thread>
#include "ScanTable.h"
#include "TabRecord.h"
#include "SortTable.h"
#include "ArrayHashTable.h"
#include "Polynom.h"

using namespace std;
void Print(TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable)
{
    cout << "ScanTable:" << endl;
    cout << table;
    cout << endl;
    cout << "SortTable:" << endl;
    cout << stable;
    cout << endl;
    cout << "HashTable:" << endl;
    cout << htable;
    cout << endl;
}
void Insert(const string& k, TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable) {
    try {
        int n = 0;

        TPolynom* p = new TPolynom(k);
        string pol_name = p->ToString();

        cout << "Select a table:" << endl;
        cout << "1. ScanTable" << endl;
        cout << "2. SortTable" << endl;
        cout << "3. HashTable" << endl;
        cout << "4. To all tables" << endl;
        do {
            cout << "Enter a number: ";
            cin >> n;
        } while (n != 1 && n!= 2 && n != 3 && n != 4);
        if (n == 1) {
            table.Insert(pol_name, p);
        }
        else if (n == 2) {
            stable.Insert(pol_name, p);
        }
        else if (n == 3) {
            htable.Insert(pol_name, p);
        }
        else {
            table.Insert(pol_name, p);
            stable.Insert(pol_name, p);
            htable.Insert(pol_name, p);
        }
        cout << "Successfully" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
    catch (const string msg) {
        cout << msg << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
}
void Remove(const string& input, TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable) {
    try {
        Print(table, stable, htable);
        system("cls");
        Print(table, stable, htable);
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
        } while (n != 1 && n != 2 && n != 3 && n != 4);
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
        cout << "Successfully" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
    catch (const string msg) {
        cout << msg << endl;
        this_thread::sleep_for(chrono::seconds(3));
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
        if (in != "0")
            Insert(in, table, stable, htable);
        else
        {
            cout << "The polynom is zero" << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
    }
    else
    {
        cout << "The polynomial is not contained in all tables" << endl;
        this_thread::sleep_for(chrono::seconds(3));
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
                cout << "Enter '*' if you want to multiply polynomials" << endl;
                cout << "Input: ";
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
        else
        {
            cout << "The polynomial is not contained in all tables" << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
    }
    else
    {
        cout << "The polynomial is not contained in all tables" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
}
void Operations(TScanTable<string, TPolynom>& table, TSortTable<string, TPolynom>& stable, TArrayHashTable<string, TPolynom>& htable)
{
    system("cls");
    Print(table, stable, htable);
    string s = "";
    do{
        cout << "Choose an action:" << endl;
        cout << "Enter 'arithmetic' if you want to add, subtract or multiply polynomials" << endl;
        cout << "Enter 'dif' if you want to take the derivative of a polynomial" << endl;
        cout << "Input: ";
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
void Sort(TScanTable<string, TPolynom>& table)
{
    TSortTable<string, TPolynom> new_table(&table);
    table.Reset();
    int k = table.GetCount();
    for (int j = 0; j < k; j++)
    {
        string str = table.GetKey();
        table.Remove(str);
        //table.Next();
    }
    new_table.Reset();
    for (int i = 0; i < new_table.GetCount(); i++)
    {
        TPolynom* p = new_table.GetData();
        string s = new_table.GetKey();
        table.Insert(s, p);
        new_table.Next();
    }
}

int main() 
{ 
    int max_size = 5;
    int step = 1;
    TScanTable<string, TPolynom> table(max_size);
    TSortTable<string, TPolynom> stable(max_size);
    TArrayHashTable<string, TPolynom> htable(max_size,step);

    string input = "";

    while (input != "exit")
    {
        system("cls");
        Print(table, stable, htable);
        cout << "Choose an action:" << endl;
        cout << "Enter 'insert' if you want to insert an element into the table" << endl;
        cout << "Enter 'remove' if you want to remove an element from the table" << endl;
        cout << "Enter 'operations' if you want to perform arithmetic operations on polynomials" << endl;
        cout << "Enter 'sort' to sort scan tables" << endl;
        cout << "Enter 'exit' to exit the program" << endl;
        cout << "Input: ";
        cin >> input;

        if (input == "insert")
        {
            system("cls");
            Print(table, stable, htable);
            string k;

            cout << "Enter key: ";
            cin >> k;
            Insert(k, table, stable, htable);
        }
        else if (input == "remove")
            Remove(input, table, stable, htable);
        else if (input == "operations")
            Operations(table, stable, htable);
        else if (input == "sort")
            Sort(table);
    }

    return 0;
}
//
//int main()
//{
//	TArrayHashTable<string, string> ht(3, 1);
//
//	string data = "abc";
//	string data2 = "def";
//
//	ht.Insert("key1", &data);
//	ht.Insert("key2", &data2);
//
//	cout << ht;
//
//	return 0;
//}