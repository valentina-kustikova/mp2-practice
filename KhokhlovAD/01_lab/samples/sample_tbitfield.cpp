#include <iostream>
#include "tbitfield.h"

int main()
{
    const int size1 = 4, size2 = 6;
    TBitField bf1(size1), bf2(size2);
    bool a = (bf1 != bf2);
    bool b = (bf1 == bf2);
    cout << "bf1 = " << bf1 << endl << "b2 = " << bf2 << endl;
    std::cout <<"bf1 != bf2 -> " << a << endl <<"bf1 == bf 2 -> " << b << std::endl;
    TBitField bf3(1);
    TBitField bf4(bf1);
    cout << "enter bf len4" << endl;
    cin >> bf4;
    cout << "bf4 = " << bf4 << endl;
    int z = bf4.GetLength();
    cout << "bf4.lenght = " << z << endl;
    bf4.ClrBit(2);
    cout << "bf4.clrbit(2) = " << bf4 << endl;
    bf3 = bf2;
    cout << "bf3 = bf2 -> " << bf3 << endl;
    bf3.SetBit(0);
    cout << "bf3.setbit(0) -> " << bf3 << endl;
    bf1 = bf3 | bf4;
    cout << "bf1 = bf3 | bf4 -> " << bf1 << endl;
    bf2 = bf3 & bf4;
    cout <<"bf2 = bf3 & bf4 -> "<< bf2  << endl;
    bf3 = ~bf4;
    cout <<"bf3 = ~bf4 -> " << bf3 << endl;
    system("PAUSE");
    return 0;
}
