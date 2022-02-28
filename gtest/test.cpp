#include "pch.h"


TEST(Monom, test_create_Monom) 
{
	Monom a;

	EXPECT_EQ(a.coef, 0);
}
TEST(Monom, test_create_Monom_with_parameters_1) 
{
	Monom a(1, 2, 3, 3);
	EXPECT_EQ(a.coef, 1);
}
TEST(Monom, test_create_Monom_with_parameters_2) 
{
	Monom a(1, 2, 3, 4);
	EXPECT_EQ(a.degx, 2);
}
TEST(Monom, test_create_Monom_with_parameters_3) 
{
	Monom a(1, 2, 3, 4);
	EXPECT_EQ(a.degy, 3);
}
TEST(Monom, test_create_Monom_with_parameters_4) 
{
	Monom a(1, 2, 3, 4);
	EXPECT_EQ(a.degz, 4);
}

TEST(Monom, test_create_Monom_with_copy) 
{
	Monom a(1, 2, 3, 4);
	Monom b(a);
	if ((a.coef == b.coef) && (a.degx == b.degx) && (a.degy == b.degy) && (a.degz == b.degz)) SUCCEED();
	else FAIL();
}
TEST(Monom, test_Monom_equal_monom) 
{
	Monom a(1, 2, 3, 4);
	Monom b;
	b = a;
	if ((a.coef == b.coef) && (a.degx == b.degx) && (a.degy == b.degy) && (a.degz == b.degz)) SUCCEED();
	else FAIL();
}
TEST(Monom, test_Monom_equal_scalar) 
{
	Monom a(1, 2, 3, 4);
	double const b = 10.5;
	a = b;
	if ((a.coef == b) && (a.degx == 0) && (a.degy == 0) && (a.degz == 0)) SUCCEED();
	else FAIL();
}
TEST(Monom, test_Monom_compare_1) 
{
	Monom a(1, 2, 3, 4);
	Monom b(a);

	if (a == b) SUCCEED();
	else FAIL();
}
TEST(Monom, test_Monom_compare_2) 
{
	Monom a(1, 2, 3, 4);
	Monom b(-1, 2, 3, 4);

	if (a != b) SUCCEED();
	else FAIL();
}

TEST(Polinoms, test_Polinom_create) {
	//Monom a(6, 2, 3, 4);
//	Monom b(-5, 7, 10, 22);
	//Monom c(10, 5, 6, 7);
	Polinoms A;
	ASSERT_NO_THROW();
}

TEST(Polinoms, test_Polinom_addFIRST) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	auto it1 = A.begin();
	it1++;
	//cout << (*it1);
	if (((*it1).coef == c.coef) && ((*it1).degx == c.degx) && ((*it1).degy == c.degy) && ((*it1).degz == c.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->[b]->[a]->nullptr
}
TEST(Polinoms, test_Polinom_addLAST) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	auto it1 = A.begin();
	it1++;
	//cout << (*it1);
	if (((*it1).coef == a.coef) && ((*it1).degx == a.degx) && ((*it1).degy == a.degy) && ((*it1).degz == a.degz)) SUCCEED();
	else FAIL();
	//[head]->[a]->[b]->[c]->nullptr
}
TEST(Polinoms, test_Polinom_addNOW_1) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Monom d(13, 44, 55, 66);
	Polinoms A;
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

	if (((*it1).coef == d.coef) && ((*it1).degx == d.degx) && ((*it1).degy == d.degy) && ((*it1).degz == d.degz)) SUCCEED();
	else FAIL();
	
}
TEST(Polinoms, test_Polinom_addNOW_2) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Monom d(13, 44, 55, 66);
	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	auto it1 = A.begin();
	it1++;
	A.addNow(d, (*it1));
	it1++;
	//	A.showList2();
	//	cout << (*it1);

	if (((*it1).coef == d.coef) && ((*it1).degx == d.degx) && ((*it1).degy == d.degy) && ((*it1).degz == d.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr
}

TEST(Polinoms, test_Polinom_create_by_constructor) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	auto it1 = A.begin();
	it1++;
	Polinoms B(A);
	//cout << (*it1);
	if (B==A) SUCCEED();
	else FAIL();
	//[head]->[a]->[b]->[c]->nullptr
}

TEST(Polinoms, test_del_First_with_all_addLast) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	
	//cout << (*it1);
	A.delFirst();
	auto it1 = A.begin();
	it1++;
	if (((*it1).coef == b.coef) && ((*it1).degx == b.degx) && ((*it1).degy == b.degy) && ((*it1).degz == b.degz)) SUCCEED();
	else FAIL();
	//[head]->X[a]X->[b]->[c]->nullptr
}
TEST(Polinoms, test_del_First_with_all_addFirst) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.delFirst();
	auto it1 = A.begin();
	it1++;
	//cout << (*it1);
	if (((*it1).coef == b.coef) && ((*it1).degx == b.degx) && ((*it1).degy == b.degy) && ((*it1).degz == b.degz)) SUCCEED();
	else FAIL();
	//[head]->X[c]X->[b]->[a]->nullptr
	
}
TEST(Polinoms, test_del_First_with_all_addNow) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Monom d(13, 44, 55, 66);
	Polinoms A;
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
		if (((*it1).coef == d.coef) && ((*it1).degx == d.degx) && ((*it1).degy == d.degy) && ((*it1).degz == d.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr

}
TEST(Polinoms, test_del_First_with_all) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Monom d(13, 44, 55, 66);
	Polinoms A;
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
	if (((*it1).coef == d.coef) && ((*it1).degx == d.degx) && ((*it1).degy == d.degy) && ((*it1).degz == d.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr

}

TEST(Polinoms, test_del_Last_with_all_addLast) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);

	//cout << (*it1);
	A.delLast();
	auto it1 = A.begin();
	while ((*it1).next != nullptr) {
		it1++;
	}
	if (((*it1).coef == b.coef) && ((*it1).degx == b.degx) && ((*it1).degy == b.degy) && ((*it1).degz == b.degz)) SUCCEED();
	else FAIL();
	//[head]->[a]->[b]->X[c]X->nullptr
}
TEST(Polinoms, test_del_Last_with_all_addFirst) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.delLast();
	auto it1 = A.begin();
	while ((*it1).next != nullptr) {
		it1++;
	}
	//cout << (*it1);
	if (((*it1).coef == b.coef) && ((*it1).degx == b.degx) && ((*it1).degy == b.degy) && ((*it1).degz == b.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->[b]->X[a]X->nullptr

}
TEST(Polinoms, test_del_Last_with_all_addNow) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Monom d(13, 44, 55, 66);
	Polinoms A;
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
	if (((*it1).coef == b.coef) && ((*it1).degx == b.degx) && ((*it1).degy == b.degy) && ((*it1).degz == b.degz)) SUCCEED();
	else FAIL();
	//[head]->[c]->NOW->[b]->[a]->nullptr

}
TEST(Polinoms, test_del_Last_with_all) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Monom d(13, 44, 55, 66);
	Polinoms A;
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
	if (((*it1).coef == b.coef) && ((*it1).degx == b.degx) && ((*it1).degy == b.degy) && ((*it1).degz == b.degz)) SUCCEED();
	else FAIL();
	

}

TEST(Polinoms, test_del_Elem_with_all_addLast) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10.4, 5, 6, 7);
	Monom d(20.52, 214, 124, 555);
	Monom e(55.5, -12, 50, 11);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	Polinoms B;
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
TEST(Polinoms, test_del_Elem_with_all_addFirst) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10.4, 5, 6, 7);
	Monom d(20.52, 214, 124, 555);
	Monom e(55.5, -12, 50, 11);
	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.addFirst(d);
	A.addFirst(e);
	Polinoms B;
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
TEST(Polinoms, test_del_Elem_with_all) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10.4, 5, 6, 7);
	Monom d(20.52, 214, 124, 555);
	Monom e(55.5, -12, 50, 11);
	Polinoms A;
	auto it1 = A.begin();
	A.addLast(a);
	A.addFirst(b);
	it1++;
	A.addNow(c, *it1);
	it1++;
	A.addNow(d, *it1);
	it1++;
	A.addNow(e, *it1);
	Polinoms B;
	B = A;
	B -= d;
	B.podobnyi();
	B.showList2();


	it1 = A.begin();
	it1++;
	it1++;
	it1++;
	A.delElem(*it1);
	
	A.showList2();
	
	EXPECT_EQ(A, B);

}

TEST(Polinoms, test_str_to_polynom_1){

	Polinoms R;
	R.str_to_poly("1");
	auto it1 = R.begin();
	it1++;
	if (((*it1).coef == 1) && ((*it1).degx == 0) && ((*it1).degy == 0) && ((*it1).degz == 0)) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_2) {

	Polinoms R;
	R.str_to_poly("1xyz");
	auto it1 = R.begin();
	it1++;
	if (((*it1).coef == 1) && ((*it1).degx == 1) && ((*it1).degy == 1) && ((*it1).degz == 1)) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_3) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46");
	auto it1 = R.begin();
	it1++;
	if (((*it1).coef == 444) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46)) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_4_with_errors_1) {

	Polinoms R;
	//R.str_to_poly("444x^2y^3zS46");
	EXPECT_ANY_THROW(R.str_to_poly("444x^2y^3zS46"));
}
TEST(Polinoms, test_str_to_polynom_4_with_errors_2) {

	Polinoms R;
	//R.str_to_poly("444x^2y^3zS46");
	EXPECT_ANY_THROW(R.str_to_poly("QW444x^2y^3z^46"));
}
TEST(Polinoms, test_str_to_polynom_4_with_errors_3) {

	Polinoms R;
	//R.str_to_poly("444x^2y^3zS46");
	EXPECT_ANY_THROW(R.str_to_poly("444x^2y^3z46"));
}
TEST(Polinoms, test_str_to_polynom_5) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46+1xyz");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).coef == 1) && ((*it1).degx == 1) && ((*it1).degy == 1) && ((*it1).degz == 1))
	{
		it1++;
		if (((*it1).coef == 444) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_6) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46+1x^3y^7z^7");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).coef == 1) && ((*it1).degx == 3) && ((*it1).degy == 7) && ((*it1).degz == 7))
	{
		it1++;
		if (((*it1).coef == 444) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_7) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46-xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).coef == -1) && ((*it1).degx == 1) && ((*it1).degy == 7) && ((*it1).degz == 700))
	{
		it1++;
		if (((*it1).coef == 444) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_8) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46-xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	if (((*it1).coef == -1) && ((*it1).degx == 1) && ((*it1).degy == 7) && ((*it1).degz == 700))
	{
		it1++;
		if (((*it1).coef == 444) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_9) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46-444x^2y^3z^46");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	
		if (((*it1).coef == 0) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
		{
			SUCCEED();
		}
	
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_10_with_podobny) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46+444x^2y^3z^46");
	//R.showList2();
	auto it1 = R.begin();
	it1++;

	if (((*it1).coef == 888) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
	{
		SUCCEED();
	}

	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_11_with_podobny) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46+444x^2y^3z^46-xy^7z^700-20xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;

	if (((*it1).coef == -21) && ((*it1).degx == 1) && ((*it1).degy == 7) && ((*it1).degz == 700))
	{
		it1++;
		if (((*it1).coef == 888) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
		{
			SUCCEED();
		}
	}
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_12_with_podobny) {

	Polinoms R;
	R.str_to_poly("444x^2y^3z^46+444x^2y^3z^46-xy^7z^700+xy^7z^700");
	//R.showList2();
	auto it1 = R.begin();
	it1++;
	it1++;
	//R.showList2();
	R.podobnyi();
	//R.showList2();
	
		if (((*it1).coef == 888) && ((*it1).degx == 2) && ((*it1).degy == 3) && ((*it1).degz == 46))
		{
			SUCCEED();
		}
	
	else FAIL();
}
TEST(Polinoms, test_str_to_polynom_13) {
	Monom a(1, 2, 3, 4);
	Monom b(-1, 7, 10, 22);
	Monom c(1, 5, 6, 7);
	Monom d(1, 214, 124, 555);
	Monom e(1, -12, 50, 11);

	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(1);
	//A.showList2();

	Polinoms B;
	B.str_to_poly("-12x^-13y^50z^11+214x^213y^124z^555+5x^4y^6z^7-7x^6y^10z^22+2x^1y^3z^4");

	B.podobnyi();


	//B.showList2();
	EXPECT_EQ(A, B);
}

TEST(Polinoms, test_podobnie) {
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10.4, 5, 6, 7);
	Monom d(20.52, 214, 124, 555);
	Monom e(55.5, -12, 50, 11);

	Polinoms A;
	A.addFirst(a);
	A.addFirst(b);
	A.addFirst(c);
	A.addFirst(d);
	A.addFirst(e);
	//A.showList2();

	Polinoms B;
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

TEST(Polinoms, test_differentir_X) {
	Monom a(1, 2, 3, 4);
	Monom b(-1, 7, 10, 22);
	Monom c(1, 5, 6, 7);
	Monom d(1, 214, 124, 555);
	Monom e(1, -12, 50, 11);

	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(1);
	//A.showList2();

	Polinoms B;
	B.str_to_poly("-12x^-13y^50z^11+214x^213y^124z^555+5x^4y^6z^7-7x^6y^10z^22+2x^1y^3z^4");

	B.podobnyi();
	

	//B.showList2();
	EXPECT_EQ(A, B);
}
TEST(Polinoms, test_differentir_Y) {
	Monom a(1, 2, 3, 4);
	Monom b(-1, 7, 10, 22);
	Monom c(1, 5, 6, 7);
	Monom d(1, 214, 124, 555);
	Monom e(1, -12, 50, 11);

	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(2);
	//A.showList2();

	Polinoms B;
	B.str_to_poly("50x^-12y^49z^11+124x^214y^123z^555+6x^5y^5z^7-10x^7y^9z^22+3x^2y^2z^4");

	B.podobnyi();


	//B.showList2();
	EXPECT_EQ(A, B);
}
TEST(Polinoms, test_differentir_Z) {
	Monom a(1, 2, 3, 4);
	Monom b(-1, 7, 10, 22);
	Monom c(1, 5, 6, 7);
	Monom d(1, 214, 124, 555);
	Monom e(1, -12, 50, 11);

	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	A.addLast(d);
	A.addLast(e);
	//A.showList2();
	A.differents(3);
	//A.showList2();

	Polinoms B;
	B.str_to_poly("11x^-12y^50z^10+555x^214y^124z^554+7x^5y^6z^6-22x^7y^10z^21+4x^2y^3z^3");

	B.podobnyi();


	//B.showList2();
	EXPECT_EQ(A, B);
}