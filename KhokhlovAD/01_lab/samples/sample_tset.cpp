#include <iostream>
#include "tset.h"


int main()
{
    TSet set1(4);
    set1.InsElem(2);
    set1.InsElem(0);
    TSet set2(4);
    set2.InsElem(1);
    set2.InsElem(3);
    cout << "ts1 = " << set1;
    cout << endl << "ts2 = " << set2 << endl;
    bool a = (set1 != set2);
    bool b = (set1 == set2);
    std::cout << "ts1 != ts2 ->" <<a << endl <<"ts1 == ts2 ->" << b << std::endl;
    TSet c;
    TSet d(set1);
    d.InsElem(3);
    cout <<"ts3(ts1).inselem(3) -> "<< d << endl;
    int g = d.GetMaxPower();
    cout <<"ts3.maxpower -> " <<g << endl;
    c = d;
    d.DelElem(3);
    cout <<"ts4 = ts3 -> " << c << endl;
    cout <<"ts3.delelem(3)-> "<< d << endl;
    d = c + set2;
    cout << "ts3 = ts4 + ts2 -> " <<d << endl;
    set1 = ~d;
    cout << "ts1 = ~ts3 -> " << set1 << endl;
    set2 = set2 * c;
    cout <<"ts2 = ts2 * ts4 -> "<< set2 << endl;
    return 0;
}
