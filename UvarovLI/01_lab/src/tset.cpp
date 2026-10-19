// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
static TSet FAKE_SET(1);

TSet::TSet(int mp) : BitField(mp)
{
  // Множество хранит числа от 0 до mp-1: номер бита = само число.
  MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
  // Битовое поле копируется своим конструктором копирования
  // (он в списке инициализации выше), здесь остаётся только мощность.
  MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
  // Готовое битовое поле становится множеством: его длина
  // и есть максимальная мощность - числа от 0 до длины-1.
  MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
  // Обратное преобразование: отдаём характеристический вектор.
  return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
  return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
  // Число входит в множество тогда и только тогда,
  // когда бит с его номером равен единице.
  return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
  // Добавить число = поставить бит. Проверку диапазона
  // сделает сам SetBit и бросит исключение, если элемент чужой.
  BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
  // Удалить число = погасить бит.
  BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &s) // присваивание
{
  if (this == &s)
    return *this;

  // Вся работа с памятью уже написана в operator= битового поля.
  MaxPower = s.MaxPower;
  BitField = s.BitField;

  return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
  // Множества равны, когда совпали и универс, и сами биты.
  return (MaxPower == s.MaxPower) && (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
  return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
  // Объединение множеств - это побитовое "или" их векторов.
  // TSet строится из TBitField конструктором преобразования.
  return TSet(BitField | s.BitField);
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
  // Копируем себя и добавляем число - исходное множество не меняется.
  TSet res(*this);
  res.InsElem(Elem);
  return res;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
  // То же самое, но элемент убираем.
  TSet res(*this);
  res.DelElem(Elem);
  return res;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
  // Пересечение - побитовое "и".
  return TSet(BitField & s.BitField);
}

TSet TSet::operator~(void) // дополнение
{
  // Дополнение до универса - побитовое отрицание.
  return TSet(~BitField);
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
  // Читаем номера элементов, пока они попадают в универс.
  int elem;
  while (istr >> elem)
  {
    if (elem < 0 || elem >= s.GetMaxPower())
      break;
    s.InsElem(elem);
  }
  return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
  // Печатаем в привычном виде: { 1 3 7 }
  ostr << "{ ";
  for (int i = 0; i < s.GetMaxPower(); i++)
    if (s.IsMember(i))
      ostr << i << " ";
  ostr << "}";
  return ostr;
}
