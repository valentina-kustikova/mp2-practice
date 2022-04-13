#include "../include/polinom.h"
using namespace std;

void Polinom::str_to_poly(const std::string& input)
{
    parser(input);
    if (isCorrect())
        converter();
    else
        throw std::exception("Error!");
}
bool Polinom::isCorrect() const
{
    return check_points() && check_vars();
}

bool Polinom::check_vars() const
{
    for (size_t i = 0; i < Lexs.size(); i++)
    {
        size_t pX = Lexs[i].find_first_of('x');
        pX = Lexs[i].find_first_of('x', pX + 1);
        size_t pY = Lexs[i].find_first_of('y');
        pY = Lexs[i].find_first_of('y', pY + 1);
        size_t pZ = Lexs[i].find_first_of('z');
        pZ = Lexs[i].find_first_of('z', pZ + 1);
        if (pX != Lexs[i].npos || pY != Lexs[i].npos || pZ != Lexs[i].npos)
            return false;
    }
    return true;
}

bool Polinom::check_points() const
{
    for (size_t i = 0; i < Lexs.size(); i++)
    {
        size_t p = Lexs[i].find_first_of('.');
        p = Lexs[i].find_first_of('.', p + 1);
        if (p != Lexs[i].npos)
            return false;
    }
    return true;
}

void Polinom::parser(const std::string& input)
{

    Lexs.clear();
    int state = 0;
    std::string lexema;

    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {
            char current = input[i];

            switch (state)
            {
            case 0: {
                if (current == '+' || current == '-')
                    state = 1;
                else if (std::isdigit(current) || current == '.')
                    state = 2;
                else if (current == 'x' || current == 'y' || current == 'z')
                    state = 3;
                else
                    throw "Wrong symbol";
                lexema.append(1, current);
                break;
            }
            case 1: {
                if (std::isdigit(current) || current == '.')
                    state = 2;
                else if (current == 'x' || current == 'y' || current == 'z')
                    state = 3;
                else
                    throw "Wrong symbol";

                lexema.append(1, current);
                break;
            }
            case 2: {
                if (current == '+' || current == '-')
                {
                    state = 1;
                    Lexs.push_back(lexema);
                    lexema.clear();
                }
                else if (std::isdigit(current) || current == '.')
                    state = 2;
                else if (current == 'x' || current == 'y' || current == 'z')
                    state = 3;
                else
                    throw "Wrong symbol";

                lexema.append(1, current);
                break;
            }
            case 3: {
                if (current == '+' || current == '-')
                {
                    state = 1;
                    Lexs.push_back(lexema);
                    lexema.clear();
                }
                else if (current == 'x' || current == 'y' || current == 'z')
                    state = 3;
                else if (current == '^')
                    state = 4;
                else
                    throw "Wrong symbol";

                lexema.append(1, current);
                break;
            }
            case 4: {
                if ((std::isdigit(current) || current == '.') || (current == '+' || current == '-'))//if ((std::isdigit(current) || current == '.')
                {
                    state = 5;
                    lexema.append(1, current);
                }
                else
                    throw "Wrong symbol";

                break;
            }
            case 5: {
                if (current == '+' || current == '-')
                {
                    state = 1;
                    Lexs.push_back(lexema);
                    lexema.clear();
                }
                else if (current == 'x' || current == 'y' || current == 'z')
                    state = 3;
                else if (std::isdigit(current) || current == '.') {
                    state = 5;
                    
                }
                else
                    throw "Wrong symbol";

                lexema.append(1, current);
                break;
            }
            default:
                break;
            }
        }
    }

    if (state == 2 || state == 3 || state == 5)
        Lexs.push_back(lexema);
    else
        throw "Wrong symbol";
}

void Polinom::converter()
{
    for (size_t i = 0; i < Lexs.size(); i++)
    {
        int state = 0;
        std::string cf;
        int degrx = 0;
        int degry = 0;
        int degrz = 0;

        for (size_t j = 0; j < Lexs[i].length(); j++)
        {
            const char current = Lexs[i][j];

            switch (state)
            {
            case 0: {
                if (std::isdigit(current) || current == '.')
                {
                    state = 2;
                    cf.append(1, current);
                }
                else if (current == '-' || current == '+')
                {
                    state = 1;
                    cf.append(1, current);
                }
                else
                {
                    state = 3;
                    cf.append("1");
                }

                break;
            }
            case 1: {
                if (std::isdigit(current) || current == '.')
                {
                    state = 2;
                    cf.append(1, current);
                }
                else
                {
                    state = 3;
                    cf.append("1");
                }
                break;
            }
            case 2: {
                if (std::isdigit(current) || current == '.')
                {
                    state = 2;
                    cf.append(1, current);
                }
                else
                {
                    state = 3;
                }
                break;
            }
            case 3: {
                if (current == '^')
                {
                    if (Lexs[i][j - 1] == 'x')
                        degrx += std::stoi(&Lexs[i][j + 1]);
                    else if (Lexs[i][j - 1] == 'y')
                        degry += std::stoi(&Lexs[i][j + 1]);
                    else
                        degrz += std::stoi(&Lexs[i][j + 1]);
                    j++;
                }
                else
                {
                    if (Lexs[i][j - 1] == 'x')
                        degrx += 1;
                    else if (Lexs[i][j - 1] == 'y')
                        degry += 1;
                    else if (Lexs[i][j - 1] == 'z')
                        degrz += 1;
                }
                break;
            }
            default:
                break;
            }
        }

        if (Lexs[i].back() == 'x')
            degrx += 1;
        else if (Lexs[i].back() == 'y')
            degry += 1;
        else if (Lexs[i].back() == 'z')
            degrz += 1;

        addFirst(Node(std::stod(cf), degrx, degry, degrz));
    }
}


void Polinom::showList() const
{
    cout.setf(ios::fixed);  // вывод в фиксированном формате 
    cout.precision(3);
    if (head) {
        Node* buf = head;
        while (buf) {
            if ((buf != head))
                if (buf->data.coef > 0) std::cout << "+" << buf->data.coef << "x^" << buf->data.degx << "y^" << buf->data.degy << "z^" << buf->data.degz;
            if (buf->data.coef < 0) std::cout << buf->data.coef << "x^" << buf->data.degx << "y^" << buf->data.degy << "z^" << buf->data.degz;

            buf = buf->next;
        }
        std::cout << endl;
    }
    else std::cout << "List is empty " << endl;

}

void Polinom::showList2() const
{
    if (head) {
        Node* buf = head;
        while (buf) {

            std::cout << buf->data.coef << "x^" << buf->data.degx << "y^" << buf->data.degy << "z^" << buf->data.degz << " ";
            buf = buf->next;
        }
        std::cout << endl;
    }
    else std::cout << "List is empty " << endl;
}
void Polinom::showList3() const
{
    cout.setf(ios::fixed);  // вывод в фиксированном формате 
    cout.precision(3);
    if (head) {
        Node* buf = head;
        while (buf) {
            if ((buf != head))
                if (buf->data.coef > 0) std::cout << "+" << buf->data.coef << "x^" << buf->data.degx << "y^" << buf->data.degy << "z^" << buf->data.degz;
            if (buf->data.coef < 0) std::cout << buf->data.coef << "x^" << buf->data.degx << "y^" << buf->data.degy << "z^" << buf->data.degz;

            buf = buf->next;
        }
        if (head->next == NULL) std::cout << 0 << "x^" << 0 << "y^" << 0 << "z^" << 0;
        // std::cout << endl;
    }
    else std::cout << "List is empty " << endl;
}


void Polinom::podobnyi()
{
    Polinom TMP = *this;

    *this += TMP;
    *this *= 0.5;

}

void Polinom::differents(int t)
{
    Node* buf = head->next;
    switch (t)
    {
    case 1:
    {
        while (buf) {
            if (buf->data.degx != 0) {
                buf->data.coef *= buf->data.degx;
                buf->data.degx -= 1;

            }
            else if (buf->data.degx == 0) {
                buf->data.coef *= 0;
            }
            buf = buf->next;
        }
        break;
    }
    case 2:
    {
        while (buf) {
            if (buf->data.degy != 0) {
                buf->data.coef *= buf->data.degy;
                buf->data.degy -= 1;

            }
            else if (buf->data.degy == 0) {
                buf->data.coef *= 0;
            }
            buf = buf->next;
        }
        break;
    }
    case 3:
    {
        while (buf) {
            if (buf->data.degz != 0) {
                buf->data.coef *= buf->data.degz;
                buf->data.degz -= 1;

            }
            else if (buf->data.degz == 0) {
                buf->data.coef *= 0;
            }
            buf = buf->next;
        }
        break;
    }
    }

}

void Polinom::fulldiff()
{
    Polinom X = *this;
    Polinom Y = *this;
    Polinom Z = *this;
    X.differents(1);
    Y.differents(2);
    Z.differents(3);
    cout << "(";
    X.showList3();
    cout << ")dx+";
    cout << "(";
    Y.showList3();
    cout << ")dy+";
    cout << "(";
    Y.showList3();
    cout << ")dz\n";
}

/*Polinom& Polinom::operator=(const Polinom& poly)
{
    if (this != &poly)
    {

        Node* p = head->next;
        Node* q = head->next;
        while (p)
        {
            q = p->next;
            delete p;
            p = q;
        }

        q = poly.head->next;
        p = head;
        while (q)
        {
            p->next = new Node(q->data.coef, q->data.degx, q->data.degy, q->data.degz);
            p = p->next;
            q = q->next;
        }
        // p->next = head;
    }
    return *this;
}*/

Polinom& Polinom::operator+=(const Node& monom)
{
    Node* pThis = head;
    bool put = 0;
    while (pThis)
    {
        if (((monom.data.degx == pThis->data.degx) && (monom.data.degy == pThis->data.degy) && (monom.data.degz == pThis->data.degz)) && (put != 1)) {
            pThis->data.coef += monom.data.coef;
            put = 1;
        }
        pThis = pThis->next;
    }
    if (put != 1) addLast(monom);
    return *this;
}

Polinom& Polinom::operator-=(const Node& monom)
{
    Node* pThis = head;
    bool put = 0;
    while (pThis)
    {
        if (((monom.data.degx == pThis->data.degx) && (monom.data.degy == pThis->data.degy) && (monom.data.degz == pThis->data.degz)) && (put != 1)) {
            pThis->data.coef -= monom.data.coef;
            put = 1;
        }
        pThis = pThis->next;
    }
    if (put != 1) addLast(Node(monom.data.coef * -1, monom.data.degx, monom.data.degy, monom.data.degz));
    return *this;
}

Polinom Polinom::operator+(const Node& monom) const
{
    Polinom res(*this);
    Node* pThis = res.head;
    bool put = 0;
    while (pThis)
    {
        if (((monom.data.degx == pThis->data.degx) && (monom.data.degy == pThis->data.degy) && (monom.data.degz == pThis->data.degz)) && (put != 1)) {
            pThis->data.coef += monom.data.coef;
            put = 1;
        }
        pThis = pThis->next;
    }
    if (put != 1) res.addLast(monom);

    return res;
}

Polinom Polinom::operator-(const Node& monom) const
{
    Polinom res(*this);
    Node* pThis = res.head;
    bool put = 0;

    while (pThis)
    {
        if (((monom.data.degx == pThis->data.degx) && (monom.data.degy == pThis->data.degy) && (monom.data.degz == pThis->data.degz)) && (put != 1)) {
            pThis->data.coef -= monom.data.coef;
            put = 1;
        }
        pThis = pThis->next;
    }
    if (put != 1) res.addLast(Node(monom.data.coef * -1, monom.data.degx, monom.data.degy, monom.data.degz));

    return res;
}

Polinom Polinom::operator*(const Node& monom) const
{
    Polinom res;
    
    Node* pThis = head->next;
    Node* pRes = res.head;

    while (pThis)
    {
        pRes->next = new Node(pThis->data.coef * monom.data.coef, pThis->data.degx + monom.data.degx, pThis->data.degy + monom.data.degy, pThis->data.degz + monom.data.degz);
        pThis = pThis->next;
        pRes = pRes->next;
    }

    
    return res;
}

Polinom& Polinom::operator*=(const Node& monom)
{
    if ((monom.data.degx == 0 && monom.data.degy == 0 && monom.data.degz == 0) || abs(monom.data.coef) < 1e-10)
        operator*=(monom.data.coef);
    else
    {
        Node* pThis = head->next;

        while (pThis)
        {
            pThis->data.coef *= monom.data.coef;
            pThis->data.degx += monom.data.degx;
            pThis->data.degy += monom.data.degy;
            pThis->data.degz += monom.data.degz;
            pThis = pThis->next;
        }
    }

    return *this;
}

Polinom& Polinom::operator+=(double scalar)
{
    addLast(Node(scalar, 0, 0, 0));
    return *this;
}

Polinom& Polinom::operator-=(double scalar)
{
    addLast(Node(-scalar, 0, 0, 0));
    return *this;
}

Polinom Polinom::operator+(double scalar) const
{
    Polinom res(*this);
    res.addLast(Node(scalar, 0, 0, 0));

    return res;
}

Polinom Polinom::operator-(double scalar) const
{
    Polinom res(*this);
    res.addLast(Node(-scalar, 0, 0, 0));
    return res;
}

Polinom Polinom::operator*(double scalar) const
{
    Polinom res;
    if (abs(scalar) > 1e-10)
    {
        res.head->data.coef *= scalar;
        Node* pThis = head->next;
        Node* pRes = res.head;
        while (pThis)
        {
            pRes->next = new Node(pThis->data.coef * scalar, pThis->data.degx, pThis->data.degy, pThis->data.degz);
            pThis = pThis->next;
            pRes = pRes->next;
        }
    }
    return res;
}

Polinom& Polinom::operator*=(double scalar)
{



    Node* pThis = head->next;
    while (pThis)
    {
        pThis->data.coef *= scalar;
        pThis = pThis->next;
    }

    return *this;
}

Polinom& Polinom::operator+=(const Polinom& poly)
{

   
    Node* pThis = head;
    Node* pPoly = poly.head->next;

    if (head->next == NULL) {
        while (pPoly)
        {
            pThis->next = new Node(pPoly->data.coef, pPoly->data.degx, pPoly->data.degy, pPoly->data.degz);
            pPoly = pPoly->next;
            pThis = pThis->next;

        }
    }
    else {
        while ((pThis))
        {
            while ((pPoly))
            {

                if ((pPoly->data.degx == pThis->next->data.degx) && (pPoly->data.degy == pThis->next->data.degy) && (pPoly->data.degz == pThis->next->data.degz))
                {
                    pThis->next->data.coef += pPoly->data.coef;
                    if (abs(pThis->next->data.coef) < 1e-10)
                    {
                        Node* tmp = pThis->next;
                        pThis->next = pThis->next->next;
                        delete tmp;
                    }
                    else
                        pThis = pThis->next;

                    pPoly = pPoly->next;
                }
                else {
                    addLast(Node(+pPoly->data.coef, pPoly->data.degx, pPoly->data.degy, pPoly->data.degz));
                    pPoly = pPoly->next;
                }

            }
            pThis = pThis->next;

        }
        while (pPoly)
        {
            pThis->next = new Node(pPoly->data.coef, pPoly->data.degx, pPoly->data.degy, pPoly->data.degz);
            pPoly = pPoly->next;
            pThis = pThis->next;
        }

    }
    return *this;
}

Polinom& Polinom::operator-=(const Polinom& poly)
{
    Node* pThis = head;
    Node* pPoly = poly.head->next;
    if (head->next == NULL) {
        while (pPoly)
        {
            pThis->next = new Node(-pPoly->data.coef, pPoly->data.degx, pPoly->data.degy, pPoly->data.degz);
            pPoly = pPoly->next;
            pThis = pThis->next;

        }
    }
    else {
        if (this == &poly)
        {

            Node* p = head->next;
            Node* q = head->next;
            while (p)
            {
                q = p->next;
                delete p;
                p = q;
            }
            head->next = head;
        }
        else
        {
            
            while ((pThis))
            {
                while ((pPoly))
                {

                    if ((pPoly->data.degx == pThis->next->data.degx) && (pPoly->data.degy == pThis->next->data.degy) && (pPoly->data.degz == pThis->next->data.degz))
                    {
                        pThis->next->data.coef -= pPoly->data.coef;
                        if (abs(pThis->next->data.coef) < 1e-10)
                        {
                            Node* tmp = pThis->next;
                            pThis->next = pThis->next->next;
                            delete tmp;
                        }
                        else
                            pThis = pThis->next;

                        pPoly = pPoly->next;
                    }
                    else {
                        addLast(Node(-pPoly->data.coef, pPoly->data.degx, pPoly->data.degy, pPoly->data.degz));
                        pPoly = pPoly->next;
                    }

                }
                pThis = pThis->next;

            }
            while (pPoly)
            {
                pThis->next = new Node(-pPoly->data.coef, pPoly->data.degx, pPoly->data.degy, pPoly->data.degz);
                pPoly = pPoly->next;
                pThis = pThis->next;
            }

        }
    }
    return *this;
}

Polinom Polinom::operator+(const Polinom& poly) const
{
    Polinom res;
    res = poly;
    res += *this;
    return res;
}

Polinom Polinom::operator-(const Polinom& poly) const
{
    Polinom res;
    res = *this;
    res -= poly;
    return res;
}

Polinom Polinom::operator*(const Polinom& poly) const
{
    Polinom res;
    Polinom tmp;
    Node* pThis = head->next;

    while (pThis)
    {
        tmp = poly * *pThis;
        res = res + tmp;
       
        pThis = pThis->next;
    }
    
    return res;
}

double Polinom::operator()(double x, double y, double z) const
{
    Node* p = head->next;
    double Res1 =0.0;

    while (p)
    {
        int degx = p->data.degx;
        int degy = p->data.degy;
        int degz = p->data.degz;

        Res1 += p->data.coef * pow(x, degx) * pow(y, degy) * pow(z, degz);
        p = p->next;
    }
    return Res1;
}

bool Polinom::operator==(const Polinom& poly) const
{
    Node* pThis = head;
    Node* pPoly = poly.head;
    do
    {
        if ((abs((((pThis->data.coef) * 100) / 100) - (((pPoly->data.coef) * 100) / 100)) > (1.0e-10)) || (pThis->data.degx != pPoly->data.degx) || (pThis->data.degy != pPoly->data.degy) || (pThis->data.degz != pPoly->data.degz))
            return false;
        pThis = pThis->next;
        pPoly = pPoly->next;
    } while (pThis || pPoly);

    if (pThis || pPoly)
        return false;

    return true;
}

std::ostream& operator<<(std::ostream& out, const Polinom& polinom)
{
    cout.setf(ios::fixed);  // вывод в фиксированном формате 
    cout.precision(3);
    if (polinom.head) {
        Node* buf = polinom.head;
        while (buf) {
            if ((buf != polinom.head))
                if (buf->data.coef > 0) out << "+" << buf->data.coef << "x^" << buf->data.degx << "y^" << buf->data.degy << "z^" << buf->data.degz;
            if (buf->data.coef < 0) out << buf->data.coef << "x^" << buf->data.degx << "y^" << buf->data.degy << "z^" << buf->data.degz;

            buf = buf->next;
        }
        if (polinom.head->next == NULL) out << 0 << "x^" << 0 << "y^" << 0 << "z^" << 0;
        out << endl;
    }
    else out << "List is empty " << endl;
    return out;
}
