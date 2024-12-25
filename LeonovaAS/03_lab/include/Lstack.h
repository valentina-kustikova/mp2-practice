#pragma once
#include "stack.h"
template <typename TElem>//—“≈  Õ¿ —œ»— ¿’
class Lstack : public stack<TElem>
{
private:
    TList<TElem> elems;

public:
    Lstack() {};
    Lstack(const Lstack<TElem>& s) 
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
        try
        {
            elems.remove(elems.first());
        }
        catch (...)
        {
            throw "Stack is empty!";
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
    const Lstack <TElem>& operator = (const Lstack <TElem>& s)
    {
        if (this == &s)
        {
            return *this;
        }
        elems = s.elems;
        return *this;
    }
    bool operator == (const Lstack <TElem>& s)const
    {
        return (elems == s.elems);
    }
    bool operator != (const Lstack <TElem>& s)const
    {
        return !(*this == s);
    }
};
