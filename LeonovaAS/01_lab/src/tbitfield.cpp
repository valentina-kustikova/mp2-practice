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
       throw "negative len";
   BitLen = len;
   MemLen = (len / (sizeof(TELEM) * 8)) + 1;
   pMem = new TELEM[MemLen];
   for (int i = 0; i < MemLen; i++)
   {
       pMem[i] = 0;
   }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
    {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[]this->pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0)
    {
        throw "negative idx!";
    }
    if (n >= BitLen)
    {
        throw "too large idx!";
    }
    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n % (8 * sizeof(TELEM)));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0)
    {
        throw "negative idx!";
    }
    if (n >= BitLen)
    {
        throw "too large idx!";
    }
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0)
    {
        throw "negative idx!";
    }
    if (n >= BitLen)
    {
        throw "too large idx!";
    }
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}


int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0)
    {
        throw "negative idx!";
    }
    if (n >= BitLen)
    {
        throw "too large idx!";
    }
    return  (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n % (8 * sizeof(TELEM)));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf)
    {
        return *this;
    }
    if (MemLen != bf.MemLen)
    {
        delete[]pMem;
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

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if ((BitLen == bf.BitLen) && (MemLen == bf.MemLen))
    {
        for (int i = 0; i < BitLen; i++)
        {
            if (pMem[GetMemIndex(i)] != bf.pMem[GetMemIndex(i)])
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение 
{
    return ~(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField copy(max(BitLen, bf.BitLen)), res(max(BitLen, bf.BitLen));
    if (BitLen >= bf.BitLen)
    {
        for (int i = 0; i < bf.BitLen; i++)
        {
            copy.pMem[GetMemIndex(i)] = bf.pMem[GetMemIndex(i)];
        }
        for (int i = 0; i < MemLen; i++)
        {
            res.pMem[i] = pMem[i] | copy.pMem[i];
        }
    }
    else
    {
        for (int i = 0; i < BitLen; i++)
        {
            copy.pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)];
        }
        for (int i = 0; i < MemLen; i++)
        {
            res.pMem[i] = bf.pMem[i] | copy.pMem[i];
        }
    }
    return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и" 
{
    TBitField copy(max(BitLen, bf.BitLen)), res(max(BitLen, bf.BitLen));
    if (BitLen >= bf.BitLen)
    {
        for (int i = 0; i < bf.BitLen; i++)
        {
            copy.pMem[GetMemIndex(i)] = bf.pMem[GetMemIndex(i)];
        }
        for (int i = 0; i < bf.MemLen; i++)
        {
            res.pMem[i] = pMem[i] & copy.pMem[i];
        }
    }
    else
    {
        for (int i = 0; i < BitLen; i++)
        {
            copy.pMem[GetMemIndex(i)] = pMem[GetMemIndex(i)];
        }
        for (int i = 0; i < bf.MemLen; i++)
        {
            res.pMem[i] = bf.pMem[i] & copy.pMem[i];
        }
    }
    
    return res;

}

TBitField TBitField::operator~(void) // отрицание 
{
    for (int i = 0; i < MemLen - 1; i++)
    {
        pMem[i] = ~pMem[i];
    }

    for (int i = (MemLen - 1) * 8 * sizeof(TELEM); i < BitLen; i++)
    {
        if (GetBit(i) == 1)
        {
            ClrBit(i);
        }
        else
        {
            SetBit(i);
        }
    }
    return *this;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    cout << "Enter BitLen: ";
    istr >> bf.BitLen;
    bf.MemLen = (bf.BitLen / (sizeof(TELEM) * 8)) + 1;
    bf.pMem = new TELEM[bf.MemLen];
    cout << "Enter bit sequence: " << endl;
    char tmp;
    for (int i = 0; i < bf.BitLen; i++)
    {
        cout << "Enter bit number " << i << ": ";
        istr >> tmp;
        if ((tmp == 0) || (tmp == 1))
        {
            switch (tmp)
            {
            case 1:
                bf.SetBit(i);
                break;
            case 0:
                bf.ClrBit(i);
                break;
            }
        }
        else
        {
            throw "Bit can only be 0 or 1";
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    ostr << "BitField: ";
    for (int i = 0; i < bf.BitLen; i++)
    {
        switch (bf.GetBit(i))
        {
        case 1:
            cout << "1 ";
            break;
        case 0:
            cout << "0 ";
            break;
        }
    }
    ostr << endl;
    return ostr;
}
