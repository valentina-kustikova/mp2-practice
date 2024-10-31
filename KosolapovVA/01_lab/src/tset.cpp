// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"
#include <iomanip>


TSet::TSet(int mp) : MaxPower(mp), BitField(mp){}

// конструктор копирования
TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField){}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : MaxPower(bf.GetLength()),BitField(bf){}

TSet::operator TBitField()
{
    TBitField temp(BitField);
    return temp;
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
    if (this == &s)
        return *this;
    MaxPower = s.MaxPower;
    BitField = TBitField(s.BitField);
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet res(std::max(MaxPower, s.MaxPower));
    res.BitField = BitField | s.BitField;
    return res;
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

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet res(std::max(MaxPower, s.MaxPower));
    res.BitField = BitField & s.BitField;
    return res;
}

TSet TSet::operator~(void) // дополнение
{
    TSet res(this->MaxPower);
    res.BitField = ~this->BitField;
    return res;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    //First variant
    std::cout << "Enter MaxPower set:";
    int temp;
    istr >> temp;
    s = TSet(temp);
    std::cout << "Enter the number of items you want to enter\n";
    istr >> temp;
    std::cout << "Enter elements:\n";
    for (int i = 0; i <temp; i++)
    {
        int elem;
        istr >> elem;
        if (elem > s.MaxPower)
            throw std::exception("Error: The element does not belong to the set");
        s.InsElem(elem);
    }
    istr >> s.BitField;
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    int k = 1;
    for (int i = 0; i < s.MaxPower; i++)
    {
        if (s.IsMember(i) == 1)
        {
            ostr << setw(4)<<i << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }        
    }
    return ostr;
}
