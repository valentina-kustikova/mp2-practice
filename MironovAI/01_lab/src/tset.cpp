
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
    if (Elem < 0 && Elem >= MaxPower)
        throw "Out of Range";
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem < 0 && Elem >= MaxPower)
        throw "Out of Range";
    return BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem < 0 && Elem >= MaxPower)
        throw "Out of Range";
    return BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet& s) // присваивание
{
    if (*this == s) return *this;
    MaxPower = s.GetMaxPower();
    BitField = TBitField(MaxPower);
    BitField = BitField | s.BitField; // bitfield = s.bitfield
    return *this;
}

int TSet::operator==(const TSet& s) const // сравнение
{
    if (MaxPower != s.GetMaxPower())
        return 0;
    
    for (int i = 0; i < MaxPower; ++i)
    {
        if (BitField.GetBit(i) != s.BitField.GetBit(i))
            return 0;
    }
    return 1;
}

int TSet::operator!=(const TSet& s) const // сравнение
{
    return !(*this == s);
}

TSet TSet::operator+(const TSet& s) // объединение
{
    TSet A(max(MaxPower, s.GetMaxPower()));
    A.BitField = BitField | s.BitField;
    return A;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    if (Elem<0 && Elem>MaxPower)
        throw "Out of Range";
    TSet A(*this);
    A.BitField.SetBit(Elem);
    return A;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    if (Elem<0 && Elem>MaxPower)
        throw "Out of Range";
    TSet A(*this);
    A.BitField.ClrBit(Elem);
    return A;
}

TSet TSet::operator*(const TSet& s) // пересечение
{
    TSet A(max(MaxPower, s.GetMaxPower()));
    A.BitField = BitField & s.BitField;
    return A;
}

TSet TSet::operator~(void) // дополнение
{
    TSet A(MaxPower);
    A.BitField = ~BitField;
    return A;
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
{
    cout << "Input a size of your set:\n";
    int size; cin >> size;
    for (int i = 0; i < size; ++i)
    {
        cout << "Input element: ";
        int val; istr >> val;
        if (val > s.MaxPower)
            throw "Wrong element ";
        s.InsElem(val);
        cout << endl;
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) // вывод
{
    const int x = s.MaxPower;
    for (int i = 0; i <= x; ++i)
    {
        if (s.IsMember(i)) cout << i << " ";
    }
    return ostr;
}