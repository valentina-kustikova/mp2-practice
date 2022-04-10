#include "../include/monom.h"


Node::Node(double _coef, int _degx, int _degy, int _degz, Node* _next)
{

	data.degx = _degx;
	data.degy = _degy;
	data.degz = _degz;

	data.coef = _coef;
	next = _next;
}

Node::Node(const Node& monom2)
{
	data.degx = monom2.data.degx;
	data.degy = monom2.data.degy;
	data.degz = monom2.data.degz;
	data.coef = monom2.data.coef;
	next = monom2.next;
}


bool Node::operator==(const Node& m) const
{
	return ((data.coef)-(m.data.coef) < 1e-10) && (data.degx == m.data.degx) && (data.degy == m.data.degy) && (data.degz == m.data.degz);
}

bool Node::operator!=(const Node& m) const
{
	return ((data.coef)-(m.data.coef) > 1e-10) || (data.degx != m.data.degx) || (data.degy != m.data.degy) || (data.degz != m.data.degz);
}

std::ostream& operator<<(std::ostream& os, const Node& m)
{
	os << m.data.coef << "x^" << m.data.degx << "y^" << m.data.degy << "z^" << m.data.degz << std::endl;
	return os;
}

List::~List()
{
}

List::List()
{
    
    head = new Node(999.0, 999, 999, 999, nullptr);

}

List::List(const List& poly)
{
    head = new Node(999.0, 999, 999, 999, nullptr);
    

    Node* p = head;
    Node* q = poly.head->next;

    while (q)
    {
        p->next = new Node(q->data.coef, q->data.degx, q->data.degy, q->data.degz);
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
}

List& List::operator=(const List& poly)
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
        
    }
    return *this;
}

void List::addFirst(const Node& monom)
{
    bool r = 0;
    Node* ptr = head;
    while (ptr)
    {
        if ((ptr->data.degx == monom.data.degx) && (ptr->data.degy == monom.data.degy) && (ptr->data.degz == monom.data.degz)) {
            ptr->data.coef += monom.data.coef;
            r = 1;
        }
        ptr = ptr->next;
    }
    if (r != 1) {
        Node* buf = new Node;
        buf->data.degx = monom.data.degx;
        buf->data.degy = monom.data.degy;
        buf->data.degz = monom.data.degz;
        buf->data.coef = monom.data.coef;
        if (abs(monom.data.coef) > 1e-10)
        {
            buf->next = head->next;
            head->next = buf;
        }
    }
} 

void List::addLast(const Node& monom)
{


    bool r = 0;
    Node* ptr = head;
    while (ptr)
    {
        if ((ptr->data.degx == monom.data.degx) && (ptr->data.degy == monom.data.degy) && (ptr->data.degz == monom.data.degz)) {
            ptr->data.coef += monom.data.coef;
            r = 1;
        }
        ptr = ptr->next;
    }
    if (r != 1) {
        Node* buf = new Node;
        Node* buf2 = head;
        buf->data.degx = monom.data.degx;
        buf->data.degy = monom.data.degy;
        buf->data.degz = monom.data.degz;
        buf->data.coef = monom.data.coef;
        if (abs(monom.data.coef) > 1e-10)
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
} 

void List::addNow(const Node& monom, Node& ptr)
{
    Node* buf = new Node;
    buf->data.degx = monom.data.degx;
    buf->data.degy = monom.data.degy;
    buf->data.degz = monom.data.degz;
    buf->data.coef = monom.data.coef;
    buf->next = ptr.next;
    ptr.next = buf;
}

void List::delFirst()
{
    Node* buf2 = head;
    Node* buf1 = head->next;
    buf2->next = buf1->next;
    delete buf1;
   
} 

void List::delLast()
{
    Node* buf = head;
    while (buf) {
        if (buf->next->next == nullptr) {
            Node* buf2 = buf->next;
            buf->next = nullptr;
            delete buf2;
        }
        buf = buf->next;
    }
} 

void List::delElem(Node& ptr)
{
    Node* buf = head;
    Node buf2 = ptr;
    while (buf) {
        if (*buf->next == ptr) {
            buf->next = ptr.next;
           
            break;
        }
        buf = buf->next;

    }
    
}

List::Iterator List::begin()
{
	return List::Iterator(head);
}

List::Iterator List::end()
{
	return List::Iterator(nullptr);
}

List::Iterator::Iterator(Node* _ptr)
	:ptr(_ptr)
{
}

List::Iterator List::Iterator::operator++(int)
{
	ptr = ptr->next;
	return *this;
}

List::Iterator& List::Iterator::operator++()
{
	ptr = ptr->next;
	return *this;
}

Node& List::Iterator::operator*()
{
	return *ptr;
}
