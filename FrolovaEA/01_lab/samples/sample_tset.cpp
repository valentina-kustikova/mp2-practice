#include <iostream>
#include"tset.h"

using namespace std;

int main()
{
    std::cout << "TSet" << std::endl;

    int power = 15;
    TSet set1(power);
    TSet set2(power);

    set1.InsElem(3);
    set1.InsElem(1);
    set1.InsElem(10);
    set1.InsElem(6);
    set1.InsElem(9);

    set2.InsElem(3);
    set2.InsElem(1);
    set2.InsElem(8);
    set2.InsElem(2);
    set2.InsElem(11);

    cout <<"Max power of set1 :  "<<set1.GetMaxPower()<<";"<<"  Elements in set1 : " << set1 << endl;
    cout << "Max power of set2 :  "<< set2.GetMaxPower() <<";"<<"  Elements in set1 : " << set2 << endl;
    cout << endl;

    //is member ?

    cout << " Element 6 in set1 :" << set1.IsMember(6) << endl;
    cout << " Element 2 in set1 :" << set1.IsMember(2) << endl;

    cout << " Element 6 in set2 :" << set2.IsMember(6) << endl;
    cout << " Element 2 in set2 :" << set2.IsMember(2) << endl;

    cout << endl;

    // delite element
    set1.DelElem(10);
    cout << "Elements in set1 after delete 10 :" << set1 << endl;
    set2.DelElem(1);
    cout << "Elements in set2 after delete 1 :" << set2 << endl;

    cout << endl;

    TSet set3(10);
    cout << "Max power of set3 :  " << set3.GetMaxPower() << ";" << "  Elements in set3 : " << set3 << endl;
    set3 = set1;
    cout << "operator = :" << "set3 = set1 : " << set3 << endl;
    cout << endl;

    cout << "operator== " << endl;
    cout << "set3 == set1 ?  : " << (set3 == set1) << endl;
    cout << "set2 == set1 ?  : " << (set2 == set1) << endl;

    cout << "operator!= " << endl;
    cout << "set3 != set1 ?  : " << (set3 != set1) << endl;
    cout << "set2 != set1 ?  : " << (set2 != set1) << endl;
    cout << endl;

    cout << set1 << endl;
    cout << set2 << endl;
    cout << "operator+ " << endl;
    cout << "set1 + set2 = " << (set1 + set2) << endl;
    cout << endl;

    cout << "operator+ (with element)" << endl;
    TSet set5(power);
    set5 = set1 + 14;
    cout << "set1 + 14 = " << set5 << endl;
    cout << endl;

    cout << "operator- (with element)" << endl;
    set5 = set1 - 14;
    cout << "set1 - 14 = " << set5 << endl;
    cout << endl;

    cout << set1 << endl;
    cout << set2 << endl;
    cout << "operator*" << endl;
    cout << "set1 * set2 = " << (set1 * set2) << endl;
    cout << endl;

    cout << set2 << endl;
    cout << "operator~" << endl;
    cout << "~set2 = " << (~set2) << endl;
    cout << endl;


    return 0;
}
