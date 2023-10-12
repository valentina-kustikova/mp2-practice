#include <iostream>

#include "tbitfield.h"

int main()
{


	

	setlocale(LC_ALL, "rus");
	cout << "Создание битовых полей..." << endl;
	TBitField bf(20 + 1);//оригинал
	TBitField copy_bf(bf);//копия
	TBitField bf2(17 + 1);
	TBitField res1(1), res2(2), res3(3);
	cout << endl;
	cout << "Битовое поле bf: " << bf << endl;
	cout << "Битовое поле copy_bf: " << copy_bf << endl;
	cout << "Битовое поле bf2: " << bf2<< endl;
	cout << endl;

	cout << "Длина битового поля bf = " << bf.GetLength() << endl;
	cout << endl;
	cout << "Установка битового поля bf..." << endl;
	bf.SetBit(5);//установить 5-ый бит в 1.
	bf.SetBit(4);//установить 4-ый бит в 1.
	bf.SetBit(20);//установить 20-ый бит в 1.
	bf.SetBit(2);//установить 2-ый бит в 1.
	bf.SetBit(1);//установить 1-ый бит в 1.
	cout << "Битовое поле bf: " << bf << endl;

	//проверка бита на принадлежность
	bool status_bit = bf.GetBit(16);
	cout << endl;
	cout << "Установка битового поля bf2..." << endl;
	
	bf2.SetBit(3);//установить 7-ый бит в 1.
	bf2.SetBit(4);//установить 4-ый бит в 1.
	bf2.SetBit(8);//установить 8-ый бит в 1.
	bf2.SetBit(2);//установить 2-ый бит в 1.
	bf2.SetBit(1);//установить 1-ый бит в 1.
	cout << "Битовое поле bf2: " << bf2 << endl;
	cout << endl;
	cout << "Очистка 4-ого бита битового поля bf..." << endl;
	bf.ClrBit(4);//установить 4-ый бит в 0.
	cout << "Состояние 4-ого бита bf: " << bf.GetBit(4) << endl;
	cout << "Битовое поле bf: " << bf << endl;
	cout << endl;
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
	cout << endl;
	////проверка на операции к себе
	//bf = bf | bf;
	//copy_bf = copy_bf & copy_bf;
	//bf2 = ~bf2;

	cout << "Выполнение операций над битовыми полями: " << endl;
	cout << endl;
	//проверка операций
	cout << "operator &: bf и bf2" << endl;
	res1 = bf & bf2;
	cout << res1 << endl;
	cout << endl;
	cout << "operator | bf2 или bf" << endl;
	res2 = bf2 | bf;
	cout << res2 << endl;
	cout << endl;
	cout << "operator ~ не bf" << endl;
	res3 = ~bf;
	cout << res3 << endl;

	//проверка тройного присваивания
	/*bf = bf2 = copy_bf;*/
	cout << endl;
	cout << "Результаты операций: " << endl;
	//вывод на экран
	cout << "Битовое поле res1: " << res1 << endl;
	cout << "Битовое поле res2: " << res2 << endl;
	cout << "Битовое поле res3: " << res3 << endl;

    return 0;
}
