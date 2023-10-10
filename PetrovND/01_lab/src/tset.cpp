#include "tset.h"

TSet::TSet(int mp) : MaxPower(mp), BitField(mp) { }

TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField) { }

TSet::TSet(const TBitField& bf) : MaxPower(bf.GetLength()), BitField(bf) { }

TSet::operator TBitField() {
    return BitField;
}

int TSet::GetMaxPower(void) const {
    return MaxPower;
}

void TSet::InsElem(const int Elem) {
    if (Elem < 0 || Elem >= MaxPower) {
        throw out_of_range("Element is out of range");
    }
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) {
    if (Elem < 0 || Elem >= MaxPower) {
        throw std::out_of_range("Element is out of range");
    }
    BitField.ClrBit(Elem);
}

int TSet::IsMember(const int Elem) const {
    if (Elem < 0 || Elem >= MaxPower) {
        throw std::out_of_range("Element is out of range");
    }
    return BitField.GetBit(Elem);
}

int TSet::operator==(const TSet& s) const {
    if (MaxPower != s.MaxPower) {
        return 0; 
    }
    return BitField == s.BitField; 
}

int TSet::operator!=(const TSet& s) const {
    return !(*this == s);
}

TSet& TSet::operator=(const TSet& s) {
    if (this == &s) {
        return *this; 
    }
    MaxPower = s.MaxPower;
    BitField = s.BitField; 
    return *this;
}

TSet TSet::operator+(const int Elem) {
    if (Elem >= MaxPower || Elem < 0) throw invalid_argument("Out of range");
    TSet result(*this); 
    result.InsElem(Elem); 
    return result;
}

TSet TSet::operator-(const int Elem) {
    if (Elem >= MaxPower || Elem < 0) throw invalid_argument("Out of range");
    TSet result(*this); 
    result.DelElem(Elem);
    return result;
}

TSet TSet::operator+(const TSet& s) {
    int len = (MaxPower > s.MaxPower) ? MaxPower : s.MaxPower;
    TSet result(len);
    result.BitField = BitField | s.BitField;
    return result;
}

TSet TSet::operator*(const TSet& s) {
    int len = (MaxPower > s.MaxPower) ? MaxPower : s.MaxPower;
    TSet result(len);
    result.BitField = BitField & s.BitField; 
    return result;
}

TSet TSet::operator~() {
    TSet result(MaxPower);
    result.BitField = ~BitField; 
    return result;
}

istream& operator>>(istream& istr, TSet& ts) {
    int inputElem;
    while (true) {
        istr >> inputElem;
        if (inputElem == -1) { // Завершаем ввод, когда встречается -1
            break;
        }
        if (inputElem >= 0 && inputElem < ts.MaxPower) {
            ts.InsElem(inputElem);
        }
        else {
            cerr << "Invalid input. Element out of range." << endl;
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& ts) {
    for (int i = 0; i < ts.MaxPower; i++) {
        if (ts.IsMember(i)) {
            ostr << i << " "; 
        }
    }
    return ostr;
}