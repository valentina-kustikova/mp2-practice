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
    if (len <= 0) {
        throw "Ошибка: Длина битового поля должен быть положительным\n";
    }
    this->BitLen = len;
    this->MemLen = (BitLen + (sizeof(TELEM) * 8 - 1)) / (sizeof(TELEM) * 8);
    this->pMem = new TELEM[this->MemLen];
    memset(this->pMem, 0, this->MemLen * sizeof(TELEM));
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
        this->pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] this->pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0 || n >= this->BitLen) {
        throw "Ошибка: Некорректный бит\n";
    }
    return n >> INT_POWER;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n >= this->BitLen) {
        throw "Ошибка: Некорректный бит\n";
    }
    return (1u << (n & (sizeof(TELEM)*8 - 1)));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return this->BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= this->BitLen) {
        throw "Ошибка: Некорректный бит\n";
    }
    this->pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= this->BitLen) {
        throw "Ошибка: Некорректный бит\n";
    }
    this->pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= this->BitLen) {
        throw "Ошибка: Некорректный бит\n";
    }
    return (this->pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n & (sizeof(TELEM)*8-1));
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf) {
        return *this;
    }
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    delete[] this->pMem;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
        this->pMem[i] = bf.pMem[i];
    }
    return *this;
    
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (this->BitLen != bf.BitLen) return 0;
    for (int i = 0; i < this->BitLen; i++) {
        if (bf.GetBit(i) != this->GetBit(i)) return 0;
    }
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int max_BitLen = max(this->BitLen, bf.BitLen);
    TBitField res(max_BitLen);

    int min_MemLen = min(this->MemLen, bf.MemLen);
    for (int i = 0; i < min_MemLen; i++) {
        res.pMem[i] = this->pMem[i] | bf.pMem[i];
    }

    for (int i = min_MemLen; i < this->MemLen; i++) {
        res.pMem[i] = this->pMem[i];
    }
    for (int i = min_MemLen; i < bf.MemLen; i++) {
        res.pMem[i] = bf.pMem[i];
    }

    return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int min_MemLen = min(this->MemLen, bf.MemLen);    
    int max_BitLen = max(this->BitLen, bf.BitLen);
    TBitField res(max_BitLen);
    for (int i = 0; i < min_MemLen; i++) {
        if (i < min_MemLen) {
            res.pMem[i] = this->pMem[i] & bf.pMem[i];
        }
    }
    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(this->BitLen);
    int remainder= this->BitLen % (sizeof(TELEM) * 8);
    if (remainder) {
        for (int i = 0; i < this->MemLen - 1; i++) {
            res.pMem[i] = ~(this->pMem[i]);
        }
        res.pMem[MemLen - 1] = ~(this->pMem[MemLen - 1]);
        res.pMem[MemLen - 1] &= ((1u << remainder) - 1);
    }
    else {
        for (int i = 0; i < this->MemLen; i++) {
            res.pMem[i] = ~(this->pMem[i]);
        }
    }
    return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    char bit_from_user;
    for (int i = 0; i < bf.BitLen; i++) {
        if (!(istr >> bit_from_user)) return istr;
        if (bit_from_user == '1') {
            bf.SetBit(bf.BitLen - 1 - i);
        }
        else if (bit_from_user == '0') {
            bf.ClrBit(bf.BitLen - 1 - i);
        }
        else {
            istr.setstate(ios::failbit);
            return istr;
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = bf.BitLen-1; i >= 0; i--) {
        ostr << bf.GetBit(i);
    }
    return ostr;
}
