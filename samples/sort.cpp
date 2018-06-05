#include"Algorithms.h"
#include<iostream>
using namespace std;

int main() {
	double* Array=new double[10];
	cout << "Fill array" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> Array[i];
	}
	Algorithms<double>::Sort(Array, 10, 2);
	cout<< "Sorted array:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout<<"Array["<<i<<"]="<<Array[i]<<endl;
	}
}