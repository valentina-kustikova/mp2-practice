#include "postfix_form.h"
using namespace posfix_form;

bool check_Symb(char s) //
{
    return((s >= 65 && s <= 90) || s == 95 || (s >= 97 && s <= 122));
}

bool check_Numb(char s) //
{
    return(s >= 48 && s <= 57);
}

bool check_Oper(char s) //
{   
    return (s == '+' || s == '-' || s == '*' || s == '/');
}

void StackToStack(Stack<std::string>& s1, Stack<std::string>& s2)
{
    while (!(s2.IsEmpty()))
    {
        s1.Push(s2.Top());
        s2.Pop();
    }
}
template <typename T>
void ChoseStack(Stack<T>*& s, STACK_IMPL impl)
{
    switch (impl)
    {
    case 0:
        s = new ArrStack<T>;
        break;
    case 1:
        s = new ListStack<T>;
        break;
    }
}

void Check_Start(int& l_symb, char inf, std::string& var, Stack<std::string>* &stack_1, Stack<std::string>* &stack_2)
{
    if (check_Symb(inf))
    {
        var += inf;
        l_symb = 2;
    }
    else if (check_Numb(inf))
    {
        var += inf;
        l_symb = 3;
    }
    else if (inf == '-')
    {
        var += '!';
        stack_2->Push(var);
        var.clear();
        l_symb = 0;
    }
    else if (inf == '(')
    {
        var += inf;
        l_symb = -1;
        stack_2->Push(var);
        var.clear();
    }
    else
    {
        throw std::exception("Error: incorrect infix form");
    }
}

void Check_After_Minus(int& l_symb, char inf, std::string& var, Stack<std::string>*& stack_1, Stack<std::string>*& stack_2)
{
    if (check_Symb(inf))
    {
        var += inf;
        l_symb = 2;
    }
    else if (check_Numb(inf))
    {
        var += inf;
        l_symb = 3;
    }
    else if (inf == '(')
    {
        l_symb = -1;
        var += inf;
        stack_2->Push(var);
        var.clear();
    }
    else
    {
        throw std::exception("Error: incorrect infix form");
    }
}

void Check_After_Oper(int& l_symb, char inf, std::string& var, Stack<std::string>*& stack_1, Stack<std::string>*& stack_2)
{
    if (check_Symb(inf))
    {
        var += inf;
        l_symb = 2;
    }
    else if (check_Numb(inf))
    {
        var += inf;
        l_symb = 3;
    }
    else if (inf == '(')
    {
        var += inf;
        l_symb = -1;
        stack_2->Push(var);
        var.clear();
    }
    else if (inf == '-')
    {
        var += '!';
        l_symb = 0;
        stack_2->Push(var);
        var.clear();
    }
    else
    {
        throw std::exception("Error: incorrect infix form");
    }
}

void Check_After_Symb(int& l_symb, char inf, std::map<std::string, int> priority_s, std::string& var, Stack<std::string>*& stack_1, Stack<std::string>*& stack_2)
{
    if (check_Symb(inf) || check_Numb(inf))
    {
        var += inf;
        l_symb = 2;
    }
    else if (check_Oper(inf))
    {
        stack_1->Push(var);
        var.clear();
        Oper_After(l_symb, inf, priority_s, var, stack_1, stack_2);
    }
    else if (inf == ')')
    {
        stack_1->Push(var);
        var.clear();
        Right_Br_After(l_symb, inf, priority_s, var, stack_1, stack_2);
    }
    else
        throw std::exception("Error: incorrect infix form");
}

void Check_After_Numb(int& l_symb, char inf, std::map<std::string, int> priority_s, std::string& var, Stack<std::string>*& stack_1, Stack<std::string>*& stack_2)
{
    if (check_Numb(inf))
    {
        var += inf;
        l_symb = 3;
    }
    else if (check_Oper(inf))
    {
        stack_1->Push(var);
        var.clear();
        Oper_After(l_symb, inf, priority_s, var, stack_1, stack_2);
    }
    else if (inf == ')')
    {
        stack_1->Push(var);
        var.clear();
        Right_Br_After(l_symb, inf, priority_s, var, stack_1, stack_2);
    }
    else
        throw std::exception("Error: incorrect infix form");
}

void Check_After_Right_Br(int& l_symb, char inf, std::map<std::string, int> priority_s, std::string& var, Stack<std::string>*& stack_1, Stack<std::string>*& stack_2)
{
    if (check_Oper(inf))
    {
    Oper_After(l_symb, inf, priority_s, var, stack_1, stack_2);
    }
    else if (inf == ')')
    {
    Right_Br_After(l_symb, inf, priority_s, var, stack_1, stack_2);
    }
    else
    throw std::exception("Error: incorrect infix form");
}

void Oper_After(int& l_symb, char inf, std::map<std::string, int> priority_s, std::string& var, Stack<std::string>*& stack_1, Stack<std::string>*& stack_2)
{
    var += inf;
    if ((!(stack_2->IsEmpty())) && (priority_s[stack_2->Top()] > priority_s[var]))
    {
        while ((!(stack_2->IsEmpty())) && (priority_s[stack_2->Top()] > priority_s[var]))
        {
            stack_1->Push(stack_2->Top());
            stack_2->Pop();
        }
    }
    stack_2->Push(var);
    var.clear();
    l_symb = 1;
}

void Right_Br_After(int& l_symb, char inf, std::map<std::string, int> priority_s, std::string& var, Stack<std::string>*& stack_1, Stack<std::string>*& stack_2)
{
    while (!(stack_2->IsEmpty()) && stack_2->Top() != "(")
    {
        stack_1->Push(stack_2->Top());
        stack_2->Pop();
    }
    if (stack_2->IsEmpty())
        throw std::exception("Error incorect infix form");
    stack_2->Pop();
    l_symb = 4;
}


ArExpression::ArExpression(const std::string& inf, STACK_IMPL impl):infix(inf), impl(impl) //
{
    int l_symb = -1;
    Stack<std::string> *stack_2;
    ChoseStack(postfix,impl);
    ChoseStack(stack_2, impl);
    std::string var;
    int flag;
    for (int i = 0; i < inf.size(); i++)
    {
        flag = l_symb;            //-1 начало или'(',0-'-', как взятие обратного значения, 1- операция, 2-переменная,
        switch (flag)             // 3- константа, 4-')'
        {
        case -1:
            Check_Start(l_symb, inf[i], var, postfix, stack_2);
            break;
        case 0:
            Check_After_Minus(l_symb, inf[i], var, postfix, stack_2);
            break;
        case 1:
            Check_After_Oper(l_symb, inf[i], var, postfix, stack_2);
            break;
        case 2:
            Check_After_Symb(l_symb, inf[i], priority_s, var, postfix, stack_2);
            break;
        case 3:
            Check_After_Numb(l_symb, inf[i], priority_s, var, postfix, stack_2);
            break;
        case 4:
            Check_After_Right_Br(l_symb, inf[i], priority_s, var, postfix, stack_2);
            break;
        }
        if (i == (inf.size() - 1))
        {
            if (l_symb == -1)
                throw std::exception("Error: Empty infex form or empty after '('");
            if (l_symb == 0 || l_symb == 1)
                throw std::exception("Incorrect infex form");
            if (l_symb == 2 || l_symb == 3)
            {
                postfix->Push(var);
                var.clear();
            }
        }
    }
    StackToStack(*postfix, *stack_2);
}

void  ArExpression::GetVariable()//
{
    Stack<std::string> *temp;
    ChoseStack(temp, impl);
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
        temp->Push(postfix->Top());
        postfix->Pop();
    }
    postfix = temp;
}

void Chose_Oper(char oper,Stack<double>*& res)
{
    double a1, a2, a3;
    if (oper == '!')
    {
        a1 = res->Top();
        res->Pop();
        a3 = -a1;
    }
    else
    {
        a2 = res->Top();
        res->Pop();
        a1 = res->Top();
        res->Pop();
        switch (oper)
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
    }
    res->Push(a3);
}

double ArExpression::Calculate()//
{
    res;
    ChoseStack(res, impl);
    while (!(postfix->IsEmpty()))
    {
        if (!(check_Oper(postfix->Top()[0])||postfix->Top()[0]=='!'))
        {
            res->Push(var[postfix->Top()]);
        }
        else
        {
            Chose_Oper(postfix->Top()[0], res);
        }
        postfix->Pop();
    }
    return res->Top();
}