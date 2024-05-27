#include"tpolynom.h"
#include"tringlist.h"

#include <gtest.h>

//-------------------CONSTRUCTOR
TEST(TPolinom, test_constructor)
{
	ASSERT_NO_THROW(TPolinom polynom);
}

TEST(TPolinom, test_constructor_with_param1)
{
	string name = "2.5x^2y^3-6.3y^7z^5";
	ASSERT_NO_THROW(TPolinom polynom(name));
}

TEST(TPolinom, test_getting_the_value_1)
{
	string name = "2.5x^2y^3-6.3y^7z^5";
	TPolinom polynom(name);
	double res = polynom(2, 3, 4);
	double value = -14108504.4;
	EXPECT_EQ(res, value);
}

TEST(TPolinom, test_constructor_with_param3)
{
	string name = "2a^2b^3-6b^7c^5";
	ASSERT_ANY_THROW(TPolinom polynom(name));
}

TEST(TPolinom, test_constructor_with_param6)
{
	string name = "2.5x^y^3-6.3y^7z^5";
	ASSERT_ANY_THROW(TPolinom polynom(name));
}

TEST(TPolinom, test_constructor_with_param4)
{
	string name = "2x^3y+5y^6z^4";
	string name1 = "+ 2.000000x^3y+ 5.000000y^6z^4";
	TPolinom polynom(name);
	EXPECT_EQ(name1, polynom.get_name());
}

TEST(TPolinom, test_getting_the_value_2)
{
	string name = "2x^3y+5y^6z^4";
	TPolinom polynom(name);
	double res = polynom(1.5, 2, 1);
	double value = 333.5;
	EXPECT_EQ(res, value);
}

TEST(TPolinom, test_constructor_with_param5)
{
	string name = "3.5xy^2z^4+7xyz";
	string name1 = "+ 3.500000xy^2z^4+ 7.000000xyz";
	TPolinom polynom(name);
	EXPECT_EQ(name1, polynom.get_name());
}

TEST(TPolinom, test_getting_the_value_3)
{
	string name = "3.5xy^2z^4+7xyz";
	TPolinom polynom(name);
	double res = polynom(1.5, 2.1, 1);
	double value = 45.2025;
	EXPECT_EQ(res, value);
}

TEST(TPolinom, test_constructor_with_param_normal_view)
{
	string name = "2yzx+4x^2+6zxy";
	string name1 = "+ 4.000000x^2+ 8.000000xyz";
	TPolinom polynom(name);
	EXPECT_EQ(name1, polynom.get_name());
}

TEST(TPolinom, test_getting_the_value_4)
{
	string name = "2yzx+4x^2+6zxy";
	TPolinom polynom(name);
	double res = polynom(1.5, 3.1, 2.1);
	double value = 87.12;
	EXPECT_EQ(res, value);
}

TEST(TPolinom, test_constructor_with_param_normal_view_1)
{
	string name = "2.5xy^5+51.1x^2y^4z^9-2.5yx";
	string name1 = "+ 51.100000x^2y^4z^9+ 2.500000xy^5  -2.500000xy";
	TPolinom polynom(name);
	EXPECT_EQ(name1, polynom.get_name());
}

TEST(TPolinom, test_constructor_with_param_normal_view_2)
{
	string name = "2.5xyz+555xz-2.5zyx-4x";
	string name1 = "+ 555.000000xz  -4.000000x";
	TPolinom polynom(name);
	EXPECT_EQ(name1, polynom.get_name());
}

TEST(TPolinom, test_constructor_with_param_normal_view_3)
{
	string name = "2.5xyz+555xz-1.5zyx-4x-yxz";
	string name1 = "+ 555.000000xz  -4.000000x";
	TPolinom polynom(name);
	EXPECT_EQ(name1, polynom.get_name());
}

TEST(TPolinom, test_constructor_with_param_RList_Constructor_1)
{
	TMonom list1(1.5, 322);
	TMonom list2(22, 322);
	TMonom list3(-1.5, 22);
	TMonom list4(1.2, 302);
	TRingList<TMonom> res;
	res.InsertLast(list1);
	res.InsertLast(list2);
	res.InsertLast(list3);
	res.InsertLast(list4);
	ASSERT_NO_THROW(TPolinom a(res));
}

TEST(TPolinom, test_constructor_with_param_RList_Constructor_2)
{
	TMonom list1(1.5, 322);
	TMonom list2(22, 322);
	TMonom list3(-1.5, 22);
	TMonom list4(1.2, 302);
	TRingList<TMonom> res;
	res.InsertLast(list1);
	res.InsertLast(list2);
	res.InsertLast(list3);
	res.InsertLast(list4);
	TPolinom a(res);
	EXPECT_EQ("+ 23.500000x^3y^2z^2+ 1.200000x^3z^2  -1.500000y^2z^2", a.get_name());
}

TEST(TPolinom, test_constructor_with_param_RList_Constructor_3)
{
	TMonom list1(0, 0);
	TRingList<TMonom> res;
	res.InsertLast(list1);
	TPolinom a(res);
	EXPECT_EQ(" 0.000000", a.get_name());
}

TEST(TPolinom, test_constructor_with_param_copy_constructor_1)
{
	TMonom list1(1.5, 322);
	TMonom list2(22, 322);
	TMonom list3(-1.5, 22);
	TMonom list4(1.2, 302);
	TRingList<TMonom> res;
	res.InsertLast(list1);
	res.InsertLast(list2);
	res.InsertLast(list3);
	res.InsertLast(list4);
	TPolinom a(res);
	ASSERT_NO_THROW(TPolinom b(a));
}

TEST(TPolinom, test_constructor_with_param_copy_constructor_2)
{
	TMonom list1(1.5, 322);
	TMonom list2(22, 322);
	TMonom list3(-1.5, 22);
	TMonom list4(1.2, 302);
	TRingList<TMonom> res;
	res.InsertLast(list1);
	res.InsertLast(list2);
	res.InsertLast(list3);
	res.InsertLast(list4);
	TPolinom a(res);
	TPolinom b(a);
	ASSERT_NO_THROW("+ 23.500000x^3y^2z^2+ 1.200000x^3z^2  -1.500000y^2z^2", b.get_name());
}

TEST(TPolinom, test_constructor_with_param_copy_constructor_3)
{
	TMonom list1(1.5, 322);
	TMonom list2(22, 322);
	TMonom list3(-1.5, 22);
	TMonom list4(1.2, 302);
	TRingList<TMonom> res;
	res.InsertLast(list1);
	res.InsertLast(list2);
	res.InsertLast(list3);
	res.InsertLast(list4);
	TPolinom a(res);
	TPolinom b(a);
	ASSERT_NO_THROW("+ 23.500000x^3y^2z^2+ 1.200000x^3z^2  -1.500000y^2z^2", b.get_name());
}
//------------SUM

TEST(TPolinom, test_checking_the_sum_1)
{
	string str1 = "x-1";
	string str2 = "1-x";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	ASSERT_NO_THROW(poly1 + poly2);
}

TEST(TPolinom, test_getting_the_value_5)
{
	string name = "x-1";
	TPolinom polynom(name);
	double res = polynom(1, 3.1, 0.5);
	double value = 0;
	EXPECT_EQ(res, value);
}

TEST(TPolinom, test_checking_the_sum_2)
{
	string str1 = "x-1";
	string str2 = "1-x";
	string str3 = " 0.000000";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 + poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_sum_3)
{
	string str1 = "x+1";
	string str2 = "1-x";
	string str3 = "+ 2.000000";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 + poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_sum_4)
{
	string str1 = "x+1";
	string str2 = "1-x";
	string str3 = "+ 2.000000";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 + poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_sum_5)
{
	string str1 = "2x^2y+3xyz-z^2";
	string str2 = "4xy^2-2xyz+5z^2";
	string str3 = "+ 2.000000x^2y+ 4.000000xy^2+ 1.000000xyz+ 4.000000z^2";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 + poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_sum_6)
{
	string str1 = "x^9+2x^7y^2-3z^5+4xy^3";
	string str2 = "5x^6y-6xyz^4+7z^9-8x^3y^2";
	string str3 = "+ 1.000000x^9+ 2.000000x^7y^2+ 5.000000x^6y  -8.000000x^3y^2+ 4.000000xy^3  -6.000000xyz^4+ 7.000000z^9  -3.000000z^5";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 + poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

//----------------DIFFERENCE

TEST(TPolinom, test_checking_the_difference_)
{
	string str1 = "x^9+2x^7y^2-3z^5+4xy^3";
	string str2 = "5x^6y-6xyz^4+7z^9-8x^3y^2";
	string str3 = "+ 1.000000x^9+ 2.000000x^7y^2  -5.000000x^6y+ 8.000000x^3y^2+ 4.000000xy^3+ 6.000000xyz^4  -7.000000z^9  -3.000000z^5";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 - poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_difference_with_similar_terms)
{
	string str1 = "x^2+2xy+y^2";
	string str2 = "x^2-xy+y^2";
	string str3 = "+ 3.000000xy";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 - poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_difference_with_negative_coefficients)
{
	string str1 = "-x^2+2xy-y^2";
	string str2 = "x^2-xy+y^2";
	string str3 = "  -2.000000x^2+ 3.000000xy  -2.000000y^2";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 - poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_difference_with_float_coefficients)
{
	string str1 = "0.5x^2+1.5xy-2.0y^2";
	string str2 = "x^2-0.75xy+0.5y^2";
	string str3 = "  -0.500000x^2+ 2.250000xy  -2.500000y^2";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 - poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

//-----------------------PRODUCT

TEST(TPolinom, test_checking_the_product_with_number_with_float_coefficients)
{
	string str1 = "0.5x^2+1.5xy-2.0y^2";
	string str2 = "2.0";
	string str3 = "+ 1.000000x^2+ 3.000000xy  -4.000000y^2";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 * poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

TEST(TPolinom, test_checking_the_product_with_number_with_zero_)
{
	string str1 = "0.5x^2+1.5xy-2.0y^2";
	string str2 = "0";
	string str3 = " 0.000000";
	TPolinom poly1(str1);
	TPolinom poly2(str2);
	TPolinom poly3 = poly1 * poly2;
	EXPECT_EQ(str3, poly3.To_string());
}

//----------------dif
TEST(TPolinom, test_checking_the_dif_x_1)
{
	string str1 = "x^9+2x^7y^2-3z^5+4xy^3";
	string str3 = "+ 9.000000x^8+ 14.000000x^6y^2+ 4.000000y^3";
	TPolinom poly1(str1);
	TPolinom poly2 = poly1.dif_x();
	EXPECT_EQ(str3, poly2.To_string());
}

TEST(TPolinom, test_checking_the_dif_y_1)
{
	string str1 = "x^9+2x^7y^2-3z^5+4xy^3";
	string str3 = "+ 4.000000x^7y+ 12.000000xy^2";
	TPolinom poly1(str1);
	TPolinom poly2 = poly1.dif_y();
	EXPECT_EQ(str3, poly2.To_string());
}

TEST(TPolinom, test_checking_the_dif_z_1)
{
	string str1 = "x^9+2x^7y^2-3z^5+4xy^3";
	string str3 = "  -15.000000z^4";
	TPolinom poly1(str1);
	TPolinom poly2 = poly1.dif_z();
	EXPECT_EQ(str3, poly2.To_string());
}

TEST(TPolinom, test_checking_the_dif_x_2)
{
	string str1 = "x^2+2xy+y^2";
	string str3 = "+ 2.000000x+ 2.000000y";
	TPolinom poly1(str1);
	TPolinom poly2 = poly1.dif_x();
	EXPECT_EQ(str3, poly2.To_string());
}

TEST(TPolinom, test_checking_the_dif_y_2)
{
	string str1 = "x^2+2xy+y^2";
	string str3 = "+ 2.000000x+ 2.000000y";
	TPolinom poly1(str1);
	TPolinom poly2 = poly1.dif_y();
	EXPECT_EQ(str3, poly2.To_string());
}

TEST(TPolinom, test_checking_the_dif_z_2)
{
	string str1 = "x^2+2xy+y^2";
	string str3 = " 0.000000";
	TPolinom poly1(str1);
	TPolinom poly2 = poly1.dif_z();
	EXPECT_EQ(str3, poly2.To_string());
}

TEST(TPolinom, test_checking_results_1_tostr)
{
	string str1 = "-1+x";
	string str2 = "-5+2x";

	string str_res1 = "+ 1.000000x  -1.000000";
	string str_res2 = "+ 2.000000x  -5.000000";

	TPolinom poly1(str1);
	TPolinom poly2(str2);

	EXPECT_EQ(str_res1, poly1.To_string());
	EXPECT_EQ(str_res2, poly2.To_string());

}

TEST(TPolinom, test_checking_results_1_difx)
{
	string str1 = "-1+x";
	string str2 = "-5+2x";

	string str_res1_difx = "+ 1.000000";
	string str_res2_difx = "+ 2.000000";
	string null = " 0.000000";

	TPolinom poly1(str1);
	TPolinom poly2(str2);

	TPolinom poly1_res = poly1.dif_x();
	TPolinom poly2_res = poly2.dif_x();

	EXPECT_EQ(str_res1_difx, poly1_res.To_string());
	EXPECT_EQ(str_res2_difx, poly2_res.To_string());

}

TEST(TPolinom, test_checking_results_1_difyz)
{
	string str1 = "-1+x";
	string str2 = "-5+2x";
	
	string null = " 0.000000";

	TPolinom poly1(str1);
	TPolinom poly2(str2);

	TPolinom poly1_res = poly1.dif_y();
	TPolinom poly2_res = poly2.dif_y();
	TPolinom poly3_res = poly1.dif_z();
	TPolinom poly4_res = poly2.dif_z();

	EXPECT_EQ(null, poly1_res.To_string());
	EXPECT_EQ(null, poly2_res.To_string());
	EXPECT_EQ(null, poly3_res.To_string());
	EXPECT_EQ(null, poly4_res.To_string());

}

TEST(TPolinom, test_checking_results_1_sum_difference_product)
{
	string str1 = "-1+x";
	string str2 = "-5+2x";

	string res1 = "+ 3.000000x  -6.000000";
	string res2 = "  -1.000000x+ 4.000000";
	string res3 = "+ 2.000000x^2  -7.000000x+ 5.000000";

	TPolinom poly1(str1);
	TPolinom poly2(str2);

	TPolinom poly1_res = poly1 + poly2;
	TPolinom poly2_res = poly1 - poly2;
	TPolinom poly3_res = poly1 * poly2;

	EXPECT_EQ(res1, poly1_res.To_string());
	EXPECT_EQ(res2, poly2_res.To_string());
	EXPECT_EQ(res3, poly3_res.To_string());


}

TEST(TPolinom, test_checking_results_2__tostr)
{
	string str1 = "x^2+2xy+y^2";
	string str2 = "x^3+3x^2y+3xy^2+y^3";

	string res1 = "+ 1.000000x^2+ 2.000000xy+ 1.000000y^2";
	string res2 = "+ 1.000000x^3+ 3.000000x^2y+ 3.000000xy^2+ 1.000000y^3";

	TPolinom poly1(str1);
	TPolinom poly2(str2);

	EXPECT_EQ(res1, poly1.To_string());
	EXPECT_EQ(res2, poly2.To_string());

}

TEST(TPolinom, test_checking_results_2_sum_difference_difxyz_1)
{
	string str1 = "x^2+2xy+y^2";

	string res1_difx = "+ 2.000000x+ 2.000000y";
	string res1_dify = "+ 2.000000x+ 2.000000y";
	string res1_difz = " 0.000000";

	TPolinom poly1(str1);
	TPolinom poly1_res = poly1.dif_x();
	TPolinom poly2_res = poly1.dif_y();
	TPolinom poly3_res = poly1.dif_z();



	EXPECT_EQ(res1_difx, poly1_res.To_string());
	EXPECT_EQ(res1_dify, poly2_res.To_string());
	EXPECT_EQ(res1_difz, poly3_res.To_string());

}

TEST(TPolinom, test_checking_results_2_sum_difference_difxyz_2)
{
	string str1 = "x^3+3x^2y+3xy^2+y^3";

	string res1_difx = "+ 3.000000x^2+ 6.000000xy+ 3.000000y^2";
	string res1_dify = "+ 3.000000x^2+ 6.000000xy+ 3.000000y^2";
	string res1_difz = " 0.000000";

	TPolinom poly1(str1);
	TPolinom poly1_res = poly1.dif_x();
	TPolinom poly2_res = poly1.dif_y();
	TPolinom poly3_res = poly1.dif_z();



	EXPECT_EQ(res1_difx, poly1_res.To_string());
	EXPECT_EQ(res1_dify, poly2_res.To_string());
	EXPECT_EQ(res1_difz, poly3_res.To_string());

}

TEST(TPolinom, test_checking_results_2_sum_difference_product)
{
	string str1 = "x^2+2xy+y^2";
	string str2 = "x^3+3x^2y+3xy^2+y^3";

	string res1 = "+ 1.000000x^3+ 3.000000x^2y+ 1.000000x^2+ 3.000000xy^2+ 2.000000xy+ 1.000000y^3+ 1.000000y^2";
	string res2 = "  -1.000000x^3  -3.000000x^2y+ 1.000000x^2  -3.000000xy^2+ 2.000000xy  -1.000000y^3+ 1.000000y^2";
	string res3 = "+ 1.000000x^5+ 5.000000x^4y+ 10.000000x^3y^2+ 10.000000x^2y^3+ 5.000000xy^4+ 1.000000y^5";

	TPolinom poly1(str1);
	TPolinom poly2(str2);

	TPolinom poly1_res = poly1 + poly2;
	TPolinom poly2_res = poly1 - poly2;
	TPolinom poly3_res = poly1 * poly2;

	EXPECT_EQ(res1, poly1_res.To_string());
	EXPECT_EQ(res2, poly2_res.To_string());
	EXPECT_EQ(res3, poly3_res.To_string());


}

