#pragma once

#include "array_stack.h"
#include "list_stack.h"
#include <locale.h>
#include <iterator>
#include <map>
#include <vector>
#include<string>

void menu();

vector<string> fill_const(const string& str1);

bool priority(string elem1, string elem2);

void expression(TStack<string>*& st1, TStack<string>*& st2, vector<string>& express); //работа с выражением

void add_elem(vector<string>& express, int curr, string elem);

vector<string> read(const string& str);

void print_stack(TStack<string>*& st1, TStack<string>*& st2);

double calculate(TStack<string>*& st1,TStack<string>*& st2, map<string, double>& var);


//На массивах
void manipulateArr(const string& str1, map<string, double>& var);

//На списках
void manipulateList(const string& str1,map<string, double>& var);
