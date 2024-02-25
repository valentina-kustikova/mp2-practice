#include "tstack.h"

#include <iostream>
#include <vector>

int main() {
    try { 
        TStack<int> st;
        int count = 0;
        std::cout << "Enter the number of elements you want to put on the stack: ";
        std::cin >> count;
        std::cout << std::endl;

        int elem;
        std::cout << "Enter elements you want to put on the stack: ";
        for (int i = 0; i < count; i++) {
            std::cin >> elem;
            st.Push(elem);
        }
        std::cout << std::endl;

        std::cout << "Is stack empty? " << st.IsEmpty() << std::endl;
        std::cout << std::endl;

        std::cout << "Enter the number of elements you want to remove from the stack: ";
        std::cin >> count;
        std::cout << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << "Stack item: " << st.Top() << std::endl;
            st.Pop();
        }
        std::cout << std::endl;

        std::cout << "Is stack empty? " << st.IsEmpty() << std::endl;
    }
    catch (std::exception exp) {
        std::cout << exp.what();
    }
    return 0;
}
