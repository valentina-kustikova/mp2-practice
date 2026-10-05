#include <stdexcept>
#include <algorithm>
#include "tset.h"




TSet::TSet(int mp) : BitField(mp), MaxPower(mp)
{
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField), MaxPower(s.MaxPower)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength())
{
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
    if (this == &s) return *this;

    BitField = s.BitField;
    MaxPower = s.MaxPower;

    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if (BitField != s.BitField) return 0;
    return 1;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return 0 == (*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
    TSet result(max(MaxPower, s.GetMaxPower()));
    result.BitField = BitField | s.BitField;

    return result;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet result(MaxPower);
    result.BitField = BitField;
    result.BitField.SetBit(Elem);

    return result;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet result(MaxPower);
    result.BitField = BitField;
    result.BitField.ClrBit(Elem);

    return result;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    TSet result(max(MaxPower, s.MaxPower));
    result.BitField = BitField & s.BitField;

    return result;

}

TSet TSet::operator~(void) // дополнение
{
    TSet result(MaxPower);
    result.BitField = ~BitField;

    return result;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    while (true) {
        int streamEl;
        istr >> streamEl;
        if (streamEl == -1) break;
        if (streamEl < 0 || streamEl >= s.GetMaxPower()) throw std::out_of_range("stream num out of range \n");
        if (s.IsMember(streamEl)) s.DelElem(streamEl);
        else s.InsElem(streamEl);
    }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    ostr << "{";

    bool is_first = true;
    for (int i = 0; i < s.GetMaxPower(); ++i) {
        if (s.IsMember(i)) {
            if (!is_first) ostr << ", ";
            ostr << i;
            is_first = false;
        }
    }
    ostr << "}";
    return ostr;
}