// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include <iostream>


TBitField::TBitField(int len)
{
	if (len < 0) throw "length_cant_be_less_then_zero";
	BitLen = len;
	MemLen = ((BitLen - 1) >> 5) + 1;
	pMem = new TELEM[MemLen];
	memset(pMem, 0, MemLen * sizeof(TELEM));
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	memcpy(pMem, bf.pMem, MemLen * sizeof(TELEM));
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n >> 5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << (BitLen - (n & 31) - 1);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n > BitLen || n < 0) throw "out_of_range";
	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n > BitLen || n < 0) throw "out_of_range";
	pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n > BitLen || n < 0) throw "out_of_range";
	if ((pMem[GetMemIndex(n)] & GetMemMask(n)) == 0) return 0;
	return 1;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
	if (bf == (*this)) return (*this);
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	memcpy(pMem, bf.pMem, MemLen * sizeof(TELEM));
	return (*this);
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
	if (bf.BitLen != BitLen) return 0;
	for (int i = 0; i < BitLen; i++) {
		if (bf.GetBit(i) != GetBit(i)) return 0;
	}
	return 1;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
	int maxl = max(BitLen, bf.BitLen), minl = min(BitLen, bf.BitLen), i;
	TBitField tmp(maxl);
	for (i = 0; i < minl; i++) {
		if (GetBit(i) | bf.GetBit(i)) tmp.SetBit(i);
	}
	while (i < BitLen) {
		if (GetBit(i)) tmp.SetBit(i);
		i += 1;
	}
	while (i < bf.BitLen) {
		if (bf.GetBit(i)) tmp.SetBit(i);
		i += 1;
	}
	return tmp;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
	int maxl = max(BitLen, bf.BitLen), minl = min(BitLen, bf.BitLen), i;
	TBitField tmp(maxl);
	for (i = 0; i < minl; i++) {
		if (GetBit(i) & bf.GetBit(i)) tmp.SetBit(i);
	}
	return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField tmp(BitLen);
	for (int i = 0; i < MemLen; i++) {
		tmp.pMem[i] = ~pMem[i];
	}
	return tmp;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
	for (int i = 0; i < bf.BitLen; i++) {
		int num;
		cin >> num;
		if (num) bf.SetBit(i);
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
	for (int i = 0; i < bf.BitLen; i++) cout << bf.GetBit(i);
	return ostr;
}
