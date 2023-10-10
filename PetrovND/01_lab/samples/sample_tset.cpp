#include <iostream>
#include "tset.h"

int main() {
    try {
        TSet set1(10);
        TSet set2(10);

        set1.InsElem(2);
        set1.InsElem(5);
        set1.InsElem(8);

        set2.InsElem(4);
        set2.InsElem(5);
        set2.InsElem(7);

        std::cout << "Set 1: " << set1 << std::endl;
        std::cout << "Set 2: " << set2 << std::endl;

        TSet set3 = set1 + set2;
        std::cout << "Set 1 + Set 2: " << set3 << std::endl;

        TSet set4 = set1 * set2;
        std::cout << "Set 1 * Set 2: " << set4 << std::endl;

        TSet set5 = ~set1;
        std::cout << "NOT Set 1: " << set5 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}