// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <string.h>
#include <stdexcept>


static const int sizeTELEM = sizeof(TELEM);
static const int TelemBits = 8 * sizeTELEM;
static const int TelemBits_ = TelemBits -1;
static const unsigned int uOne = 1;

TBitField::TBitField(int len)
{
    if (len <= 0) {
        
        throw std::out_of_range("length can not be < 0");
        
        

    }
    BitLen = len;
    MemLen = (len + TelemBits_) / TelemBits;


    pMem = new TELEM[MemLen];
    std::memset(pMem, 0, sizeTELEM * MemLen);
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; ++i)
        this->pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
    delete[] pMem;
    
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{   
    if(n < 0 || n >= BitLen){
        throw std::out_of_range("index can not be < 0");
        
    }
    return n >> (sizeTELEM + 1);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n >= BitLen) {
        throw std::out_of_range("index can not be < 0");
   }
    return uOne << (n & (TelemBits_));
    
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return this->BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen)
       throw std::out_of_range("index can not be < 0");
    
    pMem[GetMemIndex(n)] |= GetMemMask(n);
        
}

void TBitField::ClrBit(const int n) // очистить бит
{   if(n < 0 || n >= BitLen)
        throw std::out_of_range("index can not be < 0");

    pMem[GetMemIndex(n)] &= (~(GetMemMask(n)));
        
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen)
    {   
        throw std::out_of_range("");
        
    }
    

    return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
    
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this != &bf) {
     
         
         
         if (MemLen != bf.MemLen) {
             delete[] pMem;
             this->MemLen = bf.MemLen;
             this->pMem = new TELEM[this->MemLen];
         }
         this->BitLen = bf.BitLen;
         for (int i = 0; i < this->MemLen; ++i)
             this->pMem[i] = bf.pMem[i];

   
    }
    
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    if (BitLen != bf.BitLen) {
        return 0;
    }
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i])
            return 0;
    }
  return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return ~(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{   
    int res_sz = std::max(this->BitLen, bf.BitLen);
    int min_sz = std::min(this->MemLen, bf.MemLen);
    TBitField result(res_sz);
    
    int i;
    for (i = 0; i < min_sz; i++){
        
        result.pMem[i] = this->pMem[i] | bf.pMem[i];
    }
    
    for (; i < bf.MemLen;i++) {
        result.pMem[i] = bf.pMem[i];
    }

    for (; i < this->MemLen;i++) {
        result.pMem[i] = this->pMem[i];
    }    
    return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int res_sz = std::max(this->BitLen, bf.BitLen);
    int min_sz = std::min(this->MemLen, bf.MemLen);
    TBitField result(res_sz);
    for (int i = 0; i < min_sz; i++) {
        result.pMem[i] = this->pMem[i] & bf.pMem[i];
    }
    
    return result;
}

 TBitField TBitField::operator~(void) // отрицание
 {
    TBitField result(BitLen);
    for (int i = 0; i < MemLen;++i) {
        result.pMem[i] = ~pMem[i];
    }
    int tailbits = BitLen % (TelemBits);
    if (tailbits != 0 && result.MemLen > 0) {
        TELEM mask = ((TELEM)1 << tailbits) - 1;
        result.pMem[MemLen - 1] &= mask;
    }
    return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string s;
    istr >> s;
    for (int i = 0; i < bf.BitLen; i++){
        int bitIndex = bf.BitLen - 1 - i;
        if (i < (int)s.size() && s[s.size() - 1 - i] == '1')
            bf.SetBit(bitIndex);
        else
            bf.ClrBit(bitIndex);
    }
       
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++){
        
        ostr << bf.GetBit(i) << "\t";
    }
        
    return ostr;
}
