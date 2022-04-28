#include "polinom.h"
#include <string>
#include <cmath>
#include <iostream>
#include "node.h"
#include "monom.h"

using namespace std; 

void menu()
{
    setlocale(LC_ALL, "Russian");
    cout << "\n\tВЫБЕРИТЕ ДЕЙСТВИЕ, КОТОРОЕ ВЫ ХОТИТЕ ПРОИЗВЕСТИ\n\t1.Ввести полиномы\n\t2.Сложить два полинома\n\t3.Умножить полином на константу\n\t4.Перемножить введеные полиномы\n\t5.Посчитать значение полинома при заданных значениях"<<endl;
}

int main()
{
    cout << "START" <<endl;
    int V = 100;
    while (V != 0)
    {

        system("cls");
        menu();
        cin >> V;
        system("cls");
        switch (V)
        {
        case 1:
        {
            std::string A, B;
            cout << "\n\tВведите полином A:";
            cin >> A; 
            cout << "\n\tВведите полином B:";
            cin >> B;
            system("cls");
            

        }
        case 2:
        {

        }
        case 3:
        {

        }
        case 4:
        {

        }
        case 5:
        {

        }

        }

    }
    
    TNode *node = new TNode;
    //node->data = new TMonom(1, 101);
    node->pNext = nullptr;
    std::cout << "FINISH" << std::endl;
	return 0;
}
