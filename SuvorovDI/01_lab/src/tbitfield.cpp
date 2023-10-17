#include "tbitfield.h"
#include <iostream>

TBitField::TBitField(int len) {
  if (len < 0)
    throw std::exception("Negative size does not support");
	fieldSize = len;
	memSize = len / bitsInElem + 1;
	
	bField = new elem_t[memSize];
	for (int i = 0; i < fieldSize; i++) {
		ClrBit(i);
	}
}

TBitField::TBitField(const TBitField& bf) {
	fieldSize = bf.fieldSize;
	memSize = bf.memSize;

	bField = new elem_t[memSize];

	for (int i = 0; i < memSize; i++)
		bField[i] = bf.bField[i];
}

TBitField::~TBitField() {
	delete[] bField;
}

int TBitField::GetMemIndex(const int pos) const {
	return pos >> shiftSize;
}

elem_t TBitField::GetMemMask(const int pos) const {
	return 1 << (pos & (bitsInElem - 1));
}

int TBitField::GetLength(void) const {
	return fieldSize;
}

void TBitField::SetBit(const int n) {
	if (n >= fieldSize || n < 0)
		throw std::exception("out of range");

	bField[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) {
	if (n >= fieldSize || n < 0)
		throw std::exception("out of range");

	bField[GetMemIndex(n)] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const {
	if (n >= fieldSize || n < 0)
		throw std::exception("out of range");

	return (bField[GetMemIndex(n)] & GetMemMask(n)) >> (n & (bitsInElem - 1));
}

bool TBitField::operator==(const TBitField& bf) const {
	if (fieldSize != bf.fieldSize)
		return false;

	for (int i = 0; i < memSize - 1; i++)
		if (bField[i] != bf.bField[i])
			return false;

	for (int i = (memSize - 1) * bitsInElem; i < fieldSize; i++)
		if (GetBit(i) != bf.GetBit(i))
			return false;

	return true;
}

bool TBitField::operator!=(const TBitField& bf) const {
	return !(*this == bf);
}

TBitField& TBitField::operator=(const TBitField& bf) {
	if (this == &bf)
		return *this;

	fieldSize = bf.fieldSize;
	if (memSize != bf.memSize) {
		memSize = bf.memSize;
		delete[] bField;
		bField = new elem_t[memSize];
	}

	for (int i = 0; i < memSize; i++) {
		bField[i] = bf.bField[i];
	}
	return *this;
}

TBitField TBitField::operator|(const TBitField& bf) {
	const TBitField* max_field = this;
	int min_size = bf.fieldSize;
	if (fieldSize < min_size) {
		max_field = &bf;
		min_size = fieldSize;
	}

	TBitField res(*max_field);
	for (int i = 0; i < min_size; i++)
		if ((GetBit(i) || bf.GetBit(i)) == 1)
			res.SetBit(i);

	return res;
}

TBitField TBitField::operator&(const TBitField& bf) {
	int max_size = fieldSize;
	int min_size = bf.fieldSize;
	if (bf.fieldSize > max_size) {
		max_size = bf.fieldSize;
		min_size = fieldSize;
	}

	TBitField res(max_size);
	for (int i = 0; i < min_size; i++)
		if ((GetBit(i) && bf.GetBit(i)) == 1)
			res.SetBit(i);

	return res;
}

TBitField TBitField::operator~(void) {
	TBitField res(fieldSize);
	for (int i = 0; i < memSize; i++) {
		res.bField[i] = ~bField[i];
	}
	return res;
}