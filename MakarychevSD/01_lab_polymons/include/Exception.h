#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;

class M_Exeption :public exception
{
private:
	string m_error;
public:
	M_Exeption(string error) : m_error(error)
	{
	}
	const char* what() const noexcept
	{
		return m_error.c_str();
	}
};
