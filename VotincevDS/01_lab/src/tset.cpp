// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp), MaxPower(mp)
{
}

// конструктор копирования
TSet::TSet(const TSet& s) : BitField(s.BitField),
                        MaxPower(s.MaxPower)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf), 
                      MaxPower(bf.GetLength())
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
    return (BitField == s.BitField);
    
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return (BitField != s.BitField);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet answ(max(MaxPower, s.MaxPower));
    answ.BitField = BitField | s.BitField;
    return answ;
}

TSet TSet::operator+(const int Elem) // объединение с элементом // TODO!
{
    if (Elem > MaxPower) { // TODO!!! InsElem
        throw "too large element";
    }

    TSet answ(MaxPower);
    answ.BitField = BitField;
    answ.InsElem(Elem);  
    return answ;
    
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem > MaxPower) { // TODO!!! DelElem
        throw "too large element";
    }

    TSet answ(MaxPower);
    answ.BitField = BitField;
    answ.DelElem(Elem);
    return answ;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet answ(max(MaxPower,s.MaxPower));
    answ.BitField = BitField & s.BitField;
    return answ;
}

TSet TSet::operator~(void) // дополнение
{  
    TSet answ(MaxPower);
    answ.BitField = ~BitField;
    return answ;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    istr >> s.MaxPower;
    s = TSet(s.MaxPower);
    for (int i = 0; i < s.MaxPower; i++) {
        int number;
        istr >> number;
        s.InsElem(number); // TODO!!! InsElem
    }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{   
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.IsMember(i)) { // TODO!!! isMember
            ostr << i << ' ';
        }
    }
    return ostr;
}
