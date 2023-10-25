// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len < 0) {
        throw "Negative length";
    }
    BitLen = len;
    MemLen = ((len + BitsInMem - 1) >> shiftsize);//количество участков памяти под хранение элементов 1-N
    pMem = new TELEM[MemLen];//создать характеристический массив
    memset(pMem, 0, MemLen * sizeof(TELEM));//заполнить MemLen кусков нулями
}

TBitField::TBitField(const TBitField &obj) 
{
    BitLen = obj.BitLen;
    MemLen = obj.MemLen;
    pMem = new TELEM[MemLen];
    memcpy(pMem, obj.pMem, sizeof(TELEM) * MemLen);
}

TBitField::~TBitField()
{
    delete[] pMem;
    MemLen = 0;
    BitLen = 0;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n >> shiftsize;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n & (BitsInMem-1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) {
        throw "Negative length";
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int pos) // очистить бит
{
    if (pos < 0 || pos >= BitLen) {
        throw "Negative length";
    }
    pMem[GetMemIndex(pos)] = pMem[GetMemIndex(pos)] & ~GetMemMask(pos);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) {
        throw "Negative length";
    }
    int test = pMem[GetMemIndex(n)] & GetMemMask(n);
    return (pMem[GetMemIndex(n)] & GetMemMask(n) );
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) {
        return *this;
    }

    BitLen = bf.BitLen;
    if (MemLen != bf.MemLen) {
        MemLen = bf.MemLen;
        TELEM* p = new TELEM[MemLen];
        delete[] pMem;
        pMem = p;
    }
    memcpy(pMem, bf.pMem, MemLen * sizeof(TELEM));
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) {
        return false;
    }
    for (size_t i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return false;
        }
    }
    return true;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) {
        return true;
    }
    for (size_t i = 0; i < MemLen; i++) {
        if (pMem[i] == bf.pMem[i]) {
            return false;
        }
    }
    return true;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
 
    
        if (BitLen != bf.BitLen) {
            TELEM* p = new TELEM[bf.MemLen];
            memset(p, 0, bf.MemLen * sizeof(TELEM));
            memcpy(p, pMem, MemLen * sizeof(TELEM));
            delete[] pMem;
            BitLen = bf.BitLen;
            MemLen = bf.MemLen;
            pMem = p;
        }
        TBitField tmp(*this);
        for (size_t i = 0; i < bf.MemLen; i++) {
            tmp.pMem[i] = tmp.pMem[i] | bf.pMem[i];
        }
        return tmp;
    
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    if (BitLen != bf.BitLen) {
        TELEM* p = new TELEM[bf.MemLen];
        memset(p, 0, bf.MemLen * sizeof(TELEM));
        memcpy(p, pMem, bf.MemLen * sizeof(TELEM));
        delete[] pMem;
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = p;
    }
    TBitField tmp(*this);
    for (size_t i = 0; i < bf.MemLen; i++) {
        tmp.pMem[i] = tmp.pMem[i] & bf.pMem[i];
    }

    return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tbf = (*this);
    for (int i = 0; i < BitLen; i++)
    {
        if (tbf.GetBit(i))
            tbf.ClrBit(i);
        else
            tbf.SetBit(i);
    }
    return tbf;
}

// вывод



ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++) {
        if (bf.GetBit(i)) {
            ostr << "1";
        }
        else { ostr << "0"; }
    }
    return ostr;
}

//Ввод
istream& operator>>(istream& istr, TBitField& obj) {
    string BitField;
    istr >> BitField;

    for (int i = 0; i < BitField.length(); i++) {
        if (BitField[i] == '1') {
            obj.SetBit(i);
        }
        else {
            obj.ClrBit(i);
        }
    }
    return istr;
}