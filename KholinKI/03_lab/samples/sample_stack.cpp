#include <iostream>
#include "Stack.h"
#include <clocale>

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Создание стека..." << endl;
    Stack<double> st;


    cout << endl;
    cout << "Сколько элементов добавить в стек?" << endl;
    int count = 0;
    cin >> count;
    cout << "Добавьте элементы в стек: " << endl;
    for (int i = 0; i < count; i++) {
        cin >> st;
    }
    
    cout << "Вершина стека имеет значение равное " << st.Top() << " и номер в памяти " << st.GetTop() << endl;
    cout << "Текущее количество элементов в стеке равно " << st.Size() << endl;
    cout << endl;

    if (st.IsEmpty()) {
        cout << "Сработала операция проверки на полноту!" << endl;
        cout << "Cтек пустой" << endl;
    }
    else {
        cout << "Сработала операция проверки на полноту!" << endl;
        cout << "Cтек непустой" << endl;
    }
    cout << endl;
    if (st.IsFull()) {
        cout << "Сработала операция проверки на полноту!" << endl;
        cout << "Стек полный" << endl;
    }
    else {
        cout << "Сработала операция проверки на полноту!" << endl;
        cout << "Стек  неполный" << endl;
    }
    cout << endl;
    cout << "Извлечение некоторых элементов из стека..." << endl;
    double stack_item1 = st.Pop();
    double stack_item2 = st.Pop();
    double stack_item3 = st.Pop();
    cout << stack_item1 << " " << stack_item2 << " " << stack_item3 << endl;
    return 0;
}
