// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"



TSet::TSet(int mp) : MaxPower(mp), BitField(mp)
{ } 

// конструктор копирования
TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField)
{ }

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : MaxPower (bf.GetLength()), BitField(TBitField(bf))
{ }

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
    if (&s == this) {
        return *this;
    }
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
} 

int TSet::operator==(const TSet &s) const // сравнение
{
    
    return this->BitField == s.BitField; 
}

int TSet::operator!=(const TSet& s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet tmp(s.MaxPower > MaxPower ? s.MaxPower : MaxPower); 
    tmp.BitField = BitField | s.BitField;
    return tmp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet tmp(*this); 
    tmp.InsElem(Elem); 
    return tmp;
    
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet tmp(*this);
    tmp.DelElem(Elem);
    return tmp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet tmp(s.MaxPower > MaxPower ? s.MaxPower : MaxPower);
    tmp.BitField = BitField & s.BitField;
    return tmp;
}

TSet TSet::operator~(void) // дополнение
{
    TSet tmp(MaxPower);
    tmp.BitField = ~BitField;    
    return tmp;  
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
    int n;
    do {
        cout << "Input elem: " << endl;
        cin >> n;
        s.InsElem(n);
    } while (s.GetMaxPower() <= n && n < 0);
    
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    cout << "Set is: ";
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.IsMember(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return ostr;
}