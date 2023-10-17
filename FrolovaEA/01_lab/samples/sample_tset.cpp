#include <iostream>
#include"tset.h"

using namespace std;

int main()
{
    std::cout << "TSet" << std::endl;
    int power;
    cout << "Enter max power :";
    cin >> power;
    cout << endl;
    TSet set1(power);

    int num1;
    cout << "how mach elements would you like to add to set1: ";
    cin >> num1;
    cout << endl;
    int i = 0;
    while (i != num1)
    {
        int elem;
        cout << "Enter element : " << "element must be < " << power << "  :";
        cin >> elem;
        cout << endl;
        set1.InsElem(elem);
        i++;
    }
    cout << "Max power of set1 :  " << set1.GetMaxPower() << ";" << "  Elements in set1 : " << set1 << endl;


    TSet set2(power);

    int num2;
    cout << "how mach elements would you like to add to set2: ";
    cin >> num2;
    cout << endl;
    int j = 0;
    while (j != num2)
    {
        int elem;
        cout << "Enter element : " << "element must be < " << power << "  :";
        cin >> elem;
        cout << endl;
        set2.InsElem(elem);
        j++;
    }
    cout << "Max power of set2 :  " << set2.GetMaxPower() << ";" << "  Elements in set1 : " << set2 << endl;
    cout << endl;

    cout <<"Max power of set1 :  "<<set1.GetMaxPower()<<";"<<"  Elements in set1 : " << set1 << endl;
    cout << "Max power of set2 :  "<< set2.GetMaxPower() <<";"<<"  Elements in set2 : " << set2 << endl;
    cout << endl;

    //is member ?

    int element1;
    cout << "enter elemen you would like to find: ";
    cin >> element1;
    cout << endl;
    while (element1 >= power)
    {
        cout << "enter elemen you would like to find: ";
        cin >> element1;
        cout << endl;
    }
    cout << " Element " << element1 << " in set1 : " << set1.IsMember(element1) << endl;
    cout << " Element " << element1 << " in set2 : " << set2.IsMember(element1) << endl;

    cout << endl;

    // delite element
    int element2;
    cout << "enter elemen you would like to delete: ";
    cin >> element2;
    cout << endl;
    while (element2 >= power)
    {
        cout << "enter elemen you would like to find: ";
        cin >> element2;
        cout << endl;
    }
    set1.DelElem(element2);
    cout << "Elements in set1 after delete" << element2 << " :" << set1 << endl;
    set2.DelElem(element2);
    cout << "Elements in set2 after delete" << element2 << " :" << set2 << endl;

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
    int element3;
    cout << "enter elemen you would like to +: ";
    cin >> element3;
    cout << endl;
    while (element3 >= power)
    {
        cout << "enter elemen you would like to +: ";
        cin >> element3;
        cout << endl;
    }

    set1 = set1 + element3;
    cout << "set1 + " << element3 << " = " << set1 << endl;
    cout << endl;

    cout << "operator- (with element)" << endl;
    int element4;
    cout << "enter elemen you would like to -: ";
    cin >> element4;
    cout << endl;
    while (element4 >= power)
    {
        cout << "enter elemen you would like to -: ";
        cin >> element4;
        cout << endl;
    }
    set1 = set1 - element4;
    cout << "set1 - " << element4 << " = " << set1 << endl;
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
