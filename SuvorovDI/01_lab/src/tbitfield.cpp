#include "tbitfield.h"
#include <iostream>

TBitField::TBitField(int len) {
	fieldSize = len;
	memSize = len / bitsInElem + 1;
	
	bField = new elem_t[memSize];
	for (int i = 0; i < memSize * bitsInElem; i++) {
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

int TBitField::GetLength() const {
	return fieldSize;
}

void TBitField::SetBit(const int n) {
	if (n >= fieldSize)
		throw std::exception("out of range");

	bField[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) {
	if (n >= memSize*bitsInElem)
		throw std::exception("out of range");

	bField[GetMemIndex(n)] &= ~(GetMemMask(n));
}

int TBitField::GetBit(const int n) const {
	if (n >= fieldSize)
		throw std::exception("out of range");

	return (bField[GetMemIndex(n)] & GetMemMask(n)) >> (n & (bitsInElem - 1));
}

bool TBitField::operator==(const TBitField& bf) const {
	if (fieldSize != bf.fieldSize)
		return false;

	for (int i = 0; i < memSize; i++)
		if (bField[i] != bf.bField[i])
			return false;

	return true;
}

bool TBitField::operator!=(const TBitField& bf) const {
	return !(*this == bf);
}

TBitField& TBitField::operator=(const TBitField& bf) {
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

TBitField TBitField::operator|(const TBitField& bf) { // до максимальной длины, а побитовое И до минимальной!!!
	int max_size = fieldSize;
	if (bf.fieldSize > max_size)
		max_size = bf.fieldSize;

	TBitField res(max_size);

	int i = 0;
	for (; i < memSize && i < bf.memSize; i++) {
		res.bField[i] = bField[i] | bf.bField[i];
	}

	for (; i < memSize; i++) {
		res.bField[i] = bField[i] | 0;
	}

	for (; i < bf.memSize; i++) {
		res.bField[i] = bf.bField[i] | 0;
	}

	return res;
}

TBitField TBitField::operator&(const TBitField& bf) {
	int min_size = fieldSize;
	int min_mem_size = memSize;
	if (bf.fieldSize < min_size) {
		min_size = bf.fieldSize;
		min_mem_size = bf.memSize;
	}

	TBitField res(min_size);

	for (int i = 0; i < min_mem_size; i++) {
		res.bField[i] = bField[i] & bf.bField[i];
	}

	return res;
}

// ЗАЧЕМ VOID?
TBitField TBitField::operator~(void) {
	TBitField res(fieldSize);
	for (int i = 0; i < memSize; i++) {
		res.bField[i] = ~bField[i];
	}
	return res;
}