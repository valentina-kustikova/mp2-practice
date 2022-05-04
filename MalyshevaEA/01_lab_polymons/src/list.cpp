/*#include "../include/list.h"

/*template <typename T>
node<T>::node(T data = T(), node* pnext = nullptr)
{
    this->data = data;
    this->pnext = pnext;
}*/
/*
template <typename T>
list<T>::list()
{
    size = 0;
    head = nullptr; 
}

template <typename T>
void list<T>::pushback(T data)
{
    if (head == nullptr)
    {
        head = new node<T>(data);
    }
    else
    {
        node<T> *cur =  this->head;
        while (cur != nullptr)
        {
            cur = cur->pnext;
        }
        cur->pnext = new node<T>(data);
    }
    size++;
}

/*template <typename T>
T& list<T>::operator[](const int ind)
{
    int i = 0;
    node<T> *cur =  this->head;
    while(cur != nullptr)
    {
        if (i == ind)
        {
            return cur->data;
        }
        cur = cur->pnext;
        i++;
    }
}
*//*
template <typename T>
void list<T>::dlfront()
{
    node<T> *tmp = head;
    head = head->pnext;
    delete tmp;
    size--;
}

template <typename T>
void list<T>::clear()
{
    while(size > 0)
    {
        dlfront();
    }
}

template <typename T>
list<T>::~list()
{
    clear;
}

template <typename T>
void list<T>::pushfront(T data)
{
    head = new node<T>(data, head);
    size++;
}

template <typename T>
void list<T>::insert(T v, int ind)
{
    if (ind == 0)
    {
        pushfront(v);
    }
    else{
    node<T> *p = this->head;
    for (int i = 0; i < ind - 1; i++)
    {
        p = p->pnext;
    }   
    node<T> *newnode = new node<T>(v, p->pnext);
    p->pnext = newnode;
    size++;
    }
}

template <typename T>
void list<T>::dlat(int ind)
{
    if(ind == 0)
    {
        dlfront();
    }
    else{
    node<T> *p = this->head;
    for (int i = 0; i < ind - 1; i++)
    {
        p = p->pnext;
    }   
    node<T> *dlnode = p->pnext;
    p->pnext = dlnode->pnext;
    delete dlnode;
    size--;
    }
}

template <typename T>
void list<T>::dlback()
{
    dlat(size - 1);
}

template <typename T>
bool list<T>::operator==(const list<T>& List) const
{
    node<T>* tmp = head;
	node<T>* tmp2 = List.head;
	bool b = true;
    if (((tmp->pnext != head) && (tmp2->pnext == List.head)) || ((tmp2->pnext != List.head) && (tmp->pnext == head)))
		b = false;
	while ((tmp->pnext != head) && (tmp2->pnext != List.head) && (b))
	{
		if (tmp->data != tmp2->data)
			b = false;
		tmp = tmp->pnext;
		tmp2 = tmp2->pnext;
	}
	return b;
}*/