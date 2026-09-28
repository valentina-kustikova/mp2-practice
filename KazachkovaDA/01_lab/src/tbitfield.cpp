// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

static const int Mem = 32;

TBitField::TBitField(int len)
{
    if (len < 0)
        throw std::exception("Incorrect argument");//надо std::exception
    BitLen = len;
    if (BitLen - Mem * (BitLen >> 5) == 0)
        MemLen = BitLen >> 5;
    else
        MemLen = (BitLen >> 5) + 1;
    pMem = new TELEM[MemLen]();
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
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n<<5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return ((1) << (n - Mem*GetMemIndex(n)));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n > BitLen) || (n < 0))
        throw std::exception("index out of range");
    else
        pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n > BitLen) || (n < 0))
        throw std::exception("index out of range");
    else
        pMem[GetMemIndex(n)] &= (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((n > BitLen) || (n < 0))
        throw std::exception("index out of range");
    else
        return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n - Mem * (n >> 5));
}
 
// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf)
        return *this;
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    delete[] pMem;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++)
    {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    int flag = 1;
    if (BitLen != bf.BitLen)
    {
        return 0;
    }
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    int flag = 0;
    if (BitLen != bf.BitLen)
    {
        return 1;
    }
    for (int i = 0; i < MemLen; i++)
    {
        if (pMem[i] != bf.pMem[i])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    if (BitLen > bf.BitLen)
        int MaxLen = BitLen;
    else
        int MaxLen = bf.BitLen;

    return FAKE_BITFIELD;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator~(void) // отрицание
{
    return FAKE_BITFIELD;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    return ostr;
}
