#include "tpolynom.h"
#include<string>

using namespace std;


int main()
{
   /* string str_polynom;
    cout << "Input polynom\n";
    cin >> str_polynom;*/
    try {
        /*TPolynom pl1(str_polynom);

        cout << "Your polynom: " << pl1.GetString() << endl;*/

        string name1;
        string name2;

        cout << "name1 = ";
        cin >> name1;
        cout << "name2 = ";
        cin >> name2;

        TPolynom p1(name1);
        TPolynom p2(name2);
        cout << "p1 = " << p1.GetString() << endl;
        cout << "p2 = " << p2.GetString() << endl << endl;

        cout << "Operators (Addition, Subtraction, Multiplication):" << endl;
        cout << "p1 + p2 = " << (p1 + p2).GetString() << endl;
        cout << "p1 - p2 = " << (p1 - p2).GetString() << endl;
        cout << "p1 * p2 = " << (p1 * p2).GetString() << endl << endl;
    }
    catch (string exp) {
        cout << exp << endl;
    }











    //TPolynom pl_defolt();
    //string str = "1+ x^2 -y^3 + x*y*z - x^2*y*z^2";
    //TPolynom pl_str(str);
    ////+x^2-y^3+x*y*z-x^2*y*z^2

  

    //TNode<TMonom>* c = new TNode<TMonom>(TMonom(111, 2.0), nullptr);
    //TNode<TMonom>* b = new TNode<TMonom>(TMonom(11, 2.0), c);
    //TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0), b);

    //TRingList<TMonom>* rl = new TRingList<TMonom>(a);

    //TPolynom pl_rl(rl);

    //cout << pl_rl.GetString() << endl;


    //string str_2 = "1+x^2 + x^2";
    //TPolynom pl(str_2);

    //cout << pl.GetCurrent()->pNext->data.get_koef() << " " << pl.GetCurrent()->pNext->data.get_degree() << endl;
    //cout << pl.GetCurrent()->data.get_koef() << " " << pl.GetCurrent()->data.get_degree() << endl;

    //string str_3 = "1+x^2 - x^2";
    //TPolynom pl_str3(str_3);
    //cout << pl_str3.GetString() << endl;
    //cout << pl_str3.GetCurrent()->data.get_koef() << " " << pl_str3.GetCurrent()->data.get_degree() << endl;
    //cout << pl_str3.GetCurrent()->pNext->data.get_koef() << " " << pl_str3.GetCurrent()->pNext->data.get_degree() << endl;
    //
    //TPolynom pl1("1+x+y+z"), pl2("3+x+3*y +x*y");

//    TPolynom res = pl1 + pl2;

 //   cout << res.GetString() << endl;


    return 0;
}
