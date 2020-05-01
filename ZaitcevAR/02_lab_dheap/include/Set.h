#pragma once
#include "Exception.h"

class Set
{
private:
	int size; // ������
	int* keys; // �������� ���������
public:
	Set(int size_ = 10);
	Set(int size_, int* keys_);
	~Set();

	// �������� ������������� ������������
	void CreateOneElemSubset(int id);
	// ����������� 2 ����������� � ������
	void UnitedSubsets(int id_1, int id_2);
	// ����������� ������������, �������� ����������� ��-�
	int GetNameOfSubset(int id);
};