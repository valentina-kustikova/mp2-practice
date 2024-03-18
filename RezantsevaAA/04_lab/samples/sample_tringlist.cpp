#include <iostream>
#include "tringlist.h"
using namespace std;
int main()
{
    TRingList<int> ringList;
    ringList.InsrtFirst(8);
    ringList.InsrtFirst(9);
    std::cout << "Created with InsrtFirst ringlist " << std::endl;
    std::cout << ringList << std::endl;

    std::cout << "Lets delete first node in our ringlist " << std::endl;
    ringList.DeleteFirst();
    std::cout << ringList << std::endl;
    
    return 0;
}
