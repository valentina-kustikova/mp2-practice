// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : MaxPower(mp), BitField(mp)
{
}

// конструктор копирования
TSet::TSet(const TSet &s) :  MaxPower(s.MaxPower), BitField(s.BitField)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
    this->MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
    return this->BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return this->BitField.GetLength();
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return this->BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
   
    this->BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    this->BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &s) // присваивание
{
    if (this == &s)
        return *this;

    this->MaxPower = s.MaxPower;
    this->BitField = s.BitField;

    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return ((this->MaxPower == s.MaxPower) && (this->BitField == s.BitField));
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet& s) //TODO & bitfield
{
    int maxSize = std::max(MaxPower, s.MaxPower);
    TSet result(maxSize);  

    result.BitField = this->BitField | s.BitField;

    return result; 
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet res(*this);
    res.InsElem(Elem);
    return res;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet res(*this);
    res.DelElem(Elem);
    return res;
}

TSet TSet::operator*(const TSet& s) { //todo
    int new_size = std::max(this->MaxPower, s.MaxPower);
    TSet res(new_size); 

    res.BitField = this->BitField & s.BitField;
    return res;
}

TSet TSet::operator~(void) // дополнение
{
    TSet res(*this);
    res.BitField = ~res.BitField;
    return res;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    int elem;
    while (istr >> elem)
    {
        s.InsElem(elem);
    }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    for (int i = 0; i < s.MaxPower; ++i) {
        if (s.IsMember(i)) {
            ostr << i << " ";
        }
    }
    return ostr;
}