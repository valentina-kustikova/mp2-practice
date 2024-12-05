// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"


TSet::TSet(int mp) : MaxPower(mp), BitField(TBitField(mp))
{
}

// конструктор копирования
TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(TBitField(s.BitField))
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : MaxPower(bf.GetLength()), BitField(TBitField(bf))
{
}

TSet::operator TBitField()
{
    return this->BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return this->MaxPower;
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
    if (this != &s) {
        this->MaxPower = s.MaxPower;
        this->BitField = s.BitField;
    }
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return this->BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(this->operator==(s));
 
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet tmp(*this);
    tmp.MaxPower = max(this->MaxPower, s.MaxPower);
    tmp.BitField = tmp.BitField | s.BitField;
    return tmp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet tmp(*this);
    tmp.BitField.SetBit(Elem);
    return tmp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet tmp(*this);
    tmp.BitField.ClrBit(Elem);
    return tmp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet tmp(*this);
    tmp.MaxPower = max(this->MaxPower, s.MaxPower);
    tmp.BitField = this->BitField & s.BitField;
    return  tmp;
}

TSet TSet::operator~(void) // дополнение
{
    TSet tmp(*this);
    tmp.BitField = ~(tmp.BitField);
    return tmp;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод (откуда?)
{
    istr >> s.MaxPower;
    s = TSet(s.MaxPower);

    for(int i=0;i<s.MaxPower;i++){
        int n;
        istr >> n;
        s.BitField.SetBit(n);
    }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    for (int i = 0; i < s.MaxPower; i++)
    {
        if (s.BitField.GetBit(i)) {
            ostr << i << " ";
        }
    }
    ostr << "\n";
    return ostr;
}
