#include "postfix_form.h"

bool check_Symb(char s)
{
    std::string Symb = "QqWwEeRrTtYyUuIiOoPpAaSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm";
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

std::string Convert_Oper(char s)
{
    std::string res;
    res += s;
    return res;
}

void StackToStack(ArrStack<char>& s1, ArrStack<char>& s2)
{
    while (!(s2.IsEmpty()))
    {
        s1.Push(s2.Top());
        s2.Pop();
    }
}

ArrStack<char> InfToPost(std::string inf)
{
    int l_symb = -1;
    ArrStack<char> stack_1(5);
    ArrStack<char> stack_2(5);
    std::map<char, int> priority = { {'+', 1},{'-', 1},{'*', 2},{'/', 2},{'(',0} };
    for (int i = 0; i < inf.size(); i++)
    {
        if (l_symb == -1 && check_Oper(inf[i]))
            throw std::exception("Error");
        if (l_symb == 1 && check_Oper(inf[i]))
            throw std::exception("Error");
        if (l_symb == 2 && check_Symb(inf[i]))
            throw std::exception("Error");
        if (inf[i] == '(' && l_symb == 2)
            throw::std::exception("Error");
        if (inf[i] == '(')
        {
            l_symb = 1;
            stack_2.Push(inf[i]);
        }
        if (check_Oper(inf[i]))
        {
            if (!(stack_2.IsEmpty()))
            {
                if (priority[inf[i]] < priority[stack_2.Top()])
                {
                    while ((!(stack_2.IsEmpty())) && (priority[inf[i]] < priority[stack_2.Top()]))
                    {
                        stack_1.Push(stack_2.Top());
                        stack_2.Pop();
                    }
                }
            }
            l_symb = 1;
            stack_2.Push(inf[i]);
        }
        if (check_Symb(inf[i]))
        {
            l_symb = 2;
            stack_1.Push(inf[i]);
        }
        if (inf[i] == ')')
        {
            while (stack_2.Top() != '(')
            {
                stack_1.Push(stack_2.Top());
                stack_2.Pop();
            }
            stack_2.Pop();
        }
    }
    StackToStack(stack_1, stack_2);
    stack_1.Mirror_Stack();
    return stack_1;
}

void GetValue(std::map<char, double>& variety, ArrStack<char> temp)
{
    while (!(temp.IsEmpty()))
    {
        if (!(check_Oper(temp.Top())))
        {
            if (variety.find(temp.Top()) == variety.end())
            {
                std::cout << "Enter value for " << temp.Top()<<": ";
                std::cin >> variety[temp.Top()];
            }
        }
        temp.Pop();
    }
}

double Counting(std::map<char, double>& variety, ArrStack<char>& temp)
{
    ArrStack<double> res(1);
    double a1, a2, a3;
    while (!temp.IsEmpty())
    {
        if (!check_Oper(temp.Top()))
        {
            res.Push(variety[temp.Top()]);
            temp.Pop();
        }
        else if (check_Oper(temp.Top()))
        {
            a2 = res.Top();
            res.Pop();
            a1 = res.Top();
            res.Pop();
            switch (temp.Top())
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
            }
            res.Push(a3);
            temp.Pop();
        }
    }
    return res.Top();
}