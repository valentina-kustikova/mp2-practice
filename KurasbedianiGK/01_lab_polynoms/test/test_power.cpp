#include "power.h"
#include "gtest.h"

TEST(Power, can_create_power_with_default_values) {
    ASSERT_NO_THROW(Power{});
}

TEST(Power, can_create_power_with_user_values) {
    ASSERT_NO_THROW(Power power(3,4,5));
}

TEST(Power, can_create_power_with_negative_values) {
    ASSERT_NO_THROW(Power power(-3,-4,-5));
}

TEST(Power, can_create_power_via_copy_ctor1) {
    Power power(1,4,-5);

    ASSERT_NO_THROW(Power{power});
}

TEST(Power, created_power_via_copy_ctor1_is_correct) {
    Power power(1,4,-5);
    Power power1{power};

    EXPECT_EQ(power, power1);
}

TEST(Power, can_create_power_via_copy_ctor2) {
    Power power(1,4,-5);

    ASSERT_NO_THROW(Power{} = power);
}

TEST(Power, created_power_via_copy_ctor2_is_correct) {
    Power power(1,4,-5);
    Power power1 = power;

    EXPECT_EQ(power, power1);
}

TEST(Power, can_assign_power) {
    Power power(1,4,-5);
    Power power1;

    ASSERT_NO_THROW(power1 = power);
}

TEST(Power, assigned_power_is_correct) {
    Power power(1,4,-5);
    Power power1;

    power1 = power;

    EXPECT_EQ(power, power1);
}

TEST(Power, powers_are_equal_operator_eq_eq) {
    Power power(1,4,-5);
    Power power1{power};

    EXPECT_TRUE(power == power1);
}

TEST(Power, powers_are_not_equal_operator_eq_eq) {
    Power power(1,4,-5);
    Power power1(1,3,6);

    EXPECT_FALSE(power == power1);
}

TEST(Power, powers_are_not_equal_operator_not_eq_eq) {
    Power power(1,4,-5);
    Power power1(1,3,6);

    EXPECT_TRUE(power != power1);
}

TEST(Power, powers_are_equal_with_operator_not_eq_eq) {
    Power power(1,4,-5);
    Power power1{power};

    EXPECT_FALSE(power != power1);
}

TEST(Power, can_not_add_when_x_will_be_less_9) {
    ASSERT_NO_THROW(Power(7,1,1) + Power(1,6,7));
}

TEST(Power, can_not_add_when_x_will_be_equal_9) {
    ASSERT_NO_THROW(Power(7,1,1) + Power(2,6,7));
}

TEST(Power, can_not_add_when_x_will_be_greater_9) {
    ASSERT_ANY_THROW(Power(7,1,1) + Power(5,6,7));
}

TEST(Power, can_not_add_when_y_will_be_less_9) {
    ASSERT_NO_THROW(Power(7,2,1) + Power(1,6,7));
}

TEST(Power, can_not_add_when_y_will_be_equal_9) {
    ASSERT_NO_THROW(Power(7,3,1) + Power(2,6,7));
}

TEST(Power, can_not_add_when_y_will_be_greater_9) {
    ASSERT_ANY_THROW(Power(7,4,1) + Power(5,6,7));
}

TEST(Power, can_not_add_when_z_will_be_less_9) {
    ASSERT_NO_THROW(Power(7,1,1) + Power(1,6,7));
}

TEST(Power, can_not_add_when_z_will_be_equal_9) {
    ASSERT_NO_THROW(Power(7,1,2) + Power(2,6,7));
}

TEST(Power, can_not_add_when_z_will_be_greater_9) {
    ASSERT_ANY_THROW(Power(7,1,3) + Power(5,6,7));
}