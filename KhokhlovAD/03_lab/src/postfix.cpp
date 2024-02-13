#include <postfix.h>

TPostfix::TPostfix(const string& infx) {
	if (infx == "")
		throw std::exception("empty infix");
	infix = infx;
	std::string::iterator end_pos = std::remove(infix.begin(), infix.end(), ' ');
	infix.erase(end_pos, infix.end());
	priority = { {"*", 3}, {"/", 3}, 
		{"+", 2}, {"-", 2}, 
		{"(", 1}, {"=", 0}};
	ToPostfix();
	setOperands();
}

void TPostfix::Parse() {
	for (char c : infix)
		lexems.push_back(c);
}

string TPostfix::GetPostfix()const 
{
	string tmp="";
	for (int i = 0; i < postfix.size(); i++)
	{
		tmp += postfix[i];
	}
	return tmp;
}

void TPostfix::PrintInfix() 
{
	std::cout << infix;
}
void TPostfix::PrintPostfix()
{
	std::cout << GetPostfix();
}

bool TPostfix::IsCorrect()const
{
	return IsCorrectOperands() && IsCorrectOperator() && !IncorrectSybol();
}

bool TPostfix::IsOperator(int ind)const
{
	if ( lexems[ind] == '*' || lexems[ind] == '/' || 
		lexems[ind] == '+' || lexems[ind] == '-' )
		return true;
	return false;
}


bool TPostfix::IsCorrectOperands()const
{
	int flag=0;
	int ind = 0;
	while (ind < lexems.size() - 1)
	{
		if (lexems[ind] == ')' && !IsOperator(ind + 1))
			return false;
		if (lexems[ind] == '(' && IsOperator(ind + 1))
			return false;
		if(IsOperator(ind) || lexems[ind] == '(' || lexems[ind] == ')')
			ind++;
		if(lexems[ind] == '.' && IsOperator(ind +1))
			return false;
		int flag = 0;
		while(isdigit(lexems[ind]) || lexems[ind]=='.')
		{
			ind++;
			if (ind >= lexems.size())
				break;
			if (lexems[ind ] == '.')
			{
				flag++;
			}
			if (isalpha(lexems[ind]))
				return false;
		}
		if (flag > 1)
			return false;
		if (ind >= lexems.size())
			break;
		while(isalpha(lexems[ind]) && !lexems[ind] != '(' && !lexems[ind] != ')')
		{
			if (ind >= lexems.size() - 1)
				break;
			if (isdigit(lexems[ind+1]) || (lexems[ind + 1] == '.'))
				return false;
			
			ind++;
		}   
	}
	return true;
}

bool TPostfix::IsCorrectOperator()const
{
	TStack<char> brackets;
	int flag = 0;
	for (char i : lexems)
	{
		switch (i) 
		{
		case '(': 
		{
			brackets.push('('); 
			flag++; break; 
		}
		case ')': 
		{
		if (flag == 0)
			return false;
		if (brackets.isEmpty()) 
			return false;
		brackets.Pop();
		flag++;
		break;
		}
		case '*': case '/': case '+': case '-': case ',':
		{
			if (flag == 0 || flag == lexems.size()-1)
				return false;
			if (IsOperator(flag - 1) || IsOperator(flag+1) || 
				lexems[flag-1] == '.' || lexems[flag+1] == '.'
				|| lexems[flag+1] == ')' || lexems[flag - 1] == '(')
				return false;
			flag++; 
			break;
		}
		default: {flag++; break; }
		}
	}
	if (!brackets.isEmpty())
		return false;

	return true;
}

bool TPostfix::IncorrectSybol()const 
{
	for (int i = 0; i < lexems.size(); i++)
		if (!IsOperator(i) && !isdigit(lexems[i]) && 
			!isalpha(lexems[i]) && lexems[i] != '.' && 
			lexems[i] != '(' && lexems[i] != ')')
			return true;
	return false;
}

void TPostfix::ToPostfix()
{
	Parse();
	if (!IsCorrect())
	{
		throw std::exception("invalid infix");
	}
	TStack<string> st2(lexems.size());
	int i = 0;
	while (i < lexems.size())
	{
		string tmp;
		switch (lexems[i])
		{
		case '(':
		{
			tmp = lexems[i];
			st2.push(tmp);
			i++;
			break;
		}
		case ')':
		{
			while (st2.Top() != "(")
			{
				postfix.push_back(st2.Pop());
			}
			st2.Pop();
			i++;
			break;
		}
		case '+': case '-': case '*': case '/':
		{
			int flag = 0;
			tmp = lexems[i];
			if (!st2.isEmpty())
				while (flag == 0)
				{
					if (priority[st2.Top()] >= priority[tmp])
					{
						postfix.push_back(st2.Pop());
						if (st2.isEmpty())
							break;
					}
					else if (isalpha(lexems[i]) || isdigit(lexems[i]))
						flag++;
					else
						flag++;
				}
			st2.push(tmp);
			i++;
			break;
		}
		default:
		{
			string operand = "";
			int flag = 0;
			while (isdigit(lexems[i]))
			{
				operand += lexems[i];
				i++;
				if (i >= lexems.size() - 1)
					break;
				if(lexems[i] == '.' || isdigit(lexems[i]))
				{
					operand += lexems[i];
					i++;
				}
			}
			if (operand != "")
			{
				postfix.push_back(operand);
				operands.insert({ operand, stod(operand) });
				break;
			}
			else
			{
				while (isalpha(lexems[i]))
				{
					operand += lexems[i];
					i++;
					if (i >= lexems.size())
						break;
				}
				postfix.push_back(operand);
				if (operands.find(operand) != operands.end())
					operands.insert({ operand, 0.0 }); 
			}
			break;
		}
		}
	}
	while (!st2.isEmpty())
	{
		postfix.push_back(st2.Pop());    
	}
}

void TPostfix::setOperands()
{
	double b;
	for (auto it = operands.begin(); it != operands.end(); it++)
	{
		if (it->second == 0.0)
		{
			cout << it->first << " = ";
			cin >> b;
			operands[it->first] = b;
			cout << endl;
		}
	}
}


double TPostfix::Calculate()
{
	int i = 0;
	TStack<double> st(postfix.size());
	while (i < postfix.size())
	{
		bool flag = true;
		if (postfix[i] == "+")
		{
			double b = st.Pop(), a = st.Pop();
			st.push(a + b);
			i++;
			flag = false;
			continue;
		}
		if (postfix[i] == "*")
		{
			double b = st.Pop(), a = st.Pop();
			st.push(a * b);
			i++;
			flag = false;
			continue;
		}
		if (postfix[i] == "-")
		{
			double b = st.Pop(), a = st.Pop();
			st.push(a - b);
			i++;
			flag = false;
			continue;
		}
		if (postfix[i] == "/")
		{
			double b = st.Pop(), a = st.Pop();
			if (b <= 0.000000001) throw std::exception("Division by zero");
			st.push(a / b);
			i++;
			flag = false;
			continue;
		}
		if (flag)
		{
			st.push(operands[postfix[i]]);
			i++;
		}
	}
	return st.Pop();
}
