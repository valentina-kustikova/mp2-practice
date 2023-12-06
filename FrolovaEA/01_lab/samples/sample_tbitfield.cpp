#include <iostream>
#include "tbitfield.h"

using namespace std;


int main()
{
    cout << "TBitField" << std::endl;

    int len1;
    int len2;

    cout << "enter the length of the bit field 1 : ";
    cin >> len1;
    cout << endl;

    TBitField BitField1(len1);
    cout << "the bit field len= " << len1 << " :";
    cin >> BitField1;
    cout << endl;

    // вывод битового поля и его длины

    cout <<"len of bit field 1: "<< BitField1.GetLength()<<" ; "<<" bit field 1: " <<BitField1 << endl;

    cout << "enter the length of the bit field 2 : ";
    cin >> len2;
    cout << endl;

    TBitField BitField2(len2);
    cout << "the bit field len= " << len2 << " :";
    cin >> BitField2;
    cout << endl;

    // вывод битового поля и его длины

    cout << "len of bit field 2: " << BitField2.GetLength() << " ; " << " bit field 2: " << BitField2 << endl;


    //установка бита 
    int index1;
    cout << "enter index to set the bit:";
    cin >> index1;
    BitField1.SetBit(index1);
    cout << "new bit field 1:" << BitField1 << endl;

    //удаление бита
    int index2;
    cout << "enter index to delete the bit:";
    cin >> index2;
    BitField1.ClrBit(index2);
    cout << "new bit field 1:" << BitField1 << endl;

    //получить значение бита 
    int index3;
    cout << "enter index to get bit :";
    cin >> index3;
    cout << endl;
    cout << "bit in index " << index3 << " = " << BitField1.GetBit(index3) << endl;

    cout << "bit field 1 : " << BitField1 << endl;
    cout << "bit field 2 : " << BitField2 << endl;

    //сравнение битовых полей на равенство
    if (BitField1 == BitField2) {
        cout << "comparison of bit fields for equality" << endl;
        cout << (BitField1 == BitField2) << endl;
    }
    if (BitField1 == BitField2) {
        cout << "the bit fields are equal" << endl;
    }
    else {
        cout << "the bit fields are not equal" << endl;
    }

    //сравнение битовых полей на не равенство
    cout << "comparing bit fields to non-equality" << endl;
    cout << (BitField1 != BitField2) << endl;

    if (BitField1 != BitField2) {
        cout << "the bit fields are not equal" << endl;
    }
    else {
        cout << "the bit fields are equal" << endl;
    }

    int len3;
    cout << "enter the length of the bit field 3 : ";
    cin >> len3;
    cout << endl;

    TBitField BitField3(len3);
    cout << " the bit field len= " << len3 << " :";
    cin >> BitField3;
    cout << endl;

    // вывод битового поля и его длины

    cout << "len of bit field 3: " << BitField3.GetLength() << " ; " << " bit field 3: " << BitField3 << endl;

    //проверка присваивания

    cout << "bit field 3 : " << BitField3 << endl;
    cout << "bit field 1 : " << BitField1 << endl;
    BitField3 = BitField1;
    cout << "  bitfield3 = bitfield1   " <<"_____"<<"bit field 3 : "<< BitField3 << endl;

    // not
    cout << " not " << endl;
    cout << "BitField1 : " << BitField1 << endl;
    TBitField BitField4= ~BitField1;
    cout << "~BitField1 :" << BitField4 << endl;

    // and   
    cout << " and " << endl;
    cout << "BitField1 : " << BitField1 << endl;
    cout << "BitField2 : " << BitField2 << endl;
    TBitField BitField5 = BitField1 & BitField2;
    cout <<"BitField1& BitField2 "<<"BitField5 :" << BitField5 << endl; 

    // or   
    cout << " or " << endl;
    cout << "BitField1 : " << BitField1 << endl;
    cout << "BitField2 : " << BitField2 << endl;
    TBitField BitField6 = BitField1 | BitField2;
    cout << "BitField1 | BitField2 " << "BitField6 :" << BitField6 << endl;

    return 0;

    
}
