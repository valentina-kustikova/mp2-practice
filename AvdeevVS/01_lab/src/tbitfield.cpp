// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
//static const int FAKE_INT = -1;
//static TBitField FAKE_BITFIELD(1);

static const unsigned NUM_OF_BITS_IN_UNSIGNED = 32;

TBitField::TBitField(int len){
  if (len < 0) throw invalid_argument("The len of TBitField is less than zero");
  this->BitLen = len;
  if (BitLen - NUM_OF_BITS_IN_UNSIGNED * (BitLen >> 5) == 0) MemLen = BitLen >> 5;
  else MemLen = (BitLen >> 5) + 1;
  if(MemLen>0) this->pMem = new TELEM[MemLen]();
  else pMem = nullptr;
}

TBitField::TBitField(const TBitField &bf){ // конструктор копирования
  this->BitLen = bf.BitLen;
  this->MemLen = bf.MemLen;
  if (MemLen > 0){
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
      pMem[i] = bf.pMem[i]; 
     }
  }
  else this->pMem = nullptr;
}

TBitField::~TBitField(){ delete[] pMem; }

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
  return n >> 5;
  //return FAKE_INT;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
  return static_cast<TELEM>(1) << (n- NUM_OF_BITS_IN_UNSIGNED*(n>>5));
  //return FAKE_INT;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return this->BitLen;
  //return FAKE_INT;
}

void TBitField::SetBit(const int n) // установить бит
{
  if (n < 0 || n >= BitLen) throw std::out_of_range("TBitField::SetBit: index out of range");
  pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
  if (n < 0 || n >= BitLen) throw std::out_of_range("TBitField::ClrBit: index out of range");
  pMem[GetMemIndex(n)] &= (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  if (n < 0 || n >= BitLen) throw std::out_of_range("TBitField::GetBit: index out of range");
  return (pMem[GetMemIndex(n)]&GetMemMask(n)) >> (n - NUM_OF_BITS_IN_UNSIGNED * (n >> 5));
  //return FAKE_INT;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{   
  if (this == &bf) return *this;
  this->BitLen = bf.BitLen;
  this->MemLen = bf.MemLen;
  delete[] this->pMem;
  if (this->MemLen > 0) {
    pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
      pMem[i] = bf.pMem[i];
    }
  }
  else this->pMem = nullptr;
  return *this;
}

int TBitField::operator==(const TBitField &bf) const{// сравнение
  int flag = 1;
  if (BitLen != bf.BitLen) return 0;
  for (int i = 0; i < MemLen; i++) {
    if (pMem[i] != bf.pMem[i]) {
      flag = 0;
      break;
    }
  }
  return flag;
  //return FAKE_INT;
}

int TBitField::operator!=(const TBitField &bf) const{ // сравнение
  if (*this == bf) return 0;
  return 1;
  //return FAKE_INT;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
  TBitField res(max(this->BitLen, bf.BitLen));
  int MinMem = min(this->MemLen, bf.MemLen);
  for (int i = 0; i < MinMem; i++) {
    res.pMem[i] = pMem[i] | bf.pMem[i];
  }
  if (MemLen > bf.MemLen) {
    for (int i = MinMem; i < MemLen; i++) 
      res.pMem[i] = pMem[i];
  }
  else {
    for (int i = MinMem; i < bf.MemLen; i++) 
      res.pMem[i] = bf.pMem[i];
  }
  return res;
    //return FAKE_BITFIELD;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{   
  TBitField res(max(this->BitLen, bf.BitLen));
  int MinMem = min(this->MemLen, bf.MemLen);
  for (int i = 0; i < MinMem; i++) {
    res.pMem[i] = pMem[i] & bf.pMem[i];
  }
  return res;
    //return FAKE_BITFIELD;
}

TBitField TBitField::operator~(void) // отрицание
{
  TBitField res = *this;
  for (int i = 0; i < res.BitLen; i++) {
    if (GetBit(i) == 0) res.SetBit(i);
    else res.ClrBit(i);
  }
  return res;
  //return FAKE_BITFIELD;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
  string s;
  istr >> s;
  int n = (int)s.size();
  for (int i = 0; i < bf.BitLen && i < n; i++) {
    char c = s[n - 1 - i];
    if (c == '1')
      bf.SetBit(i);
    else if (c == '0')
      bf.ClrBit(i);
    else {
      istr.setstate(ios::failbit);
      return istr;
    }
  }
  return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{   
  for (int i = 0; i < bf.MemLen; i++) {
    ostr << " | ";
    for (int j = NUM_OF_BITS_IN_UNSIGNED - 1; j >= 0; j--)
      ostr << ((bf.pMem[i] >> j) & 1);
    ostr << "(" << bf.pMem[i] << ")";
  }
  ostr << "|";
  return ostr;
}
