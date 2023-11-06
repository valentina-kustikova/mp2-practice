#include "tmatrix.h"


void test_tmatrix()
{
	TMatrix<int> m1(3), m2(3);
	cout << "Input 2 matrix (6 int elements for each): \n";
	cin >> m1 >> m2;
	cout << "First mector:\n" << m1 << endl;
	cout << "Second mector:\n" << m2 << "\n\n";
	cout << "m1+m2:\n" << m1 + m2 << endl;
	cout << "m1-m2:\n" << m1 - m2 << endl;
	cout << "m1*m2:\n" << m1 * m2 << endl;
	cout << "m1.size(): " << m1.GetSize() << endl;
	cout << "m1 == m2: " << (m1 == m2) << endl;
	m1 = m2;
	cout << "m1 == m2 after m1 = m2: " << (m1 == m2) << endl;
	cout << "m1[1]: " << m1[1] << endl;
	cout << "m2[0][1]: " << m2[0][1] << endl;
	cout << "m1 != m2: " << (m1 != m2) << endl;

	cout << "OK" << endl;
	return;
}

int main()
{
	test_tmatrix();
}