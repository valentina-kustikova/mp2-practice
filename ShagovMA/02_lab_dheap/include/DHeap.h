#pragma once
#include <iostream>

template<typename TData>
class DHeap
{

	int max_size;
	int size;
	int base;
	TData* elements;

	void transpose(int i, int j);
	int min(int first, int second) const;
	int findMinChild(int i) const;
	
public:
	DHeap<TData>(TData* elements_, int size_, int base_ = 2);

	bool IsEmpty() const;

	int getSize() const;
	TData top();
	TData popMin();
	void popUp(int i);
	void dipDown(int i);
	void hilling();

	friend std::ostream& operator<< (std::ostream &out, DHeap<TData> &heap)
	{
		if (heap.size == 0)
		{
			out << "Heap is empty" << "\n";
		}
		for (int i = 0; i < heap.size; i++)
		{
			out << heap.elements[i] << "|";
		}
		out << "\n";
		return out;
	};

	friend class HeapsortAlgorithm;
};

template<typename TData>
DHeap<TData>::DHeap(TData* elements_, int size_, int base_)
{
	if (base_ <= 1)
	{
		throw "Incorrect base";
	}
	if (size_ <= 0)
	{
		throw "Incorrect size";
	}
	base = base_;
	max_size = size_;
	size = size_;
	elements = elements_;
	hilling();
}

template<typename TData>
void DHeap<TData>::transpose(int i, int j)
{
	TData temp_elem = elements[i];
	elements[i] = elements[j];
	elements[j] = temp_elem;
}

template<typename TData>
inline int DHeap<TData>::min(int first, int second) const
{
	return first < second ? first : second;
}

template<typename TData>
int DHeap<TData>::findMinChild(int i) const
{
	if (i * base + 1 >= size)
	{
		return -1;
	}
	int firstChild, lastChild, minChild;
	firstChild = i * base + 1;
	lastChild = min(size - 1, base * (i + 1));
	minChild = firstChild;
	for (int i = firstChild + 1; i <= lastChild; i++)
	{
		if (elements[i] < elements[minChild])
		{
			minChild = i;
		}
	}
	return minChild;
}

template<typename TData>
void DHeap<TData>::popUp(int i)
{
	while (i > 0)
	{
		int p = (i - 1) / base;
		if (elements[p] > elements[i])
		{
			transpose(i, p);
			i = p;
		}
		else
		{
			break;
		}
	}
}

template<typename TData>
void DHeap<TData>::dipDown(int i)
{
	int minChild = findMinChild(i);
	while ((minChild != -1) && (elements[minChild] < elements[i]))
	{
		transpose(i, minChild);
		i = minChild;
		minChild = findMinChild(i);
	}
}

template<typename TData>
void DHeap<TData>::hilling()
{
	for (int i = size - 1; i >= 0; i--)
	{
		dipDown(i);
	}
}

template<typename TData>
inline bool DHeap<TData>::IsEmpty() const
{
	return size == 0;
}

template<typename TData>
inline int DHeap<TData>::getSize() const
{
	return size;
}

template<typename TData>
inline TData DHeap<TData>::top()
{
	return elements[0];
}

template<typename TData>
TData DHeap<TData>::popMin()
{
	TData min = elements[0];
	elements[0] = elements[size - 1];
	size--;
	dipDown(0);
	return min;
}