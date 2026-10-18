// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"


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
  return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
  BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
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
    return (MaxPower == s.MaxPower) & (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
  return !(*this == s); 
}

TSet TSet::operator+(const TSet &s) // объединение
{   
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
    int x;
    while (istr >> x) {
        if (x < 0 || x >= s.MaxPower) {
            istr.setstate(ios::failbit);
            return istr;
        }
        s.InsElem(x);
    }
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    for (int i = 0;i < s.GetMaxPower();i++) {
        if (s.IsMember(i) == 1) ostr << i << ' ';
    }
  return ostr;
}
