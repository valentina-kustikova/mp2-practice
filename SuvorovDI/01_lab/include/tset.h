#ifndef __SET_H__
#define __SET_H__

#include "tbitfield.h"
#include <iostream>

class TSet
{
private:
    int MaxPower;       // максимальная мощность множества
    TBitField BitField; // битовое поле для хранения характеристического вектора
public:
    TSet(int mp) : MaxPower(mp), BitField(mp) {};
    TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.MaxPower) {
        BitField = s.BitField;
    };       // конструктор копирования
    TSet(const TBitField& bf) : MaxPower(bf.GetLength()), BitField(bf) {}; // конструктор преобразования типа
    operator TBitField();      // преобразование типа к битовому полю ЧТО ЭТО, КАК РАБОТАЕТ?

    // доступ к битам
    int GetMaxPower(void) const;
    void InsElem(const int Elem);       // включить элемент в множество
    void DelElem(const int Elem);       // удалить элемент из множества
    int IsMember(const int Elem) const; // проверить наличие элемента в множестве

    // теоретико-множественные операции
    int operator== (const TSet& s) const; // сравнение
    int operator!= (const TSet& s) const; // сравнение
    TSet& operator=(const TSet& s);  // присваивание
    TSet operator+ (const int Elem); // объединение с элементом
    // элемент должен быть из того же универса
    TSet operator- (const int Elem); // разность с элементом
    // элемент должен быть из того же универса
    TSet operator+ (const TSet& s);  // объединение
    TSet operator* (const TSet& s);  // пересечение
    TSet operator~ (void);           // дополнение

    friend std::istream& operator>>(std::istream& istr, TSet& s) {
        int Curr_Elem;
        while (true) {
            std::cout << "\n";
            istr >> Curr_Elem;
            if (Curr_Elem == -1) {
                break;
            }

            if (Curr_Elem >= 0 && Curr_Elem < s.MaxPower) {
                s.InsElem(Curr_Elem);
            }
            else {
                throw std::exception("out of range");
            }
        }

        return istr;
    }

    friend std::ostream& operator<<(std::ostream& ostr, const TSet& s) {
        ostr << "{";
        for (int i = 0; i < s.GetMaxPower(); i++) {
            if (s.IsMember(i)) {
                ostr << " " << i;
            }
        }
        ostr << " }";

        /*ostr << s.BitField;*/

        return ostr;
    }
};

#endif