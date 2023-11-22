// ����, ���, ���� "������ ����������������-2", �++, ���
//
// tbitfield.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (19.04.2015)
//
// 
// 
// ������� ����

#include "tbitfield.h"
const int bitsInElem = 32;
const int shiftSize = 5;//�������� ��� ������

TBitField::TBitField(int Len)//����������� �� ���������
{
    if (Len > 0) {
        BitLen = Len;// ����� �������� ���� - ����. �-�� �����
        MemLen = ((Len + bitsInElem - 1) >> shiftSize); // �-�� ��-��� ��� ��� ������������� ���.����
        pMem = new TELEM[MemLen];//������ ��� �������������� �������� ����
        memset(pMem, 0, MemLen * sizeof(TELEM));//������� ����������� ������ ������� � ������ �������� ���������� ���
    }
    else if (Len < 0)
    {
        throw ("Field less than 0");
    }
    else if (Len == 0) {
        MemLen = 0;// �-�� ��-��� ��� ��� ������������� ���.����
        BitLen = 0;// ����� �������� ���� - ����. �-�� �����
        pMem = nullptr;//�������� ������� ���������
    }
}

TBitField::TBitField(const TBitField& bf) //����������� ����������� 
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    if (MemLen) {
        pMem = new TELEM[MemLen];
        memcpy(pMem, bf.pMem, MemLen * sizeof(TELEM));
    }
    else {
        pMem = nullptr;
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const
{
    return n >> shiftSize;
}

TELEM TBitField::GetMemMask(const int n) const
{
    return 1 << (n & (bitsInElem - 1));
}

int TBitField::GetLength(void) const
{
    return BitLen;
}

void TBitField::SetBit(const int n)
{
    if (n >= BitLen || n < 0)
        throw("The bit is not in the range");
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n)
{
    if (n >= BitLen || n < 0)
        throw("The bit is not in the range");
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const {
    if (n >= BitLen || n < 0)
        throw("The bit is not in the range");
    return (pMem[GetMemIndex(n)] & GetMemMask(n)) ? 1 : 0;
}

const TBitField& TBitField::operator=(const TBitField& bf)
{
    if (this == &bf)
        return *this;
    if (BitLen != bf.BitLen)
    {
        delete[] pMem;
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
    }
    for (int i = 0; i < MemLen; ++i)
    {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}


int TBitField::operator!=(const TBitField& bf) const
{
    return !((*this) == bf);
}

int TBitField::operator==(const TBitField& bf) const
{
    if (BitLen != bf.BitLen) return 0;
    for (int i = 0; i < MemLen; i++) {
        if (pMem[i] != bf.pMem[i]) {
            return 0;

        }
    }
    return 1;
}

TBitField TBitField::operator&(const TBitField& bf)
{
    int Len = max(BitLen, bf.BitLen);
    TBitField obj(Len);
    for (int i = 0; i < obj.MemLen; i++) {
        obj.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return obj;
}

TBitField TBitField::operator|(const TBitField& bf)
{
    int Len = max(BitLen, bf.BitLen);
    TBitField obj(Len);
    for (int i = 0; i < obj.MemLen; i++)
        obj.pMem[i] = pMem[i] | bf.pMem[i];
    return obj;
}

TBitField TBitField::operator~()
{
    TBitField obj(BitLen);
    for (int i = 0; i < BitLen; i++)
        if (GetBit(i) == 0)
            obj.SetBit(i);
    return obj;
}

istream& operator>>(istream& istr, TBitField& bf) {
    int ans;
    for (int i = 0; i < bf.BitLen; i++) {
        istr >> ans;
        if (ans == 0) {
            bf.ClrBit(i);
        }
        else if (ans == 1) {
            bf.SetBit(i);
        }
        else {
            throw ("The Element doesn't match the bitfield");
            break;
        }
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf)
{
    for (int i = 0; i < bf.GetLength(); ++i)
    {
        ostr << bf.GetBit(i) << " ";
    }
    return ostr;
}