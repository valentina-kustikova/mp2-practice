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
        throw std::exception("Error");
    }
    BitLen = len;
    MemLen = (len - 1) / (sizeof(TELEM) * 8) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
    {
        pMem[i] = TELEM(0);
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
    if (pMem != 0)
    {
        delete[]pMem;
    }
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return TELEM(1) << (n % (sizeof(TELEM) * 8));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n<0 || n>BitLen)
    {
        throw std::exception("Error");
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n<0 || n>BitLen)
    {
        throw std::exception("Error");
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & (~(GetMemMask(n)));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n<0||n>BitLen)
    {
        throw std::exception("Error");
    }
    int res = pMem[GetMemIndex(n)]&GetMemMask(n);
    if (res == 0)
        return 0;
    else
        return 1;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf)
        return *this;
    if (this->BitLen == bf.BitLen)
    {
        for (int i = 0; i < this->MemLen; i++)
        {
            this->pMem[i] = bf.pMem[i];
        }
    }
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    delete[] this->pMem;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++)
    {
        this->pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (this->BitLen != bf.BitLen)
        return 0;
    else
    {
        int temp=0;
        for (int i = 0; i < BitLen; i++)
        {
            if (this->GetBit(i) == bf.GetBit(i))
                temp += 1;
        }
        if (this->BitLen == temp)
            return 1;
        else
            return 0;
    }
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if (*this == bf)
        return 0;
    else
        return 1;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField temp(std::max(this->BitLen, bf.BitLen));
    for (int i = 0; i < std::min(this->MemLen, bf.MemLen); i++)
        temp.pMem[i] = this->pMem[i] | bf.pMem[i];
    if (this->MemLen > bf.MemLen)
    {
        for (int i = std::min(MemLen, bf.MemLen); i < std::max(MemLen, bf.MemLen); i++)
            temp.pMem[i] = this->pMem[i];
    }
    else if (this->MemLen < bf.MemLen)
    {
        for (int i = std::min(MemLen, bf.MemLen); i < std::max(MemLen, bf.MemLen); i++)
            temp.pMem[i] = bf.pMem[i];
    }
    return temp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    TBitField temp(std::max(this->BitLen, bf.BitLen));
    for (int i = 0; i < std::min(this->MemLen, bf.MemLen); i++)
        temp.pMem[i] = this->pMem[i] & bf.pMem[i];
    for (int i = std::min(MemLen, bf.MemLen); i < std::max(MemLen, bf.MemLen); i++)
        temp.pMem[i] = 0;
    return temp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField temp(this->BitLen);
    for (int i = 0; i < this->BitLen; i++)
    {
        if (this->GetBit(i) == 0)
            temp.SetBit(i);
        else
            temp.ClrBit(i);
    }
    return temp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{    
    int temp = 0;
    int len;
    std::cout << "Enter the length of the bit field: ";
    istr >> len;
    bf = TBitField(len);
    std::cout << "Enter the bit value (0 | 1): ";
    for (int i = 0; i < bf.BitLen; i++)
    {
        istr >> temp;
        if (temp == 1)
            bf.SetBit(i);
    }    
    /*
    for (int i = 0; i < bf.MemLen; i++)
        istr >> bf.pMem[i];    
    */
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = bf.BitLen; i >= 0; i --)
        ostr << bf.GetBit(i) << " ";
    ostr << "\n";
    return ostr;
}
