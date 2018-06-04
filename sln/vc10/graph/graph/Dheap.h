#pragma once
#include"Graph.h"
#include <cmath>
#define MSIZE 1000;

template<typename K>
class PArr
{public:
	K weight;
};

template<typename T>
class Dheap {
private:
	int d;//арность кучи
	int m;//максимальное число элементов
	T* keys;
	int freepos;//индекс след элемента
public:
	Dheap(int);
	Dheap(int,int);
	Dheap(T*,int, int);
	Dheap(const Dheap<T>&);
	Dheap( Graph&,int);
	~Dheap();

	void transpose(int, int);
	void dipping(int);
	void surfacing(int);
	void hilling();
	int find(T);
	void insert(T);
	void remove(int);
	int min_child(int);
	bool IsFull();
	bool IsEmpty();
	int getparid(int);
	T checktop();
	void print();
	void psevdoprint();
};
template <typename T>
void Dheap<T>::print()
{
	int level = 0, tmp = 0;
	while (tmp < freepos)
	{
		tmp += pow(d, level);
		level++;
	}
	int k = 1, z = 0;
	cout << "\t" << keys[0].weight << endl;
	for (int i = 1; i < level; i++)
	{
		for (int j = k; (j<k + pow(d, i)) && (j < freepos); j++)
			cout << keys[j].weight << "\t";
		cout << endl;
		if (k + pow(d, i) > freepos)
			k = freepos;
		else k += pow(d, i);
	}
}
template<typename T>
 void Dheap<T>::psevdoprint()
{
	 for (int i=0;i<freepos;i++)
	 {
		 cout << i << "  " << keys[i].weight << endl;
	 }
}
 template<typename T>
 Dheap<T>::Dheap(int d)
 {
	 if (d < 1)
		 throw"wrong d";
	  m = MSIZE;
	  this->d = d;
	  keys = new T[m];
	  freepos = 0;
 }
 template<typename T>
 Dheap<T>::Dheap(int _m,int _d)
 {
	 d = _d;
	 m = _m;
	 freepos = 0;
	 keys = new T[_m];
}

 template<typename T>
 Dheap<T>::Dheap(T *a, int m, int d)
 {
	 this->d = d;
	 this->m = m;
	 freepos = m;
	 keys = new T[m];
	 for (int i = 0; i < m; i++)
	 {
		 keys[i] = a[i];
	 }
 }

 template<typename T>
  Dheap<T>::Dheap(const Dheap<T>&a)
 {
	  d = a.d;
	  m = a.m;
	  keys = new T[m];
	  freepos = a.freepos;
	  for(int i=0;i<freepos;i++)
	  {
		  keys[i] = a.keys[i];
	  }
	 
 }

 
 template<typename T>
 Dheap<T>::Dheap(Graph& Graph,int _d)
 {	
	 d = _d;
	 m = Graph.getsize();
	 keys = new T[m];
	 Edge* a = Graph.getEdges();
	 for (int i = 0; i < Graph.getsize(); i++)
	 {
		 keys[i] = a[i];
	 }
	 freepos = m;
 }

 template<typename T>
 Dheap<T>::~Dheap()
 {
		delete[] keys;
 }

 template<typename T>
void Dheap<T>::transpose(int i, int p)
{
	T tmp=keys[i];
	keys[i] = keys[p];
	keys[p] = tmp;
}

template<typename T>
void Dheap<T>::dipping(int i)
{
	int s = min_child(i);
	while ((s != 0) && (keys[i].weight > keys[s].weight))
	{
		transpose(i, s);
		i = s;
		s = min_child(i);
	}
}
template<typename T>
void Dheap<T>::surfacing(int i)
{
	int p = getparid(i);
	while ((i != 0) && (keys[p].weight > keys[i].weight))
	{
		transpose(i, p);
		i = p;
		p = getparid(i);
	}
}

 /*template<typename T>
int Dheap<T>::min_child(int i)
{
	int s, min_key,last;
	s = i*d + 1;
	if (s>= count) return 0;
	else {
		
		min_key = keys[s].weight;
		last = (i + 1)*d;
		if (last >= count) last = count- 1;
		for (int j = s + 1; j <= last; j++)
		{
			if (min_key > keys[j].weight) min_key = keys[j].weight;
			s = j;
		}
		return s;
	}
}*/
template<typename T>
int Dheap<T>::min_child(int a)
{
	int minCh = a*d + 1;
	int maxCh;
	if (minCh >= freepos) return 0;
	if (a*d + d < freepos - 1)
		maxCh = a*d + d;
	else maxCh =freepos -1;

	for (int i = minCh; i <= maxCh; i++)
	{
		if (keys[i].weight < keys[minCh].weight)
		{
			minCh = i;
		}
	}
	return minCh;
}


template<typename T>
void Dheap<T>::hilling()
{
	for (int i = freepos - 1; i >= 0; i--)
	{
		dipping(i);
	}
}

template<typename T>
 int Dheap<T>::find(T a)
{
	 for (int i = 0; i < m; i++)
	 {
		 if (keys[i] == a)return i;
	 }
	 throw"Element not found";
}

 template<typename T>
void Dheap<T>::insert(T a)
{
	if (IsFull())
		throw "Dheap is full";
		keys[freepos] = a;
	freepos++;
}

template <typename T>
void Dheap<T>::remove(int i)
{
	if (IsEmpty())
		throw"Dheap is empty";
	T tmp = keys[freepos - 1];
	keys[freepos - 1] = keys[i];
	keys[i] = tmp;
	freepos--;
	if ((i != 0) && (keys[i].weight< keys[getparid(i)].weight))
		surfacing(i);
	else dipping(i);
}



template<typename T>
bool Dheap<T>::IsFull()
{
	return (freepos == m );
}

template<typename T>
inline bool Dheap<T>::IsEmpty()
{
	return (freepos == 0);
}

template<typename T>
int Dheap<T>::getparid(int i)
{
	int res = i - 1 / d;
	return res;
}

template<typename T>
T Dheap<T>::checktop()
{
	return keys[0];
}
