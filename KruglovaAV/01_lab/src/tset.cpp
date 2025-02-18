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
TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : MaxPower(bf.GetLength()), BitField(bf)
{
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
    return BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    return BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &s) // присваивание
{
    if (this != &s)
    {
        MaxPower = s.MaxPower;
        BitField = s.BitField;
    }
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return ((MaxPower == s.MaxPower) && (BitField == s.BitField));
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    int len = max(MaxPower, s.MaxPower);
    TSet result(len);
    result.BitField = BitField | s.BitField;
    return result;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet result(*this);
    result.InsElem(Elem);
    return result;

}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet result(*this);
    result.DelElem(Elem);
    return result;

}

TSet TSet::operator*(const TSet &s) // пересечение
{
    int len = max(MaxPower, s.MaxPower);
    TSet result(len);
    result.BitField = BitField & s.BitField;
    return result;
}

TSet TSet::operator~(void) // дополнение
{
    TSet result(MaxPower);
    result.BitField = ~BitField;
    return result;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    cout << "Input max power of your set" << endl;
    int power;
    cin >> power;

    cout << "Input  your set" << endl;

    for (int i = 0; i < power; i++)
    {
        s.InsElem(i);
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
    ostr << endl;
    return ostr;
}
