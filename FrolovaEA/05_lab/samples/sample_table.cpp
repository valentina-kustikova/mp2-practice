#include<iostream>
#include<string.h>
#include"ScanTable.h"
#include"SortedTable.h"
#include"Arrayhashtable.h"
#include"tpolynom.h"

using namespace std;


TScanTable<string, TPolinom> scan_table(101);
TSortedTable<string, TPolinom> sort_table(101);
TArrayHashTable<string, TPolinom> hash_table(101, 1);

TPolinom inputPolynomial(const string& message, TScanTable<string, TPolinom>& scan_table, TSortedTable<string, TPolinom>& sort_table, TArrayHashTable<string, TPolinom>& hash_table);
void Remove_polynom();
void InsertRes(TPolinom poly, int choice);
void derivative_of_a_polynomial();
void Insert_polynom();
void arithmetic_operations_with_polynomials();
void Print_table();
int correctness_check(int choice);
char chooseOperation();

int correctness_check(int choice)
{
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "Enter table :" << endl;
        cout << "1: scan table" << endl;
        cout << "2: sorted table" << endl;
        cout << "3: hash table" << endl;
        cout << "4: all tables" << endl;
        cin >> choice;
        cout << endl;
    }
    return choice;
}

void derivative_of_a_polynomial()
{
    string dif;
    cout << "Enter polynom which one you want to derivative: ";
    TPolinom poly1 = inputPolynomial(std::string("Enter first polynomial: "), scan_table, sort_table, hash_table);
    cout << "choose which variable to take the derivative of: x, y, z" << std::endl;
    cin >> dif;
    while (dif != "x" && dif != "y" && dif != "z")
    {
        std::cout << " Choose correctly:" << endl;
        cout << "x, y, z" << endl;
        cin >> dif;
    }

    if (dif == "x")
    {
        TPolinom result = poly1.dif_x();
        InsertRes(result, 5);
    }
    if (dif == "y")
    {
        TPolinom result = poly1.dif_y();
        InsertRes(result, 5);
    }
    if (dif == "z")
    {
        TPolinom result = poly1.dif_z();
        InsertRes(result, 5);
    }
}

char chooseOperation()
{
    char func;
    std::cout << "Choose what you want to do with polynomials: +, -, * ";
    std::cin >> func;
    std::cout << std::endl;

    while (func != '+' && func != '-' && func != '*')
    {
        std::cout << "Choose what you want to do with polynomials: +, -, * ";
        std::cin >> func;
    }

    return func;
}

TPolinom inputPolynomial(const string& message, TScanTable<string, TPolinom>& scan_table, TSortedTable<string, TPolinom>& sort_table, TArrayHashTable<string, TPolinom>& hash_table)
{
    std::string str;
    std::cout << message;
    std::cin >> str;
    TPolinom poly(str);

    while (scan_table.Find(poly.To_string()) == nullptr && sort_table.Find(poly.To_string()) == nullptr && hash_table.Find(poly.To_string()) == nullptr)
    {
        std::cout << "There is no such polynomial in the tables" << std::endl;
        std::cout << "Enter polynomial: " << std::endl;
        std::cin >> str;
        poly = TPolinom(str);
    }

    return poly;
}

void arithmetic_operations_with_polynomials()
{
    std::string str1, str2;
    char func;

    cout << "the polynomial must exist in any table" << std::endl;
    bool flag;

    TPolinom poly1 = inputPolynomial("Enter first polynomial: ", scan_table, sort_table, hash_table);
    TPolinom poly2 = inputPolynomial("Enter second polynomial: ", scan_table, sort_table, hash_table);

    func = chooseOperation();

    if (func == '+')
    {
        TPolinom result = poly1 + poly2;

        InsertRes(result, 5);
    }
    if (func == '-')
    {
        TPolinom result = poly1 - poly2;
        InsertRes(result, 5);
    }
    if (func == '*')
    {
        TPolinom result = poly1 * poly2;
        InsertRes(result, 5);
    }
}

void Remove_polynom()
{
    string str;
    cout << "Enter polynom you want to remove : ";
    cin >> str;
    cout << endl;
    int choice;
    cout << " In which table you want to remove polynom:" << endl;
    cout << "1: scan table" << endl;
    cout << "2: sorted table" << endl;
    cout << "3: hash table" << endl;
    cout << "4: all tables" << endl;

    cin >> choice;
    cout << endl;

    choice = correctness_check(choice);
    TPolinom poly(str);

    switch (choice)
    {
    case 1:
        if (scan_table.Find(poly.To_string()) != nullptr)
        {
            scan_table.Remove(poly.To_string());
            cout << "remove is done" << endl;
        }
        else
        {
            cout << "Scan table doesn't contain this polynom" << endl;
        }
        break;
    case 2:

        if (sort_table.Find(poly.To_string()) != nullptr)
        {
            sort_table.Remove(poly.To_string());
            cout << "remove is done" << endl;
        }
        else
        {
            cout << "Sorry. Sorted table doesn't contain this polynom" << endl;
        }
        break;
    case 3:

        if (hash_table.Find(poly.To_string()) != nullptr)
        {
            hash_table.Remove(poly.To_string());
            cout << "remove is done" << endl;
        }
        else
        {
            std::cout << "Hash table doesn't contain this polynom" << endl;
        }
        break;
    case 4:

        if (hash_table.Find(poly.To_string()) != nullptr && scan_table.Find(poly.To_string()) != nullptr && sort_table.Find(poly.To_string()) != nullptr)
        {
            scan_table.Remove(poly.To_string());
            sort_table.Remove(poly.To_string());
            hash_table.Remove(poly.To_string());
        }
        else
        {
            std::cout << "some of the tables do not contain this polynomial" << endl;
        }
        break;
    }
}

void InsertRes(TPolinom poly, int choice)
{
    choice = correctness_check(choice);
    switch (choice)
    {
    case 1:
        if (!scan_table.IsFull())
        {
            scan_table.Insert(poly.To_string(), &poly);
            cout << "Insert into scan table is done" << endl;
            break;
        }
        else
        {
            cout << "Table is full, choose another table" << endl;
            cout << "2 - Sorted table" << endl;
            cout << "3 - Hash table" << endl;
            cin >> choice;
            while (choice != 2 && choice != 3)
            {
                cin >> choice;
            }
            break;
        }
    case 2:
        if (!sort_table.IsFull())
        {
            sort_table.Insert(poly.To_string(), &poly);
            cout << "Insert into sort table is done" << endl;
            break;
        }
        else
        {
            cout << "Table is full, choose another table" << endl;
            cout << "1 - Scan table" << endl;
            cout << "3 - Hash table" << endl;
            cin >> choice;
            while (choice != 1 && choice != 3)
            {
                cin >> choice;
            }
            break;
        }
    case 3:
        if (!hash_table.IsFull())
        {
            hash_table.Insert(poly.To_string(), &poly);
            cout << "Insert into hash table is done" << endl;
            break;
        }
        else
        {
            cout << "Table is full, choose another table" << endl;
            cout << "2 - Sorted table" << endl;
            cout << "1 - Scan table" << endl;
            cin >> choice;
            while (choice != 2 && choice != 1)
            {
                cin >> choice;
            }
            break;
        }
    case 4:
        if (!scan_table.IsFull() && !hash_table.IsFull() && !sort_table.IsFull())
        {
            hash_table.Insert(poly.To_string(), &poly);
            sort_table.Insert(poly.To_string(), &poly);
            scan_table.Insert(poly.To_string(), &poly);
            cout << "Insert into all tables is done" << endl;
            break;
        }
        else
        {
            cout << "some table is full, choose another table" << endl;
            cout << "1 - Scan table" << endl;
            cout << "2 - Sorted table" << endl;
            cout << "3 - Hash table" << endl;
            cin >> choice;
            while (choice != 2 && choice != 1 && choice != 3)
            {
                cin >> choice;
            }
            break;
        }
    }
}

void Insert_polynom()
{
    string str;
    cout << "Enter polynom to insert : ";
    cin >> str;
    cout << endl;

    TPolinom poly(str);

    int choice;

    cout << "Enter in which table do you want to insert polynom :" << endl;
    cout << "1: scan table" << endl;
    cout << "2: sorted table" << endl;
    cout << "3: hash table" << endl;
    cout << "4: all tables" << endl;

    cin >> choice;
    cout << endl;

    choice = correctness_check(choice);

    InsertRes(poly, choice);
}

void Print_table()
{
    int choice;

    cout << "Enter which table do you want to print :" << endl;
    cout << "1: scan table" << endl;
    cout << "2: sorted table" << endl;
    cout << "3: hash table" << endl;
    cout << "4: all tables" << endl;

    cin >> choice;
    cout << endl;

    choice = correctness_check(choice);
    switch (choice) {
    case 1:
        cout << "Scan table : " << endl;
        cout << scan_table << endl;
        break;

    case 2:
        cout << "sorted table : " << endl;
        cout << sort_table << endl;
        break;

    case 3:
        cout << "Hash table : " << endl;
        cout << hash_table << endl;
        break;

    case 4:
        cout << "Scan table : " << endl;
        cout << scan_table << endl;
        cout << endl;
        cout << "sorted table : " << endl;
        cout << sort_table << endl;
        cout << endl;
        cout << "Hash table : " << endl;
        cout << hash_table << endl;
        cout << endl;

        break;
    }
}





int main()
{
    try {
        int flag;
        do {
            cout << "1: Print" << endl;
            cout << "2: Insert polynom" << endl;
            cout << "3: Remove polynom" << endl;
            cout << "4: arithmetic operations with polynomials" << endl;
            cout << "5: derivative of a polynomial" << endl;
            cout << "6: EXIT" << endl;
            cout << "Choice: ";
            cin >> flag;

            switch (flag) {
            case 1:
                cout << "Print : " << endl;
                Print_table();
                break;

            case 2:
                cout << "Insert polynom : ";
                Insert_polynom();
                cout << endl;
                break;

            case 3:
                cout << "Remove polynom : ";
                Remove_polynom();
                cout << endl;
                break;

            case 4:
                cout << "arithmetic operations with polynomials: ";
                arithmetic_operations_with_polynomials();
                cout << endl;
                break;

            case 5:
                cout << "derivative of a polynomial" << endl;
                derivative_of_a_polynomial();
                break;

            }
        } while (flag != 6);
    }

    catch (const char* exp)
    {
        cout << exp;
        return -1;
    }

    return 0;
}
