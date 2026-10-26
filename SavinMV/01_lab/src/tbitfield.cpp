// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"



static const int TELEM_BITS = sizeof(TELEM) * 8;

TBitField::TBitField(int len)
{
    if (len < 0)
        throw std::invalid_argument("length cannot be negative");
    BitLen = len;
    MemLen = (len + TELEM_BITS - 1) / (TELEM_BITS);
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
        pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0 || n >= BitLen) {
        throw("err");
    }
    return n / (TELEM_BITS);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n >= BitLen) {
        throw("err");
    }
    return 1 << (n % (TELEM_BITS));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen)
        throw std::out_of_range("TBitField: bit index out of range");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen)
        throw std::out_of_range("TBitField: bit index out of range");
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
    
}


int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen)
        throw std::out_of_range("TBitField: bit index out of range");
    if (pMem[GetMemIndex(n)] & GetMemMask(n)) return 1;
    else return 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (&bf == this) {
        return *this;
    }

    if (MemLen != bf.MemLen) {
        delete[] pMem;
        pMem = new TELEM[bf.MemLen];
    }

    BitLen = bf.BitLen;
    MemLen = bf.MemLen;

    for (int i = 0; i < bf.MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }

    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) return 0;
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int maxLen = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField res(maxLen);
    int minMemLen = (MemLen < bf.MemLen) ? MemLen : bf.MemLen;

    for (int i = 0; i < minMemLen; i++) {
        res.pMem[i] = pMem[i] | bf.pMem[i];
    }

    int i = minMemLen;
    while (i < MemLen) {
        res.pMem[i] = pMem[i];
        i++;
    }
    while (i < bf.MemLen) {
        res.pMem[i] = bf.pMem[i];
        i++;
    }
    
    return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int maxLen = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
    TBitField res(maxLen);
    int minMemLen = (MemLen < bf.MemLen) ? MemLen : bf.MemLen;

    int i = 0;
    while (i < minMemLen) {
        res.pMem[i] = pMem[i] & bf.pMem[i];
        i++;
    }
    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(BitLen);
    for (int i = 0; i < MemLen; i++)
        res.pMem[i] = ~pMem[i];
    
    int tail = BitLen % TELEM_BITS;
    if (tail != 0)
        res.pMem[MemLen - 1] &= (1 << tail) - 1;
    return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = 0; i < bf.BitLen; i++)
    {
        int bit;
        istr >> bit;
        if (bit)
            bf.SetBit(i);
        else
            bf.ClrBit(i);
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++)
        ostr << bf.GetBit(i);
    return ostr;
}
