#include "tpolynom.h"

#include <gtest.h>



//конструкторы: по умолчанию из списка
TEST(TPolynom, can_create_empty_polynom)
{
	ASSERT_NO_THROW(TPolynom pl());
}


//конструкторы: из строки

TEST(TPolynom, can_create_polynom_from_string_1)
{
	string a = "1";
	ASSERT_NO_THROW(TPolynom pl(a));
}

TEST(TPolynom, check_correct_create_polynom_from_string_1)
{
	string a = "1";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.get_degree(), 0);
	EXPECT_EQ(pl.GetCurrent()->data.get_koef(), 1);
}


TEST(TPolynom, can_create_polynom_from_string_2)
{
	string a = "1+x^2-y^3+x*y*z-x^2*y*z^2";
	ASSERT_NO_THROW(TPolynom pl(a));
}

TEST(TPolynom, check_correct_create_polynom_from_string_2)
{
	string a = "1+ x^2 -y^3 + x*y*z - x^2*y*z^2";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.get_degree(), 0);
	EXPECT_EQ(pl.GetCurrent()->data.get_koef(), 1);

	EXPECT_EQ(pl.GetCurrent()->pNext->data.get_degree(), 30);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.get_koef(), -1);
}


TEST(TPolynom, can_create_polynom_from_string_3)
{
	string a = "1+x^2*y*z^9-y^3+x*y*z-x^2*y*z^2";
	ASSERT_NO_THROW(TPolynom pl(a));
}

TEST(TPolynom, check_correct_create_polynom_from_string_3)
{
	string a = "1+x^2*y*z^9-y^3+x*y*z-x^2*y*z^2";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.get_degree(), 0);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.get_degree(), 30);
}


TEST(TPolynom, check_correct_create_polynom_from_string_4)
{
	string a = "1+x^2 + x^2";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.get_degree(), 0);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.get_degree(), 200);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.get_koef(), 2);
}


TEST(TPolynom, check_correct_create_polynom_from_string_5)
{
	string a = "1+x^2 - x^2";
	TPolynom pl(a);
	EXPECT_EQ(pl.GetCurrent()->data.get_degree(), 0);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.get_degree(), 0);
	EXPECT_EQ(pl.GetCurrent()->pNext->data.get_koef(), 0);
	EXPECT_EQ(pl.GetString(), "1.00");
}


//конструкторы: из списка


TEST(TPolynom, can_create_polynom_from_ringlist_1)
{
	TNode<TMonom>* c = new TNode<TMonom>(TMonom(111, 2.0), nullptr);
	TNode<TMonom>* b = new TNode<TMonom>(TMonom(11, 2.0), c);
	TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0), b);

	TRingList<TMonom>* rl = new TRingList<TMonom>(a);

	ASSERT_NO_THROW(TPolynom pl(rl));
}


TEST(TPolynom,check_correct_create_polynom_from_ringlist_1)
{
	TNode<TMonom>* c = new TNode<TMonom>(TMonom(111, 2.0), nullptr);
	TNode<TMonom>* b = new TNode<TMonom>(TMonom(11, 2.0), c);
	TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0), b);

	TRingList<TMonom>* rl = new TRingList<TMonom>(a);

	TPolynom pl(rl);

	EXPECT_EQ(pl.GetString(), "2.00*z+2.00*y*z+2.00*x*y*z");
}


TEST(TPolynom, can_create_polynom_from_ringlist_2)
{
	TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0));

	TRingList<TMonom>* rl = new TRingList<TMonom>(a);

	ASSERT_NO_THROW(TPolynom pl(rl));
}


TEST(TPolynom, check_correct_create_polynom_from_ringlist_2)
{
	TNode<TMonom>* a = new TNode<TMonom>(TMonom(1, 2.0));

	TRingList<TMonom>* rl = new TRingList<TMonom>(a);

	TPolynom pl(rl);

	EXPECT_EQ(pl.GetString(), "2.00*z");
}


//сложение

TEST(TPolynom, correct_add_operator_1)
{
	TPolynom pl1("1+x+y+z"), pl2("3+x+3*y +x*y");

	TPolynom res = pl1 + pl2;

	EXPECT_EQ(res.GetString(), "4.00+1.00*z+4.00*y+2.00*x+1.00*x*y");
}



//унарный минус 

TEST(TPolynom, correct_unar_minus_operator_1)
{
	TPolynom pl1("1+x+y+z");

	TPolynom res = -pl1;

	EXPECT_EQ(res.GetString(), "-1.00-1.00*z-1.00*y-1.00*x");
}


TEST(TPolynom, correct_unar_minus_operator_2)
{
	TPolynom pl1("1-x+y-z");

	TPolynom res = -pl1;

	EXPECT_EQ(res.GetString(), "-1.00+1.00*z-1.00*y+1.00*x");
}

TEST(TPolynom, correct_unar_minus_operator_3)
{
	TPolynom pl1("-1-x+y-z");

	TPolynom res = -pl1;

	EXPECT_EQ(res.GetString(), "1.00+1.00*z-1.00*y+1.00*x");
}



//обычный минус, правильный если унарный работает

TEST(TPolynom, correct_minus_operator_1)
{
	TPolynom pl1("1+x+y+z"), pl2("3+x+3*y +x*y");

	TPolynom res = pl1 - pl2;

	EXPECT_EQ(res.GetString(), "-2.00+1.00*z-2.00*y-1.00*x*y");
}

//умножение


TEST(TPolynom, correct_multiplication_operator_1)
{
	TPolynom pl1("1+x"), pl2("1");

	TPolynom res = pl1 * pl2;

	EXPECT_EQ(res.GetString(),
		"1.00+1.00*x");


}


TEST(TPolynom, correct_multiplication_operator_2)
{
	TPolynom pl1("1+x+y"), pl2("400+z^9");

	TPolynom res = pl1 * pl2;

	EXPECT_EQ(res.GetString(),
		"400.00+1.00*z^9+400.00*y+1.00*y*z^9+400.00*x+1.00*x*z^9");


}



TEST(TPolynom, correct_multiplication_operator_3)
{
	TPolynom pl1("1+x+y+z"), pl2("3+x+3*y +x*y");

	TPolynom res = pl1 * pl2;

	EXPECT_EQ(res.GetString(), 
	"3.00+3.00*z+6.00*y+3.00*y*z+3.00*y^2+4.00*x+1.00*x*z+5.00*x*y+1.00*x*y*z+1.00*x*y^2+1.00*x^2+1.00*x^2*y");
}


TEST(TPolynom, correct_multiplication_operator_4)
{
	TPolynom pl1("x^9"), pl2("1+100+10+x^3");

	ASSERT_ANY_THROW(TPolynom res = pl1 * pl2);
}


//дифференцирвоание

TEST(TPolynom, correct_dif_x_1)
{
	TPolynom pl("x^9");

	TPolynom res = pl.dif_x();
	EXPECT_EQ(res.GetString(),
		"9.00*x^8");
}

TEST(TPolynom, correct_dif_x_2)
{
	TPolynom pl("x^9+y+z+x^2");

	TPolynom res = pl.dif_x();
	EXPECT_EQ(res.GetString(),
		"2.00*x+9.00*x^8");
}


TEST(TPolynom, correct_dif_y_1)
{
	TPolynom pl("x^9+y+z+x^2+y^9");

	TPolynom res = pl.dif_y();
	EXPECT_EQ(res.GetString(),
		"1.00+9.00*y^8");
}


TEST(TPolynom, correct_dif_y_2)
{
	TPolynom pl("4*y^5+100*y^7+0*y^3");

	TPolynom res = pl.dif_y();
	EXPECT_EQ(res.GetString(),
		"20.00*y^4+700.00*y^6");
}



//Calculate


TEST(TPolynom, correct_calculate_1)
{
	TPolynom pl("x+y+z");

	EXPECT_EQ(pl(1, 2, 3), 6);
}


TEST(TPolynom, correct_calculate_2)
{
	TPolynom pl("x+y^2+z");

	EXPECT_EQ(pl(1, 2, 3), 8);
}



TEST(TPolynom, correct_calculate_3)
{
	TPolynom pl("x+10*y^2+z");

	EXPECT_EQ(pl(1, 2, 3), 44);
}


TEST(TPolynom, correct_calculate_4)
{
	TPolynom pl("x+10*y^2+z-y-z-x^9");

	EXPECT_EQ(pl(1, 2, 3), 38);
}


TEST(TPolynom, correct_calculate_5)
{
	TPolynom pl("x+10*y^2+z-y-z-x^9+z^3");

	EXPECT_EQ(pl(1, 2, 3), 65);
}
