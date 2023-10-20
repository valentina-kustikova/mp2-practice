#include <iostream>
#include "tvector.h"

int main()
{
    
    TVector<int> v1(4,1);
    TVector<int> v2(4,1);
    TVector<int> v3(3, 2);
    TVector<int> v4(4, 1);

    for (int i = 0; i < 4; i++)
    {
        v1[i] = i+1;
        v2[i] = i*2 +1;
        v4[i] = v2[i];
    }

    for (int i = 0; i < 3; i++)
    {
        v3[i] = i*3 +1;
    }


    std::cout << "v1 = "<< v1 << '\n';
    std::cout << "v2 = " << v2 << '\n';
    std::cout << "v3 = " << v3 << '\n';
    std::cout << "v4 = " << v4 << '\n'<< '\n';
    
    //getSize
    std::cout << "Size of v1 = v2 = " << v1.GetSize() << '\n';
    std::cout << "Size of v3 = " << v3.GetSize() << '\n' << '\n';
    
    //getIndex
    std::cout << "Index of v1 = v2 = " << v1.GetIndex() << '\n';
    std::cout << "Index of v3 = " << v3.GetIndex() << '\n' << '\n';

    //element on position = index
    std::cout << "Element of v2 on position 3 = " << v2 [3] << '\n' << '\n';

    //==, !=
    std::cout << "v1 == v2? " << (v1 == v2) << '\n';             //0
    std::cout << "v2 != v4? " << (v2 != v4) << '\n';             //0  
    std::cout << "v2 == v4? " << (v2 == v4) << '\n' << '\n';     //1  

    //vector and number
    std::cout << "v1 = " << v1 << '\n' << '\n';

    std::cout << "v1 * 5 = " << v1 * 5 << '\n';
    std::cout << "v1 + 5 = " << v1 + 5 << '\n';
    std::cout << "v1 - 5 = " << v1 - 5 << '\n' << '\n';
    
    //vector and vector
    std::cout << "v1 = " << v1 << '\n';
    std::cout << "v2 = " << v2 << '\n' << '\n';

    std::cout << "v1 + v2 = " << v1 + v2 << '\n';
    std::cout << "v2 - v1 = " << v2 - v1 << '\n';
    std::cout << "v1 scalar * v2 = " << v1 * v2 << '\n';
   
    return 0;

}
