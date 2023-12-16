#include "expression.h"


bool Expression::IsOperator(const string& op) const 
{
	for (const pair<string, short>& operator_ : priority) {
		
		if (operator_.first == op) 
		{
			return true;
		}
	}
	return false;
}
bool Expression::IsConst(const string& op) const
{
	for (int i = 0; i < op.size(); i++)
		
		if (op[i] < '0' || op[i] > '9')
		{
			if (op[i] != '.')
			{
				return false;
			}
			return true;
		}
	return true;
}
bool Expression::IsArOperator(const char& op) const
{
	return (op == '*' || op == '/' || op == '+' || op == '-');
}

int Expression::FindFirstOperator(int pos) const
{
	if (pos < 0 || pos >= infix.size()) return -1;

	for (int i = pos; i < infix.size(); i++)
	{	
		string op;
		op += infix[i];

		if (IsOperator(op))
		{
			return i;
		}
	}

	return -1;
}

void Expression::Preparation()
{
	string massage = "Incorrect expression";
	string expression_without_spaces;
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] - ' ')
			expression_without_spaces += infix[i];
	}

	string expression;
	if (expression_without_spaces[0] == '-') 
	{
		expression += "0-";
	}
	else if (expression_without_spaces[0] == '.')
	{
		throw massage;
	}
	else expression += expression_without_spaces[0];


	if (expression_without_spaces[expression_without_spaces.size() - 1] == '.')
	{
		throw massage;
	}

	


	for (int i = 1; i < expression_without_spaces.size(); i++) 
	{
		char t = expression_without_spaces[i];

		if (t == '-') 
		{
			
			if (expression_without_spaces[i - 1] == '(')
			{
				expression += '0';
			}
			
			expression += '-';
		}
		else if (t == '.') 
		{
			if (expression_without_spaces[i - 1] < '0' || expression_without_spaces[i - 1] > '9' ||
				expression_without_spaces[i + 1] < '0' || expression_without_spaces[i + 1] > '9')
			{
				throw massage;
			}

			expression += '.';
		}
		else if (t == '(') 
		{
			
			if (expression_without_spaces[i - 1] == ')' || (expression_without_spaces[i - 1] >= '0' && expression_without_spaces[i - 1] <= '9'))
			{
				expression += '*';
			}
			
			expression += '(';
		
		}
		else
		{
			expression += t;
		}
	}
	
	infix = expression;
}

void Expression::IsCorrect() const
{
	int open_count = 0;
	int closed_count = 0;
	int dots_count = 0;
	int len = infix.size() - 1;
	string massage = "Incorrect expression";

	if (infix[0] == '*' || infix[0] == '/' || infix[0] == '+' || infix[0] == ')')
	{
		throw massage;
	}
	else if (infix[0] == '(')
	{
		open_count++;
	}

	if (IsArOperator(infix[len]) || infix[len] == '(')
	{
		throw massage;
	}
	else if (infix[len] == ')')
	{
		closed_count++;
	}
	
	for (int i = 1; i < len; i++) 
	{
		
		char t = infix[i];
		
		if (t == '(')
		{
			open_count++;
		}
		else if (t == ')') 
		{			
			if (IsArOperator(infix[i-1]) || infix[i - 1] == '(')
			{
				throw massage;
			}
			
			
			closed_count++;
		}
		
		else if (t == '.')
		{
			dots_count++;
		}
		else if (IsArOperator(t)) 
		{
			if (dots_count > 1 || IsArOperator(infix[i-1]) || infix[i - 1] == '(')
			{
				throw massage;
			}
			dots_count = 0;
		}
		else
		{
			if (infix[i - 1] == ')')
			{
				//  ") A" 
				throw massage;
			}
		}
	}
	if (open_count != closed_count || dots_count > 1)
	{
		throw massage;
	}
}

void Expression::Parse()
{
	Preparation();
	IsCorrect();

	int id1 = FindFirstOperator(), id2 = FindFirstOperator(id1 + 1);
	string substring;

	if (id1 == -1) {
		lexems.push_back(infix);
		return;
	}
	else
	{
		for (int i = 0; i < id1; i++)
		{
			substring += infix[i];
		}
		if (substring.size())
		{
			lexems.push_back(substring);
		}
	}

	while (id2 + 1) 
	{
		string substring1;
		substring = infix[id1];
		lexems.push_back(substring);
		
		for (int i = id1+1; i < id2 ; i++)
		{
			substring1 += infix[i];
		}

		if (!substring1.empty())
			lexems.push_back(substring1);

		id1 = id2;
		id2 = FindFirstOperator(id1 + 1);
	
	}

	substring = infix[id1];
	lexems.push_back(substring);
	substring.clear();

	for (int i = id1; i < infix.size(); i++)
	{
		substring += infix[i];
	}

	if (id1 != infix.size() - 1)
	{
		substring = infix[id1 + 1];
		for (int i = id1 + 2; i < infix.size(); i++)
		{
			substring += infix[i];
		}
		lexems.push_back(substring);
	}
}

void Expression::Convert() 
{
	Parse();

	string op;
	TStack<string> stack(infix.size()+10);

	for (string lexem : lexems) 
	{
		if ((lexem.size() == 1) && IsArOperator(lexem[0]))
		{
			while (!stack.IsEmpty())
			{

				op = stack.Top();
				stack.Pop();
				if (priority[op] >= priority[lexem])
				{
					postfix.push_back(op);
				}
				else
				{
					stack.Push(op);
					break;
				}
			}

			stack.Push(lexem);

		}
		else if (lexem == "(")
		{
			stack.Push(lexem);
		}
		else if (lexem == ")")
		{
			op = stack.Top();
			stack.Pop();

			while (op != "(") 
			{
				postfix.push_back(op);
				op = stack.Top();
				stack.Pop();
			}
		}
		else
		{
			double value = 0.0;
			if (IsConst(lexem))
			{
				value = stod(lexem);
				operands[lexem] = value;
			}
			postfix.push_back(lexem);
		}
	}
	while (!stack.IsEmpty()) {
		op = stack.Top();
		stack.Pop();
		postfix.push_back(op);
	}
}

string Expression::GetPostfix() const
{
	string string_postfix = postfix[0];
	for (int i = 1; i < postfix.size(); i++) string_postfix += postfix[i];
	return string_postfix;
}

void Expression::Calculate()
{
	
	TStack<double> stack(infix.size()+10);
	double op1, op2;

	for (string lexem : postfix) {

		if (lexem == "+") 
		{

			op2 = stack.Top();
			stack.Pop();
			
			op1 = stack.Top();
			stack.Pop();
			
			stack.Push(op1 + op2);
		}

		else if (lexem == "-")
		{
			
			op2 = stack.Top();
			stack.Pop();
			
			op1 = stack.Top();
			stack.Pop();
			
			stack.Push(op1 - op2);
		}
		
		else if (lexem == "/")
		{
			
			op2 = stack.Top();
			stack.Pop();
			
			op1 = stack.Top();
			stack.Pop();
			
			if (op2 == 0) {
				throw "Division by 0";
			}
			else stack.Push(op1 / op2);
		}
		
		else if (lexem == "*")
		{
			
			op2 = stack.Top();
			stack.Pop();

			op1 = stack.Top();
			stack.Pop();
			
			stack.Push(op1 * op2);

		}
		
		else
		{
			if (operands.find(lexem) == operands.end())
			{
				throw "Wrong list of operands";
			}
			stack.Push( operands[lexem] );
		}
	}

	res = stack.Top();

}

Expression::Expression(const string& expression, const map<string, double> operands_) 
{
	if (operands_ != map<string, double>::map())
	{
		for (pair<string, double> elems : operands_)
		{
			operands[elems.first] = elems.second;
		}
	}
	if (expression.empty())
	{
		throw "Expression can`t be empty";
	}
	infix = expression;
	priority = {
	{"(", 1}, {")", 1},
	{"+", 2}, {"-", 2},
	{"*", 3}, {"/", 3}
	};

	Convert();
	Calculate();
}
