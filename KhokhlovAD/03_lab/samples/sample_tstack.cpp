#include <iostream> 
#include "tstack.h"
#include <cstring>
#include "postfix.h"

int main()
{
	using namespace std;
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

	cout << "Input a size of stack:\n";
	int size; cin >> size;
	if (size > max_size)
	{
		cout << "Try again.\n";
	}

	for (int i = 0; i < size; i++)
	{
		cout << "Input a element:\n";
		int elem; cin >> elem;
		stack.push(elem);
	}

	cout << "Stack.IsEmpty():  " << stack.IsEmpty() << endl;


	if (size != 0)
		cout << "Stack.check()  " << stack.check() << endl;
	
	if (size)
	{
		stack.pop();
	}
	cout << "Stack after remove element: " << endl;
	cout << "Stack.IsEmpty():  " << stack.IsEmpty() << endl;;
	if (size > 1) cout << "Stack.Top()  " << stack.check() << endl;

	cout << "\n\n DONE! \n\n";
	

	system("PAUSE");
	return 0;
}