// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len <= 0)
    {
        throw len;
    }
    this->BitLen = len;
    this->MemLen = (len / (sizeof(TELEM) * 8)) + 1;

    pMem = new TELEM[this->MemLen];
    for (int i = 0; i < MemLen; i++)
    {
        pMem[i] = 0;
    }

}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < MemLen; i++)
    {
        this->pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    if (this->pMem != nullptr)
    {
        delete[]this->pMem;
    }
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n<0 || n>this->BitLen)
    {
        throw "Wrong index mem";
    }

    return (n / (sizeof(TELEM) * 8));
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n > this->BitLen)
    {
        throw "Wrong bit mask";
    }

    return 1 << n % (sizeof(TELEM) * 8);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return this->BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n<0 || n > this->BitLen)
    {
        throw "Wrong set bit";
    }

    this->pMem[GetMemIndex(n)] = this->pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n<0 || n > this->BitLen)
    {
        throw "Wrong set bit";
    }

    this->pMem[GetMemIndex(n)] = this->pMem[GetMemIndex(n)] & (~GetMemMask(n));

}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n<0 || n > this->BitLen)
    {
        throw "Wrong set bit";
    }

    int idx = GetMemIndex(n);
    if (GetMemMask(n) == (GetMemMask(n) & pMem[idx]))
    {
        return 1;
    }
    return 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this->pMem == bf.pMem)
    {
        return *this;
    }
    if (this->MemLen != bf.MemLen)
    {
        delete[]this->pMem;        
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    BitLen = bf.BitLen;

    for (int i = 0; i < MemLen; i++)
    {
        pMem[i] = bf.pMem[i];
    }

    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (BitLen != bf.BitLen)
    {
        return 0;
    }
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
        {
            return 0;
        }
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    TBitField ress(max(BitLen, bf.BitLen));
    for (int i=0; i < min(this->MemLen, bf.MemLen); i++)
    {
        ress.pMem[i] = pMem[i] | bf.pMem[i];
    }

    if (MemLen >= bf.MemLen) { // TODO!!! were
        for (int i = bf.MemLen; i < MemLen; i++) {
            ress.pMem[i] = pMem[i];
        }

    }
    else {
        for (int i = MemLen; i < bf.MemLen; i++) {
            ress.pMem[i] = bf.pMem[i];
        }
    }

    return ress;

}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    TBitField ress(max(BitLen, bf.BitLen));

    for (int i = 0; i < min(MemLen, bf.MemLen); i++)
    {
        ress.pMem[i] = pMem[i] & bf.pMem[i];
    }

    if (MemLen >= bf.MemLen) {  // TODO!!! were
        for (int i = bf.MemLen; i < MemLen; i++) {
            ress.pMem[i] = pMem[i];
        }

    }
    else {
        for (int i = MemLen; i < bf.MemLen; i++) {
            ress.pMem[i] = bf.pMem[i];
        }
    }

    return ress;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField ress(BitLen);
    for (int i = 0; i < BitLen; i++)
    {
        if (this->GetBit(i) == 0)
        {
            ress.SetBit(i);
        }
    }
    return ress;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    string bsting;
    istr >> bsting;
    for (int i = 0; i < bf.BitLen; i++) {
        if (bsting[i] == '1') {
            bf.SetBit(i);
        }

    }

    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++)
    {
        ostr << bf.GetBit(i);
    }

    return ostr;
}