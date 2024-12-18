#include <gtest.h>
#include "postform.h"



TEST(TList, can_create_list) {
	TNode<int>* a();
	ASSERT_NO_THROW(TList<int> l);
}

TEST(TList, can_insert_and_getlast_node_in_list) {

	TList<int> l;
	l.Insert(1);
	TNode<int>* a = l.GetLast();
	ASSERT_TRUE(a->key == 1);
}
TEST(TList, can_delete_node_in_list) {

	TList<int> l;
	l.Insert(1);
	l.Insert(1);
	l.DeleteLast();
	ASSERT_TRUE(l.GetLast()->pNext == nullptr);
}




TEST(TStack, can_create_stack_with_positive_length) {
	ASSERT_NO_THROW(TStack<int> s(2));
}
TEST(TStack, cant_create_stack_with_negative_length) {
	ASSERT_ANY_THROW(TStack<int> s(-2));
}
TEST(TStack, can_create_copied_stack) {
	TStack<int> s(2);
	ASSERT_NO_THROW(TStack<int> s1(s));
}
TEST(TStack, can_push_and_get_top_element) {
	TStack<int> s(2);
	s.push(1);
	EXPECT_EQ(s.Top(), 1);
}
TEST(TStack, new_stack_is_empty) {
	TStack<int> s(2);
	ASSERT_TRUE(s.isEmpty());
}
TEST(TStack, stack_is_full) {
	TStack<int> s(2);
	for (int i = 0; i < 2; i++) {
		s.push(1);
	}
	ASSERT_TRUE(s.isFull());
}
TEST(TStack, can_pop_and_element) {
	TStack<int> s(2);
	s.push(1);
	s.pop();
	ASSERT_TRUE(s.isEmpty());
}
TEST(TStack, copied_stack_is_equal_to_source_one) {
	TStack<int> s(2);
	ASSERT_NO_THROW(TStack<int> s1(s));
}
TEST(TStack, cant_pop_from_empty_stack) {
	TStack<int> s(2);
	ASSERT_ANY_THROW(s.pop());
}
TEST(TStack, cant_push_from_full_stack) {
	TStack<int> s(2);
	for(int i = 0; i < 2; i++) {
		s.push(1);
	}
	ASSERT_ANY_THROW(s.push(1));
}




TEST(getPostform, can_create_single_operand_example) {
	char* st = "A+C";
	char* st1 = "AC+";
	string a = getPostform(st, strlen(st));
	EXPECT_EQ(a, st1);
}
TEST(getPostform, can_create_single_operand_with_brackets_example) {
	char* st = "(A+C)";
	char* st1 = "AC+";
	string a = getPostform(st, strlen(st));
	EXPECT_EQ(a, st1);
}
TEST(getPostform, can_create_example_with_prioritized) {
	char* st = "A+C*B";
	char* st1 = "ACB*+";
	string a = getPostform(st, strlen(st));
	EXPECT_EQ(a, st1);
}
TEST(getPostform, can_create_example_with_prioritized_with_brackets) {
	char* st = "(A+C)*B";
	char* st1 = "AC+B*";
	string a = getPostform(st, strlen(st));
	EXPECT_EQ(a, st1);
}
TEST(getPostform, can_create_example_with_prioritized_and_more_arguments) {
	char* st = "T*A+C*B";
	char* st1 = "TA*CB*+";
	string a = getPostform(st, strlen(st));
	EXPECT_EQ(a, st1);
}
TEST(getPostform, can_create_example_with_prioritized_and_more_arguments_with_more_brackets) {
	char* st = "(A+C)*(B-G/Q)-((W/E)+P)";
	char* st1 = "AC+BGQ/-*WE/P+-";
	string a = getPostform(st, strlen(st));
	EXPECT_EQ(a, st1);
}




TEST(Calculate, can_sum_two_elements) {
	char* st = "A+C";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(7, Calculate(a, n, s));
}
TEST(Calculate, can_subtract_two_elements) {
	char* st = "C-A";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(3, Calculate(a, n, s));
}
TEST(Calculate, can_subtract_two_elements_with_negative_answer) {
	char* st = "A-C";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(-3, Calculate(a, n, s));
}
TEST(Calculate, can_divide_two_elements) {
	char* st = "A/C";
	map<char, int> s;
	s.insert({ 'A', 9 });
	s.insert({ 'C', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(3, Calculate(a, n, s));
}
TEST(Calculate, can_sum_three_elements_with_brackets) {
	char* st = "(A+C)+B";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(10, Calculate(a, n, s));
}
TEST(Calculate, can_sum_and_subtract_three_elements_with_brackets) {
	char* st = "(A+C)-B";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(4, Calculate(a, n, s));
}
TEST(Calculate, can_subtract_and_sum_three_elements_with_brackets) {
	char* st = "(C-A)+B";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(6, Calculate(a, n, s));
}
TEST(Calculate, can_sum_and_multiply_three_elements_with_brackets) {
	char* st = "(C+A)*B";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(21, Calculate(a, n, s));
}
TEST(Calculate, can_multiply_and_sum_three_elements_with_brackets) {
	char* st = "(C*A)+B";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(13, Calculate(a, n, s));
}
TEST(Calculate, can_sum_and_multiply_three_elements) {
	char* st = "C+A*B";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(11, Calculate(a, n, s));
}
TEST(Calculate, can_multiply_and_multiply_three_elements) {
	char* st = "C*A*B";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(30, Calculate(a, n, s));
}
TEST(Calculate, can_multiply_brackets) {
	char* st = "(A+C)*(B-T)";
	map<char, int> s;
	s.insert({ 'A', 2 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	s.insert({ 'T', 1 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(14, Calculate(a, n, s));
}
TEST(Calculate, can_divide_and_subtract_elements) {
	char* st = "A/B-C";
	map<char, int> s;
	s.insert({ 'A', 6 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(-3, Calculate(a, n, s));
}
TEST(Calculate, can_subtract_and_divide_elements) {
	char* st = "C-A/B";
	map<char, int> s;
	s.insert({ 'A', 6 });
	s.insert({ 'C', 5 });
	s.insert({ 'B', 3 });
	string a = getPostform(st, strlen(st));
	int n = strlen(st) - getSymb(st, strlen(st));
	EXPECT_EQ(3, Calculate(a, n, s));
}