// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len > 0)
    {
        BitLen = len;
        MemLen = (len + sizeof(TELEM) * 8 - 1) / (sizeof(TELEM) * 8);
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++)
            pMem[i] = 0;
    }
    else if (len == 0) 
    {
        BitLen = 0;
        MemLen = 0;
        pMem = nullptr;
    }
    else 
        throw "Size error";
   
   
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    if (MemLen)
    {
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
    }
    else 
        pMem = nullptr;
}

TBitField::~TBitField()
{
    if (MemLen > 0)
        delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n / (sizeof(TELEM) * 8);//возвращает индекс ячейки для бита с номером n
}
/*
Операция n % (sizeof(TELEM) * 8) вычисляет остаток от деления номера бита n на количество битов в типе TELEM.
Это позволяет обеспечить, что номер бита не выходит за пределы размера типа TELEM.
Затем число 1 сдвигается влево на полученное значение, что приводит к установке соответствующего бита в маске.*/
TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n % (sizeof(TELEM) * 8));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n >= 0 && n < BitLen)
        pMem[GetMemIndex(n)] |= GetMemMask(n);
    else
        throw "Error";
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n >= 0 && n < BitLen)
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);
    else
        throw "Error";
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n >= 0 && n < BitLen)
        return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
    else
        throw "Error";
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this != &bf)
    {
        if (MemLen != bf.MemLen)
        {
            delete[] pMem;
            MemLen = bf.MemLen;
            pMem = new TELEM[MemLen];
        }
        BitLen = bf.BitLen;
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 0;
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
            return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;
    TBitField result(len);
    for (int i = 0; i < MemLen; i++)
        result.pMem[i] = pMem[i] | bf.pMem[i];
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;
    TBitField result(len);
    for (int i = 0; i < MemLen; i++)
        result.pMem[i] = pMem[i] & bf.pMem[i];
    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField result(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (!GetBit(i)) result.SetBit(i);
    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string str;
    istr >> str;
    for (int i = 0; i < bf.BitLen; i++)
    {
        int bit = str[i] - '0';
        if (bit)
            bf.SetBit(i);
        else
            bf.ClrBit(i);
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    //for (int i = bf.BitLen - 1; i >= 0; i--) 
    for (int i = 0; i < bf.BitLen; i++)
        ostr << bf.GetBit(i);
    return ostr;
}
