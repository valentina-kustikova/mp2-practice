#include "Monom.h"
TNode<unsigned int, double>::TNode(const TNode<unsigned int, double>& _node)
{
	key = _node.key;
	pData = _node.pData;
	if (_node.pNext == nullptr)
		pNext = nullptr;
	else
	pNext = _node.pNext;
}
TNode<unsigned int, double>::TNode(unsigned int _key, double _data, TNode<unsigned int, double>* node)
{
	//if (_key < 0 || _key > 999 || _data == 0.0)
		//throw "incorrect monom";
	key = _key;
	pData = _data;
	if (node)
	{
		if (node->pNext == nullptr)
			pNext = nullptr;
		pNext = node->pNext;
	}
	else
	pNext = nullptr;
	/*if (node->pNext == nullptr)
		pNext = nullptr;
	else
		*pNext = *node->pNext;*/
}
TNode<unsigned int, double>::TNode(const string& monom)
{
	string simbols;
	string coef;
	string degree;
	string degree1;
	string degree2;
	string degree3;
	for (int i = 0; i < monom.length(); i++)
		if (monom[i] != '*' && monom[i] != '^')
			simbols += monom[i];
	if (simbols[0] == 'x' || simbols[0] == 'y' || simbols[0] == 'z')
		coef = '1';
	int i = 0;
	while (simbols[i] != 'x' && simbols[i] != 'y' && simbols[i] != 'z' && i < simbols.length())
	{
		coef += simbols[i];
		i++;
	}
	for (int i = 0; i < simbols.length(); i++)
	{
		if (simbols[i] == 'x')
		{
			i++;
			if (simbols[i] == 'y' || simbols[i] == 'z' || i == simbols.length())
				degree1 = '1';
			else {
				degree1 = simbols[i];
				i++;
			}
		}
		if (simbols[i] == 'y')
		{
			i++;
			if (simbols[i] == 'x' || simbols[i] == 'z' || i == simbols.length())
				degree2 = '1';
			else {
				degree2 = simbols[i];
				i++;
			}
		}
		if (simbols[i] == 'z')
		{
			i++;
			if (simbols[i] == 'x' || simbols[i] == 'y' || i == simbols.length())
				degree3 = '1';
			else {
				degree3 = simbols[i];
				i++;
			}
		}
	}
	degree = degree1 + degree2 + degree3;
	pData = stod(coef);
	key = stoi(degree);
	pNext = nullptr;
}
TNode<unsigned int, double>::~TNode()
{}
TNode<unsigned int, double> TNode<unsigned int, double>::operator*(double number)
{
	TNode<unsigned int, double> result(*this);
	result.pData = result.pData * number;
	return result;
}
TNode<unsigned int, double> TNode<unsigned int, double>::operator+(const TNode<unsigned int, double>& slog)
{
	if (key != slog.key)
		throw "additiion can`t be performed";
	TNode<unsigned int, double> result(*this);
	result.pData = result.pData + slog.pData;
	return result;
}
TNode<unsigned int, double> TNode<unsigned int, double>::operator-(const TNode<unsigned int, double>& slog)
{
	if (key != slog.key)
		throw "additiion can`t be performed";
	TNode<unsigned int, double> result(*this);
	result.pData = result.pData - slog.pData;
	return result;
}
TNode<unsigned int, double> TNode<unsigned int, double>::operator*(const TNode<unsigned int, double>& slog)
{
	TNode<unsigned int, double> result(*this);
	result.pData = result.pData * slog.pData;
	result.key = result.key + slog.key;
	return result;
}
TNode<unsigned int, double> TNode<unsigned int, double>::operator-() const
{
	TNode<unsigned int, double> result(*this);
	result.pData = result.pData * -1;
	return result;
}
TNode<unsigned int, double>& TNode<unsigned int, double>::operator=(const TNode<unsigned int, double>& slog)
{
	if (*this == slog)
		return *this;
	pData = slog.pData;
	key = slog.key;
	pNext = slog.pNext;
	return *this;
}
bool TNode<unsigned int, double>::operator>(const TNode<unsigned int, double>& slog) const
{
	return (key > slog.key);
}
bool TNode<unsigned int, double>::operator==(const TNode<unsigned int, double>& slog) const
{
	if (key == slog.key && pData == slog.pData)
		return true;
	return false;
}
bool TNode<unsigned int, double>::operator!=(const TNode<unsigned int, double>& slog) const
{
	return !(*this == slog);
}
bool TNode<unsigned int, double>::operator<(const TNode<unsigned int, double>& slog) const
{
	if (this == nullptr) return false;
	return (key < slog.key);
}