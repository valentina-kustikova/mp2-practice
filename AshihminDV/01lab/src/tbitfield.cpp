// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
//static const int FAKE_INT = -1;
//static TBitField FAKE_BITFIELD(1);

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
    if (this->BitLen != bf.BitLen)
    {
        if(BitLen>0)
        {
            delete[]this->pMem;
        }
    }
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
    if (this->pMem == nullptr)
    {
        throw "Wrong set bit pMem=nullptr";
    }

    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);

}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n<0 || n > this->BitLen)
    {
        throw "Wrong set bit";
    }
    if (this->pMem == nullptr)
    {
        throw "Wrong set bit pMem=nullptr";
    }

    this->pMem[GetMemIndex(n)] = this->pMem[GetMemIndex(n)] & (~GetMemMask(n));



}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n<0 || n > this->BitLen)
    {
        throw "Wrong set bit";
    }
    if (this->pMem == nullptr)
    {
        throw "Wrong set bit pMem=nullptr";
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
    if (bf.pMem == nullptr)
    {
        BitLen = 0;
        MemLen = 0;
        pMem = 0;
        return *this;
    }
    if (pMem == bf.pMem)
    {
        return *this;
    }
    if (BitLen != bf.BitLen)
    {
        delete[]pMem;
    }
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
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
    if (BitLen != bf.BitLen)
    {
        return 1;
    }
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
        {
            return 1;
        }
    }
    return 0;
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    TBitField ress(max(BitLen, bf.BitLen));

    if (MemLen >= bf.MemLen) {
        for (int i = 0; i < bf.MemLen; i++) {
            ress.pMem[i] = pMem[i] | bf.pMem[i];
        }
        for (int i = bf.MemLen; i < MemLen; i++) {
            ress.pMem[i] = pMem[i];
        }

    }
    else {
        for (int i = 0; i < MemLen; i++) {
            ress.pMem[i] = pMem[i] | bf.pMem[i];
        }
        for (int i = MemLen; i < bf.MemLen; i++) {
            ress.pMem[i] = bf.pMem[i];
        }
    }

    return ress;

}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    TBitField ress(max(BitLen, bf.BitLen));
    int i = 0;

    if (MemLen >= bf.MemLen) {
        for (int i = 0; i < bf.MemLen; i++) {
            ress.pMem[i] = pMem[i] & bf.pMem[i];
        }
        for (int i = bf.MemLen; i < MemLen; i++) {
            ress.pMem[i] = pMem[i];
        }

    }
    else {
        for (int i = 0; i < MemLen; i++) {
            ress.pMem[i] = pMem[i] & bf.pMem[i];
        }
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
    for (int i = 0; i < bf.BitLen; i++)
    {
        int bit;
        istr >> bit;
        if (bit)
        {
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