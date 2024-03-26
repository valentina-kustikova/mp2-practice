#include <iostream>
#include "tringlist.h"

using namespace std;

template<typename T>
void PrintList(TRingList<T>& rl) {
	rl.Reset();
	while (!rl.IsEnded()) {
		cout << rl.GetCurrent()->key << " ";
	}
}

int main() {
	cout << "TRingList\n" << endl;
	
	try {
		TRingList<int> rl;
		int ans = 0;
		do {
			system("cls");
			cout << "";
			cin >> ans;

		} while (ans != 0);
	}
	catch (string exp) {
		cout << exp << endl;
	}

	return 0;
}
