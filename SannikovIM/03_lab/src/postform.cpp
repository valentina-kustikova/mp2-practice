#include "postform.h"
#include <string>
#include <gtest.h>

/*char* getPostform(char* simpleForm, int n) {
	TStack<char> s1(n);
	TStack<char> s2(n);
	for (int i = 0; i < n; i++) {
		if (simpleForm[i] == '+' || simpleForm[i] == '-') {
			s2.push(simpleForm[i]);
		}
		else if (simpleForm[i] == '*' || simpleForm[i] == '/') {

			if (s2.Top() == '+' || s2.Top() == '-') {
				while (!s2.isEmpty()) {
					s1.push(s2.Top());
					s2.pop();
				}
				s2.push(simpleForm[i]);
			}
		}
			//else if (simpleForm[i] == '(') s2.push(simpleForm[i]);
			else if (simpleForm[i] == ')') {
				while (!s2.isEmpty()) {
					s1.push(s2.Top());
					s2.pop();
				}
				s1.pop();
			}
			else {
				s1.push(simpleForm[i]);
			}
	}
	while (!s2.isEmpty()) {
		s1.push(s2.Top());
		s2.pop();
	}
	char* newForm = new char[n];
	while (!s2.isEmpty()) {
		s1.push(s2.Top());
		s2.pop();
	}
	int i = 0;
	while (!s1.isEmpty()) {
		newForm[i] + s1.Top();
		s1.pop();
		i++;
	}

	return newForm;


	*/