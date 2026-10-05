#include <stdexcept>
#include <algorithm>
#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len < 0) throw std::invalid_argument("len cannot be negative");
    BitLen = len;
    MemLen = (len + sizeof(TELEM) * 8 - 1) / (sizeof(TELEM) * 8);
    pMem = new TELEM[MemLen]{0};
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
    pMem = nullptr;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0 || n >= BitLen) throw std::out_of_range("ind n out of range");
    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    TELEM mask = (TELEM)1 << (n % (sizeof(TELEM) * 8));
    return mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen) throw std::out_of_range("ind n out of range");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen) throw std::out_of_range("ind n out of range");
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen) throw std::out_of_range("ind n out of range");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) return *this;

    delete[] pMem;

    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; ++i) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) return 0;
    if (MemLen != bf.MemLen) return 0;
    for (int i = 0; i < MemLen; ++i) {
        if (pMem[i] != bf.pMem[i]) return 0;
    } return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return 0 == (*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int maxBitLen = max(BitLen, bf.BitLen);
    int minMemLen = min(MemLen, bf.MemLen);
    int maxMemLen = max(MemLen, bf.MemLen);
    bool is_this_bigger = MemLen > bf.MemLen;
    TBitField result(maxBitLen);
    for (int i = 0; i < maxMemLen; ++i) {
        if (i < minMemLen) {
            result.pMem[i] = pMem[i] | bf.pMem[i];
            continue;
        }
        if (is_this_bigger) {
            result.pMem[i] = pMem[i];
        }
        else result.pMem[i] = bf.pMem[i];
    }
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int maxBitLen = max(BitLen, bf.BitLen);
    int minMemLen = min(MemLen, bf.MemLen);
    int maxMemLen = max(MemLen, bf.MemLen);
    bool is_this_bigger = MemLen > bf.MemLen;
    TBitField result(maxBitLen);
    for (int i = 0; i < maxMemLen; ++i) {
        if (i < minMemLen) {
            result.pMem[i] = pMem[i] & bf.pMem[i];
            continue;
        }
        result.pMem[i] = 0;
    }
    return result;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField result(BitLen);
    int lastSignificantBits = BitLen % (sizeof(TELEM) * 8);

    for (int i = 0; i < MemLen; ++i) {
        result.pMem[i] = ~(pMem[i]);
    }

    if (lastSignificantBits == 0) return result;
    TELEM lastMemMask = ((TELEM)1 << lastSignificantBits) - 1;
    result.pMem[MemLen - 1] &= lastMemMask;
    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    for (int i = bf.BitLen - 1; i >= 0; --i) {
        char streamEl;
        istr >> streamEl;
        if (streamEl == '1') {
            bf.SetBit(i);
            continue;
        }
        if (streamEl == '0') {
            bf.ClrBit(i);
            continue;
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = bf.BitLen - 1; i >= 0; --i) {
        ostr << bf.GetBit(i);
    }
    return ostr;
}
