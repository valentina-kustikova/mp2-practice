#include <iostream>
#include "TVector.h"

int main()
{

    TVector<int> v1(4, 1);
    TVector<int> v2(4, 1);
    TVector<int> v3(3, 2);
    TVector<int> v4(4, 1);

    for (int i = 0; i < 4; i++)
    {
        v1[i] = i + 1;
        v2[i] = i * 3 + 1;
        v4[i] = v2[i];
    }

    cin >> v3;


    std::cout << "v1 = " << v1 << '\n';
    std::cout << "v2 = " << v2 << '\n';
    std::cout << "v3 = " << v3 << '\n';
    std::cout << "v4 = " << v4 << '\n' << '\n';


    std::cout << "Size of v1 = v2 = " << v1.GetSize() << '\n';
    std::cout << "Size of v3 = " << v3.GetSize() << '\n' << '\n';

    std::cout << "v1 == v2? " << (v1 == v2) << '\n';            
    std::cout << "v2 != v4? " << (v2 != v4) << '\n';               
    std::cout << "v2 == v4? " << (v2 == v4) << '\n' << '\n';       

    std::cout << "v1 * 5 = " << v1 * 5 << '\n';
    std::cout << "v1 + 5 = " << v1 + 5 << '\n';
    std::cout << "v1 - 5 = " << v1 - 5 << '\n' << '\n';

    std::cout << "v1 + v2 = " << v1 + v2 << '\n';
    std::cout << "v2 - v1 = " << v2 - v1 << '\n';
    std::cout << "v1 scalar * v2 = " << v1 * v2 << '\n';

    return 0;

}