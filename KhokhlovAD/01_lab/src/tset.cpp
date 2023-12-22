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
TSet::TSet(const TSet& s) : BitField(s.BitField)
{
	MaxPower = s.GetMaxPower();
}

// конструктор преобразования типа
TSet::TSet(const TBitField& bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
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
	if ((Elem < MaxPower) & (Elem >= 0))
		if (BitField.GetBit(Elem) == 1) return 1;
		else return 0; else throw "Negative Elem";
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	if ((Elem < MaxPower) & (Elem >= 0))
		BitField.SetBit(Elem); else throw "Negative n";
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	if ((Elem < MaxPower) & (Elem >= 0))
		BitField.ClrBit(Elem); else throw "Negative n";
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet& s) // присваивание
{
	if (*this == s)
		return *this;
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

bool TSet::operator==(const TSet& s) const // сравнение
{
	return (BitField == s.BitField);
}

bool TSet::operator!=(const TSet& s) const // сравнение
{
	return !(*this == s);
}

TSet TSet::operator+(const TSet& s) // объединение
{
	TSet a(BitField | s.BitField);
	return a;
}



TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet a(*this);
	if ((Elem < MaxPower) & (Elem >= 0)) {
		a.InsElem(Elem);
	}
	else throw "Nrgative Elem";
	return a;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet a(*this);
	if ((Elem < MaxPower) & (Elem >= 0)) {
		a.DelElem(Elem);
	}
	else throw "Nrgative Elem";
	return a;
}

TSet TSet::operator*(const TSet& s) // пересечение
{
	TSet a(BitField & s.BitField);
	return a;
}

TSet TSet::operator~(void) // дополнение
{
	TSet a(~BitField);
	return a;

}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
	for (int i = 0; i < s.MaxPower; i++) {
		s.DelElem(i);
	}
	cout << "Input your set (To finish, enter -1)" << endl;
	int i;

	while (1) {
		istr >> i;
		if (i == -1) {
			return istr;
		}
		if ((i < 0) || (i > s.MaxPower)) {
			throw "OUTOFRANGE";
		}
		s.InsElem(i);
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
	for (int i = 0; i < s.MaxPower; i++)
		if (s.IsMember(i) == 1)
			ostr << i;
	return ostr;
}
