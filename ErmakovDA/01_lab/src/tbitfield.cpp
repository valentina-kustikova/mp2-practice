#include "tbitfield.h"
using namespace std;

// Конструктор
TBitField::TBitField(int len) {
    if (len <= 0) {
        throw invalid_argument("Negative length");
    }
    BitLen = len;
    MemLen = (len) / (8 * sizeof(TELEM))+1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }  // Обнуляем память
}

// Конструктор копирования
TBitField::TBitField(const TBitField& bf) {

    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }  // Копируем данные
}

// Деструктор
TBitField::~TBitField() {
    delete[] pMem;
}

// Вспомогательные методы
int TBitField::GetMemIndex(const int n) const {
    return n / (8 * sizeof(TELEM)); 
}

TELEM TBitField::GetMemMask(const int n) const { 
    return 1 << (n % (8 * sizeof(TELEM)));  // Маска для бита
}

// Доступ к битам 
int TBitField::GetLength(void) const {
    return BitLen;
}

void TBitField::SetBit(const int n) {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Out of range");
    }
    int index = GetMemIndex(n);
    TELEM mask = GetMemMask(n);
    pMem[index] |= mask;  // Установка бита
}

void TBitField::ClrBit(const int n) {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Out of range");
    }
    int index = GetMemIndex(n);
    TELEM mask = GetMemMask(n);
    pMem[index] &= ~mask;  // Очистка бита
}

int TBitField::GetBit(const int n) const {
    if (n < 0 || n >= BitLen) {
        throw out_of_range("Out of range");
    }
    int index = GetMemIndex(n);
    TELEM mask = GetMemMask(n);
    return (pMem[index] & mask) >> (n % (sizeof(TELEM)*8));
}

// Битовые операции
const TBitField& TBitField::operator=(const TBitField& bf) { 
    if (this == &bf)
        return *this;
    BitLen = bf.BitLen;
    if (MemLen != bf.MemLen)
    {
        MemLen = bf.MemLen;
        delete[] pMem;
        pMem = new TELEM[MemLen];
    }
    for (int i = 0; i < MemLen; i++)
        pMem[i] = bf.pMem[i];
    return *this;
}

int TBitField::operator==(const TBitField& bf) const { 
    if (BitLen != bf.BitLen) {
        return 0;
    }
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) 
            return 0;
    }
    return 1; 
}

int TBitField::operator!=(const TBitField& bf) const { 
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) {
    TBitField bf1(max(BitLen, bf.BitLen));

    for (int i = 0; i < max(MemLen, bf.MemLen); i++) {
        bf1.pMem[i] = pMem[i] | bf.pMem[i];
    }
    return bf1;
}

TBitField TBitField::operator&(const TBitField& bf) {
    TBitField bf1(max(GetLength(), bf.GetLength()));

    for (int i = 0; i < max(MemLen, bf.MemLen); i++) {

        bf1.pMem[i] = pMem[i] & bf.pMem[i];

    }
    return bf1;
}

TBitField TBitField::operator~(void) {
    for (int i = 0; i < BitLen; i++) {
        if (GetBit(i) == 0) {
            SetBit(i);
        }
        else {
            ClrBit(i);
        }
    }
    return *this;
}

// Ввод вывод
istream& operator>>(istream& istr, TBitField& bf) {

    string BitSting;
    istr >> BitSting;

    for (int i = 0; i < bf.BitLen; i++) {
        if (BitSting[i] == '1') {
            bf.SetBit(i);
        }
    }

    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) {
    for (int i = 0; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i);  // Выводим значения битов
    }
    return ostr;
}