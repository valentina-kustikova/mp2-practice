#include "tpolynom.h"


int main()
{
    TPolynom pl_defolt();
    string str = "1+ x^2 -y^3 + x*y*z - x^2*y*z^2";
    TPolynom pl_str(str);
    //+x^2-y^3+x*y*z-x^2*y*z^2

  

    TNode<TMonom>* c = new TNode<TMonom>(TMonom(111, 2.0), nullptr);
    TNode<TMonom>* b = new TNode<TMonom>(TMonom(11, 2.0), c);
    TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0), b);

    TRingList<TMonom>* rl = new TRingList<TMonom>(a);

    TPolynom pl_rl(rl);

    cout << pl_rl.GetString() << endl;

    return 0;
}
