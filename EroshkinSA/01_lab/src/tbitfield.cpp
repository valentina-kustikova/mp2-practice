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

TBitField::TBitField(int len)
{
    if (len < 0) throw std::exception("Invalid length");
    BitLen = len;
    MemLen = (len + ((sizeof(TELEM) << 3) - 1)) >> 5;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) pMem[i] = 0;
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
    return n >> 5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1 << (n & ((sizeof(TELEM) << 3) - 1));
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
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n & ((sizeof(TELEM) << 3) - 1));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) return *this;
    if (BitLen != bf.BitLen) {
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
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
    while (i < nbf.MemLen) nbf.pMem[i] = 0;
    return nbf;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField nbf(BitLen);

    for (int i = 0; i < MemLen; i++) nbf.pMem[i] = static_cast<TELEM>(~pMem[i]);
    nbf.pMem[MemLen - 1] &= (1 << (BitLen & ((1 << 5) - 1))) - 1;
    return nbf;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = 0; i < bf.MemLen; i++) cin >> bf.pMem[i];
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.MemLen; i++) ostr << bf.pMem[i] << " ";
    return ostr;
}
