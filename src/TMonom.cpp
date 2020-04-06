#include "TMonom.h"

TNode<double, unsigned int>::TNode() : pData(0), key(0), pNext(nullptr) {}

TNode<double, unsigned int>::TNode(unsigned int _key, double _pData, TNode* _pNext) : key(_key), pData(_pData), pNext(_pNext) {}

TNode<double, unsigned int>::TNode(const TNode<double, unsigned int>& node) : key(node.key), pData(node.pData), pNext(nullptr) {}

TNode<double, unsigned int>& TNode<double, unsigned int>::operator=(const TNode& mon)
{
    if (*this == mon)
        return *this;
    key = mon.key;
    pData = mon.pData;
    pNext = nullptr;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator+(const TNode<double, unsigned int>& mon)
{
    if (key != mon.key)
        throw "Monoms have diffrent degrees";
    TNode<double, unsigned int> res(mon);
    res.pData += pData;
    return res;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator-(const TNode<double, unsigned int>& mon)
{
    if (key != mon.key)
        throw "Monoms have diffrent degrees";
    TNode<double, unsigned int> res(*this);
    res.pData -= mon.pData;
    return res;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator*(const TNode<double, unsigned int>& mon)
{
    if (((mon.key / 100) + (key / 100) > 9) || (((mon.key / 10) % 10) + ((key / 10) % 10) > 9) || ((mon.key % 10) + (key % 10) > 9))
        throw "Degree limit exceeded";
    TNode<double, unsigned int> res;
    res.pData = pData * mon.pData;
    res.key = key + mon.key;
    return res;
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator*(double a)
{
    TNode<double, unsigned int> res(*this);
    res.pData *= a;
    return res;
}

TNode<double, unsigned int>& TNode<double, unsigned int>::operator+=(const TNode<double, unsigned int>& tmp)
{
    if (key != tmp.key)
        throw "Monoms have diffrent degrees";
    pData += tmp.pData;
    return *this;
}
TNode<double, unsigned int>& TNode<double, unsigned int>::operator-=(const TNode<double, unsigned int>& tmp)
{
    if (key != tmp.key)
        throw "Monoms have diffrent degrees";
    pData -= tmp.pData;
    return *this;
}
TNode<double, unsigned int>& TNode<double, unsigned int>::operator*=(const TNode<double, unsigned int>& tmp)
{
    if (((tmp.key / 100 + key / 100) > 9) || ((tmp.key / 10 + key / 10) > 90)
        || ((tmp.key % 10 + key % 10) > 9))
        throw "Degree limit exceeded";
    key += tmp.key;
    pData *= tmp.pData;
    return *this;
}
TNode<double, unsigned int>& TNode<double, unsigned int>::operator*=(double c)
{
    pData *= c;
    return *this;
}

bool TNode<double, unsigned int>::operator==(const TNode<double, unsigned int>& mon) const
{
    if ((key == mon.key) && (pData == mon.pData))
        return true;
    return false;
}

bool TNode<double, unsigned int>::operator!=(const TNode<double, unsigned int>& mon) const
{
    return (!(*this == mon));
}

TNode<double, unsigned int> TNode<double, unsigned int>::operator-() const
{
    TNode<double, unsigned int> res(key, -pData);
    return res;
}