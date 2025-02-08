#include "postfix_form.h"
#include <gtest.h>

TEST(Postfix_Form, can_fill_const_correct)
{
	string str = "A+";
	vector<string> consts = fill_const(str);
	EXPECT_EQ("A", consts[0]);
}

TEST(Postfix_Form, can_check_priority)
{
	string elem = "*", elem2= "-";
	EXPECT_TRUE(priority(elem, elem2));
}

TEST(Postfix_Form, can_correct_read_str)
{
	vector<string> v = read("A+B");
	EXPECT_EQ("A+B", v[0]+ v[1]+ v[2]);
}

TEST(Postfix_Form, can_create_correct_expession_on_array)
{
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TStackArray <string>(5);
	stack2 = new TStackArray <string>(10);

	vector<string> v = read("A+B");
	expression(stack1, stack2, v);
	string str;
	str = stack2->Top();
	stack2->Pop();
	str += stack2->Top();
	stack2->Pop();
	str += stack2->Top();
	EXPECT_EQ("AB+", str);
}

TEST(Postfix_Form, can_create_correct_expession_on_list)
{
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TListStack <string>();
	stack2 = new TListStack <string>();

	vector<string> v = read("A+B");
	expression(stack1, stack2, v);
	string str;
	str = stack2->Top();
	stack2->Pop();
	str += stack2->Top();
	stack2->Pop();
	str += stack2->Top();
	EXPECT_EQ("AB+", str);
}

TEST(Postfix_Form, can_correct_calculate_light_list)
{
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TListStack <string>();
	stack2 = new TListStack <string>();

	vector<string> v = read("A+B");
	expression(stack1, stack2, v);
	map<string, double> var;
	var["A"] = 1; var["B"] = 1;
	EXPECT_EQ(2,calculate(stack1,stack2,var));
}

TEST(Postfix_Form, can_correct_calculate_hard_list)
{
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TListStack <string>();
	stack2 = new TListStack <string>();

	vector<string> v = read("Aa+B/A*(B-A)*A");
	expression(stack1, stack2, v);
	map<string, double> var;
	var["A"] = 1; var["B"] = 1; var["Aa"] = 10;
	EXPECT_EQ(10, calculate(stack1, stack2, var));
}

TEST(Postfix_Form, can_correct_calculate_light_arr)
{
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TStackArray <string>(5);
	stack2 = new TStackArray <string>(10);

	vector<string> v = read("A+B*A");
	expression(stack1, stack2, v);
	map<string, double> var;
	var["A"] = 1; var["B"] = 1;
	EXPECT_EQ(2, calculate(stack1, stack2, var));
}

TEST(Postfix_Form, can_correct_calculate_hard_arr)
{
	TStack<string>* stack1;
	TStack<string>* stack2;

	stack1 = new TStackArray <string>(5);
	stack2 = new TStackArray <string>(10);

	vector<string> v = read("A+B*(A+A)/B+(B*Cc)");
	expression(stack1, stack2, v);
	map<string, double> var;
	var["A"] = 1; var["B"] = 1; var["Cc"] = 10;
	EXPECT_EQ(13, calculate(stack1, stack2, var));
}

