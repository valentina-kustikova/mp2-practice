// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

static const int POW = 5;
static const int BITS_IN_CELL = 32;

TBitField::TBitField(int len)
{
    if (len < 0) throw std::exception("Invalid length");
    BitLen = len;
    MemLen = (len + (BITS_IN_CELL - 1)) >> POW;
    pMem = new TELEM[MemLen];
    memset(pMem, 0, sizeof(TELEM) * MemLen);
}

TBitField::TBitField(const TBitField &bf) : BitLen(bf.BitLen), MemLen(bf.MemLen) // конструктор копирования
{
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n >> POW;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n & (BITS_IN_CELL - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) throw std::exception("Invalid index");
    pMem[GetMemIndex(n)] |= (GetMemMask(n));
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen) throw std::exception("Invalid index");
    pMem[GetMemIndex(n)] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) throw std::exception("Invalid Index");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n & (BITS_IN_CELL - 1));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) return *this;
    if (BitLen != bf.BitLen) {
        delete[] pMem;
        pMem = new TELEM[bf.MemLen];
    }
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    for (int i = 0; i < MemLen; i++) pMem[i] = bf.pMem[i];
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) return 0;
    for (int i = 0; i < MemLen; i++) if (pMem[i] != bf.pMem[i]) return 0;
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !((*this) == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField nbf(max(BitLen, bf.BitLen));
    int nMemLen = min(MemLen, bf.MemLen), i;
    for (i = 0; i < nMemLen; i++) nbf.pMem[i] = pMem[i] | bf.pMem[i];
    while (i < MemLen) {
        nbf.pMem[i] = pMem[i];
        i++;
    }
    while (i < bf.MemLen) {
        nbf.pMem[i] = bf.pMem[i];
        i++;
    }
    return nbf;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    TBitField nbf(max(BitLen, bf.BitLen));
    int nMemLen = min(MemLen, bf.MemLen), i;
    for (i = 0; i < nMemLen; i++) nbf.pMem[i] = pMem[i] & bf.pMem[i];
    return nbf;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField nbf(BitLen);

    for (int i = 0; i < MemLen; i++) nbf.pMem[i] = ~pMem[i];
    nbf.pMem[MemLen - 1] &= (1 << (BitLen & (BITS_IN_CELL - 1))) - 1;
    return nbf;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string s; istr >> s;
    for (int i = 0; i < s.size(); i++) if(s[i] == '1') bf.SetBit(i);
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++) ostr << bf.GetBit(i);
    return ostr;
}
