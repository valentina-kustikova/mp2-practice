#include "gtest.h"
#include "monom.h"

TEST(Monom, can_create_monom_with_default_values) {
    ASSERT_NO_THROW(Monom{});
}

TEST(Monom, can_create_monom_with_user_coef) {
    ASSERT_NO_THROW(Monom(3));
}

TEST(Monom, can_create_monom_with_user_power) {
    ASSERT_NO_THROW(Monom(3, Power{4, 2, 6}));
}

TEST(Monom, can_not_create_monom_with_power_of_x_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{10, 1, 1}));
}

TEST(Monom, can_not_create_monom_with_power_of_y_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{1, 10, 1}));
}

TEST(Monom, can_not_create_monom_with_power_of_z_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{1, 1, 10}));
}

TEST(Monom, can_not_create_monom_with_power_of_x_less_than_0) {
    ASSERT_ANY_THROW(Monom(3, Power{-10, 1, 1}));
}

TEST(Monom, can_not_create_monom_with_power_of_y_less_than_0) {
    ASSERT_ANY_THROW(Monom(3, Power{1, -10, 1}));
}

TEST(Monom, can_not_create_monom_with_power_of_z_less_than_0) {
    ASSERT_ANY_THROW(Monom(3, Power{1, 1, -10}));
}

TEST(Monom, can_create_monom_via_copy_ctor1) {
    Monom monom{3, Power{1,2,3}};

    ASSERT_NO_THROW(Monom{monom});
}

TEST(Monom, created_monom_via_copy_ctor1_is_correct) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1{monom};

    EXPECT_EQ(monom, monom1);
}

TEST(Monom, can_create_monom_via_copy_ctor2) {
    Monom monom{3, Power{1,2,3}};

    ASSERT_NO_THROW(Monom{} = monom);
}

TEST(Monom, created_monom_via_copy_ctor2_is_correct) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1 = monom;

    EXPECT_EQ(monom, monom1);
}

TEST(Monom, can_assign_monom) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1{5, Power{4,1,5}};

    ASSERT_NO_THROW(monom1 = monom);
}

TEST(Monom, assigned_monom_is_correct) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1{5, Power{4,1,5}};

    monom1 = monom;

    EXPECT_EQ(monom, monom1);
}

TEST(Monom, can_get_coefficient) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}).get_coefficient());
}

TEST(Monom, goten_coefficient_is_correct) {
    EXPECT_EQ(3, Monom(3, Power{1,2,3}).get_coefficient());
}

TEST(Monom, can_set_coefficient) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}).set_coefficient(5));
}

TEST(Monom, established_coefficient_is_correct) {
    Monom monom(3, Power{1,2,3});
    monom.set_coefficient(5);

    EXPECT_EQ(5, monom.get_coefficient());
}

TEST(Monom, can_get_power) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}).get_power());
}

TEST(Monom, goten_power_is_correct) {
    EXPECT_EQ(Power(1,2,3), Monom(3, Power{1,2,3}).get_power());
}

TEST(Monom, can_set_correct_power) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}).set_power(Power{4,5,6}));
}

TEST(Monom, established_power_is_correct) {
    Monom monom(3, Power{1,2,3});
    monom.set_power(Power{4,5,6});

    EXPECT_EQ(Power(4,5,6), monom.get_power());
}

TEST(Monom, can_not_set_power_where_x_is_less_than_0) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}).set_power(Power{-10,5,6}));
}

TEST(Monom, can_not_set_power_where_x_is_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}).set_power(Power{10,5,6}));

}

TEST(Monom, can_not_set_power_where_y_is_less_than_0) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}).set_power(Power{1,-10,6}));
}

TEST(Monom, can_not_set_power_where_y_is_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}).set_power(Power{1,10,6}));
}

TEST(Monom, can_not_set_power_where_z_is_less_than_0) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}).set_power(Power{1,5,-10}));
}

TEST(Monom, can_not_set_power_where_z_is_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}).set_power(Power{1,5,10}));
}

TEST(Monom, monoms_are_equal_operaor_eq_eq) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1{monom};

    EXPECT_TRUE(monom1 == monom);
}

TEST(Monom, monoms_are_not_equal_operaor_eq_eq) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1{5, Power{4,1,5}};

    EXPECT_FALSE(monom1 == monom);
}

TEST(Monom, monoms_are_not_equal_operator_not_eq_eq) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1{5, Power{4,1,5}};

    EXPECT_TRUE(monom != monom1);
}

TEST(Monom, monoms_are_equal_operator_not_eq_eq) {
    Monom monom{3, Power{1,2,3}};
    Monom monom1{monom};

    EXPECT_FALSE(monom != monom1);
}

TEST(Monom, can_sum_two_monoms_with_equal_power) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}) + Monom(3, Power{1,2,3}));
}

TEST(Monom, sum_two_monoms_with_equal_power_is_correct) {
    EXPECT_EQ(Monom(6, Power{1,2,3}), Monom(3, Power{1,2,3}) + Monom(3, Power{1,2,3}));
}

TEST(Monom, can_not_sum_two_monoms_with_not_equal_power) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}) + Monom(3, Power{2,2,3}));
}

TEST(Monom, can_substract_two_monoms_with_equal_power) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}) - Monom(3, Power{1,2,3}));
}

TEST(Monom, substract_two_monoms_with_equal_power_is_correct) {
    EXPECT_EQ(Monom(2, Power{1,2,3}), Monom(3, Power{1,2,3}) - Monom(1, Power{1,2,3}));
}

TEST(Monom, can_substract_not_sum_two_monoms_with_not_equal_power) {
    ASSERT_ANY_THROW(Monom(3, Power{1,2,3}) - Monom(1, Power{2,2,3}));
}

TEST(Monom, can_mul_two_monoms) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}) * Monom(3, Power{1,2,3}));
}

TEST(Monom, mul_two_monoms_is_correct) {
    EXPECT_EQ(Monom(9, Power{2,4,6}), Monom(3, Power{1,2,3}) * Monom(3, Power{1,2,3}));
}

TEST(Monom, can_not_mul_monoms_if_resulting_power_of_x_is_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{8,2,3}) * Monom(3, Power{4,2,3}));
}

TEST(Monom, can_not_mul_monoms_if_resulting_power_of_y_is_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{3,2,3}) * Monom(3, Power{1,8,3}));
}

TEST(Monom, can_not_mul_monoms_if_resulting_power_of_z_is_greater_than_9) {
    ASSERT_ANY_THROW(Monom(3, Power{3,2,3}) * Monom(3, Power{4,2,8}));
}

TEST(Monom, can_mul_monom_and_coef) {
    ASSERT_NO_THROW(Monom(3, Power{1,2,3}) * 3);
}

TEST(Monom, res_of_mul_monom_and_coef_is_correct) {
    EXPECT_EQ(Monom(9, Power{1,2,3}), Monom(3, Power{1,2,3}) * 3);
}