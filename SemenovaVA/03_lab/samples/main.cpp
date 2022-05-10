#include "ScanTable.h"
#include "HashTable.h"
#include "SortTable.h"
#include "AVLTable.h"
#include "Polynom.h"
using namespace std;

void menu()
{
    cout << "\n\t1. Add a polynomial to table\n\t2. Delete the polynomial from the table\n\t3. Clear the table\n\t4. Perform an operation on polynomials\n\t5. Show the current state of the tables\n\t0. Exit\n\n\tInput: ";
}
void menu1()
{
    cout << "\n\t1. Add two polynomials\n\t2. Subtract two polynomials\n\t3. Multiply a polynomial by a constant\n\t4. Multiply two polynomials\n\t5. Calculate the polynomial\n\n\tInput: ";
}
void Choice(int a)
{
    cout << "\n\tSelect the table view :\n\t 1. Viewable tables\n\t 2. Ordered tables\n\t 3. Hash Tables\n\t 4. Table on AVL trees";
    if (a % 2 != 0) { cout << "\n\t 5. All tables"; }
    cout << "\n\n\tInput: ";
}
Polynom Operation(Polynom P1, Polynom P2, int entry)
{
    system("cls");
    cout << "\n\t\t ENTERED:\n\tF1 - " << P1;
    int c;
    Polynom P3("1");
    switch (entry)
    {
    case 1: cout << "\n\tF2 - " << P2 << "\n\tAdd two polynomials: "; P3 = P1 + P2; cout << P3;
        break;
    case 2: cout << "\n\tF2 - " << P2 << "\n\tSubtract two polynomials: ";  P3 = P1 - P2; cout << P3;
        break;
    case 3: cout << "\n\tEnter a constant\n\tInput: ";
        cin >> c;
        cout << "\n\tMultiply a polynomial by a constant: ";  P3 = P1 * c; cout << P3;
        break;
    case 4: cout << "\n\tF2 - " << P2 << "\n\t4. Multiply two polynomials: "; P3 = P1 * P2; cout << P3;
        break;
    case 5: cout << "\n\tCalculate the polynomial:" << P1.Ñalculate();
        break;
    }
    return P3;
    ;
}
template <typename Tab>
string Switch(Tab& A, int entry, string a = "")
{
    switch (entry)
    {
    case 1:  if (a == "")
    {
        system("cls");
        cout << "\n\tEnter the polynomial to add.\n\n\tInput: ";
        cin >> a;
    }
          A.Insert(Polynom(a), Polynom(a).Re());
          return a;
    case 2:  if (a == "")
    {
        system("cls");
        cout << "\n\tEnter the polynomial to delete.\n\n\tInput: ";
        cin >> a;
    }
          A.Delete(Polynom(a).Re());
          return a;
    case 3:  A = Tab();
        return "";
    case 4: {int entry2;
        system("cls");
        menu1();
        cin >> entry2;
        system("cls");
        if ((A.GetCount() > 1 && entry2 != 5) || (A.GetCount() > 0 && entry2 == 5))
        {
            cout << "\n\tCurrent table:\n\tKey - Data:\n" << A;;
        }
        else { cout << " Error"; return""; }
        cout << "\n\tEnter the polynomial\n\n\tInput: ";
        string x, y;
        Polynom A1, B1;
        cin >> x;
        if (A.Search(x) != nullptr)
        {
            A1 = Polynom(x);
        }
        else { throw 1; }
        if (entry2 != 5)
        {
            cin >> y;
            if (A.Search(y) != nullptr)
            {
                B1 = Polynom(y);
            }
            else { throw 1; }
        }
        B1 = Operation(A1, B1, entry2);
        string s = B1.Re();
        if (entry2 != 5)
        {
            A.Insert(Polynom(B1), Polynom(B1).Re());
        }
        return "";
        break; }
    case 5:  if (!A.IsEmpty())
    {
        cout << "\n\tKey - Data:\n";
    }
          cout << A;
          return "";
          break;
    }
}

int main()
{
    int  entry = 1, entry2 = 0, i;
    unsigned int n;
    cout << "\t\tTABLES\n\n\t\tEnter the size of the tables\n\tInput: ";
    cin >> n;
    ScanTable <Polynom, string> A(n);
    SortTable <Polynom, string> B(n);
    HashTable <Polynom, string> C(n);
    AVLTable <Polynom, string> D;
    while (entry != 0)
    {
        system("cls");
        cout << "\t\tTABLES\n";
        menu();
        cin >> entry;
        if (entry != 0)
        {
            system("cls");
            Choice(entry);
            cin >> entry2;
            string a;
            switch (entry2)
            {
            case 1:  a = Switch(A, entry); break;
            case 2:  a = Switch(B, entry); break;
            case 3:  a = Switch(C, entry); break;
            case 4:  a = Switch(D, entry); break;

            case 5:  a = Switch(A, entry);
                a = Switch(B, entry, a);
                a = Switch(C, entry, a);
                a = Switch(D, entry, a);
                break;
            }
            char c;
            cout << "\n\nEnter any character to continue\n";
            cin >> c;
        }

    }


}
