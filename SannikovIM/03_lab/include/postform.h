#include <iostream>
#include <map>
#include "stack.h"

using namespace std;

string getPostform(const string& simpleForm, int n);

int Calculate(const string& postForm, int n, map<char, int>& values);
