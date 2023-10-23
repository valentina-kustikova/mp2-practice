// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
}

TBitField::~TBitField()
{
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    throw "Method is not implemented";
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    throw "Method is not implemented";
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return 0;
}

void TBitField::SetBit(const int n) // установить бит
{
    throw "Method is not implemented";
}

void TBitField::ClrBit(const int n) // очистить бит
{
    throw "Method is not implemented";
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    throw "Method is not implemented";
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    throw "Method is not implemented";
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    throw "Method is not implemented";
}

TBitField TBitField::operator~(void) // отрицание
{
    throw "Method is not implemented";
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    throw "Method is not implemented";
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    throw "Method is not implemented";
}
