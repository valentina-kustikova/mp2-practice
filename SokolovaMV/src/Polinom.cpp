#include "Polinom.h"

TPolinom::TPolinom() {
    TMonom m;
    pHead->data = m;
}

/*TPolinom::TPolinom(const int& m)
{
	TMonom m;
	pHead->data = m;
}/**/
TPolinom::TPolinom(const TMonom &m) {
    insCurrent(m);
}

TPolinom::TPolinom(const TPolinom &p) {

    auto pCurr = p.pFirst;
    auto pPrev = p.pStop;

    for (; !(pCurr == p.pStop);) {
        insLast(pCurr->data);
        pPrev = pCurr;
        pCurr = pCurr->pNext;
    }
}

TPolinom TPolinom::operator*(const double &c) const {
    TPolinom res(*this);
    res.reset();
    while (!res.isEnd()) {
        if (c != 0) {
            res.pCurr->data.coeff *= c;
            res.goNext();
        } else {
            res.RemoveCurr();
        }
    }
    return res;
}//double
TPolinom TPolinom::operator*(const TMonom &m) const {
    TPolinom res(*this);
    res.reset();
    while (!res.isEnd()) {
        if (m.coeff != 0) {
            int x, y, z;
            x = res.pCurr->data.degree / 100;
            y = (res.pCurr->data.degree - x * 100) / 10;
            z = res.pCurr->data.degree - x * 100 - y * 10;
            res.pCurr->data.coeff *= m.coeff;
            x += m.degree / 100;
            y += (m.degree / 10) % 10;
            z += m.degree % 10;
            if (x >= 10 || y >= 10 || z >= 10) {
                throw ("Выход за границу степени");
                break;
            }
            res.pCurr->data.degree = x * 100 + y * 10 + z;
        } else {
            res.RemoveCurr();
        }
        res.goNext();
    }
    return res;
}

TPolinom TPolinom::operator*(const TPolinom& p) const {
    TPolinom tmp1(*this);
    TPolinom tmp2(p);
    TPolinom res;
    tmp2.reset();
    tmp1.reset();
    while (!tmp2.isEnd()) {
        res = res + tmp1 * tmp2.pCurr->data;
        tmp2.goNext();
    }
    return res;
}
/*
TPolinom TPolinom::operator*(const TPolinom &p) const {
    TPolinom tmp1(*this);
    TPolinom tmp2(p);
    TPolinom res;
    tmp2.reset();
    while (!tmp2.isEnd()) {
        tmp1.reset();
        res = res + tmp1 * tmp2.pCurr->data;
        tmp2.goNext();
        if (!tmp1.isEnd()) {
            tmp2.reset();
        }
    }
    return res;
}/**/
TPolinom &TPolinom::operator=(const TPolinom &p) {
    TPolinom res(p);
    res.reset();
    reset();
    while (!isEnd()) {
        RemoveCurr();
    }
    while (!res.isEnd()) {
        TMonom t = res.getCurrdata();
        addMonom(t);
        res.goNext();
    }
    return *this;
}

/*
* 
	TPolinom& operator=(const TPolinom& p) {
		TPolinom tmp(p);
		tmp.reset();
		reset();
		while (!isEnd()) {
			RemoveCurr();
			goNext();
		}
		while (!tmp.isEnd()) {
			TMonom t = tmp.getCurrdata();
			addMonom(t);
			tmp.goNext();
		}
		return *this;
	}
/**/


bool TPolinom::operator==(const TPolinom& p) const {
    TPolinom res(p);
    TPolinom l((*this));
    if (l.isEmpty()) return p == "0";
    TPolinom pthis(*this);
    res.reset();
    pthis.reset();
    while (!res.isEnd()) {
        if ((pthis.getCurrdata() == res.getCurrdata()) == 0) return false;
        res.goNext();
        pthis.goNext();
    }
    return true;
}
/*
bool TPolinom::operator==(const TPolinom &p) const {
    TPolinom res(p);
    TPolinom pthis(*this);
    res.reset();
    pthis.reset();
    while (!res.isEnd()) {
        if ((pthis.getCurrdata() == res.getCurrdata()) == 0) return false;
        res.goNext();
        pthis.goNext();
    }
    return true;
}/**/

bool TPolinom::operator==(const string &s) const {
    TPolinom res(s);
    return *this == res;
}

TPolinom TPolinom::operator-(const TMonom &p) const {
    TPolinom res(p);
    return (*this + res * (-1.0));
}

TPolinom TPolinom::operator-(const TPolinom &p) const {
    TPolinom res(p);
    res = *this + res * (-1.0);
    return (res);
}

TPolinom TPolinom::operator+(const TPolinom &p) const {
    TPolinom pthis(*this);
    TPolinom res(p);
    res.reset();
    pthis.reset();
    while (!pthis.isEnd()) {
        if (res.pCurr->data.degree > pthis.pCurr->data.degree)
            res.goNext();
        else if (res.pCurr->data.degree < pthis.pCurr->data.degree) {
//            res.insCurrent(pthis.pCurr->data);
            res.addMonom(pthis.pCurr->data);
            pthis.goNext();
        } else {
            res.pCurr->data.coeff += pthis.pCurr->data.coeff;
            if (res.pCurr->data.coeff != 0) {
                res.goNext();
                pthis.goNext();
            } else {
                res.RemoveCurr();
                pthis.goNext();
            }
        }

    }
    return res;
}

/*TPolinom TPolinom::operator+(const TMonom& m) const
{
	TPolinom res;
	res.insCurrent(m);
	res = *this + res;
	return res;
}/**/
TPolinom::TPolinom(const string &str) {
    TPolinom res;
    int i = 0;

    while (i < str.length()) {
        if (str[i] == ' ' || str[i] == '+') {
            i++;
            continue;
        }
        string coeff;
        if (str[i] == '-') {
            if (!isdigit(str[i + 1])) {
                coeff = "-1";
                ++i;
            }
            else{
                coeff = "-";
                coeff += str[i + 1];
                i=i+2;
                }
        }
        else {
            for (; isdigit(str[i]) || str[i] == ' ' || str[i] == ','; i++) {
                if (str[i] == ' ') {
                    continue;
                }
                coeff += str[i];
            }
        }

        //if (coeff == "-")
         //   coeff += '1';
        string degX;
        if (str[i] == 'x') {
            i += 1;
            if (str[i] != '^') {
                degX = "1";
            } else {
                i += 1;
                while (isdigit(str[i])) {
                    degX.push_back(str[i]);
                    i++;
                }
            }
        }
        string degY;
        if (str[i] == 'y') {
            i += 1;
            if (str[i] != '^') {
                degY = "1";
            } else {
                i += 1;
                while (isdigit(str[i])) {
                    degY.push_back(str[i]);
                    i++;
                }
            }
        }
        string degZ;
        if (str[i] == 'z') {
            i += 1;
            if (str[i] != '^') {
                degZ = "1";
            } else {
                i += 1;
                while (isdigit(str[i])) {
                    degZ.push_back(str[i]);
                    i++;
                }
            }
        }

        double _coeff = 1;
        int _degX = 0, _degY = 0, _degZ = 0;
        if (!coeff.empty()) _coeff = stod(coeff);
        if (!degX.empty()) _degX = stoi(degX);
        if (!degY.empty()) _degY = stoi(degY);
        if (!degZ.empty()) _degZ = stoi(degZ);
        if ((_degX > 9) || (_degY > 9) || (_degZ > 9)) {
            throw ("Выход за границу степени");
        }

        int d = _degX * 100 + _degY * 10 + _degZ;
        TMonom m(_coeff, d);
        addMonom(m);
    }
}

void TPolinom::addMonom(const TMonom &m) {
    for (reset(); !isEnd(); goNext()) {
        if (m == pCurr->data) {
            pCurr->data.coeff += m.coeff;
            if (pCurr->data.coeff == 0) {
                RemoveCurr();
            }
            break;
        }
        if (m > pCurr->data) {
            insCurrent(m);
            break;
        }
    }
    if (isEnd()) {
        insLast(m);
    }
}

double TPolinom::operator()(double x, double y, double z)
{

    {
        double res = 0.0;
        this->reset();
        while (!this->isEnd())
        {
            double stx = this->getCurrdata().degree / 100;
            double sty = this->getCurrdata().degree / 10 % 10;
            double stz = this->getCurrdata().degree % 10;
            res += this->getCurrdata().coeff * pow(x, stx) * pow(y, sty) * pow(z, stz);
            this->goNext();
        }
        return res;
    }
}
/**/
