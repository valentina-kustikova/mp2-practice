template <typename T>
class node
{
public:
    node<T>* pnext;
    T data;
    node(T data = T(), node* pnext = nullptr)
    {
    this->data = data;
    this->pnext = pnext;
    }
};

template <typename T>
class list
{
    public:
    node<T> *pfirst;
    int size;
    list();
    ~list();
    void pushback(T data);
    int getsize() const {return size;};
    T& operator[](const int ind) const;
    void dlfront();
    void clear();
    void pushfront(T data);
    void dlback();
    void insert(T v, int ind);
    void dlat(int ind);

    bool operator==(const list<T>& List) const;
};

template <typename T>
class headlist : public list<T>
{
    public:
    node<T>* head;
    headlist();
    ~headlist();
    void pushfront(T el);
    void dlfront();
};

template <typename T>
headlist<T>::headlist()
{
    head = new node<T>;
    head->pnext = head;
    list<T>::size = 0;
}

template <typename T>
headlist<T>::~headlist()
{
    list<T>::~list();
    delete head;
}

template <typename T>
void headlist<T>::pushfront(T el)
{
    list<T>::pushfront(el);
    head->pnext = list<T>::pfirst;
}

template <typename T>
void headlist<T>::dlfront()
{
    list<T>::dlfront();
    head->pnext = list<T>::pfirst;
}

/*
template <typename T>
node<T>::node(T data = T(), node* pnext = nullptr)
{
    this->data = data;
    this->pnext = pnext;
}*/

template <typename T>
list<T>::list()
{
    size = 0;
    pfirst = nullptr; 
}

template <typename T>
void list<T>::pushback(T data)
{
    if (pfirst == nullptr)
    {
        pfirst = new node<T>(data);
    }
    else
    {
        node<T> *cur =  this->pfirst;
        while (cur->pnext != nullptr)
        {
            cur = cur->pnext;
        }
        cur->pnext = new node<T>(data);
    }
    size++;
}

template <typename T>
T& list<T>::operator[](const int ind) const//добавила нонст
{
    int i1 = 0;
    node<T> *cur =  this->pfirst;
    while(cur != nullptr)
    {
        if (i1 == ind)
        {
            return cur->data;
        }
        cur = cur->pnext;
        i1++;
    }
}

template <typename T>
void list<T>::dlfront()
{
    //проверить равен 0 или нет
    if (pfirst != nullptr)
    {
    node<T> *tmp = pfirst;
    pfirst = pfirst->pnext;
    delete tmp;
    size--;
    }
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
    clear();
}

template <typename T>
void list<T>::pushfront(T data)
{
    pfirst = new node<T>(data, pfirst);
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
    node<T> *p = this->pfirst;
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
    node<T> *p = this->pfirst;
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
    node<T>* tmp = pfirst;
	node<T>* tmp2 = List.pfirst;
	bool b = true;
    int i = 0;
    
    /*if (((tmp->pnext != head) && (tmp2->pnext == List.head)) || ((tmp2->pnext != List.head) && (tmp->pnext == head)))
		b = false;*/    
    if(size > 0)
	{while ((tmp->pnext != pfirst) && (tmp2->pnext != List.pfirst) && (b) && (i < size - 1))
	{
		if (tmp->data != tmp2->data)
			b = false;
		tmp = tmp->pnext;
		tmp2 = tmp2->pnext;
        i++;
	}}
	return b;
}