#include <iostream> 
#include "tstack.h"
#include <cstring>


int main()
{
	using namespace std;
	cout << "Input a max size of stack: \n";
	int max_size; 
	cin >> max_size;
	try
	{
		TStack<int> stack(max_size);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	TStack<int> stack(max_size);

	cout << "Input a size of stack:\n";
	int size; cin >> size;
	if (size > max_size)
	{
		cout << "Try again.\n";
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Input a element:\n";
		int elem; 
		cin >> elem;
		stack.push(elem);
	}

	cout << "Stack.IsEmpty():  " << stack.isEmpty() << endl;
	cout << "Stack.IsFull():  " << stack.isFull() << endl;

	if (size != 0)
		cout << "Stack.Top()  " << stack.Top() << endl;
	
	TStack<int> stack2(stack);
	cout << "stack2(stack)" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << stack2.Top() << endl;
		stack2.Pop();
	}
	if (size)
	{
		stack.Pop();
	}
	cout << "Stack after remove element: " << endl;
	cout << "Stack.IsEmpty():  " << stack.isEmpty() << endl;
	cout << "Stack.IsFull():  " << stack.isFull() << endl;
	if (size > 1) cout << "Stack.Top()  " << stack.Top() << endl;

	cout << "\n\n DONE! \n\n";
	

	system("PAUSE");
	return 0;
}