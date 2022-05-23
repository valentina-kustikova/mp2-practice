#include"ScanTable.h"
#include"HashTable.h"
#include"SortTable.h"
#include"Table.h"
#include"polinom.h"

#include"AVLTable.h"
#include"AVLTree.h"
#include"BinaryTree.h"

#include<string>;
using namespace std;
#define SS <int,string>
#define SSS <int,int>
#define ZZ <Polinom,string>
int main(){
int TEST=0;
cin >> TEST;

if (TEST==0){
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
}
else {

    AVLTable SSS T1;
    AVLTree SSS T3;
    BinaryTree SSS T2;
    for (int i = 0; i < 4; i++)
    {
        T1.InsertRecord((i + 1) * 8 + (i * i) % 13, i + 1);

        T2.Insert(i,(i + 1) * 8 + (i * i) % 13);
        T3.Insert(i, (i + 1) * 8 + (i * i) % 13);
        //(*(T1.GetDat())).printTree((BalanceNode SSS*)((*(T1.GetDat())).Find(i)), nullptr, 1);
    }
    //T1.Reset();
    //AVLTree SS TT = *(T1.GetDat());
    (*(T1.GetDat())).printTree((BalanceNode SSS*)((*(T1.GetDat())).Find(2)), nullptr, 1);
    std::cout << T1;

    //std::cout << T1;
    //T1.Delete(9);
    cout << "_________________BINARY_TREE___________________\n";
    cout << T2;
    cout << "__________________AVL_TREE_____________________\n";
    cout << T3;

    cout << "\nNEW TESTS______________________________________\n";

    cout << "Derevo BINARY TREE:" << "\t" << "\n";
    T2.printTree(T2.Find(0), nullptr, 1);
    cout << "________________________________" << "\t" << "\n";


    cout << "Derevo AVL TREE:" << "\t" << "\n";
    T3.printTree((BalanceNode SSS*)(T3.Find(1)), nullptr, 1);
    cout << "________________________________" << "\t" << "\n";

    cout << "SRAVNENIE" << "\t" << "\n";
    cout << (T3 == T2);
}
    return 0;
}

