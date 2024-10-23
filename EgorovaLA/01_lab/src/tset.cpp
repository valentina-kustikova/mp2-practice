// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
    MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
    MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
    MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
    return TBitField(BitField); 
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
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
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if ((MaxPower == s.MaxPower) &&
        (BitField == s.BitField)) return 1;
    return 0;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet M (max(MaxPower, s.MaxPower));
    M.BitField = BitField | s.BitField;
    return M;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    if (Elem > MaxPower) throw "No_correct_element";
    TSet M(*this);
    M.InsElem(Elem);
    return M;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem > MaxPower) throw "No_correct_element";
    TSet M(*this);
    M.DelElem(Elem);
    return M;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet M(max(MaxPower, s.MaxPower));
    M.BitField = BitField & s.BitField;
    return M;
}

TSet TSet::operator~(void) // дополнение
{
    TSet M(MaxPower);
    M.BitField = ~BitField;
    return M;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    istr >> s.MaxPower;
    s = TSet(s.MaxPower);
    for (int i = 0; i < s.MaxPower; i++) {
        int elem;
        istr >> elem;
        s.InsElem(elem);
    }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.BitField.GetBit(i)) {
            ostr << i << ' ';
        }
    }
    return ostr;
}
