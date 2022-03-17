#include <gtest.h>
#include "polynom.h"

TEST(Polynom, can_create_polynom_with_default_values) {
    ASSERT_NO_THROW(Polynom{});
}

TEST(Polynom, can_create_polynm_with_user_values) {
    List<Monom> list;
    list.insert(Monom(3, Power{1, 2, 3}));

    ASSERT_NO_THROW(Polynom{list});
}

TEST(Polynom, can_create_polynom_via_copy_ctor) {
    List<Monom> list;
    list.insert(Monom(3, Power{1, 2, 3}));
    Polynom polynom{list};

    ASSERT_NO_THROW(Polynom{polynom});
}

TEST(Polynom, created_polynom_via_copy_ctor_is_correct) {
    List<Monom> list;
    list.insert(Monom(3, Power{1, 2, 3}));
    list.insert(Monom(7, Power{4, 5, 6}));
    Polynom polynom{list};
    Polynom polynom1{polynom};

    for (int i = 0; i < polynom.get_poly().get_size(); ++i) {
        EXPECT_EQ((polynom.get_poly().get_head() + i)->data,
                  (polynom1.get_poly().get_head() + i)->data);
    }
}

TEST(Polynom, can_get_poly_list) {
    List<Monom> list;
    list.insert(Monom(3, Power{1, 2, 3}));
    list.insert(Monom(7, Power{4, 5, 6}));
    Polynom polynom{list};
    ASSERT_NO_THROW(polynom.get_poly());
}

TEST(Polynom, getted_poly_list_is_correct) {
    List<Monom> list;
    list.insert(Monom(7, Power{4, 5, 6}));
    list.insert(Monom(3, Power{1, 2, 3}));
    Polynom polynom{list};

    for (int i = 0; i < polynom.get_poly().get_size(); ++i) {
        EXPECT_EQ((list.get_head() + i)->data,
                  (polynom.get_poly().get_head() + i)->data);
    }
}

TEST(Polynom, can_assign_polynom) {
    List<Monom> list;
    List<Monom> list1;
    list.insert(Monom(7, Power{4, 5, 6}));
    list1.insert(Monom(3, Power{1, 2, 3}));
    Polynom polynom{list};
    Polynom polynom1{list1};

    ASSERT_NO_THROW(polynom1 = polynom);
}

TEST(Polynom, assigned_polynom_is_correct) {
    List<Monom> list;
    List<Monom> list1;
    list.insert(Monom(7, Power{4, 5, 6}));
    list1.insert(Monom(3, Power{1, 2, 3}));
    Polynom polynom{list};
    Polynom polynom1{list1};

    polynom1 = polynom;

    for (int i = 0; i < polynom.get_poly().get_size(); ++i) {
        EXPECT_EQ((polynom.get_poly().get_head() + i)->data,
                  (polynom1.get_poly().get_head() + i)->data);
    }
    EXPECT_EQ(polynom.get_name(), polynom1.get_name());
}

TEST(Polynom, sum_two_polynoms_with_eq_power) {
    List<Monom> list;
    List<Monom> list1;
    List<Monom> expected_list;

    list.insert(Monom(7, Power{4, 5, 6}));
    list1.insert(Monom(3, Power{4, 5, 6}));
    expected_list.insert(Monom(10, Power{4, 5, 6}));

    Polynom polynom{list};
    Polynom polynom1{list1};
    Polynom expected_poly{"+", expected_list};
    Polynom actual_poly = polynom + polynom1;

    for (int i = 0; i < actual_poly.get_poly().get_size(); ++i) {
        EXPECT_EQ((expected_poly.get_poly().get_head() + i)->data,
                  (actual_poly.get_poly().get_head() + i)->data);
    }
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, substract_two_polynoms_with_eq_power) {
    List<Monom> list;
    List<Monom> list1;
    List<Monom> expected_list;

    list.insert(Monom(7, Power{4, 5, 6}));
    list1.insert(Monom(3, Power{4, 5, 6}));
    expected_list.insert(Monom(4, Power{4, 5, 6}));

    Polynom polynom{list};
    Polynom polynom1{list1};
    Polynom expected_poly{"()-()", expected_list};
    Polynom actual_poly = polynom - polynom1;

    for (int i = 0; i < actual_poly.get_poly().get_size(); ++i) {
        EXPECT_EQ((expected_poly.get_poly().get_head() + i)->data,
                  (actual_poly.get_poly().get_head() + i)->data);
    }
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, mul_two_polynoms_with_eq_power) {
    List<Monom> list;
    List<Monom> list1;
    List<Monom> expected_list;

    list.insert(Monom(7, Power{4, 3, 2}));
    list1.insert(Monom(3, Power{4, 3, 2}));
    expected_list.insert(Monom(21, Power{8, 6, 4}));

    Polynom polynom{list};
    Polynom polynom1{list1};
    Polynom expected_poly{"()*()", expected_list};
    Polynom actual_poly = polynom * polynom1;

    for (int i = 0; i < actual_poly.get_poly().get_size(); ++i) {
        EXPECT_EQ((expected_poly.get_poly().get_head() + i)->data,
                  (actual_poly.get_poly().get_head() + i)->data);
    }
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, sum_two_polynoms_with_not_eq_power) {
    List<Monom> list;
    List<Monom> list1;
    List<Monom> expected_list;

    list.insert(Monom(7, Power{4, 5, 6}));
    list1.insert(Monom(3, Power{1, 2, 3}));
    expected_list.insert(Monom(7, Power{4, 5, 6}));
    expected_list.insert(Monom(3, Power{1, 2, 3}));


    Polynom polynom{list};
    Polynom polynom1{list1};
    Polynom expected_poly{"+", expected_list};
    Polynom actual_poly = polynom + polynom1;

    for (int i = 0; i < actual_poly.get_poly().get_size(); ++i) {
        EXPECT_EQ((expected_poly.get_poly().get_head() + i)->data,
                  (actual_poly.get_poly().get_head() + i)->data);
    }
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, substract_two_polynoms_with_not_eq_power) {
    List<Monom> list;
    List<Monom> list1;
    List<Monom> expected_list;

    list.insert(Monom(7, Power{4, 5, 6}));
    list1.insert(Monom(3, Power{1, 2, 3}));
    expected_list.insert(Monom(7, Power{4, 5, 6}));
    expected_list.insert(Monom(-3, Power{1, 2, 3}));

    Polynom polynom{list};
    Polynom polynom1{list1};
    Polynom expected_poly{"()-()", expected_list};
    Polynom actual_poly = polynom - polynom1;

    for (int i = 0; i < actual_poly.get_poly().get_size(); ++i) {
        EXPECT_EQ((expected_poly.get_poly().get_head())->data,
                  (actual_poly.get_poly().get_head())->data);
    }
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, mul_two_polynoms_with_not_eq_power) {
    List<Monom> list;
    List<Monom> list1;
    List<Monom> expected_list;

    list.insert(Monom(7, Power{4, 3, 2}));
    list1.insert(Monom(3, Power{1, 2, 5}));
    expected_list.insert(Monom(21, Power{5, 5, 7}));

    Polynom polynom{list};
    Polynom polynom1{list1};
    Polynom expected_poly{"()*()", expected_list};
    Polynom actual_poly = polynom * polynom1;

    EXPECT_EQ((expected_poly.get_poly().get_head())->data,
              (actual_poly.get_poly().get_head())->data);
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, add_polynom_and_scalar) {
    List<Monom> list;
    List<Monom> expected_list;
    double scalar = 5.0;

    list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(scalar, Power{0, 0, 0}));

    Polynom polynom{list};
    Polynom expected_poly{"+" + std::to_string(scalar), expected_list};
    Polynom actual_poly = polynom + scalar;

    EXPECT_EQ((expected_poly.get_poly().get_head())->data,
              (actual_poly.get_poly().get_head())->data);
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, substract_polynom_and_scalar) {
    List<Monom> list;
    List<Monom> expected_list;
    double scalar = 5.0;

    list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(scalar, Power{0, 0, 0}));

    Polynom polynom{list};
    Polynom expected_poly{"()-(" + std::to_string(scalar) + ")", expected_list};
    Polynom actual_poly = polynom - scalar;

    EXPECT_EQ((expected_poly.get_poly().get_head())->data,
              (actual_poly.get_poly().get_head())->data);
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, mul_polynom_and_scalar) {
    List<Monom> list;
    List<Monom> expected_list;
    double scalar = 5.0;

    list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(35, Power{4, 3, 2}));

    Polynom polynom{list};
    Polynom expected_poly{"()*" + std::to_string(scalar), expected_list};
    Polynom actual_poly = polynom * scalar;

    EXPECT_EQ((expected_poly.get_poly().get_head())->data,
              (actual_poly.get_poly().get_head())->data);
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, add_scalar_and_polynom) {
    List<Monom> list;
    List<Monom> expected_list;
    double scalar = 5.0;

    list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(scalar, Power{0, 0, 0}));

    Polynom polynom{list};
    Polynom expected_poly{"+" + std::to_string(scalar), expected_list};
    Polynom actual_poly = scalar + polynom;

    EXPECT_EQ((expected_poly.get_poly().get_head())->data,
              (actual_poly.get_poly().get_head())->data);
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, substract_scalar_and_polynom) {
    List<Monom> list;
    List<Monom> expected_list;
    double scalar = 5.0;

    list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(-7, Power{4, 3, 2}));
    expected_list.insert(Monom(scalar, Power{0, 0, 0}));

    Polynom polynom{list};
    Polynom expected_poly{"(" + std::to_string(scalar) + ")-()", expected_list};
    Polynom actual_poly = scalar - polynom;

    EXPECT_EQ((expected_poly.get_poly().get_head())->data,
              (actual_poly.get_poly().get_head())->data);
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}

TEST(Polynom, mul_scalar_and_polynom) {
    List<Monom> list;
    List<Monom> expected_list;
    double scalar = 5.0;

    list.insert(Monom(7, Power{4, 3, 2}));
    expected_list.insert(Monom(35, Power{4, 3, 2}));

    Polynom polynom{list};
    Polynom expected_poly{std::to_string(scalar) + "*()", expected_list};
    Polynom actual_poly = scalar * polynom;

    EXPECT_EQ((expected_poly.get_poly().get_head())->data,
              (actual_poly.get_poly().get_head())->data);
    EXPECT_EQ(expected_poly.get_name(), actual_poly.get_name());
}