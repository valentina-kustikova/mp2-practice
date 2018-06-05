#pragma once
#include <map>
#include"Stack.h"
#include <string>
using namespace std;
class funcs {
private:
	static int checkpriority(char);//проверка приоритета у символа
	static map<char, float> readvalue(string);//формирование контейнера типа map,где ключ-символ операнда,a значение-значение операнда
public:
	static void calculate(string);//подсчет арифметического выражения
	static string postfixform(string);//перевод в постфиксную форму
	static bool checkcorrectness(string);//проверка строки на корректность
};