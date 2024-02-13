#include "stack.h"
using namespace std;

int main()
{
	cout << "Input a max size of stack: \n";
	int max_size; cin >> max_size;
	try
	{
		Stack<int> stack(max_size);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	Stack<int> stack(max_size);

	cout << "Input a size of stack (it should be less than max_size:\n";
	int size; cin >> size;
	if (size > max_size)
	{
		cout << "Try again.\n";
		return 0;
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Input a element:\n";
		int elem; cin >> elem;
		stack.push(elem);
	}

	cout << "Stack.IsEmpty():  " << stack.isEmpty() << endl;
	cout << "Stack.IsFull():   " << stack.isFull() << endl;

	if (size != 0)
		cout << "Stack.Top()  " << stack.top() << endl;


	if (size)
	{
		stack.pop();
	}
	cout << "Stack after remove element: (if size != 0)  " << endl;
	cout << "Stack.IsEmpty():  " << stack.isEmpty() << endl;
	cout << "Stack.IsFull():   " << stack.isFull() << endl;
	if (size > 1) cout << "Stack.Top()  " << stack.top() << endl;

	cout << "\n\n DONE! \n\n";
	return 0;
}
