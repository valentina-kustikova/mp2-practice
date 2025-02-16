#pragma once
#include "stack.h"
template <typename TElem>
class list_stack : public stack<TElem>
{
private:
    TList<TElem> elems;

public:
    list_stack() {};
    list_stack(const list_stack<TElem>& s)
    {
        elems = s.elems;
    }
    void push(const TElem& e)
    {
        if (is_full())
        {
            throw "stack is full!";
        }
        TNode<TElem>* newNode = new TNode<TElem>(e);
        elems.push_front(newNode);
        return;
    }
    TElem show_top()const
    {
        return elems.first();
    }
    void pop()
    {
        if (is_empty())
        {
            throw "EMPTY STACK";
        }
        try
        {
            elems.remove(elems.first());
        }
        catch (...)
        {
            throw "EMPTY STACK";
        }
    }
    bool is_full()const
    {
        try
        {
            TNode<TElem>* newNode = new TNode<TElem>();
            if (newNode == nullptr)
            {
                return true;
            }
            delete newNode;
        }
        catch (...)
        {
            return true;
        }
        return false;

    }
    bool is_empty()const
    {
        return elems.empty();
    }
    const list_stack <TElem>& operator = (const list_stack <TElem>& s)
    {
        if (this == &s)
        {
            return *this;
        }
        elems = s.elems;
        return *this;
    }
    bool operator == (const list_stack <TElem>& s)const
    {
        return (elems == s.elems);
    }
    bool operator != (const list_stack <TElem>& s)const
    {
        return !(*this == s);
    }
};