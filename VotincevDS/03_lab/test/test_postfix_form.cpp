//#include "postfix_form.h"
//
//#include <gtest.h>
//
//
////
////                ArrayStack
////
//
//
//
//
//TEST(ArrayStack, postfixform_works_correctly_testcase1)
//{
//    string s = "A+B-C";
//    string correct = "A B C - + ";
//    ArrayStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//TEST(ArrayStack, postfixform_counts_correctly_testcase1)
//{
//    string s = "A+B-C";
//    ArrayStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 5;
//    values["B"] = 3;
//    values["C"] = 7;
//    EXPECT_EQ(1,test_solvepf(ar1,values));
//}
//
//
//
//TEST(ArrayStack, postfixform_works_correctly_testcase2)
//{
//    string s = "A+(B-C)*D";
//    string correct = "A B C - D * + ";
//    ArrayStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//    
//}
//
//TEST(ArrayStack, postfixform_counts_correctly_testcase2)
//{
//    string s = "A+(B-C)*D";
//    ArrayStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 5;
//    values["B"] = 3;
//    values["C"] = 7;
//    values["D"] = -3;
//    EXPECT_EQ(17, test_solvepf(ar1, values));
//}
//
//
//
//
//
//TEST(ArrayStack, postfixform_works_correctly_testcase3)
//{
//    string s = "-1+33-A*-5+AA-A/(A-AA)";
//    string correct = "-1 33 A -5 * - AA A A AA - / - + + ";
//    ArrayStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//TEST(ArrayStack, postfixform_counts_correctly_testcase3)
//{
//    string s = "-1+33-A*-5+AA-A/(A-AA)";
//    ArrayStack<string> ar1; // 32+50+5-2
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 10;
//    values["AA"] = 5;
//    EXPECT_EQ(85, test_solvepf(ar1, values));
//}
//
//
//
//
//
//TEST(ArrayStack, postfixform_works_correctly_testcase4)
//{
//    string s = "(-5)-A+(-3)";
//    string correct = "-5 A - -3 + ";
//    ArrayStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//TEST(ArrayStack, postfixform_counts_correctly_testcase4)
//{
//    string s = "A+(B-C)*D";
//    ArrayStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 5;
//    values["B"] = 3;
//    values["C"] = 7;
//    values["D"] = -3;
//    EXPECT_EQ(17, test_solvepf(ar1, values));
//}
//
//
//
//TEST(ArrayStack, postfixform_works_correctly_testcase5)
//{
//    string s = "1-A*(-5)+AA";
//    string correct = "1 A -5 * - AA + ";
//    ArrayStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//
//
//TEST(ArrayStack, postfixform_counts_correctly_testcase5)
//{
//    string s = "1-A*(-5)+AA";
//    ArrayStack<string> ar1; 
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 10;
//    values["AA"] = 5;
//    EXPECT_EQ(56, test_solvepf(ar1, values));
//}
//
//
//
//TEST(ArrayStack, postfixform_works_correctly_testcase6)
//{
//    string s = "A-A+A-A+A-A";
//    string correct = "A A - A A - A A - + + ";
//    ArrayStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//
//
//TEST(ArrayStack, postfixform_counts_correctly_testcase6)
//{
//    string s = "A-A+A-A+A-A";
//    ArrayStack<string> ar1; 
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 10;
//    EXPECT_EQ(0, test_solvepf(ar1, values));
//}
//
//
//TEST(ArrayStack, postfixform_works_correctly_testcase7)
//{
//    string s = "-1--2--3--4+-5-6";
//    string correct = "-1 -2 -3 -4 - - - -5-6 + ";
//    ArrayStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//
//
//TEST(ArrayStack, postfixform_counts_correctly_testcase7)
//{
//    string s = "-1--2--3--4+-5-6"; // (-1 + 2 + 3 + 4 - 5 - 6)
//    ArrayStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    EXPECT_EQ(-3, test_solvepf(ar1, values));
//}
//
//
//
//
//
//
////
////                ListStack
////
//
//
//
//
//TEST(ListStack, postfixform_works_correctly_testcase1)
//{
//    string s = "A+B-C";
//    string correct = "A B C - + ";
//    ListStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//TEST(ListStack, postfixform_counts_correctly_testcase1)
//{
//    string s = "A+B-C";
//    ListStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 5;
//    values["B"] = 3;
//    values["C"] = 7;
//    EXPECT_EQ(1, test_solvepf(ar1, values));
//}
//
//
//
//TEST(ListStack, postfixform_works_correctly_testcase2)
//{
//    string s = "A+(B-C)*D";
//    string correct = "A B C - D * + ";
//    ListStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//
//}
//
//TEST(ListStack, postfixform_counts_correctly_testcase2)
//{
//    string s = "A+(B-C)*D";
//    ListStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 5;
//    values["B"] = 3;
//    values["C"] = 7;
//    values["D"] = -3;
//    EXPECT_EQ(17, test_solvepf(ar1, values));
//}
//
//
//
//
//
//TEST(ListStack, postfixform_works_correctly_testcase3)
//{
//    string s = "-1+33-A*-5+AA-A/(A-AA)";
//    string correct = "-1 33 A -5 * - AA A A AA - / - + + ";
//    ListStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//TEST(ListStack, postfixform_counts_correctly_testcase3)
//{
//    string s = "-1+33-A*-5+AA-A/(A-AA)";
//    ListStack<string> ar1; // 32+50+5-2
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 10;
//    values["AA"] = 5;
//    EXPECT_EQ(85, test_solvepf(ar1, values));
//}
//
//
//
//
//
//TEST(ListStack, postfixform_works_correctly_testcase4)
//{
//    string s = "(-5)-A+(-3)";
//    string correct = "-5 A - -3 + ";
//    ListStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//TEST(ListStack, postfixform_counts_correctly_testcase4)
//{
//    string s = "A+(B-C)*D";
//    ListStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 5;
//    values["B"] = 3;
//    values["C"] = 7;
//    values["D"] = -3;
//    EXPECT_EQ(17, test_solvepf(ar1, values));
//}
//
//
//
//TEST(ListStack, postfixform_works_correctly_testcase5)
//{
//    string s = "1-A*(-5)+AA";
//    string correct = "1 A -5 * - AA + ";
//    ListStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//
//
//TEST(ListStack, postfixform_counts_correctly_testcase5)
//{
//    string s = "1-A*(-5)+AA";
//    ListStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 10;
//    values["AA"] = 5;
//    EXPECT_EQ(56, test_solvepf(ar1, values));
//}
//
//
//
//TEST(ListStack, postfixform_works_correctly_testcase6)
//{
//    string s = "A-A+A-A+A-A";
//    string correct = "A A - A A - A A - + + ";
//    ListStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//
//
//TEST(ListStack, postfixform_counts_correctly_testcase6)
//{
//    string s = "A-A+A-A+A-A";
//    ListStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    values["A"] = 10;
//    EXPECT_EQ(0, test_solvepf(ar1, values));
//}
//
//
//TEST(ListStack, postfixform_works_correctly_testcase7)
//{
//    string s = "-1--2--3--4+-5-6";
//    string correct = "-1 -2 -3 -4 - - - -5-6 + ";
//    ListStack<string> ar1;
//    EXPECT_TRUE(correct == postfixform(s, ar1));
//}
//
//
//
//
//TEST(ListStack, postfixform_counts_correctly_testcase7)
//{
//    string s = "-1--2--3--4+-5-6"; // (-1 + 2 + 3 + 4 - 5 - 6)
//    ListStack<string> ar1;
//    postfixform(s, ar1);
//    unordered_map<string, double> values;
//    EXPECT_EQ(-3, test_solvepf(ar1, values));
//}
