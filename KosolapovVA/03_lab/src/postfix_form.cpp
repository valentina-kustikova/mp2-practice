#include "postfix_form.h"
using namespace posfix_form;

bool check_Symb(char s)
{
    std::string Symb = "QqWwEeRrTtYyUuIiOoPpAaSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm_";
    for (int i = 0; i < Symb.length(); i++)
    {
        if (s == Symb[i])
            return 1;
    }
    return 0;
}

bool check_Numb(char s)
{
    std::string Numb = "1234567890";
    for (int i = 0; i < Numb.length(); i++)
    {
        if (s == Numb[i])
            return 1;
    }
    return 0;
}

bool check_Oper(char s)
{
    std::string Oper = "+-*/";
    for (int i = 0; i < Oper.length(); i++)
    {
        if (s == Oper[i])
            return 1;
    }
    return 0;
}

void StackToStack(Stack<std::string>& s1, Stack<std::string>& s2)
{
    while (!(s2.IsEmpty()))
    {
        s1.Push(s2.Top());
        s2.Pop();
    }
}

ArExpression::ArExpression(const std::string& inf, STACK_IMPL impl):infix(inf), impl(impl)
{
    if (impl == 0)
    {
        int l_symb = -1;
        ArrStack<std::string> stack_1(5);
        ArrStack<std::string> stack_2(5);
        std::map<std::string, int> priority_s = { { "+", 1},{"-", 2},{"!",2},{"*", 3},{"/", 4},{"(",0} };
        std::string var;
        int flag;
        for (int i = 0; i < inf.size(); i++)
        {
            flag = l_symb;            //-1 начало или'(',0-'-', как взятие обратного значения, 1- операция, 2-переменная,
            switch (flag)             // 3- константа, 4-')'
            {
            case -1:
                
                if (check_Symb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (inf[i] == '-')
                {
                    var += '!';
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 0;
                }
                else if (inf[i] == '(')
                {
                    var += inf[i];
                    l_symb = -1;
                    stack_2.Push(var);
                    var.clear();
                }
                else
                {
                    throw std::exception("Error: incorrect infix form");
                }
                break;
            case 0:
                if (check_Symb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (inf[i] == '(')
                {
                    l_symb = -1;
                    var += inf[i];
                    stack_2.Push(var);
                    var.clear();
                }
                else
                {
                    throw std::exception("Error: incorrect infix form");
                }
                break;
            case 1:
                if (check_Symb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (inf[i] == '(')
                {
                    var += inf[i];
                    l_symb = -1;
                    stack_2.Push(var);
                    var.clear();
                }
                else if (inf[i] == '-')
                {
                    var += '!';
                    l_symb = 0;
                    stack_2.Push(var);
                    var.clear();
                }
                else
                {
                    throw std::exception("Error: incorrect infix form");
                }
                break;
            case 2:
                if (check_Symb(inf[i])|| check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Oper(inf[i]))
                {
                    stack_1.Push(var);
                    var.clear();
                    var += inf[i];
                    if (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                    {
                        while (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                        {
                            stack_1.Push(stack_2.Top());
                            stack_2.Pop();
                        }
                    }
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 1;
                }
                else if (inf[i] == ')')
                {
                    stack_1.Push(var);
                    var.clear();
                    while (!(stack_2.IsEmpty()) && stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                    if (stack_2.IsEmpty())
                        throw std::exception("Error incorect infix form");
                    stack_2.Pop();
                    l_symb = 4;
                }
                else
                    throw std::exception("Error: incorrect infix form");
                break;
            case 3:
                if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (check_Oper(inf[i]))
                {
                    stack_1.Push(var);
                    var.clear();
                    var += inf[i];
                    if ((!(stack_2.IsEmpty())) && (priority_s[stack_2.Top()] > priority_s[var]))
                    {
                        while ((!(stack_2.IsEmpty())) && (priority_s[stack_2.Top()] > priority_s[var]))
                        {
                            stack_1.Push(stack_2.Top());
                            stack_2.Pop();
                        }
                    }
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 1;
                }
                else if (inf[i] == ')')
                {
                    stack_1.Push(var);
                    var.clear();
                    while (!(stack_2.IsEmpty()) && stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                    if (stack_2.IsEmpty())
                        throw std::exception("Error incorect infix form");
                    stack_2.Pop();
                    l_symb = 4;
                }
                else
                    throw std::exception("Error: incorrect infix form");
                break;
            case 4:
                if (check_Oper(inf[i]))
                {
                    stack_1.Push(var);
                    var.clear();
                    var += inf[i];
                    if (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                    {
                        while (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                        {
                            stack_1.Push(stack_2.Top());
                            stack_2.Pop();
                        }
                    }
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 1;
                }
                else if (inf[i] == ')')
                {
                    stack_1.Push(var);
                    var.clear();
                    while (!(stack_2.IsEmpty())&&stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                    if (stack_2.IsEmpty())
                        throw std::exception("Error incorect infix form");
                    stack_2.Pop();
                    l_symb = 4;
                }
                else
                    throw std::exception("Error: incorrect infix form");
                break;          
            }
            if (i == (inf.size() - 1))
            {
                if (l_symb == -1)
                    throw std::exception("Error: Empty infex form or emty after (");
                if (l_symb == 0 || l_symb == 1)
                    throw std::exception("Incorrect infex form");
                if (l_symb == 2 || l_symb == 3)
                {
                    stack_1.Push(var);
                    var.clear();
                }                
            }
        }
        StackToStack(stack_1, stack_2);
        stack_1.Mirror_Stack();
        postfix = new ArrStack<std::string>(stack_1);
    }
    if (impl == 1)
    {
        int l_symb = -1;
        ArrStack<std::string> stack_1(5);
        ArrStack<std::string> stack_2(5);
        std::map<std::string, int> priority_s = { { "+", 0},{"-", 1},{"!",1},{"*", 2},{"/", 3},{"(",4} };
        std::string var;
        int flag;
        for (int i = 0; i < inf.size(); i++)
        {
            flag = l_symb;            //-1 начало или'(',0-'-', как взятие обратного значения, 1- операция, 2-переменная,
            switch (flag)             // 3- константа, 4-')'
            {
            case -1:

                if (check_Symb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (inf[i] == '-')
                {
                    var += '!';
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 0;
                }
                else if (inf[i] == '(')
                {
                    var += inf[i];
                    l_symb = -1;
                    stack_2.Push(var);
                    var.clear();
                }
                else
                {
                    throw std::exception("Error: incorrect infix form");
                }
                break;
            case 0:
                if (check_Symb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (inf[i] == '(')
                {
                    l_symb = -1;
                    var += inf[i];
                    stack_2.Push(var);
                    var.clear();
                }
                else
                {
                    throw std::exception("Error: incorrect infix form");
                }
                break;
            case 1:
                if (check_Symb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (inf[i] == '(')
                {
                    var += inf[i];
                    l_symb = -1;
                    stack_2.Push(var);
                    var.clear();
                }
                else if (inf[i] == '-')
                {
                    var += '!';
                    l_symb = 0;
                    stack_2.Push(var);
                    var.clear();
                }
                else
                {
                    throw std::exception("Error: incorrect infix form");
                }
                break;
            case 2:
                if (check_Symb(inf[i]) || check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 2;
                }
                else if (check_Oper(inf[i]))
                {
                    stack_1.Push(var);
                    var.clear();
                    var += inf[i];
                    if (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                    {
                        while (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                        {
                            stack_1.Push(stack_2.Top());
                            stack_2.Pop();
                        }
                    }
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 1;
                }
                else if (inf[i] == ')')
                {
                    stack_1.Push(var);
                    var.clear();
                    while (!(stack_2.IsEmpty()) && stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                    if (stack_2.IsEmpty())
                        throw std::exception("Error incorect infix form");
                    stack_2.Pop();
                    l_symb = 4;
                }
                else
                    throw std::exception("Error: incorrect infix form");
                break;
            case 3:
                if (check_Numb(inf[i]))
                {
                    var += inf[i];
                    l_symb = 3;
                }
                else if (check_Oper(inf[i]))
                {
                    stack_1.Push(var);
                    var.clear();
                    var += inf[i];
                    if (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                    {
                        while (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                        {
                            stack_1.Push(stack_2.Top());
                            stack_2.Pop();
                        }
                    }
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 1;
                }
                else if (inf[i] == ')')
                {
                    stack_1.Push(var);
                    var.clear();
                    while (!(stack_2.IsEmpty()) && stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                    if (stack_2.IsEmpty())
                        throw std::exception("Error incorect infix form");
                    stack_2.Pop();
                    l_symb = 4;
                }
                else
                    throw std::exception("Error: incorrect infix form");
                break;
            case 4:
                if (check_Oper(inf[i]))
                {
                    stack_1.Push(var);
                    var.clear();
                    var += inf[i];
                    if (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                    {
                        while (!(stack_2.IsEmpty()) && (priority_s[stack_2.Top()] > priority_s[var]))
                        {
                            stack_1.Push(stack_2.Top());
                            stack_2.Pop();
                        }
                    }
                    stack_2.Push(var);
                    var.clear();
                    l_symb = 1;
                }
                else if (inf[i] == ')')
                {
                    stack_1.Push(var);
                    var.clear();
                    while (!(stack_2.IsEmpty()) && stack_2.Top() != "(")
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                    if (stack_2.IsEmpty())
                        throw std::exception("Error incorect infix form");
                    stack_2.Pop();
                    l_symb = 4;
                }
                else
                    throw std::exception("Error: incorrect infix form");
                break;
            }
            if (i == (inf.size() - 1))
            {
                if (l_symb == -1)
                    throw std::exception("Error: Empty infex form or emty after (");
                if (l_symb == 0 || l_symb == 1)
                    throw std::exception("Incorrect infex form");
                if (l_symb == 2 || l_symb == 3)
                {
                    stack_1.Push(var);
                    var.clear();
                }
            }
        }
        StackToStack(stack_1, stack_2);
        stack_1.Mirror_Stack();
        std::cout << "Complete\n";
        stack_1.Print();
        *postfix = stack_1;
    }
}

void  ArExpression::GetValue()
{
    if (impl == 0)
    {
        ArrStack<std::string> temp(5);
        while (!(postfix->IsEmpty()))
        {
            if (!(check_Oper(postfix->Top()[0])))
            {
                if (check_Numb(postfix->Top()[0]))
                {
                    if (var.find(postfix->Top()) == var.end())
                    {
                        var[postfix->Top()] = std::stod(postfix->Top());
                    }
                }
                if (check_Symb(postfix->Top()[0]))
                {
                    if (var.find(postfix->Top()) == var.end())
                    {
                        std::cout << "Enter value for " << postfix->Top() << ": ";
                        std::cin >> var[postfix->Top()];
                    }
                }
            }
            temp.Push(postfix->Top());
            postfix->Pop();           
        }
        temp.Mirror_Stack();
        postfix = new ArrStack<std::string>(temp);
    }
    if (impl == 1)
    {
        //ListStack<std::string> temp;
    }
}

double ArExpression::Calculate()
{
    ArrStack<double> res(1);
    double a1, a2, a3;
    while (!(postfix->IsEmpty()))
    {
        if (!check_Oper(postfix->Top()[0]))
        {
            res.Push(var[postfix->Top()]);
            postfix->Pop();
        }
        else
        {
            a2 = res.Top();
            res.Pop();
            a1 = res.Top();
            res.Pop();
            switch (postfix->Top()[0])
            {
            case '+':
                a3 = a1 + a2;
                break;
            case '-':
                a3 = a1 - a2;
                break;
            case '*':
                a3 = a1 * a2;
                break;
            case '/':
                a3 = a1 / a2;
                break;
            case '!':
                a3 = 0.0 - a2;
                break;
            }
            res.Push(a3);
            postfix->Pop();
        }
    }
    return res.Top();
}