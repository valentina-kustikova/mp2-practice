#pragma once
#include "stack.h"
template <typename TElem>
class Liststack : public stack<TElem>
{
private:
    TList<TElem> el;

public:
    Liststack() {};
    Liststack(const Liststack<TElem>& s)
    {
        el = s.el;
    }
    
    void push(const TElem& e)
    {
        if (is_full())
        {
            throw "FULL STACK";
        }

        TNode<TElem>* newNode = new TNode<TElem>(e);
        el.push_front(newNode);
        return;
    }


    TElem show_top()const
    {
        return el.first();
    }


    void pop()
    {
        try
        {
            el.remove(el.first());
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
        return el.empty();
    }

    const Liststack <TElem>& operator= (const Liststack <TElem>& s)
    {
        if (this == &s)
        {
            return *this;
        }
        el = s.el;
        return *this;
    }

    bool operator== (const Liststack <TElem>& s)const
    {
        return (el == s.el);
    }

    bool operator!= (const Liststack <TElem>& s)const
    {
        return !(*this == s);
    }
};