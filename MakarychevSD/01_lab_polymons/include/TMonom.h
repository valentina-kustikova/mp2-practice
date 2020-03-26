#ifndef TMONOM_H
#define TMONOM_H

#include "TNode.h"
#include "Exception.h"

template<>
class TNode<unsigned int, float>
{
public:
	unsigned int key;
	float pData;
	TNode<unsigned int, float>* pNext;
	TNode() : key(0), pData(0), pNext(nullptr)
	{
	}
	TNode(int NewKey, float Data, TNode<unsigned int, float>* next = nullptr) :key(NewKey), pData(Data), pNext(next)
	{
	}
	TNode(const TNode& tmp) : key(tmp.key), pData(tmp.pData), pNext(nullptr)
	{
	}
	TNode(unsigned int deg_x, unsigned int deg_y, unsigned int deg_z, float coeff, TNode<unsigned int, float>* next = nullptr);
	~TNode()
	{
		pNext = nullptr;
	}
	TNode<unsigned int, float> operator*(const TNode<unsigned int, float>&);
	TNode<unsigned int, float> operator+(const TNode<unsigned int, float>&);
	TNode<unsigned int, float> operator-(const TNode<unsigned int, float>&);
	TNode<unsigned int, float>* operator-()const;
	bool operator <(const TNode<unsigned int, float>&)const;
	bool operator >(const TNode<unsigned int, float>&)const;
	bool operator !=(const TNode<unsigned int, float>&)const;
	bool operator ==(const TNode<unsigned int, float>&)const;
	const TNode<unsigned int, float>& operator= (const TNode<unsigned int, float>& monom);
};

TNode<unsigned int, float> ::TNode(unsigned int deg_x, unsigned int deg_y, unsigned int deg_z, float coeff, TNode<unsigned int, float>* next)
{
	if (deg_x > 9 || deg_x < 0 || deg_y > 9 || deg_y < 0 || deg_z > 9 || deg_z < 0)
		throw M_Exeption("invalid parameter");
	this->key = deg_x * 100 + deg_y * 10 + deg_z;
	this->pData = coeff;
	this->pNext = next;
}

bool TNode<unsigned int, float> ::operator <(const TNode& OtherMonom)const
{
	return(this->key < OtherMonom.key);
}

bool TNode<unsigned int, float> ::operator >(const TNode& OtherMonom)const
{
	return(this->key > OtherMonom.key);
}

bool TNode<unsigned int, float> ::operator ==(const TNode& OtherMonom)const
{
	return(this->key == OtherMonom.key && this->pData == OtherMonom.pData);
}

bool TNode<unsigned int, float> ::operator !=(const TNode& OtherMonom)const
{
	return(!(*this == OtherMonom));
}

const TNode<unsigned int, float>& TNode<unsigned int, float> :: operator=(const TNode<unsigned int, float>& monom)
{
	if (*this == monom)
		return *this;
	this->key = monom.key;
	this->pData = monom.pData;
	return *this;
}

TNode<unsigned int, float> TNode<unsigned int, float>::operator*(const TNode<unsigned int, float>& monom)
{
	int deg_x1 = this->key / 100;
	int deg_y1 = (this->key - deg_x1 * 100) / 10;
	int deg_z1 = this->key - deg_x1 * 100 - deg_y1 * 10;
	int deg_x2 = monom.key / 100;
	int deg_y2 = (monom.key - deg_x2 * 100) / 10;
	int deg_z2 = monom.key - deg_x2 * 100 - deg_y2 * 10;
	if (deg_z1 + deg_z2 > 9 || deg_y1 + deg_y2 > 9 || deg_x1 + deg_x2 > 9)
		throw M_Exeption("invalid parameter");
	TNode<unsigned int, float> product(this->key + monom.key, this->pData * monom.pData);
	return product;
}

TNode<unsigned int, float> TNode<unsigned int, float>::operator+(const TNode<unsigned int, float>& monom)
{
	if (this->key != monom.key)
		throw M_Exeption("monoms have different degrees");
	return TNode<unsigned int, float>(monom.key, this->pData + monom.pData);
}

TNode<unsigned int, float> TNode<unsigned int, float>::operator-(const TNode<unsigned int, float>& monom)
{
	if (this->key != monom.key)
		throw M_Exeption("monoms have different degrees");
	return TNode<unsigned int, float>(monom.key, this->pData - monom.pData);
}
TNode<unsigned int, float>* TNode<unsigned int, float>::operator-() const
{
	TNode<unsigned int, float>* tmp = new TNode<unsigned int, float>(*this);
	tmp->pData = -1 * tmp->pData;
	return tmp;
}

#endif 
