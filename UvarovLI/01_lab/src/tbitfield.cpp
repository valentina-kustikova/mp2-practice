// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

#include <stdexcept>

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
  if (len < 0)
    throw length_error("Длина битового поля не может быть отрицательной");

  BitLen = len;

  const int bitsInElem = sizeof(TELEM) * 8;
  MemLen = (len + bitsInElem - 1) / bitsInElem; // округление вверх

  pMem = new TELEM[MemLen];
  for (int i = 0; i < MemLen; i++)
    pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
  BitLen = bf.BitLen;
  MemLen = bf.MemLen;

  pMem = new TELEM[MemLen]; // своя память, а не указатель bf
  for (int i = 0; i < MemLen; i++)
    pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
  delete[] pMem;
  pMem = nullptr;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
  const int bitsInElem = sizeof(TELEM) * 8;
  return n / bitsInElem;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
  const int bitsInElem = sizeof(TELEM) * 8;
  return (TELEM)1 << (n % bitsInElem);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
  if (n < 0 || n >= BitLen)
    throw out_of_range("Номер бита вне диапазона битового поля");

  pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
  if (n < 0 || n >= BitLen)
    throw out_of_range("Номер бита вне диапазона битового поля");

  pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  if (n < 0 || n >= BitLen)
    throw out_of_range("Номер бита вне диапазона битового поля");

  return (pMem[GetMemIndex(n)] & GetMemMask(n)) ? 1 : 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
  if (this == &bf)
    return *this;

  if (MemLen != bf.MemLen)
  {
    delete[] pMem;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
  }

  BitLen = bf.BitLen; // меняется всегда, даже если MemLen совпал
  for (int i = 0; i < MemLen; i++)
    pMem[i] = bf.pMem[i];

  return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  if (BitLen != bf.BitLen)
    return 0;

  for (int i = 0; i < BitLen; i++)
    if (GetBit(i) != bf.GetBit(i))
      return 0;

  return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
  int len = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
  TBitField res(len);

  for (int i = 0; i < BitLen; i++)
    if (GetBit(i))
      res.SetBit(i);
  for (int i = 0; i < bf.BitLen; i++)
    if (bf.GetBit(i))
      res.SetBit(i);

  return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
  int len = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;
  TBitField res(len);

  int minLen = (BitLen < bf.BitLen) ? BitLen : bf.BitLen;
  for (int i = 0; i < minLen; i++)
    if (GetBit(i) && bf.GetBit(i))
      res.SetBit(i);

  return res;
}

TBitField TBitField::operator~(void) // отрицание
{
  TBitField res(BitLen);

  for (int i = 0; i < BitLen; i++)
    if (!GetBit(i))
      res.SetBit(i);

  return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
  char ch;
  int i = 0;
  while (i < bf.GetLength() && istr >> ch)
  {
    if (ch == '1')
      bf.SetBit(i);
    else
      bf.ClrBit(i);
    i++;
  }
  return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
  for (int i = 0; i < bf.GetLength(); i++)
    ostr << bf.GetBit(i);
  return ostr;
}
