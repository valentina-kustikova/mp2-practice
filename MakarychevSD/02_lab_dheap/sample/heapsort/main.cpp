#include "HeapSort.h"
#include "Graph.h"
#include "Exception.h"
#include <iostream>
#include <time.h>

float* GenerateRandArr(int n)
{
	int a, b;
	cout << "Enter a range of values" << endl;
	cin >> a >> b;
	if (a >= b)
		throw M_Exeption("a must be more than b");
	float* arr = new float[n];
	cout << "Generated arr: ";
	for (int i = 0; i < n; i++)
	{
		arr[i] = a + rand() % b;
		cout << arr[i] << " ";
	}
	cout << endl;
	return arr;
}

int main()
{
	try
	{
		srand(time(0));
		int n;
		cout << "Enter the size of the array" << endl;
		cin >> n;
		if (n < 0)
			throw M_Exeption("Invalid parameter");
		float* arr = GenerateRandArr(n);
		PyramSort::Sort(arr, n);
		cout << "Sorted arr: ";
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	catch (const M_Exeption & exception)
	{
		cerr << " Error: " << exception.what() << endl;
	}
	return 0;
}