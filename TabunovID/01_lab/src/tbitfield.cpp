// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле
#include "tbitfield.h"
#define size 32 //sizeof(ui)

TBitField::TBitField(int len)
{
	if (len <= 0)
		throw "len_is_LEq_zero!";
	BitLen = len;
	MemLen = (BitLen - 1) / (size)+1;
	pMem = new TELEM[MemLen];

	// зануление битов (может из-за поведения заполнить "мусором")
	for (int i = 0; i < MemLen; ++i)
	{
		pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; ++i)
	{
		pMem[i] = bf.pMem[i];
	}
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	if (n < 0)
		throw "n_is_below_zero";
	return n / (size);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	if (n > BitLen)
		throw "overload_n";
	if (n < 0)
		throw "n_is_below_zero";
	TELEM Mask = 1u << (size - n % size - 1);
	return Mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n > BitLen)
		throw "overload_n";
	if (n < 0)
		throw "n_is_below_zero";

	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n > BitLen)
		throw "overload_n";
	if (n < 0)
		throw "n_is_below_zero";
	pMem[GetMemIndex(n)] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n > BitLen)
		throw "overload_n";
	if (n < 0)
		throw "n_is_below_zero";
	return (pMem[GetMemIndex(n)] & (GetMemMask(n))) >> (size - n % size - 1);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
	if (bf.pMem != pMem)
	{
		if (MemLen != bf.MemLen)
		{
			TELEM* pNew = new TELEM[bf.MemLen];
			if (pNew != nullptr)
			{
				delete[] pMem;
				pMem = pNew;
			}
			else
			{
				throw "Memory exception";
			}
		}
		MemLen = bf.MemLen;
		BitLen = bf.BitLen;
		for (int i = 0; i < MemLen; i++)
		{
			pMem[i] = bf.pMem[i];
		}
	}
	return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
	if (BitLen != bf.GetLength())
		return 0;
	else
	{
		for (int i = 0; i < BitLen; ++i)
		{
			if (GetBit(i) != bf.GetBit(i))
				return 0;
		}
	}
	return 1;

}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
	int len = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;

	TBitField res(len);

	for (int i = 0; i < MemLen; i++) {
		res.pMem[i] = pMem[i];
	}
	for (int i = 0; i < bf.MemLen; i++) {
		res.pMem[i] |= bf.pMem[i];
	}
	return res;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int len = (BitLen > bf.BitLen) ? BitLen : bf.BitLen;

    TBitField res(len);
    for (int i = 0; i < MemLen; i++) {
        res.pMem[i] = pMem[i];
    }
    for (int i = 0; i < bf.MemLen; i++) {
        res.pMem[i] &= bf.pMem[i];
    }
    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField A(GetLength());
	for (int i = 0; i <= GetMemIndex(GetLength()); ++i)
	{
		A.pMem[i] = ~pMem[i];
	}
	return A;
}

// ввод/вывод
istream& operator>>(istream& istr, TBitField& bf) // ввод
{
	for (int i = 0; i < bf.GetLength(); ++i)
	{
		int val;
		istr >> val;
		if ((val != 0) && (val != 1))
			throw "Wrong element ";
		if (val)
			bf.SetBit(i);
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
	for (int i = 0; i < bf.GetLength(); ++i)
	{
		ostr << bf.GetBit(i) << " ";
	}
	ostr << "\n";
	return ostr;
}