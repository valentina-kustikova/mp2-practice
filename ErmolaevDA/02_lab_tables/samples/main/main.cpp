#include"ScanTable.h"
#include"HashTable.h"
#include"SortTable.h"
#include"Table.h"
#include"polinom.h"
#include<string>;
using namespace std;
#define SS <int,string>

#define ZZ <Polinom,string>
int main(){

setlocale(LC_ALL,"utf_8");
ScanTable SS A;
A.InsertRecord(11,"1");
A.InsertRecord(121, "1");
A.InsertRecord(9,"2");
A.InsertRecord(8,"3");
A.InsertRecord(7,"1777");
A.InsertRecord(6,"16688");
A.InsertRecord(5,"6");
A.InsertRecord(4,"7");
A.InsertRecord(3,"8");
A.InsertRecord(200,"9");
    cout<<A<<endl;

    //A.SortData();
    //cout<<A;
    cout << endl;
    
SortTable SS B(A);
cout << B;
    
cout << endl;
    
    SortTable ZZ Poltable;

    Polinom p1;
    p1.str_to_poly("x+y");
        Polinom p2;
    p2.str_to_poly("2x+z^2");
        Polinom p3;

HashTable SS T1;
for (int i = 0; i < 4; i++)
{
    T1.InsertRecord((i + 1) * 8 + (i * i) % 13, to_string(i + 1) + " record");
}
T1.Reset();
//T1.SetNext();
cout << *(T1.GetData());
cout << T1;
T1.Clear();
cout << T1;
//T1.RemoveRecord("1 record");
//cout <<endl<< T1;
//T1.RemoveRecord("1 record");
//T1.RemoveRecord("2 record");
//cout << endl << T1;
    return 0;
}

