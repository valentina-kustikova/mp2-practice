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
    cout << "\n\t�������� ��������, ������� �� ������ ����������\n\t1.������ ��������\n\t2.������� ��� ��������\n\t3.�������� ������� �� ���������\n\t4.����������� �������� ��������\n\t5.��������� �������� �������� ��� �������� ���������"<<endl;
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
            cout << "\n\t������� ������� A:";
            cin >> A; 
            cout << "\n\t������� ������� B:";
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
