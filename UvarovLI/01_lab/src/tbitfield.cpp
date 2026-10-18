// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

#include <stdexcept>

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
  if (len < 0)
    throw length_error("Длина битового поля не может быть отрицательной");

  BitLen = len;

  // Сколько элементов TELEM нужно, чтобы вместить len битов.
  // Деление с округлением вверх: добавляем (размер - 1), тогда любой
  // ненулевой остаток добавляет ещё один элемент, а полные - нет.
  const int bitsInElem = sizeof(TELEM) * 8;
  MemLen = (len + bitsInElem - 1) / bitsInElem;

  // Память под биты. Обязательно обнуляем: new оставляет мусор,
  // а тест new_bitfield_is_set_to_zero ждёт все биты нулевыми.
  pMem = new TELEM[MemLen];
  for (int i = 0; i < MemLen; i++)
    pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
}

TBitField::~TBitField()
{
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
  // В каком элементе массива лежит бит n.
  // Биты 0..31 -> pMem[0], биты 32..63 -> pMem[1] и так далее.
  // bitsInElem обязательно int: sizeof даёт беззнаковый тип, и деление
  // отрицательного n на беззнаковое дало бы огромное число вместо минуса.
  const int bitsInElem = sizeof(TELEM) * 8;
  return n / bitsInElem;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
  // Число, где все биты нули, кроме одного - на месте бита n
  // внутри своего элемента. Остаток от деления даёт позицию,
  // сдвиг влево ставит единицу на эту позицию.
  const int bitsInElem = sizeof(TELEM) * 8;
  return (TELEM)1 << (n % bitsInElem);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
  // Бит должен существовать: допустимы номера от 0 до BitLen-1.
  if (n < 0 || n >= BitLen)
    throw out_of_range("Номер бита вне диапазона битового поля");

  // GetMemIndex(n) - в каком элементе массива лежит этот бит.
  // GetMemMask(n)  - число с единицей на его месте.
  // |= ставит эту единицу, остальные биты элемента не трогает.
  pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
  // Проверка та же, что в SetBit.
  if (n < 0 || n >= BitLen)
    throw out_of_range("Номер бита вне диапазона битового поля");

  // ~GetMemMask(n) - все единицы, кроме нуля на месте бита n.
  // &= с таким числом гасит только этот бит: там, где в маске
  // единица, бит сохраняется, а на месте нуля обнуляется.
  pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  // Проверка та же.
  if (n < 0 || n >= BitLen)
    throw out_of_range("Номер бита вне диапазона битового поля");

  // & оставляет от элемента только интересующий бит: результат
  // либо 0, либо само значение маски (например 32 для бита 5).
  // Тесты ждут 0 или 1, поэтому приводим к этим двум значениям.
  return (pMem[GetMemIndex(n)] & GetMemMask(n)) ? 1 : 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    return FAKE_BITFIELD;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return FAKE_INT;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return FAKE_INT;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator~(void) // отрицание
{
    return FAKE_BITFIELD;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    return ostr;
}
