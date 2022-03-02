
#include "polinom.h"
using namespace std;



void Polinoms::str_to_poly(const std::string& input)
{
    parser(input);
    if (isCorrect())
       converter();
    else
       throw std::exception("Error!");
}
bool Polinoms::isCorrect() const
{
    return check_points() && check_vars();
}

bool Polinoms::check_vars() const
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

bool Polinoms::check_points() const
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

void Polinoms::parser(const std::string& input)
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
                if ((std::isdigit(current) || current == '.')|| (current == '+' || current == '-'))//if ((std::isdigit(current) || current == '.')
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
                    //lexema.append(1, current);
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

void Polinoms::converter()
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

        addFirst(Monom(std::stod(cf), degrx,degry,degrz));
    }
}

Polinoms::~Polinoms()
{
}

Polinoms::Polinoms()
{
	//head=NULL;
    head=new Monom(999.0, 999, 999, 999, nullptr);
 
}

Polinoms::Polinoms(const Polinoms& poly)
{
    head = new Monom(999.0, 999, 999, 999, nullptr);
    //head = new Monom(poly.head->coef, poly.head->degx, poly.head->degy, poly.head->degz);

    Monom* p = head;
    Monom* q = poly.head->next;

    while (q)
    {
        p->next = new Monom(q->coef, q->degx,q->degy,q->degz);
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
}

void Polinoms::addFirst(const Monom& monom)
{
    bool r = 0;
    Monom* ptr = head;
    while (ptr)
    {
        if ((ptr->degx==monom.degx)&& (ptr->degy == monom.degy)&& (ptr->degz == monom.degz)) {
            ptr->coef += monom.coef;
            r = 1;
        }
        ptr = ptr->next;
    }
    if (r != 1) {
        Monom* buf = new Monom;
        buf->degx = monom.degx;
        buf->degy = monom.degy;
        buf->degz = monom.degz;
        buf->coef = monom.coef;
        if (abs(monom.coef) > 1e-10)
        {
            buf->next = head->next;
            head->next = buf;
        }
    }
} //ÈÇÌÅÍÈÒÜ ×ÒÎÁ ÑÊËÀÄÛÂÀË ÊÎÝÔÛ ++

void Polinoms::addLast(const Monom& monom)
{


    bool r = 0;
    Monom* ptr = head;
    while (ptr)
    {
        if ((ptr->degx == monom.degx) && (ptr->degy == monom.degy) && (ptr->degz == monom.degz)) {
            ptr->coef += monom.coef;
            r = 1;
        }
        ptr = ptr->next;
    }
    if (r != 1) {
        Monom* buf = new Monom;
        Monom* buf2 = head;
        buf->degx = monom.degx;
        buf->degy = monom.degy;
        buf->degz = monom.degz;
        buf->coef = monom.coef;
        if (abs(monom.coef) > 1e-10)
        {
            if (head->next == NULL)
            {
                head->next = buf;
                buf->next = NULL;
            }
            else {
                buf->next = NULL;
                while (buf2) {
                    buf2 = buf2->next;
                    if (buf2->next == NULL) {
                        buf2->next = buf;
                        break;
                    }

                }
            }

        }
    }
} //ÈÇÌÅÍÈÒÜ ×ÒÎÁ ÑÊËÀÄÛÂÀË ÊÎÝÔÛ++

void Polinoms::addNow(const Monom& monom, Monom& ptr)
{
    Monom* buf = new Monom;
    buf->degx = monom.degx;
    buf->degy = monom.degy;
    buf->degz = monom.degz;
    buf->coef = monom.coef;
    buf->next = ptr.next;
    ptr.next = buf;
} 

void Polinoms::showList() const
{
    cout.setf(ios::fixed);  // âûâîä â ôèêñèðîâàííîì ôîðìàòå 
    cout.precision(3);
        if (head) {
            Monom* buf = head;
            while (buf) {
                if ((buf!= head))
                    if (buf->coef>0) std::cout <<"+" << buf->coef << "x^" << buf->degx << "y^" << buf->degy << "z^" << buf->degz;
                    if (buf->coef < 0) std::cout << buf->coef << "x^" << buf->degx << "y^" << buf->degy << "z^" << buf->degz;

                buf = buf->next;
            }
            std::cout <<endl;
        }
        else std::cout << "List is empty " << endl;
    
}

void Polinoms::showList2() const
{
    if (head) {
        Monom* buf = head;
        while (buf) {

                std::cout << buf->coef << "x^" << buf->degx << "y^" << buf->degy << "z^" << buf->degz << " ";
            buf = buf->next;
        }
        std::cout << endl;
    }
    else std::cout << "List is empty " << endl;
}
void Polinoms::showList3() const
{
    cout.setf(ios::fixed);  // âûâîä â ôèêñèðîâàííîì ôîðìàòå 
    cout.precision(3);
    if (head) {
        Monom* buf = head;
        while (buf) {
            if ((buf != head))
                if (buf->coef > 0) std::cout << "+" << buf->coef << "x^" << buf->degx << "y^" << buf->degy << "z^" << buf->degz;
            if (buf->coef < 0) std::cout << buf->coef << "x^" << buf->degx << "y^" << buf->degy << "z^" << buf->degz;

            buf = buf->next;
        }
        if (head->next==NULL) std::cout << 0 << "x^" << 0 << "y^" << 0 << "z^" << 0;
       // std::cout << endl;
    }
    else std::cout << "List is empty " << endl;
}

void Polinoms::delFirst()
{
    Monom* buf2 = head;
    Monom* buf1 = head->next;
    buf2->next = buf1->next;
    delete buf1;
/*    while (buf2) {
        buf1 = buf2;
        buf2 = buf2->next;
        if (buf2->next == NULL) {
            delete buf2;
            buf1->next = NULL;
            break;
        }
    }
    */
} //ÈÇÌÅÍÈÒÜ ×ÒÎÁ ÍÅ ÒÐÎÃÀË ÃÎËÎÂÓ++

void Polinoms::delLast()
{
    Monom* buf = head;
    while (buf) {
        if (buf->next->next == nullptr) {
            Monom* buf2 = buf->next;
            buf->next = nullptr;
            delete buf2;
        }
        buf = buf->next;
    }
} //ÈÇÌÅÍÈÒÜ ×ÒÎÁ ÍÅ ÒÐÎÃÀË ÃÎËÎÂÓ++

void Polinoms::delElem(Monom& ptr)
{
    Monom* buf = head;
    Monom buf2 = ptr;
    while (buf) {
        if (*buf->next == ptr) {
            buf->next = ptr.next;
            //ptr=*buf2.next;
            break;
        }
        buf = buf->next;
        
    }
    //ptr.next = buf;
}

void Polinoms::podobnyi()
{
    Polinoms TMP = *this;
    
    *this += TMP;
    *this *= 0.5;

}

void Polinoms::differents(int t)
{
    Monom* buf = head->next;
    switch (t)
    {
    case 1:
    {
        while (buf) {
            if (buf->degx != 0) {
                buf->coef *= buf->degx;
                buf->degx -= 1;

            }
            else if (buf->degx == 0) {
                buf->coef *= 0;
            }
            buf = buf->next;
        }
        break;
    }
    case 2:
    {
        while (buf) {
            if (buf->degy != 0) {
                buf->coef *= buf->degy;
                buf->degy -= 1;

            }
            else if (buf->degy == 0) {
                buf->coef *= 0;
            }
            buf = buf->next;
        }
        break;
    }
    case 3:
    {
        while (buf) {
            if (buf->degz != 0) {
                buf->coef *= buf->degz;
                buf->degz -= 1;

            }
            else if (buf->degz == 0) {
                buf->coef *= 0;
            }
            buf = buf->next;
        }
        break;
    }
    }
    
}

void Polinoms::fulldiff()
{
    Polinoms X=*this;
    Polinoms Y=*this;
    Polinoms Z=*this;
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

Polinoms& Polinoms::operator=(const Polinoms& poly)
{
    if (this != &poly)
    {
        
        Monom* p = head ->next;
        Monom* q = head ->next;
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
            p->next = new Monom(q->coef, q->degx,q->degy,q->degz);
            p = p->next;
            q = q->next;
        }
       // p->next = head;
    }
    return *this;
}

Polinoms& Polinoms::operator+=(const Monom& monom)
{
    Monom* pThis = head;
    bool put = 0;
    while (pThis) 
    {
        if (((monom.degx == pThis->degx) && (monom.degy == pThis->degy) && (monom.degz == pThis->degz))&&(put!=1)) {
            pThis->coef += monom.coef;
            put = 1;
        }
        pThis = pThis->next;
    }
    if (put!=1) addLast(monom);
    return *this;
} 

Polinoms& Polinoms::operator-=(const Monom& monom)
{
    Monom* pThis = head;
    bool put = 0;
    while (pThis)
    {
        if (((monom.degx == pThis->degx) && (monom.degy == pThis->degy) && (monom.degz == pThis->degz)) && (put != 1)) {
            pThis->coef -= monom.coef;
            put = 1;
        }
        pThis = pThis->next;
    }
    if (put != 1) addLast(Monom(monom.coef*-1,monom.degx,monom.degy,monom.degz));
    return *this;
}

Polinoms Polinoms::operator+(const Monom& monom) const
{
        Polinoms res(*this);
        Monom* pThis = res.head;
        bool put = 0;
        while (pThis)
        {
            if (((monom.degx == pThis->degx) && (monom.degy == pThis->degy) && (monom.degz == pThis->degz)) && (put != 1)) {
                pThis->coef += monom.coef;
                put = 1;
            }
            pThis = pThis->next;
        }
        if (put != 1) res.addLast(monom);

        return res; 
}

Polinoms Polinoms::operator-(const Monom& monom) const
{
    Polinoms res(*this);
    Monom* pThis = res.head;
    bool put = 0;

    while (pThis)
    {
        if (((monom.degx == pThis->degx) && (monom.degy == pThis->degy) && (monom.degz == pThis->degz)) && (put != 1)) {
            pThis->coef -= monom.coef;
            put = 1;
        }
        pThis = pThis->next;
    }
    if (put != 1) res.addLast(Monom(monom.coef * -1, monom.degx, monom.degy, monom.degz));

    return res;
}

Polinoms Polinoms::operator*(const Monom& monom) const
{
    Polinoms res;
    /*
    if ((monom.degx == 0 && monom.degy == 0 && monom.degz == 0))
    { 
        res *= (monom.coef);
        return res;
    }
    else if (abs(monom.coef) < 1e-10) {
        res *= 0;
        return res;
    }
    else
    {*/
        Monom* pThis = head->next;
        Monom* pRes = res.head;

        while (pThis)
        {
            pRes->next = new Monom(pThis->coef * monom.coef, pThis->degx + monom.degx, pThis->degy + monom.degy, pThis->degz + monom.degz);
            pThis = pThis->next;
            pRes = pRes->next;
        }
       
   // }
    //res.podobnyi();
    return res;
}

Polinoms& Polinoms::operator*=(const Monom& monom)
{
    if ((monom.degx == 0 && monom.degy == 0 && monom.degz == 0) || abs(monom.coef) < 1e-10)
        operator*=(monom.coef);
    else
    {
        Monom* pThis = head->next;

        while (pThis)
        {
            pThis->coef *= monom.coef;
            pThis->degx += monom.degx;
            pThis->degy += monom.degy;
            pThis->degz += monom.degz;
            pThis = pThis->next;
        }
    }

    return *this;
}

Polinoms& Polinoms::operator+=(double scalar)
{
    addLast(Monom(scalar, 0, 0, 0));
    return *this;
}

Polinoms& Polinoms::operator-=(double scalar)
{
    addLast(Monom(-scalar, 0, 0, 0));
    return *this;
}

Polinoms Polinoms::operator+(double scalar) const
{
    Polinoms res(*this);
    res.addLast(Monom(scalar, 0, 0, 0));
    
    return res;
}

Polinoms Polinoms::operator-(double scalar) const
{
    Polinoms res(*this);
    res.addLast(Monom(-scalar, 0, 0, 0));
    return res;
}

Polinoms Polinoms::operator*(double scalar) const
{
    Polinoms res;
    if (abs(scalar) > 1e-10)
    {
        res.head->coef *= scalar;
        Monom* pThis = head->next;
        Monom* pRes = res.head;
        while (pThis)
        {
            pRes->next = new Monom(pThis->coef * scalar, pThis->degx, pThis->degy, pThis->degz);
            pThis = pThis->next;
            pRes = pRes->next;
        }
    }
    return res;
}

Polinoms& Polinoms::operator*=(double scalar)
{
    
    
    
        Monom* pThis = head->next;
        while (pThis)
        {
            pThis->coef *= scalar;
            pThis = pThis->next;
        }
        
    return *this;
}

Polinoms& Polinoms::operator+=(const Polinoms& poly)
{

   // head->coef += poly.head->coef;
    Monom* pThis = head;
    Monom* pPoly = poly.head->next;

    if (head->next==NULL){
        while (pPoly)
        {
            pThis->next = new Monom(pPoly->coef, pPoly->degx, pPoly->degy, pPoly->degz);
            pPoly = pPoly->next;
            pThis = pThis->next;

        }
    }
    else {
        while ((pThis))
        {
            while ((pPoly))
            {

                if ((pPoly->degx == pThis->next->degx) && (pPoly->degy == pThis->next->degy) && (pPoly->degz == pThis->next->degz))
                {
                    pThis->next->coef += pPoly->coef;
                    if (abs(pThis->next->coef) < 1e-10)
                    {
                        Monom* tmp = pThis->next;
                        pThis->next = pThis->next->next;
                        delete tmp;
                    }
                    else
                        pThis = pThis->next;

                    pPoly = pPoly->next;
                }
                else {
                    addLast(Monom(+pPoly->coef, pPoly->degx, pPoly->degy, pPoly->degz));
                    pPoly = pPoly->next;
                }

            }
            pThis = pThis->next;

        }
        while (pPoly)
        {
            pThis->next = new Monom(pPoly->coef, pPoly->degx, pPoly->degy, pPoly->degz);
            pPoly = pPoly->next;
            pThis = pThis->next;
        }

    }
        return *this;
}

Polinoms& Polinoms::operator-=(const Polinoms& poly)
{
    Monom* pThis = head;
    Monom* pPoly = poly.head->next;
    if (head->next == NULL) {
        while (pPoly)
        {
            pThis->next = new Monom(-pPoly->coef, pPoly->degx, pPoly->degy, pPoly->degz);
            pPoly = pPoly->next;
            pThis = pThis->next;

        }
    }
    else {
        if (this == &poly)
        {

            Monom* p = head->next;
            Monom* q = head->next;
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
            //Monom* pThis = head;
           // Monom* pPoly = poly.head->next;
            while ((pThis))
            {
                while ((pPoly))
                {

                    if ((pPoly->degx == pThis->next->degx) && (pPoly->degy == pThis->next->degy) && (pPoly->degz == pThis->next->degz))
                    {
                        pThis->next->coef -= pPoly->coef;
                        if (abs(pThis->next->coef) < 1e-10)
                        {
                            Monom* tmp = pThis->next;
                            pThis->next = pThis->next->next;
                            delete tmp;
                        }
                        else
                            pThis = pThis->next;

                        pPoly = pPoly->next;
                    }
                    else {
                        addLast(Monom(-pPoly->coef, pPoly->degx, pPoly->degy, pPoly->degz));
                        pPoly = pPoly->next;
                    }

                }
                pThis = pThis->next;

            }
            while (pPoly)
            {
                pThis->next = new Monom(-pPoly->coef, pPoly->degx, pPoly->degy, pPoly->degz);
                pPoly = pPoly->next;
                pThis = pThis->next;
            }

        }
    }
    return *this;
}

Polinoms Polinoms::operator+(const Polinoms& poly) const
{
    Polinoms res;
    res = poly;
    res +=*this;
    return res;
}

Polinoms Polinoms::operator-(const Polinoms& poly) const
{
    Polinoms res;
    res = *this;
    res -= poly;
    return res;
}

Polinoms Polinoms::operator*(const Polinoms& poly) const
{
    Polinoms res;
    Polinoms tmp;
    Monom* pThis = head->next;
 
    while (pThis)
    {
        tmp = poly * *pThis;
        res =res + tmp;
       // res.showList2();
        pThis = pThis->next;
    }
  //  res.podobnyi();
    return res;
}

bool Polinoms::operator==(const Polinoms& poly) const
{
    Monom* pThis = head;
    Monom* pPoly = poly.head;
    do
    {
        if ((abs((((pThis->coef)*100)/100)- (((pPoly->coef) * 100) / 100))> (1.0e-10))||(pThis->degx != pPoly->degx)||(pThis->degy != pPoly->degy)|| (pThis->degz != pPoly->degz))
            return false;
        pThis = pThis->next;
        pPoly = pPoly->next;
    } while (pThis|| pPoly);

    if (pThis|| pPoly)
        return false;

    return true;
}

//ÈÒÅÐÀÒÎÐ
Polinoms::Iterator Polinoms::begin()
{
    return Polinoms::Iterator(head);
}

Polinoms::Iterator Polinoms::end()
{
    return Polinoms::Iterator(nullptr);
}

Polinoms::Iterator::Iterator(Monom* _ptr)
	:ptr(_ptr)
{
}

Polinoms::Iterator Polinoms::Iterator::operator++(int)
{
    ptr = ptr->next;
    return *this;
}

Polinoms::Iterator& Polinoms::Iterator::operator++()
{
	ptr = ptr->next;
	return *this;
}

Monom& Polinoms::Iterator::operator*()
{
	return *ptr;
}