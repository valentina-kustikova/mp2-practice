// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"



TBitField::TBitField(int len)
{
    if (len <= 0) {
        throw "ERROR";
    }

    BitLen = len;
    MemLen = (len - 1) / (sizeof(TELEM) * 8) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    MemLen = bf.MemLen;
    BitLen = bf.BitLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] this->pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0)
    {
        throw "NEGATIVE INDEX";
    }
    if (n >= BitLen)
    {
        throw "BIG INDEX";
    }
    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if ((n < 0) || (n > BitLen)) {
        throw "ERROR";
    }
    return 1 << (n % (8 * sizeof(TELEM)));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n < 0) || (n > BitLen)) {
        throw "ERROR";
    }
    int i = GetMemIndex(n);
    int m = GetMemMask(n);
    pMem[i] = pMem[i] | m;
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n < 0) || (n > BitLen)) {
        throw "ERROR";
    }
    int i = GetMemIndex(n); 
    int m = GetMemMask(n);
    pMem[i] = pMem[i] & ~m;
    
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n < 0) || (n > BitLen)) {
        throw "ERROR";
    }
    if ((pMem[n / (sizeof(TELEM) * 8)] & GetMemMask(n)) == 0) return 0; 
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this == &bf) { 
        return *this;
    }
    if (MemLen != bf.MemLen) {
        MemLen = bf.MemLen;
        delete[] this->pMem;
    }
    pMem = new TELEM[MemLen];
    BitLen = bf.BitLen;
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen){
        return 0;
    }
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 0;
        }
    }
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField tmp(max(BitLen, bf.BitLen));

    for (int i = 0; i < min(this->MemLen, bf.MemLen); i++) { 
        tmp.pMem[i] = pMem[i] | bf.pMem[i]; 
    }
    if (MemLen > bf.MemLen) {
        for (int i = bf.MemLen; i < MemLen; i++) {
            tmp.pMem[i] = pMem[i];
        }
    }
    else {
        for (int i = MemLen; i < bf.MemLen; i++) {
            tmp.pMem[i] = bf.pMem[i];
        }
    }
    return tmp;
    
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    TBitField tmp(max(BitLen, bf.BitLen));  
    for (int i = 0; i < min(this->MemLen, bf.MemLen); i++) { 
        tmp.pMem[i] = pMem[i] & bf.pMem[i];
    } 
    
    return tmp;
   
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tmp(*this);
    for (int i = 0; i < this->BitLen; i++)  
    {
        if (GetBit(i) == 0){
            tmp.SetBit(i); 
        }
        else
        {
            tmp.ClrBit(i); 
        }
    }
    return tmp; 
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string s;
    cout << "Enter bitlength " << endl;
    cin >> s;
    if (sizeof(s) * 8 >= bf.GetLength()) {
        throw range_error("The size isn't equal");
    }
    for (int i = 0; i < bf.GetLength(); i++) {
        if (s[i] == '1') {
            bf.SetBit(i);
        }
        else if (s[i] == '0') {
            bf.ClrBit(i);
        }
        else {
            throw range_error("NOT BIT"); 
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    ostr << "Our bitfield length is " << bf.GetLength() << endl;
    for (int i = 0; i < bf.GetLength(); i++) {
        ostr << "BIT of " << i << " " << bf.GetBit(i) << endl;
    }
    return ostr;
}