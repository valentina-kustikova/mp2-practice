#include <stack.h>

int main()
{
    ArrayStack<int> s1(5);
    for (int i = 0; i < 101; i++) {
        s1.push(i);
    }
    return 0;
}
