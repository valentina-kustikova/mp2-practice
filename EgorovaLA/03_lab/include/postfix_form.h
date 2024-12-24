#pragma once

#include "array_stack.h"
#include "list_stack.h"
#include <locale.h>

void menu();

string* fill_const(const string& str1,int &size);

int get_count_consts(const string& str1);

bool priority(string elem1, string elem2);

void expression(TStack<string>*& st1, TStack<string>*& st2, string* express, int size);  //работа с выражением

void read(TStack<string>*& st1, TStack<string>*& st2, const string& str);

void print_stack(TStack<string>*& st1);

template<typename T> T calculate(TStack<string>*& st1);


//На массивах

void manipulateArr(const string& str1, string*);

//На списках

void manipulateList(const string& str1, string*);
