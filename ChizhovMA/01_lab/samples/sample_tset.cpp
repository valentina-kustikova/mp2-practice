#include <iostream>
#include "tset.h"

using namespace std;

int main()
{
    cout << "TSet" << endl;

    int maxPower;      // ������������ �������� ���������
    cout << "Enter the max size: ";
    cin >> maxPower;

    // �������� ��������� � ������������ ��������� maxPower
    TSet set1(maxPower);
    TSet set2(maxPower);

    cout << "Enter set1" << endl;
    cin >> set1;// ���������� ��������� � ���������
  
    cout << "Enter set2" << endl;
    cin >> set2;

    cout << "set1: " << set1 << endl;   // ����� ��������� �� �����
    cout << "set2: " << set2 << endl;

    // �������� ������� ��������� � ���������
    cout << "Element 5 in set1: " << set1.IsMember(5) << endl;
    cout << "Element 2 in set2: " << set2.IsMember(2) << endl;

    // �������� ������ ��������� set2, ������� set1

    // �������� �������� �� ��������� set2
    set2.DelElem(3);

    // ����� ��������� set2 �� �����
    cout << "set2 after delete 3: " << set2 << endl;

    // �������� ��������
    cout << "operator==: " << (set1 == set2) << endl;
    cout << "operator!=: " << (set1 != set2) << endl;
    cout << "operator+ (elem + 0): " << (set1 + 0) << endl;
    cout << "operator- (elem - 5): " << (set1 - 5) << endl;
    cout << "operator*: " << (set1 * set2) << endl;
    cout << "operator+: " << (set1 + set2) << endl;
    cout << "operator~: " << ~set1 << endl;
    cout << "operator= (set2=set1): " << (set2 = set1) << endl;
    return 0;
}
