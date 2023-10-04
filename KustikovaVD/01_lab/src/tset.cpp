// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(-1)
{
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(-1)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(-1)
{
}

TSet::operator TBitField()
{
    throw "Method is not implemented";
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    throw "Method is not implemented";
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    throw "Method is not implemented";
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    throw "Method is not implemented";
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
    throw "Method is not implemented";
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return 0;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    throw "Method is not implemented";
}

TSet TSet::operator+(const TSet &s) // объединение
{
    throw "Method is not implemented";
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    throw "Method is not implemented";
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    throw "Method is not implemented";
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    throw "Method is not implemented";
}

TSet TSet::operator~(void) // дополнение
{
    throw "Method is not implemented";
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    throw "Method is not implemented";
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    throw "Method is not implemented";
}
