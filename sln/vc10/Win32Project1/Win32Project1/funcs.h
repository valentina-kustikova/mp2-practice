#pragma once
#include <map>
#include"Stack.h"
#include <string>
using namespace std;
class funcs {
private:
	static int checkpriority(char);//�������� ���������� � �������
	static map<char, float> readvalue(string);//������������ ���������� ���� map,��� ����-������ ��������,a ��������-�������� ��������
public:
	static void calculate(string);//������� ��������������� ���������
	static string postfixform(string);//������� � ����������� �����
	static bool checkcorrectness(string);//�������� ������ �� ������������
};