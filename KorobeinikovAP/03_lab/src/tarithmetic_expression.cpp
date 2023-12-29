#include "tarithmetic_expression.h"



//Соответственные проверки
bool TArithmeticExpression:: IsOperator(const string& op) const
{
		if ((op == "(") || (op == ")") || (op == "+") || (op == "-") || (op == "*") || (op == "/"))
		{
			return true;
		}
	return false;
}
bool TArithmeticExpression::IsConst(const string& op) const
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
bool TArithmeticExpression::IsBinaryOperator(const char& op) const
{
	return (op == '*' || op == '/' || op == '+' || op == '-');
}


//нахождение первой операции после указанной позиции (нужно для парсинга)
int TArithmeticExpression::FindFirstOperator(int pos) const
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


//приведение строки к нужному виду
void TArithmeticExpression::GetFinishedLine() {
	string expression_without_spaces;
	string finished_expression;
	for (int i = 0; i < infix.size(); ++i) {
		if (infix[i] != ' ')
			expression_without_spaces += infix[i];
	}

	if (expression_without_spaces[0] == '-')
	{
		finished_expression += "0-";
	}
	else finished_expression += expression_without_spaces[0];

	for (int i = 1; i < expression_without_spaces.size(); i++)
	{
		char t = expression_without_spaces[i];

		switch (t)
		{
		case '-':
			if (expression_without_spaces[i - 1] == '(')
			{
				finished_expression += '0';
			}

			finished_expression += '-';
			break;
		case'.':
			if (expression_without_spaces[i - 1] < '0' || expression_without_spaces[i - 1] > '9' ||
				expression_without_spaces[i + 1] < '0' || expression_without_spaces[i + 1] > '9')
			{
				throw "Incorrect expression (extra point)";
			}
			finished_expression += '.';
			break;
		case '(':
			if (expression_without_spaces[i - 1] == ')' ||
			   (expression_without_spaces[i - 1] >= '0' &&
			    expression_without_spaces[i - 1] <= '9'))
			{
				finished_expression += '*';
			}

			finished_expression += '(';
			break;
		default:
			finished_expression += t;
			break;
		} //switch
	} //for
	infix = finished_expression;
} 
	


//проверка на корректность
void TArithmeticExpression::CheckCorrect() const {
	int open_count = 0;
	int closed_count = 0;
	int point_counter = 0;
	int len = infix.size() - 1;

	if (infix[0] == '*' || infix[0] == '/' || infix[0] == '+' || infix[0] == ')' || infix[0] == '.')
		throw "Incorrest expression (first simbol isn't correct)";

	 if (infix[0] == '(')
		open_count++;

	if (IsBinaryOperator(infix[len]) || infix[len] == '('  || infix[len] == '.')
		throw "Incorrest expression (last simbol isn't correct)";

	if (infix[len] == ')')
		closed_count++;

	for (int i = 1; i < len; i++)
	{

		char t = infix[i];

		switch (t)
		{
		case '(':
			open_count++;
			break;
		case ')':
			if (IsBinaryOperator(infix[i - 1]) || infix[i - 1] == '(')
				throw "Incorrest expression (simbol beside brackets incorrect)";
			closed_count++;
			break;
		case '.':
			point_counter += 1;
			break;
		default:
			break;
		} // switch

		if (IsBinaryOperator(t))
		{
			if (point_counter > 1 || IsBinaryOperator(infix[i - 1]) || infix[i - 1] == '(')
			{
				throw "Incorrect expression (two point in one number OR two operators OR operator after bracket)";
			}
			point_counter = 0;
		}
		else
		{
			if (infix[i - 1] == ')')
			{
				throw "Incorrect expession";
			}
		}
	}
	if (open_count != closed_count || point_counter > 1)
	{
		throw "Incorrect expression (different number of brackets)";
	}
}


//парсинг (разбиение на лексемы)
void TArithmeticExpression::Parse()
{
	GetFinishedLine();
	CheckCorrect();

	int id1 = FindFirstOperator(0), id2 = FindFirstOperator(id1 + 1);
	string substring;


	//if добавление первой лексемы
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


	//добавление от второй до n-2 лексемы
	while (id2 + 1)
	{
		string substring1;
		substring = infix[id1];
		lexems.push_back(substring);

		for (int i = id1 + 1; i < id2; i++)
		{
			substring1 += infix[i];
		}

		if (!substring1.empty())
			lexems.push_back(substring1);

		id1 = id2;
		id2 = FindFirstOperator(id1 + 1);              

	}

	//добавление последней операции
	substring = infix[id1];
	lexems.push_back(substring);
	substring.clear();	

	
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



//перевод в постфиксную форму
void TArithmeticExpression::ToPostfix() {
	Parse();

	string op;
	TStack<string> stack(infix.size() + 10);

	for (string lexem : lexems)
	{
		if (lexem == "(")
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
		else if ((lexem.size() == 1) && IsBinaryOperator(lexem[0]))
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



//операнды нужно вводить самому с клаватуры, требование!
void TArithmeticExpression::SetOperand(const string& operand)
{
	string op;
	cout << "Input operand:        | " + operand + " : ";
	cin >> op;
	try
	{
		double number = stoi(op);
		operands[operand] = number;
	}
	catch (const exception& e)
	{
		throw "It's not a number: " + op + "\n";
	}
}


//вычисление
double TArithmeticExpression::Calculate() {
	TStack<double> st(infix.size() + 10);
	double op1, op2;

	for (string lexem : postfix) {

		//swutch для лексем нет, но если очень хочется switch, то можно брать бубен и танцевать с map
		if (lexem == "+")
		{

			op2 = st.Top();
			st.Pop();

			op1 = st.Top();
			st.Pop();

			st.Push(op1 + op2);
		}

		else if (lexem == "-")
		{

			op2 = st.Top();
			st.Pop();

			op1 = st.Top();
			st.Pop();

			st.Push(op1 - op2);
		}

		else if (lexem == "/")
		{

			op2 = st.Top();
			st.Pop();

			op1 = st.Top();
			st.Pop();

			if (op2 == 0) {
				throw string("Division by 0 (prohibited)");
			}
			else st.Push(op1 / op2);
		}

		else if (lexem == "*")
		{

			op2 = st.Top();
			st.Pop();

			op1 = st.Top();
			st.Pop();

			st.Push(op1 * op2);

		}

		else
		{
			if (operands.find(lexem) == operands.end())
			{
				SetOperand(lexem);
			}
			st.Push(operands[lexem]);
		}
	}
	return st.Top();
}


/*
TArithmeticExpression::TArithmeticExpression(const string& infx) {
	priority = { {"(",1}, {"-", 2}, {"+", 2}, {"*", 3}, {"/", 3} };

	ToPostfix();
}
*/

TArithmeticExpression::TArithmeticExpression(string infx,const map<string, double> operands_): infix(infx) 
{
	if (operands_ != map<string, double>() )
	{
		for (pair<string, double> elem : operands_)
		{
			operands[elem.first] = elem.second;
		}
	}

	priority = { {"(",1}, {"-", 2}, {"+", 2}, {"*", 3}, {"/", 3} };
	
	ToPostfix();
}









