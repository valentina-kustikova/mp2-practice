// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
    if (len <=0) throw "errorw";

    BitLen = len;
    MemLen = (len / (sizeof(TELEM) * 8)) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[BitLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }


}

TBitField::~TBitField()
{
    if (pMem != nullptr) {
        delete[]pMem;
    }

}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < 0 || n > BitLen) {
        throw "wrong bit";
    }

    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n > BitLen) {
        throw "wrong bit";
    }

    TELEM k = n % (sizeof(TELEM) * 8);

    return 1 << k;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n > BitLen) {
        throw "wrong bit";
    }

    pMem[GetMemIndex(n)] =
        pMem[GetMemIndex(n)] | GetMemMask(n);

}

void TBitField::ClrBit(const int n) // очистить бит
{

    if (n < 0 || n > BitLen) {
        throw "wrong bit";
    }

    TELEM k = n % (sizeof(TELEM) * 8);
    pMem[GetMemIndex(n)] =
        pMem[GetMemIndex(n)] & (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n > BitLen) {
        throw "wrong bit";
    }

    // порядок бита
    TELEM k = n % (sizeof(TELEM) * 8);

    return (pMem[GetMemIndex(n)] & (GetMemMask(k))) >> k;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    if (this == &bf)
    {
        return *this;
    }
    if (BitLen != bf.BitLen)
    {
        delete[]pMem;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    BitLen = bf.BitLen;

    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (BitLen != bf.BitLen) {
        return 0;
    }

    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 0;
        }
    }
    return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    return !((*this) == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    TBitField answ(max(BitLen, bf.BitLen));
    for (int i = 0; i < answ.MemLen; i++) {
        answ.pMem[i] = pMem[i] | bf.pMem[i];
    }
    
    if (MemLen >= bf.MemLen) {
        for (int i = bf.MemLen; i < MemLen; i++) {
            answ.pMem[i] = pMem[i];
        }

    }
    else {
        for (int i = MemLen; i < bf.MemLen; i++) {
            answ.pMem[i] = bf.pMem[i];
        }
    }

    return answ;
    
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    TBitField answ(max(BitLen, bf.BitLen));
    for (int i = 0; i < answ.MemLen; i++) {
        answ.pMem[i] = pMem[i] & bf.pMem[i];
    }

    if (MemLen >= bf.MemLen) {
        for (int i = bf.MemLen; i < MemLen; i++) {
            answ.pMem[i] = pMem[i];
        }

    }
    else {
        for (int i = MemLen; i < bf.MemLen; i++) {
            answ.pMem[i] = bf.pMem[i];
        }
    }
    return answ;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField answ(BitLen);
    
    for (int i = 0; i < MemLen-1; i++) {
        answ.pMem[i] = ~pMem[i];
    }
    for (int i = (MemLen-1)*(sizeof(TELEM)); i < BitLen;i++) {
        if (!GetBit(i)) {
            answ.SetBit(i);
            continue;
        }            
    }

    return answ;  
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    
    string bitstr;
    istr >> bitstr;
    
    for (int i = 0; i < bf.BitLen; i++) {
        if (bitstr[i] == '1') {
            bf.SetBit(i);
        }
        
    }

    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i);
    }
    return ostr;
}
