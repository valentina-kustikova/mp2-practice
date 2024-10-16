// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);


TBitField::TBitField(int len) 
{
    if (len <= 0) throw range_error("Can't make BitField with negative size");
    this->MemLen = len / 32 + 1;
    this->BitLen = len;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
        this->pMem[i] = 0;
    }
    
    
   
  
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    
    this->MemLen = bf.MemLen;
    this->BitLen = bf.BitLen;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
        this->pMem[i] = bf.pMem[i];
    }

}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n>>5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1<<(n%32);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0) {
        throw range_error("There is no such bit");
    }
    if (n >= BitLen) throw out_of_range("");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0) throw range_error("");
    if (n >= BitLen) throw out_of_range("");
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0) throw range_error("There is no such bit");
    if (n >= BitLen) throw out_of_range("There is no such bit");
  return (pMem[n/32]&(1<<(n%32)))>>(n%32);
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    this->MemLen = bf.MemLen;
    this->BitLen = bf.BitLen;
    this->pMem = new TELEM[this->MemLen];
    for (int i = 0; i < this->MemLen; i++) {
        this->pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    //if (this->GetLength() != bf.GetLength()) return 0;
    for (int i = 0; i < this->GetLength(); i++) {
        if (this->GetBit(i) != bf.GetBit(i)) return 0;
    }
  return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    if (this->BitLen != bf.BitLen) return 1;
    for (int i = 0; i < this->BitLen; i++) {
        if (this->GetBit(i) != bf.GetBit(i)) return 1;
    }
    return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField bf1(max(this->BitLen, bf.BitLen));

    for (int i = 0; i < min(this->BitLen, bf.BitLen); i++) {
        if (this->GetBit(i) == 1 || bf.GetBit(i) == 1) {
            bf1.SetBit(i);
        }
        else {
            bf1.ClrBit(i);
        }
    }

    for (int i = min(this->BitLen, bf.BitLen); i < max(this->BitLen, bf.BitLen); i++) {
        if (this->BitLen < bf.BitLen) {
            if (bf.GetBit(i) == 1) {
                bf1.SetBit(i);
            }
            else {
                bf1.ClrBit(i);
            }
        }
        else {
            if (this->GetBit(i) == 1) {
                bf1.SetBit(i);
            }
            else {
                bf1.ClrBit(i);
            }
        }
    }
    return bf1;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    TBitField bf1(max(this->GetLength(), bf.GetLength()));

    for (int i = 0; i < min(this->GetLength(), bf.GetLength()); i++) {
        if ((this->GetBit(i) == 0) || (bf.GetBit(i) == 0)) {
           
            bf1.ClrBit(i);
            
        }
        else {
            bf1.SetBit(i);
        }
        
    }
    

        for (int i = min(this->GetLength(), bf.GetLength()); i < bf1.GetLength(); i++) {
            bf1.ClrBit(i);
           
        }
       
    return bf1;
}

TBitField TBitField::operator~(void) // отрицание
{
    for (int i = 0; i < this->BitLen; i++) {
        if (GetBit(i) == 0) {
            this->SetBit(i);
        }
        else {
            this->ClrBit(i);
        }
    }
    return *this;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{

    setlocale(LC_ALL, "Rus");
    int n;
    for (int i = 0; i < bf.GetLength(); i++) {
        do{
            cout << "Введите значение бита №" << i << "(Допустимые значения: 0 или 1): " << endl;
            cin >> n;
            if (n == 0) {
                 bf.ClrBit(i);
            }
            else {
                bf.SetBit(i);
            }
        }while (n == 0 || n == 1);
    }
    
    istr >> bf;
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{

    
    ostr << "The length of the beaten field:: " << bf.GetLength() << endl;
    ostr << "Field data: " << endl;
    for (int i = 0; i < bf.GetLength(); i++) {
        ostr << "Bit " << i << "\t" << bf.GetBit(i) << endl;
    }
    return ostr;
}
