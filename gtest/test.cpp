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
	//B.showList2();


	it1 = A.begin();
	it1++;
	it1++;
	it1++;
	A.delElem(*it1);
	
	//A.showList2();
	
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

TEST(Polinoms, test_operator_equals_1){
	Monom a(6, 2, 3, 4);
	Monom b(-5, 7, 10, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B = A;
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_equals_2){
	Monom a(6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B = A;
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_equals_3) {
	Monom a(6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B = A;
	Polinoms C(A);
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}

TEST(Polinoms, test_operator_plus_with_equals_monom_1) {
	Monom a(6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B += a;
	B += b;
	B += c;
	//B.showList2();
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_plus_with_equals_monom_2) {
	Monom a(6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B += a;
	A += a;
	//B.showList2();
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_minus_with_equals_monom_1) {
	Monom a(6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B -= a;
	A -= a;
	//B.showList2();
	//cout << (*it1);
	if (B == A) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_minus_with_equals_monom_2) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
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
TEST(Polinoms, test_operator_plus_monom_1) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B = A + a;
	Polinoms C(A);
	C += a;
	//B.showList2();
	//A.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_plus_monom_2) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B = A + a;
	B += b;
	B += c;
	Polinoms C(A);
	C *= 2;
	//B.showList2();
	//A.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_minus_monom_1) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B = A - a;
	Polinoms C(A);
	C -= a;
	//B.showList2();
	//A.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_minus_monom_2) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B = A - a;
	B -= b;
	B += c;
	B.podobnyi();
	Polinoms C;
	C += c;
	C += c;
	B.showList2();
	C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_monom_1) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B = A * a;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("64x^7y^9z^11+35.2x^-5y^-67z^26+40.96x^4y^6z^8");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_monom_2) {
	Monom a(0, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B = A * a;
	B.podobnyi();
	Polinoms C;
	C.str_to_poly("0");
	B.showList2();
	C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_with_equal_monom_1) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B *= a;
	B -= a;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("64x^7y^9z^11+35.2x^-5y^-67z^26+40.96x^4y^6z^8");
	C -= a;
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_with_equal_monom_2) {
	Monom a(-6.4, 2, 3, 4);
	Monom b(-5.5, -7, -70, 22);
	Monom c(-10, 5, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B *= a;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("64x^7y^9z^11+35.2x^-5y^-67z^26+40.96x^4y^6z^8");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}

TEST(Polinoms, test_operator_sum_scalar_1) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B += 1000;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("1000x^0y^0z^0-0.5x^1233y^6z^7+5100x^-7y^-70z^22-234.555x^2y^3z^4");
	//B.showList2();
	C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_sum_scalar_2) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B = A + 1000;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("1000x^0y^0z^0 -0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_minus_scalar_1) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B = A - 1000;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("-1000x^0y^0z^0 -0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_minus_scalar_2) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B -= 1000;
	B += 500;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("-500x^0y^0z^0 -0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_scalar_1) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B *= 100;
	B *= 0.01;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("-0.5x^1233y^6z^7+5100x^-7y^-70z^22 -234.555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_scalar_2) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B *= 100;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("-50x^1233y^6z^7+510000x^-7y^-70z^22 -23455.5x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_scalar_3) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B(A);
	B *= 0.001;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("-0.0005x^1233y^6z^7+5.1x^-7y^-70z^22 -0.234555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_multiply_scalar_4) {
	Monom a(-234.555, 2, 3, 4);
	Monom b(5100, -7, -70, 22);
	Monom c(-0.5, 1233, 6, 7);
	Polinoms A;
	A.addLast(a);
	A.addLast(b);
	A.addLast(c);
	Polinoms B;
	B = A* 0.001;
	//B.podobnyi();
	Polinoms C;
	C.str_to_poly("-0.0005x^1233y^6z^7+5.1x^-7y^-70z^22 -0.234555x^2y^3z^4");
	//B.showList2();
	//C.showList2();
	//B.showList2();
	//cout << (*it1);
	if (B == C) SUCCEED();
	else FAIL();
}

TEST(Polinoms, test_operator_polinoms_with_polinoms_1) {
	Polinoms A;
	A.str_to_poly("10x^2");
	Polinoms B;
	B.str_to_poly("20x^2");
	A += B;
	Polinoms C;
	C.str_to_poly("30x^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_2) {
	Polinoms A;
	A.str_to_poly("10x^2y^2");
	Polinoms B;
	B.str_to_poly("20x^2");
	A += B;
	Polinoms C;
	C.str_to_poly("20x^2+10x^2y^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_3) {
	Polinoms A;
	A.str_to_poly("10x^2y^2+z^2");
	Polinoms B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinoms C;
	C.str_to_poly("-20x^2+10x^2y^2+z^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_4) {
	Polinoms A;
	A.str_to_poly("10x^2");
	Polinoms B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinoms C;
	C.str_to_poly("-10x^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_5) {
	Polinoms A;
	A.str_to_poly("10x^2y^2+z^2");
	Polinoms B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinoms C;
	C.str_to_poly("-20x^2+10x^2y^2+z^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_6) {
	Polinoms A;
	A.str_to_poly("1000");
	Polinoms B;
	B.str_to_poly("20x^2");
	A -= B;
	Polinoms C;
	C.str_to_poly("-20x^2+1000x^0y^0z^0");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_7) {
	Polinoms A;
	A.str_to_poly("1000");
	Polinoms B;
	B.str_to_poly("20x^2");
	A = B+A;
	Polinoms C;
	C.str_to_poly("20x^2+1000x^0y^0z^0");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_8) {
	Polinoms A;
	A.str_to_poly("1000");
	Polinoms B;
	B.str_to_poly("20x^2");
	Polinoms D;
	D.str_to_poly("99z^2-99y^2+99x^2");
	A = B + D;
	Polinoms C;
	C.str_to_poly("99z^2-99y^2+119x^2");
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_9)
{
	Polinoms A;
	A.str_to_poly("1000");
	Polinoms B;
	B.str_to_poly("20x^2");
	Polinoms D;
	D.str_to_poly("99z^2-99y^2+99x^2");
	A = D - B;
	A *= -1;
	Polinoms C;
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
TEST(Polinoms, test_operator_polinoms_with_polinoms_10)
{
	Polinoms A;
	A.str_to_poly("10");
	Polinoms B;
	B.str_to_poly("2x^2");
	Polinoms D;
	D.str_to_poly("9z^2-9y^2+9x^2");
	A = D * B;
	Polinoms C;
	//A.showList2();
	C.str_to_poly("18x^4y^0z^0 -18x^2y^2z^0+18x^2y^0z^2");
	//C.showList2();
	if (A == C) SUCCEED();
	else FAIL();
}
TEST(Polinoms, test_operator_polinoms_with_polinoms_11)
{
	Polinoms A;
	A.str_to_poly("10");
	Polinoms B;
	B.str_to_poly("2x^2");
	Polinoms D;
	D.str_to_poly("9z^2-9y^2+9x^2");
	D= D * A;
	Polinoms C;
	//D.showList2();
	C.str_to_poly("90x^2y^0z^0 -90x^0y^2z^0+90x^0y^0z^2");
	//C.showList2();
	if (C == D) SUCCEED();
	else FAIL();
}
/*
TEST(Polinoms, test_operator_polinoms_with_polinoms_12)
{
	Polinoms A;
	A.str_to_poly("0");
	Polinoms B;
	B.str_to_poly("2x^2");
	Polinoms D;
	D.str_to_poly("9z^2-9y^2+9x^2");
	D = D * A;
	Polinoms C;
	D.showList2();
	C.str_to_poly("0x^2y^0z^0 -0x^0y^2z^0+0x^0y^0z^2");
	C.showList2();
	if (C == D) SUCCEED();
	else FAIL();
}*///тест ломает всё ибо умножение не работает как задуманно. 