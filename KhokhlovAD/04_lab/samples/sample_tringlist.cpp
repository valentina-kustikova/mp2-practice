#include <iostream>
#include <tringlist.h>

int main()
{
    int data, N;
    TRingList<int> ringList;
    std::cin >> ringList;
    
    std::cout << "Created with InsrtFirst ringlist " << std::endl;
    std::cout << ringList << std::endl;

    std::cout << "Lets delete first node in our ringlist " << std::endl;
    ringList.DeleteFirst();
    std::cout << ringList << std::endl;
    ringList.Reset();
    std::cout << "Lets sort nodes in our ringlist " << std::endl;
    ringList.Sort();
    std::cout << ringList << std::endl;

    std::cout << "Is empty? " << ringList.IsEmpty()<< std::endl;
    std::cout << "Is full? " << ringList.IsFull() << std::endl;
    return 0;
}
