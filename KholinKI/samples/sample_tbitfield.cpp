#include <iostream>

#include "tbitfield.h"

int main()
{
	setlocale(LC_ALL, "rus");
	TBitField bf(18 + 1);//оригинал
	TBitField copy_bf(bf);//копия
	TBitField bf2(17 + 1);
	TBitField res1(1), res2(2), res3(3);
	cout << "Длина битового поля bf = " << bf.GetLength() << endl;

	bf.SetBit(5);//установить 5-ый бит в 1.
	bf.SetBit(4);//установить 4-ый бит в 1.
	bf.SetBit(18);//установить 18-ый бит в 1.
	bf.SetBit(2);//установить 2-ый бит в 1.
	bf.SetBit(1);//установить 1-ый бит в 1.

	//проверка бита на принадлежность
	bool status_bit = bf.GetBit(18);


	bf2.SetBit(3);//установить 7-ый бит в 1.
	bf2.SetBit(4);//установить 4-ый бит в 1.
	bf2.SetBit(8);//установить 8-ый бит в 1.
	bf2.SetBit(2);//установить 2-ый бит в 1.
	bf2.SetBit(1);//установить 1-ый бит в 1.


	bf.ClrBit(4);//установить 4-ый бит в 0.
	cout << "Состояние 4-ого бита: " << bf.GetBit(4) << endl;
	if (bf == bf2) {
		cout << "Битовые поля bf и bf2 одинаковы" << endl;
	}
	else {
		cout << "Битовые поля  bf и bf2 различны" << endl;
	}

	if (bf != bf2) {
		cout << "Битовые поля bf и bf2 различны" << endl;
	}
	else {
		cout << "Битовые поля bf и bf2 одинаковы" << endl;
	}

	//проверка на операции к себе
	bf = bf | bf;
	copy_bf = copy_bf & copy_bf;
	bf2 = ~bf2;

	//проверка операций
	cout << "operator &" << endl;
	res1 = bf & bf2;
	cout << res1 << endl;
	cout << endl;
	cout << "operator |" << endl;
	res2 = bf2 | bf;
	cout << res2 << endl;
	cout << endl;
	cout << "operator ~" << endl;
	res3 = ~bf;
	cout << res3 << endl;

	//проверка тройного присваивания
	/*bf = bf2 = copy_bf;*/

	//вывод на экран
	cout << "Битовое поле res1: " << bf << endl;
	cout << "Битовое поле res2: " << bf2 << endl;
	cout << "Битовое поле res3: " << copy_bf << endl;

    return 0;
}
