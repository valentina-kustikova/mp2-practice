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
    MaxPower = (bf.GetLength()/ (8 * sizeof(TELEM))) + 1;
}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return (BitField.GetBit(Elem) == 1);
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
    if (this == &s)
    {
        return *this;
    }
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return ((MaxPower == s.MaxPower) && (BitField == s.BitField));
}

int TSet::operator!=(const TSet &s) const // сравнение 
{
    return ((MaxPower != s.MaxPower) || (BitField != s.BitField));
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet res(max(MaxPower, s.MaxPower));
    res.BitField = BitField | s.BitField;
    return res;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    InsElem(Elem);
    return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    DelElem(Elem);
    return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet res(max(MaxPower, s.MaxPower));
    res.BitField = BitField & s.BitField;
    return res;
}

TSet TSet::operator~(void) // дополнение
{
    BitField = ~BitField;
    return *this;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    cout << "Enter MaxPower: ";
    cin >> s.MaxPower;
    int flag = 0;
    do
    {
        int elem;
        cout << "Enter element: ";
        cin >> elem;
        s.InsElem(elem);
        cout << "Enter another element? 1 - yes, 0 - no ";
        cin >> flag;

    } while (flag == 1);
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    cout << "Set: ";
    for (int i = 0; i < s.MaxPower; i++)
    {
        if (s.IsMember(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return ostr;
}
