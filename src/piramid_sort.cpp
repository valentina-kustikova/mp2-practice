#include <DHBPQ.h>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> piramid_sort(vector<T> m) {
	DHBPQ<T> queue = DHBPQ<T>(m, 2);
	vector<T> sorted;
	while (!queue.is_empty()) {
		sorted.push_back(queue.pop());
	}
	return sorted;
}


int main() {
	srand(time(nullptr));

	for (int arr = 1; arr <= 8; arr++) {
		const int length = rand() % 10 + 5;
		vector<int> v = vector<int>();
		for (int i = 0; i < length; i++) {
			v.push_back(rand() % 30 - 10);
		}
		cout << "Array #" << arr << ": ";
		for (int i = 0; i < v.size(); i++) {
			cout.width(4);
			cout << v[i];
		}
		cout << endl << "Sorted:   ";
		v = piramid_sort(v);
		for (int i = 0; i < v.size(); i++) {
			cout.width(4);
			cout << v[i];
		}
		cout << "\n\n";
	}

	return 0;
}
