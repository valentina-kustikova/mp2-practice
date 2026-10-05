// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include <stdexcept>
#include "tbitfield.h"

static const int BITS = sizeof(TELEM) * 8;

// Fake variables used as placeholders in tests
//static const int FAKE_INT = -1;
//static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    if (len < 0) {
        //throw std::invalid_argument("TBitField: negative length");
    }

    BitLen = len;
    pMem = nullptr;
    MemLen = 0;

    if (BitLen > 0) {
        MemLen = (BitLen - 1) / BITS + 1;
        pMem = new TELEM[MemLen]();
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    pMem = nullptr;
    MemLen = bf.MemLen;

    if (BitLen > 0) {
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++) {
            pMem[i] = bf.pMem[i];
        }
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n / BITS;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    TELEM temp = 1;
    return temp << (n % BITS);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) {
        throw std::out_of_range("TBitField: bit index out of range");
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen) {
        throw std::out_of_range("TBitField: bit index out of range");
    }
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) {
        throw std::out_of_range("TBitField: bit index out of range");
    }
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    TELEM* newMem = nullptr;

    if (bf.MemLen > 0) {
        newMem = new TELEM[bf.MemLen];
        for (int i = 0; i < bf.MemLen; i++) {
            newMem[i] = bf.pMem[i];
        }
    }

    delete[] pMem;

    BitLen = bf.BitLen;
    pMem = newMem;
    MemLen = bf.MemLen;

    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 0;

    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 0;
        }
    }

    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen)
        return 1;

    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 1;
        }
    }

    return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int maxBitLen = (BitLen >= bf.BitLen) ? BitLen : bf.BitLen;
    TBitField result(maxBitLen);
    int maxMemLen = (MemLen >= bf.MemLen) ? MemLen : bf.MemLen;

    for (int i = 0; i < maxMemLen; i++) {
        result.pMem[i] = pMem[i] | bf.pMem[i];
    }

    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int maxBitLen = (BitLen >= bf.BitLen) ? BitLen : bf.BitLen;
    TBitField result(maxBitLen);
    int maxMemLen = (MemLen >= bf.MemLen) ? MemLen : bf.MemLen;

    for (int i = 0; i < maxMemLen; i++) {
        result.pMem[i] = pMem[i] & bf.pMem[i];
    }

    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField result(BitLen);

    for (int i = 0; i < MemLen; i++) {
        result.pMem[i] = ~pMem[i];
    }

    int used = BitLen % BITS;
    if (used != 0) {
        TELEM mask = (TELEM(1) << used) - 1;
        result.pMem[MemLen - 1] = result.pMem[MemLen - 1] & mask;
    }

    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = bf.GetLength() - 1; i >= 0; i--) {
        char streamBit;
        istr >> streamBit;
        if (streamBit == '1') {
            bf.SetBit(i);
        }
        else if (streamBit == '0') {
            bf.ClrBit(i);
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = bf.GetLength() - 1; i >= 0; i--) {
        ostr << bf.GetBit(i);
    }
    return ostr;

}
