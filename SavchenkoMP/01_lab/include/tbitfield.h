// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>

using namespace std;

typedef unsigned int TELEM;
class TBitField
{
private:
  int  BitLen; // длина битового поля - макс. к-во битов
  TELEM *pMem; // память для представления битового поля
  int  MemLen; // к-во эл-тов Мем для представления бит.поля


  // TELEM = unsigned int
  // значения bitsInElem и shiftSize установлены ТОЛЬКО для unsigned int
  const int bitsInElem = 32;
  const int shiftSize = 5;


  // методы реализации
  int   GetMemIndex(const int n) const noexcept;
  TELEM GetMemMask (const int n) const noexcept;
public:
  TBitField(int len);
  TBitField(const TBitField &bf);
  ~TBitField();

  // доступ к битам
  int GetLength(void) const;      // получить длину (к-во битов)
  void SetBit(const int n);       // установить бит
  void ClrBit(const int n);       // очистить бит
  int  GetBit(const int n) const; // получить значение бита

  // битовые операции
  bool operator==(const TBitField &bf) const; // сравнение
  bool operator!=(const TBitField &bf) const; // сравнение
  const TBitField& operator=(const TBitField &bf); // присваивание#П3)
  TBitField  operator|(const TBitField &bf); // операция "или"
  TBitField  operator&(const TBitField &bf); // операция "и"
  TBitField  operator~(void);                // отрицание

  friend istream& operator>>(istream& in, TBitField& bf);
  friend ostream& operator<<(ostream& out, const TBitField& bf);
};

#endif
