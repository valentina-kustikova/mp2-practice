#include "TMonom.h"
#include <iostream>
#include <string>

using namespace std;

typedef TNode<unsigned int, double> TMonom;

TNode<unsigned int, double>::TNode() {
    key = 0;
    pData = 0;
    pNext = NULL;
}

TNode<unsigned int, double>::TNode(unsigned int _key, double _data, TNode<unsigned int, double>* node) {
    key = _key;
    pData = _data;
    pNext = node;
}

TNode<unsigned int, double>::TNode(const TMonom& tmp) {
    key = tmp.key;
    pData = tmp.pData;
    pNext = NULL;
}

TNode<unsigned int, double>::TNode(const string& str) {
    string sim, coef, degree, degreeX, degreeY, degreeZ = "0";

    for (int i = 0; i < str.length(); i++) {
        if ((str[i] != '*') && (str[i] != '^')) {
            sim += str[i];
        }
    }

    if ((sim[0] == 'x') || (sim[0] == 'y') || (sim[0] == 'z')) {
        coef = 1;
    }

    int i = 0;
    while ((sim[i] != 'x') && (sim[i] != 'y') && (sim[i] != 'z') && (i < str.length())) {
        coef += sim[i];
        i++;
    }

    for (int j = 0; j < str.length(); j++) {
        switch (sim[j]) {
        case 'x':
            j++;
            if ((sim[j] == 'y') || (sim[j] == 'z') || (str.length() == j)) {
                degreeX = 1;
            }
            else {
                degreeX = sim[j];
                j++;
            }
            break;
        
        case 'y':
            j++;
            if ((sim[j] == 'x') || (sim[j] == 'z') || (str.length() == j)) {
                degreeY = 1;
            }
            else {
                degreeY = sim[j];
                j++;
            }
            break;

        case 'z':
            j++;
            if ((sim[j] == 'x') || (sim[j] == 'y') || (str.length() == j)) {
                degreeZ = 1;
            }
            else {
                degreeZ = sim[j];
                j++;
            }
            break;

        default:
            break;
        }
    }

    degree = degreeX + degreeY + degreeZ;
    pData = stod(coef);
    key = stoi(degree);
    pNext = NULL;
}

TNode<unsigned int, double>::~TNode() {}

TMonom& TNode<unsigned int, double>::operator=(const TNode<unsigned int, double>& tmp) {
    if (*this == tmp) return *this;

    key = tmp.key;
    pData = tmp.pData;
    pNext = NULL;
    return *this;
}

TMonom TNode<unsigned int, double>::operator+(const TNode<unsigned int, double>& tmp) {
    if (key != tmp.key) throw "add unsuccessfully";

    TMonom rez(tmp);
    rez.pData += pData;
    return rez;
}

TMonom TNode<unsigned int, double>::operator-(const TNode<unsigned int, double>& tmp) {
    if (key != tmp.key) throw "dif unsuccessfully";

    TMonom rez(tmp);
    rez.pData -= pData;
    return rez;
}

TMonom TNode<unsigned int, double>::operator*(const TNode<unsigned int, double>& tmp) {
    if (key + tmp.key < 0 || key + tmp.key > 999) throw "incorrect degree";

    TMonom rez;
    rez.pData = pData * tmp.pData;
    rez.key = key + tmp.key;
    return rez;
}

TMonom TNode<unsigned int, double>::operator-() const {
    TMonom rez(*this);
    rez *= (-1);
    return rez;
}

TMonom TNode<unsigned int, double>::operator*(double c) {
    TMonom rez(*this);
    rez.pData *= c;
    return rez;
}

bool TNode<unsigned int, double>::operator==(const TNode<unsigned int, double>& tmp) const {
    if ((tmp.key != key) || (tmp.pData != pData)) return false;
    return true;
}

bool TNode<unsigned int, double>::operator>(const TNode<unsigned int, double>& tmp) const {
    return (key > tmp.key);
}

bool TNode<unsigned int, double>::operator<(const TNode<unsigned int, double>& tmp) const {
    return (key < tmp.key);
}

bool TNode<unsigned int, double>::operator!=(const TNode<unsigned int, double>& tmp) const {
    return !(*this == tmp);
}

TMonom& TNode<unsigned int, double>::operator+=(const TNode<unsigned int, double>& tmp) {
    if (key != tmp.key)
        throw "unsuccessfully";
    pData += tmp.pData;
    return *this;
}

TMonom& TNode<unsigned int, double>::operator-=(const TNode<unsigned int, double>& tmp) {
    if (key != tmp.key)
        throw "unsuccessfully";
    pData -= tmp.pData;
    return *this;
}

TMonom& TNode<unsigned int, double>::operator*=(const TNode<unsigned int, double>& tmp) {
    if (key + tmp.key < 0 || key + tmp.key > 999) throw "incorrect degree";

    key += tmp.key;
    pData *= tmp.pData;
    return *this;
}

TMonom& TNode<unsigned int, double>::operator*=(double c) {
    pData *= c;
    return (*this);
}