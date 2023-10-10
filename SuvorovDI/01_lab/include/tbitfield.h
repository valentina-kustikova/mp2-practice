#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>
#include <cmath>

typedef unsigned int elem_t;

class TBitField {
private:
	elem_t* bField;
	int fieldSize;
	int memSize;

	int bitsInElem = sizeof(elem_t)*8;
	int shiftSize = round(log2(bitsInElem));

	int GetMemIndex(const int n) const;
	elem_t GetMemMask(const int n) const;
	
public:
	//конструкторы диструкторы
	TBitField(int len);
	TBitField(const TBitField& bf);
	~TBitField();

	// доступ к битам
	int GetLength(void) const;
	void SetBit(const int n);
	void ClrBit(const int n);
	int  GetBit(const int n) const;

	// битовые операции
	bool operator==(const TBitField& bf) const;
	bool operator!=(const TBitField& bf) const; 
	TBitField& operator=(const TBitField& bf);
	TBitField  operator|(const TBitField& bf);
	TBitField  operator&(const TBitField& bf);
	TBitField  operator~(void);

	friend std::istream& operator>>(std::istream& in, TBitField& bf) {
		std::string input;
		in >> input;

		if (input.length() > bf.fieldSize)
			throw "out of range";

		for (int i = 0; i < bf.fieldSize; i++) {
			if (input[bf.fieldSize - 1 - i] == '1') {
				bf.SetBit(i);
			}
		}
		return in;
	}
	friend std::ostream& operator<<(std::ostream& out, const TBitField& bf) {
		for (int i = bf.fieldSize - 1; i >= 0; i--) {
			out << bf.GetBit(i);
		}
		return out;
	}
};

#endif