#include "tstack.h"
#include <iostream>
using namespace std;


void test_stack()
{
	cout << "Input a max size of stack: \n";
	int max_size; cin >> max_size;
	try
	{
		TStack<int> stack(max_size);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	TStack<int> stack(max_size);

	cout << "Input a size of stack (it should be less than max_size:\n";
	int size; cin >> size;
	if (size > max_size)
	{
		cout << "Try again.\n"; return;
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Input a element:\n";
		int elem; cin >> elem;
		stack.Push(elem);
	}

	cout << "Stack.IsEmpty():  " << stack.IsEmpty() << endl;
	cout << "Stack.IsFull():   " << stack.IsFull() << endl;
	
	if (size != 0)
		cout << "Stack.Top()  " << stack.Top() << endl;
	

	if (size)
	{
		stack.Pop();
	}
	cout << "Stack after remove element: (if size != 0)  " << endl;
	cout << "Stack.IsEmpty():  " << stack.IsEmpty() << endl;
	cout << "Stack.IsFull():   " << stack.IsFull() << endl;
	if (size > 1) cout << "Stack.Top()  " << stack.Top() << endl;

	cout << "\n\n DONE! \n\n";
}

int main() 
{

	test_stack();
	return 0;
}