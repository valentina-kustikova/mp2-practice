#include "polinom.h"
#include "monom.h"
#include "gtest.h"

TEST(Node, test_create_Monom)
{
	Node a;

	EXPECT_EQ(a.data.coef, 0);
}
TEST(Node, test_create_Monom_with_parameters_1)
{
	Node a(1, 2, 3, 3);
	EXPECT_EQ(a.data.coef, 1);
}
TEST(Node, test_create_Monom_with_parameters_2)
{
	Node a(1, 2, 3, 4);
	EXPECT_EQ(a.data.degx, 2);
}
TEST(Node, test_create_Monom_with_parameters_3)
{
	Node a(1, 2, 3, 4);
	EXPECT_EQ(a.data.degy, 3);
}
TEST(Node, test_create_Monom_with_parameters_4)
{
	Node a(1, 2, 3, 4);
	EXPECT_EQ(a.data.degz, 4);
}

TEST(Node, test_create_Monom_with_copy)
{
	Node a(1, 2, 3, 4);
	Node b(a);
	if ((a.data.coef == b.data.coef) && (a.data.degx == b.data.degx) && (a.data.degy == b.data.degy) && (a.data.degz == b.data.degz)) SUCCEED();
	else FAIL();
}
TEST(Node, test_Monom_equal_monom)
{
	Node a(1, 2, 3, 4);
	Node b;
	b = a;
	if ((a.data.coef == b.data.coef) && (a.data.degx == b.data.degx) && (a.data.degy == b.data.degy) && (a.data.degz == b.data.degz)) SUCCEED();
	else FAIL();
}
TEST(Node, test_Monom_equal_scalar)
{
	Node a(1, 2, 3, 4);
	double const b = 10.5;
	a = b;
	if ((a.data.coef == b) && (a.data.degx == 0) && (a.data.degy == 0) && (a.data.degz == 0)) SUCCEED();
	else FAIL();
}
TEST(Node, test_Monom_compare_1)
{
	Node a(1, 2, 3, 4);
	Node b(a);

	if (a == b) SUCCEED();
	else FAIL();
}
TEST(Node, test_Monom_compare_2)
{
	Node a(1, 2, 3, 4);
	Node b(-1, 2, 3, 4);

	if (a != b) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_Polinom_create) {
	//Node a(6, 2, 3, 4);
//	Node b(-5, 7, 10, 22);
	//Node c(10, 5, 6, 7);
	Polinom A;
	ASSERT_NO_THROW();
}

TEST(Polinom, test_Polinom_addFIRST) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	auto it1 = A.begin();
	it1++;
	//cout << (*it1);
	if (((*it1).data.coef == c.data.coef) && ((*it1).data.degx == c.data.degx) && ((*it1).data.degy == c.data.degy) && ((*it1).data.degz == c.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->[b]->[a]->nullptr
}
TEST(Polinom, test_Polinom_addLAST) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	auto it1 = A.begin();
	it1++;
	//cout << (*it1);
	if (((*it1).data.coef == a.data.coef) && ((*it1).data.degx == a.data.degx) && ((*it1).data.degy == a.data.degy) && ((*it1).data.degz == a.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[a]->[b]->[c]->nullptr
}
TEST(Polinom, test_Polinom_addNOW_1) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Node d(13, 44, 55, 66);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	auto it1 = A.begin();
	it1++;
	it1++;
	A.addNow(d, (*it1));
	//	A.showList2();
	it1++;
	//	cout << (*it1);

	if (((*it1).data.coef == d.data.coef) && ((*it1).data.degx == d.data.degx) && ((*it1).data.degy == d.data.degy) && ((*it1).data.degz == d.data.degz)) SUCCEED();
	else FAIL();

}
TEST(Polinom, test_Polinom_addNOW_2) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Node d(13, 44, 55, 66);
	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	auto it1 = A.begin();
	it1++;
	A.addNow(d, (*it1));
	it1++;
	//	A.showList2();
	//	cout << (*it1);

	if (((*it1).data.coef == d.data.coef) && ((*it1).data.degx == d.data.degx) && ((*it1).data.degy == d.data.degy) && ((*it1).data.degz == d.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr
}

TEST(Polinom, test_Polinom_create_by_constructor) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	auto it1 = A.begin();
	it1++;
	Polinom B(A);
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
	//[head]->[a]->[b]->[c]->nullptr
}

TEST(Polinom, test_del_First_with_all_addLast) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);

	//cout << (*it1);
	A.delFirst();
	auto it1 = A.begin();
	it1++;
	if (((*it1).data.coef == b.data.coef) && ((*it1).data.degx == b.data.degx) && ((*it1).data.degy == b.data.degy) && ((*it1).data.degz == b.data.degz)) SUCCEED();
	else FAIL();
	//[head]->X[a]X->[b]->[c]->nullptr
}
TEST(Polinom, test_del_First_with_all_addFirst) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.delFirst();
	auto it1 = A.begin();
	it1++;
	//cout << (*it1);
	if (((*it1).data.coef == b.data.coef) && ((*it1).data.degx == b.data.degx) && ((*it1).data.degy == b.data.degy) && ((*it1).data.degz == b.data.degz)) SUCCEED();
	else FAIL();
	//[head]->X[c]X->[b]->[a]->nullptr

}
TEST(Polinom, test_del_First_with_all_addNow) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Node d(13, 44, 55, 66);
	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	auto it1 = A.begin();
	it1++;
	A.addNow(d, (*it1));
	it1++;
	A.delFirst();
	it1 = A.begin();
	++it1;
	//	A.showList2();
	//	cout << (*it1);
	if (((*it1).data.coef == d.data.coef) && ((*it1).data.degx == d.data.degx) && ((*it1).data.degy == d.data.degy) && ((*it1).data.degz == d.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr

}
TEST(Polinom, test_del_First_with_all) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Node d(13, 44, 55, 66);
	Polinom A;
	A.addFirst(a);
	A.addLast(b);
	A.addLast(c);
	auto it1 = A.begin();
	it1++;
	A.addNow(d, (*it1));
	it1++;
	//A.showList2();

	A.delFirst();
	it1 = A.begin();
	++it1;
	//	A.showList2();
	//	cout << (*it1);
	if (((*it1).data.coef == d.data.coef) && ((*it1).data.degx == d.data.degx) && ((*it1).data.degy == d.data.degy) && ((*it1).data.degz == d.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr

}

TEST(Polinom, test_del_Last_with_all_addLast) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);

	//cout << (*it1);
	A.delLast();
	auto it1 = A.begin();
	while ((*it1).next != nullptr) {
		it1++;
	}
	if (((*it1).data.coef == b.data.coef) && ((*it1).data.degx == b.data.degx) && ((*it1).data.degy == b.data.degy) && ((*it1).data.degz == b.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[a]->[b]->X[c]X->nullptr
}
TEST(Polinom, test_del_Last_with_all_addFirst) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.delLast();
	auto it1 = A.begin();
	while ((*it1).next != nullptr) {
		it1++;
	}
	//cout << (*it1);
	if (((*it1).data.coef == b.data.coef) && ((*it1).data.degx == b.data.degx) && ((*it1).data.degy == b.data.degy) && ((*it1).data.degz == b.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->[b]->X[a]X->nullptr

}
TEST(Polinom, test_del_Last_with_all_addNow) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Node d(13, 44, 55, 66);
	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	auto it1 = A.begin();
	it1++;
	A.addNow(d, (*it1));
	it1++;
	A.delLast();
	it1 = A.begin();
	while ((*it1).next != nullptr) {
		it1++;
	}
	//	A.showList2();
	//	cout << (*it1);
	if (((*it1).data.coef == b.data.coef) && ((*it1).data.degx == b.data.degx) && ((*it1).data.degy == b.data.degy) && ((*it1).data.degz == b.data.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr

}
TEST(Polinom, test_del_Last_with_all) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Node d(13, 44, 55, 66);
	Polinom A;
	A.addFirst(a);
	A.addLast(b);
	A.addLast(c);
	auto it1 = A.begin();
	it1++;
	A.addNow(d, (*it1));
	it1++;
	//A.showList2();

	A.delLast();
	it1 = A.begin();
	while ((*it1).next != nullptr) {
		it1++;
	}
	//A.showList2();
	//	cout << (*it1);
	if (((*it1).data.coef == b.data.coef) && ((*it1).data.degx == b.data.degx) && ((*it1).data.degy == b.data.degy) && ((*it1).data.degz == b.data.degz)) SUCCEED();
	else FAIL();


}

TEST(Polinom, test_del_Elem_with_all_addLast) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10.4, 5, 6, 7);
	Node d(20.52, 214, 124, 555);
	Node e(55.5, -12, 50, 11);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	Polinom B;
	B = A;
	B -= b;
	B.podobnyi();
	//	A.showList2();
	auto it1 = A.begin();
	it1++;
	it1++;
	//cout << (*it1);
	A.delElem(*it1);
	//	A.showList2();
	//	B.showList2();
	EXPECT_EQ(A, B);
}
TEST(Polinom, test_del_Elem_with_all_addFirst) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10.4, 5, 6, 7);
	Node d(20.52, 214, 124, 555);
	Node e(55.5, -12, 50, 11);
	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.addFirst(d);
	A.addFirst(e);
	Polinom B;
	B = A;
	B -= d;
	B.podobnyi();
	//	A.showList2();
	auto it1 = A.begin();
	it1++;
	it1++;
	//cout << (*it1);
	A.delElem(*it1);
	//	A.showList2();
	//	B.showList2();
	EXPECT_EQ(A, B);

}
TEST(Polinom, test_del_Elem_with_all) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10.4, 5, 6, 7);
	Node d(20.52, 214, 124, 555);
	Node e(55.5, -12, 50, 11);
	Polinom A;
	auto it1 = A.begin();
	A.addLast(a);
	A.addFirst(b);
	it1++;
	A.addNow(c, *it1);
	it1++;
	A.addNow(d, *it1);
	it1++;
	A.addNow(e, *it1);
	Polinom B;
	B = A;
	B -= d;
	B.podobnyi();
	//B.showList2();


	it1 = A.begin();
	it1++;
	it1++;
	it1++;
	A.delElem(*it1);

	//A.showList2();

	EXPECT_EQ(A, B);

}

TEST(Polinom, test_str_to_polynom_1) {

	Polinom R;
	R.str_to_poly("1");
	auto it1 = R.begin();
	it1++;
	if (((*it1).data.coef == 1) && ((*it1).data.degx == 0) && ((*it1).data.degy == 0) && ((*it1).data.degz == 0)) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_2) {

	Polinom R;
	R.str_to_poly("1xyz");
	auto it1 = R.begin();
	it1++;
	if (((*it1).data.coef == 1) && ((*it1).data.degx == 1) && ((*it1).data.degy == 1) && ((*it1).data.degz == 1)) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_3) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46");
	auto it1 = R.begin();
	it1++;
	if (((*it1).data.coef == 444) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46)) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_4_with_errors_1) {

	Polinom R;
	//R.str_to_poly("444x^2y^3zS46");
	EXPECT_ANY_THROW(R.str_to_poly("444x^2y^3zS46"));
}
TEST(Polinom, test_str_to_polynom_4_with_errors_2) {

	Polinom R;
	//R.str_to_poly("444x^2y^3zS46");
	EXPECT_ANY_THROW(R.str_to_poly("QW444x^2y^3z^46"));
}
TEST(Polinom, test_str_to_polynom_4_with_errors_3) {

	Polinom R;
	//R.str_to_poly("444x^2y^3zS46");
	EXPECT_ANY_THROW(R.str_to_poly("444x^2y^3z46"));
}
TEST(Polinom, test_str_to_polynom_5) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46+1xyz");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).data.coef == 1) && ((*it1).data.degx == 1) && ((*it1).data.degy == 1) && ((*it1).data.degz == 1))
	{
		it1++;
		if (((*it1).data.coef == 444) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_6) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46+1x^3y^7z^7");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).data.coef == 1) && ((*it1).data.degx == 3) && ((*it1).data.degy == 7) && ((*it1).data.degz == 7))
	{
		it1++;
		if (((*it1).data.coef == 444) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_7) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46-xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).data.coef == -1) && ((*it1).data.degx == 1) && ((*it1).data.degy == 7) && ((*it1).data.degz == 700))
	{
		it1++;
		if (((*it1).data.coef == 444) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_8) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46-xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).data.coef == -1) && ((*it1).data.degx == 1) && ((*it1).data.degy == 7) && ((*it1).data.degz == 700))
	{
		it1++;
		if (((*it1).data.coef == 444) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_9) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46-444x^2y^3z^46");
	//R.showList2();
	auto it1 = R.begin();
	it1++;

	if (((*it1).data.coef == 0) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
	{
		SUCCEED();
	}

	else FAIL();
}
TEST(Polinom, test_str_to_polynom_10_with_podobny) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46+444x^2y^3z^46");
	//R.showList2();
	auto it1 = R.begin();
	it1++;

	if (((*it1).data.coef == 888) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
	{
		SUCCEED();
	}

	else FAIL();
}
TEST(Polinom, test_str_to_polynom_11_with_podobny) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46+444x^2y^3z^46-xy^7z^700-20xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;

	if (((*it1).data.coef == -21) && ((*it1).data.degx == 1) && ((*it1).data.degy == 7) && ((*it1).data.degz == 700))
	{
		it1++;
		if (((*it1).data.coef == 888) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinom, test_str_to_polynom_12_with_podobny) {

	Polinom R;
	R.str_to_poly("444x^2y^3z^46+444x^2y^3z^46-xy^7z^700+xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	it1++;
	//R.showList2();
	R.podobnyi();
	//R.showList2();

	if (((*it1).data.coef == 888) && ((*it1).data.degx == 2) && ((*it1).data.degy == 3) && ((*it1).data.degz == 46))
	{
		SUCCEED();
	}

	else FAIL();
}
TEST(Polinom, test_str_to_polynom_13) {
	Node a(1, 2, 3, 4);
	Node b(-1, 7, 10, 22);
	Node c(1, 5, 6, 7);
	Node d(1, 214, 124, 555);
	Node e(1, -12, 50, 11);

	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(1);
	//A.showList2();

	Polinom B;
	B.str_to_poly("-12x^-13y^50z^11+214x^213y^124z^555+5x^4y^6z^7-7x^6y^10z^22+2x^1y^3z^4");

	B.podobnyi();


	//B.showList2();
	EXPECT_EQ(A, B);
}

TEST(Polinom, test_podobnie) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10.4, 5, 6, 7);
	Node d(20.52, 214, 124, 555);
	Node e(55.5, -12, 50, 11);

	Polinom A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.addFirst(d);
	A.addFirst(e);
	//A.showList2();

	Polinom B;
	B = A;
	B -= d;
	B -= e;
	B -= a;
	B.podobnyi();
	A.delFirst();
	A.delFirst();
	A.delLast();
	//	B.showList2();
	EXPECT_EQ(A, B);
}

TEST(Polinom, test_differentir_X) {
	Node a(1, 2, 3, 4);
	Node b(-1, 7, 10, 22);
	Node c(1, 5, 6, 7);
	Node d(1, 214, 124, 555);
	Node e(1, -12, 50, 11);

	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(1);
	//A.showList2();

	Polinom B;
	B.str_to_poly("-12x^-13y^50z^11+214x^213y^124z^555+5x^4y^6z^7-7x^6y^10z^22+2x^1y^3z^4");

	B.podobnyi();


	//B.showList2();
	EXPECT_EQ(A, B);
}
TEST(Polinom, test_differentir_Y) {
	Node a(1, 2, 3, 4);
	Node b(-1, 7, 10, 22);
	Node c(1, 5, 6, 7);
	Node d(1, 214, 124, 555);
	Node e(1, -12, 50, 11);

	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(2);
	//A.showList2();

	Polinom B;
	B.str_to_poly("50x^-12y^49z^11+124x^214y^123z^555+6x^5y^5z^7-10x^7y^9z^22+3x^2y^2z^4");

	B.podobnyi();


	//B.showList2();
	EXPECT_EQ(A, B);
}
TEST(Polinom, test_differentir_Z) {
	Node a(1, 2, 3, 4);
	Node b(-1, 7, 10, 22);
	Node c(1, 5, 6, 7);
	Node d(1, 214, 124, 555);
	Node e(1, -12, 50, 11);

	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(3);
	//A.showList2();

	Polinom B;
	B.str_to_poly("11x^-12y^50z^10+555x^214y^124z^554+7x^5y^6z^6-22x^7y^10z^21+4x^2y^3z^3");

	B.podobnyi();


	//B.showList2();
	EXPECT_EQ(A, B);
}

TEST(Polinom, test_operator_equals_1) {
	Node a(6, 2, 3, 4);
	Node b(-5, 7, 10, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B = A;
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_equals_2) {
	Node a(6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B = A;
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_equals_3) {
	Node a(6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B = A;
	Polinom C(A);
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_operator_plus_with_equals_monom_1) {
	Node a(6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B += a;
	B += b;
	B += c;
	//B.showList2();
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_plus_with_equals_monom_2) {
	Node a(6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B += a;
	A += a;
	//B.showList2();
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_minus_with_equals_monom_1) {
	Node a(6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B -= a;
	A -= a;
	//B.showList2();
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_minus_with_equals_monom_2) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B -= a;
	B -= b;
	B -= c;
	//B.showList2();
	A *= -1;
	//A.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_plus_monom_1) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B = A + a;
	Polinom C(A);
	C += a;
	//B.showList2();
	//A.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_plus_monom_2) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B = A + a;
	B += b;
	B += c;
	Polinom C(A);
	C *= 2;
	//B.showList2();
	//A.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_minus_monom_1) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B = A - a;
	Polinom C(A);
	C -= a;
	//B.showList2();
	//A.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_minus_monom_2) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B = A - a;
	B -= b;
	B += c;
	B.podobnyi();
	Polinom C;
	C += c;
	C += c;
	B.showList2();
	C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_monom_1) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B = A * a;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("64x^7y^9z^11+35.2x^-5y^-67z^26+40.96x^4y^6z^8");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_monom_2) {
	Node a(0, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B = A * a;
	B.podobnyi();
	Polinom C;
	C.str_to_poly("0");
	B.showList2();
	C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_with_equal_monom_1) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B *= a;
	B -= a;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("64x^7y^9z^11+35.2x^-5y^-67z^26+40.96x^4y^6z^8");
	C -= a;
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_with_equal_monom_2) {
	Node a(-6.4, 2, 3, 4);
	Node b(-5.5, -7, -70, 22);
	Node c(-10, 5, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B *= a;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("64x^7y^9z^11+35.2x^-5y^-67z^26+40.96x^4y^6z^8");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_operator_sum_scalar_1) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B += 1000;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("1000x^0y^0z^0-0.5x^1233y^6z^7+5100x^-7y^-70z^22-234.555x^2y^3z^4");
	//B.showList2();
	C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_sum_scalar_2) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B = A + 1000;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("1000x^0y^0z^0 -0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_minus_scalar_1) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B = A - 1000;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("-1000x^0y^0z^0 -0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_minus_scalar_2) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B -= 1000;
	B += 500;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("-500x^0y^0z^0 -0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_scalar_1) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B *= 100;
	B *= 0.01;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("-0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_scalar_2) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B *= 100;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("-50x^1233y^6z^7+510000x^-7y^-70z^22 -23455.5x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_scalar_3) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B(A);
	B *= 0.001;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("-0.0005x^1233y^6z^7+5.1x^-7y^-70z^22 -0.234555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_multiply_scalar_4) {
	Node a(-234.555, 2, 3, 4);
	Node b(5100, -7, -70, 22);
	Node c(-0.5, 1233, 6, 7);
	Polinom A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinom B;
	B = A * 0.001;
	//B.podobnyi();
	Polinom C;
	C.str_to_poly("-0.0005x^1233y^6z^7+5.1x^-7y^-70z^22 -0.234555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_operator_polinoms_with_polinoms_1) {
	Polinom A;
	A.str_to_poly("10x^2");
	Polinom B;
	B.str_to_poly("20x^2");
	A += B;
	Polinom C;
	C.str_to_poly("30x^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_2) {
	Polinom A;
	A.str_to_poly("10x^2y^2");
	Polinom B;
	B.str_to_poly("20x^2");
	A += B;
	Polinom C;
	C.str_to_poly("20x^2+10x^2y^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_3) {
	Polinom A;
	A.str_to_poly("10x^2y^2+z^2");
	Polinom B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinom C;
	C.str_to_poly("-20x^2+10x^2y^2+z^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_4) {
	Polinom A;
	A.str_to_poly("10x^2");
	Polinom B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinom C;
	C.str_to_poly("-10x^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_5) {
	Polinom A;
	A.str_to_poly("10x^2y^2+z^2");
	Polinom B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinom C;
	C.str_to_poly("-20x^2+10x^2y^2+z^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_6) {
	Polinom A;
	A.str_to_poly("1000");
	Polinom B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinom C;
	C.str_to_poly("-20x^2+1000x^0y^0z^0");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_7) {
	Polinom A;
	A.str_to_poly("1000");
	Polinom B;
	B.str_to_poly("20x^2");
	A = B + A;
	Polinom C;
	C.str_to_poly("20x^2+1000x^0y^0z^0");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_8) {
	Polinom A;
	A.str_to_poly("1000");
	Polinom B;
	B.str_to_poly("20x^2");
	Polinom D;
	D.str_to_poly("99z^2-99y^2+99x^2");
	A = B + D;
	Polinom C;
	C.str_to_poly("99z^2-99y^2+119x^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_9)
{
	Polinom A;
	A.str_to_poly("1000");
	Polinom B;
	B.str_to_poly("20x^2");
	Polinom D;
	D.str_to_poly("99z^2-99y^2+99x^2");
	A = D - B;
	A *= -1;
	Polinom C;
	//A.showList2();
	C.str_to_poly("-99z^2+99y^2-79x^2");
	if (A == C) SUCCEED();
	else FAIL();
}
///
/// Переписать код или
/// вставить защиту от дурака
/// (прописать в правилах программы, что надо вычитать полиномы с меньшим количеством мономов)
///
TEST(Polinom, test_operator_polinoms_with_polinoms_10)
{
	Polinom A;
	A.str_to_poly("10");
	Polinom B;
	B.str_to_poly("2x^2");
	Polinom D;
	D.str_to_poly("9z^2-9y^2+9x^2");
	A = D * B;
	Polinom C;
	//A.showList2();
	C.str_to_poly("18x^4y^0z^0 -18x^2y^2z^0+18x^2y^0z^2");
	//C.showList2();
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinom, test_operator_polinoms_with_polinoms_11)
{
	Polinom A;
	A.str_to_poly("10");
	Polinom B;
	B.str_to_poly("2x^2");
	Polinom D;
	D.str_to_poly("9z^2-9y^2+9x^2");
	D = D * A;
	Polinom C;
	//D.showList2();
	C.str_to_poly("90x^2y^0z^0 -90x^0y^2z^0+90x^0y^0z^2");
	//C.showList2();
	if (C == D) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_main_test_01) {

	Polinom Q;
	Q.str_to_poly("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	Polinom P;
	P.str_to_poly("4x^3y^2z^6 - 6x^2yz^8");
	Polinom PQ;
	PQ = Q + P;
	Polinom Test;
	Test.str_to_poly("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z + 4x^3y^2z^6 - 6x^2yz^8");
	if (PQ == Test) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_main_test_02) {

	Polinom Q;
	Q.str_to_poly("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	Polinom P;
	P.str_to_poly("-3x^5y^2z^5 + 5x^4y^3z^3 - 7x^3y^5z");
	Polinom PQ;
	PQ = Q + P;
	Polinom Test;
	Test.str_to_poly("0");
	if (PQ == Test) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_main_test_03) {

	Polinom Q;
	Q.str_to_poly("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	Polinom P;
	P.str_to_poly("4x^7y^2z^6 - 6x^6yz^8");
	Polinom PQ;
	PQ = Q + P;
	Polinom Test;
	Test.str_to_poly("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z + 4x^7y^2z^6 - 6x^6yz^8");
	if (PQ == Test) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_main_test_04) {

	Polinom Q;
	Q.str_to_poly("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^3y^5z");
	Polinom P;
	P.str_to_poly("4x^5y^2z^5 + 5x^4y^3z^3");
	Polinom PQ;
	PQ = Q + P;
	Polinom Test;
	Test.str_to_poly("7x^3y^5z+7x^5y^2z^5");
	if (PQ == Test) SUCCEED();
	else FAIL();
}

TEST(Polinom, test_main_test_05) {

	Polinom Q;
	Q.str_to_poly("3x^5y^2z^5 - 5x^4y^3z^3 + 7x^7y^5z");
	Polinom P;
	P.str_to_poly("4x^6y^2z^6 - 6x^2y^3z^8");
	Polinom PQ;
	PQ = Q + P;
	//PQ.showList();
	Polinom Test;
	Test.str_to_poly("+3.000x^5y^2z^5-5.000x^4y^3z^3+7.000x^7y^5z^1+4.000x^6y^2z^6-6.000x^2y^3z^8");
	//Test.showList();
	if (PQ == Test) SUCCEED();
	else FAIL();
}