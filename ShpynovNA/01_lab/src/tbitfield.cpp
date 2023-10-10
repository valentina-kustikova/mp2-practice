#include "tbitfield.h"
#define bitsInElem 32
#define shiftSize 5
#define Amount (MemLen * shiftSize)
TBitField::TBitField(int len)
{
     if (len < 0) {
        throw "got negative length";
       
    }
    else if (len == 0)
    {
        BitLen = 0;
        MemLen = 0;
        pMem = nullptr;
    }
    else {
        BitLen = len;
        MemLen = ((BitLen + bitsInElem - 1) >> shiftSize);
        pMem = new TELEM[MemLen];
        memset(pMem, 0, Amount);
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    if (bf.MemLen != 0) {
        pMem = new TELEM[MemLen];
        memcpy(pMem, bf.pMem, Amount);
    }
    else {
        pMem = nullptr;
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if (n < BitLen)
        return n >> shiftSize;
    else 
        throw "no such bit";
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
   return 1 << (n & (bitsInElem - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
     if ((n >= BitLen) || (n < 0)) 
        throw "out of range";
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n >= BitLen) || (n < 0)) 
        throw "out of range";
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n >= BitLen || n < 0)
        throw"out of range";
    if ((pMem[GetMemIndex(n)] & GetMemMask(n)) == 0)
        return 0 ;
    else 
        return 1;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (*this == bf) 
        return *this;
    if (BitLen != bf.BitLen)
    {
        delete[] pMem;
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    memcpy(pMem, bf.pMem, Amount);
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) 
        return 0;
    for (int i = 0; i < MemLen; i++)
        if (pMem[i] != bf.pMem[i])
            return 0;
     return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return (!(*this == bf));
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int maxlen = max(BitLen, bf.BitLen);
    TBitField Ftmp(maxlen);
    for (int i = 0; i < Ftmp.MemLen; i++)
        Ftmp.pMem[i] = pMem[i] | bf.pMem[i];
    return Ftmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int maxlen = max(BitLen, bf.BitLen);
    TBitField Ftmp(maxlen);
    for (int i = 0; i < Ftmp.MemLen; i++)
        Ftmp.pMem[i] = pMem[i] & bf.pMem[i];
    return Ftmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField Ftmp(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (GetBit(i))
            Ftmp.ClrBit(i);
        else Ftmp.SetBit(i);
    return Ftmp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    int bt;
        for (int i = 0; i < bf.BitLen; i++) {
            istr >> bt;
            if (!bt) {
                bf.ClrBit(i); 
            }
            else if (bt == 1) {
                bf.SetBit(i); 
            }
            else{
                throw "not 0 or 1";
                break;
            }
        }
        return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++){
        if (bf.GetBit(i)) cout << "1";
        else cout << "0";
    }
}
