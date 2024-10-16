// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len < 0) throw "Negativ_len";
    BitLen = len;
    MemLen = (BitLen / (sizeof(TELEM) * 8)) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++){
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    if (pMem != bf.pMem) {
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
        for (int i = 0; i < MemLen; i++) {
            pMem[i] = bf.pMem[i];
        }
        return;
    }
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = bf.pMem;
}

TBitField::~TBitField()
{
    if (pMem != nullptr) {
        delete[] pMem;
    }
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n/ (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if ((n > BitLen) || (n < 0)) throw "No_correct_bit";
    return 1 << (n%(sizeof(TELEM)*8));

}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n > BitLen) || (n < 0)) throw "No_correct_bit";
    int indx = GetMemIndex(n);
    pMem[indx] = pMem[indx] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n > BitLen) || (n < 0)) throw "No_correct_bit";
    int indx = GetMemIndex(n);
    pMem[indx] = pMem[indx] & (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
   if ((n > BitLen) || (n < 0)) throw "No_correct_bit";
   TELEM k = pMem[n / (sizeof(TELEM) * 8)];
   if ((k & GetMemMask(n)) == 0) return 0;
   return 1;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (pMem == bf.pMem) return *this;
    if (bf.pMem == nullptr) {
        BitLen = 0;
        MemLen = 0;
        pMem = nullptr;
        return *this;
    }
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (MemLen == bf.MemLen) {
        if (pMem == bf.pMem) return 1;
        int flag = 0;
        for (int i = 0; i < MemLen; i++) {
            if (pMem[i] == bf.pMem[i]) flag = 1;
            else flag = 0;
        }
        return flag;
    }
    return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if ((BitLen != bf.BitLen) || (MemLen != bf.MemLen)) return 1;
    if (pMem != bf.pMem) {
    int flag = 0;
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) flag = 1;
        else flag = 0;
    }
    return flag;
    }
    return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    if (MemLen != bf.MemLen) {
        TBitField res(max(MemLen, bf.MemLen));
        for (int i = 0; i < MemLen; i++) {
            res.pMem[i] = pMem[i] | bf.pMem[i];
        }
    }
    else {
        TBitField res(*this);
        for (int i = 0; i < MemLen; i++) {
            res.pMem[i] |= bf.pMem[i];
        }
        return res;
    }
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    if (MemLen != bf.MemLen) {
        TBitField res(max(MemLen, bf.MemLen));
        for (int i = 0; i < MemLen; i++) {
            res.pMem[i] = pMem[i] & bf.pMem[i];
        }
    }
    else {
        TBitField res(*this);
        for (int i = 0; i < MemLen; i++) {
            res.pMem[i] &= bf.pMem[i];
        }
        return res;
    }
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(*this);
    for (int i = 0; i < BitLen; i++) {
        if (GetBit(i) == 1) res.ClrBit(i);
        else res.SetBit(i);
    }
    return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    istr >> bf.BitLen;
    string bit;
    istr >> bit;
    for (int i = 0; i < bf.BitLen; i++) {
        if (int(bit[i] - '0') == 1) bf.SetBit(i);
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 1; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i);
    }
    return ostr;
}
