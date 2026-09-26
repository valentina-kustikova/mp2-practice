// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Fake variables used as placeholders in tests
//static const int FAKE_INT = -1;
//static TBitField FAKE_BITFIELD(1);
//static TSet FAKE_SET(1);

TSet::TSet(int mp):BitField(mp){
  if (mp < 0) throw invalid_argument("The len of TSet is less than zero");
  this->MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s):BitField(s.BitField){
  this->MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf):BitField(bf){
  this->MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return this->MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{   
  if (Elem >= MaxPower || Elem < 0) throw std::out_of_range("TSet::IsMember: index out of range");
  return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
  if (Elem >= MaxPower || Elem < 0) throw std::out_of_range("TSet::InsElem: index out of range");
  BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
  if (Elem >= MaxPower || Elem < 0) throw std::out_of_range("TSet::DelElem: index out of range");
  BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &s) // присваивание
{
  if (this == &s) return *this;
  this->MaxPower = s.MaxPower;
  this->BitField = s.BitField;
  return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
  int flag = 1;
  if (MaxPower != s.MaxPower) flag = 0;
  if (BitField != s.BitField) flag = 0;
  return flag;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
  if (*this == s) return 0;
  return 1;
}

TSet TSet::operator+(const TSet &s) // объединение
{   
    /*TSet res(max(MaxPower, s.MaxPower));
    res.BitField = BitField | s.BitField;
    return res;*/
    return TSet(BitField | s.BitField);
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
  if (Elem >= MaxPower || Elem < 0) throw std::out_of_range("TSet::operator+: index out of range");
  TSet res(*this);
  res.InsElem(Elem);
  return res;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
  if (Elem >= MaxPower || Elem < 0) throw std::out_of_range("TSet::operator-: index out of range");
  TSet res(*this);
  res.DelElem(Elem);
  return res;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
  return TSet(BitField & s.BitField);
}

TSet TSet::operator~(void) // дополнение
{
  TSet res(*this);
  res.BitField = ~BitField;
  return res;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
  istr >> s.BitField;
  return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
  ostr << s.BitField;
  return ostr;
}
