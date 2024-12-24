#include "postfix_form.h"

void menu() {
	string str;
	cout << "Введите арифметическое выражение\n";
	cin >> str;
	cout << "Введите значения для введенных констант\n";
	int size;
	string* consts = fill_const(str, size);
	for (int i = 0; i < size; i++) {
		cin >> consts[i];
	}
	cout << "Выберете способ подсчета.\n" <<
		"С помощью стека на массивах - 1, на листах - 2\n";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		manipulateArr(str, consts);
		break;
	case 2:
		manipulateList(str, consts);
		break;
	default:
		cout << "Неверный ввод\n";
		break;
	}
	return;
}

int get_count_consts(const string& str1) {
	int lenstr = str1.length();
	int i = 0;
	char elem;
	int curr = 0;
	while (i < lenstr) {
		elem = str1[i];
		if ((elem != '+') && (elem != '-') && (elem != '*')
			&& (elem != '/') && (elem != '(') && (elem != ')')) {
			i++;
			continue;
		}
		if ((elem == '(') || (elem == ')')) {
			i++;
			continue;
		}
		i++;
		curr++;
	}
	return curr;
}

string* fill_const(const string& str1,int &size) {
	int lenstr = str1.length();
	int i = 0, curr = 0, count = get_count_consts(str1);
	char elem;
	string* consts = new string[count+1];
	while (i < lenstr) {
		elem = str1[i];
		if ((elem != '+') && (elem != '-') && (elem != '*')
			&& (elem != '/') && (elem != '(') && (elem != ')')) {
			consts[curr] += elem;
			i++;
			continue;
		}
		if ((elem == '(') || (elem == ')')) {
			i++;
			continue;
		}
		curr++;
		i++;
	}
	for (int j = 0; j < count+1; j++) {
		cout << consts[j] << " ";
	}
	cout << "\n";
	size = count + 1;
	return consts;
}

bool priority(string elem1, string elem2) {
	int res1 = 0, res2 = 0;
	if ((elem1 == "(") || (elem1 == ")"))  res1 = 1;
	if ((elem2 == "(") || (elem2 == ")"))  res2 = 1;
	if ((elem1 == "+") || (elem1 == "-"))  res1 = 2;
	if ((elem2 == "+") || (elem2 == "-"))  res2 = 2;
	if ((elem1 == "*") || (elem1 == "/"))  res1 = 3;
	if ((elem2 == "*") || (elem2 == "/"))  res2 = 3;
	return (res1 > res2);
}

void print_stack(TStack<string>*& st1) {
	TStack<string>* stack(st1);
	while (stack->IsEmpty() != 1) {
		cout << st1->Top();
		stack->Pop();
	}
	cout << "\n";
}

void expression(TStack<string>*& st1, TStack<string>*& st2, string* express, int size) {
	int lenexp = size;
	int i = 0;
	string elem;
	while (i < lenexp) {
		elem = express[i];
		if ((elem != "+") && (elem != "-") && (elem != "*")//блок для букв
			&& (elem != "/") && (elem != "(") && (elem != ")")) {
			st1->Push(elem);
			i++;
			continue;
		}
		if ((elem == "+") || (elem == "-") || (elem == "*")//операции
			|| (elem == "/") || (elem == "(") || (elem == ")")) {
			if (st2->IsEmpty()) {//если начало
				st2->Push(elem);
				i++;
				continue;
			}
			if ((elem == "(")) {
				st2->Push(elem);
				i++;
				continue;
			}
			if ((elem == ")")) {
				while (st2->Top() != "(") {
					st1->Push(st2->Top());
					st2->Pop();
				}
				st2->Pop();
				i++;
				continue;
			}
			if (priority(elem, st2->Top())) {//проверка приоритета, если низ меньше работаем
				st2->Push(elem);
				i++;
				continue;
			}
			else {
				while (priority(elem, st2->Top()) != 1) {
					st1->Push(st2->Top());//если нет то кладем в стек1
					st2->Pop();
					if (st2->IsEmpty()) break;
				}
				st2->Push(elem);
				i++;
				continue;
			}
		}
	}
	while (st2->IsEmpty()!=1) {
		st1->Push(st2->Top());
		st2->Pop();
	}
}

void read(TStack<string>*& st1, TStack<string>*& st2,const string& str) {
	int lenstr = str.length();
	string* express = new string[lenstr+1];
	int i = 0;
	int curr = 0;
	char elem;
	while (i < lenstr) {
		elem = str[i];
		if ((elem != '+') && (elem != '-') && (elem != '*')
			&& (elem != '/') && (elem != '(') && (elem != ')')) {
			express[curr] += elem;
			i++;
			continue;
		}
		if ((elem == '(')) {
			express[curr] = elem;
			curr++;
			i++;
			continue;
		}
		if ((elem == ')')) {
			curr++;
			express[curr] = elem;
			i++;
			continue;
		}
		curr++;
		express[curr] = elem;
		curr++;
		i++;
	}
	expression(st1, st2, express, lenstr+1);
	delete[] express;
}

template<typename T> T calculate(TStack<string>*& st1) {

}

//Для массивов

void manipulateArr(const string& str1, string* consts) {
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TStackArray <string> (str1.length()*2);
	stack2 = new TStackArray <string> (str1.length());

	read(stack1, stack2, str1);

	cout << "Выражение в постфиксной форме\n";
	print_stack(stack1);
	cout << "Ответ с введенными значениями: ";
}

//Для списков

void manipulateList(const string& str1, string* consts) {
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TListStack <string>();
	stack2 = new TListStack <string>();

	read(stack1, stack2, str1);

	cout << "Выражение в постфиксной форме\n";
	print_stack(stack1);
	cout << "Ответ с введенными значениями: ";
}


