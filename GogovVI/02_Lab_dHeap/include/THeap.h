#ifndef _THEAP_H_
#define _THEAP_H_
#include <iostream>

template<typename TData>
class THeap
{
	int max_size;
	int current_size;
	int base;
	TData* elements;

	friend class  HeapSort;

	void transpose(int i, int j);
	int min(int first, int second) const;
	int findMinChild(int i) const;
public:
	THeap<TData>(TData* elements_, int size, int base_ = 2);

	void popUp(int i);
	void dipDown(int i);
	void hilling();

	const int GetCurrentSize() const;
	TData popMin();
	TData topMin();
	bool IsFull();
	bool IsEmpty();

	friend std::ostream& operator<< (std::ostream& out, THeap<TData>& heap)
	{
		for (int i = 0; i < heap.max_size; i++)
			out << heap.elements[i] << "|";
		out << "\n";
		return out;
	}
};

template<typename TData>
THeap<TData>::THeap(TData* elements_, int size, int base_)
{
	if (elements_ == nullptr)
		throw "Empty data.\n";
	if (size < 0)
		throw "The size must be positive.\n";
	if (base_ < 2)
		throw "Invalid base.\n";
	base = base_;
	max_size = size;
	current_size = size;
	elements = elements_;
	hilling();
}

template<typename TData>
void THeap<TData>::transpose(int i, int j)
{
	TData temp_elem = elements[i];
	elements[i] = elements[j];
	elements[j] = temp_elem;
}

template<typename TData>
inline int THeap<TData>::min(int first, int second) const
{
	return first < second ? first : second;
}

template<typename TData>
int THeap<TData>::findMinChild(int i) const
{
	if (i * base + 1 >= current_size)
		return -1;
	int firstChild, lastChild, minChild;
	firstChild = i * base + 1;
	lastChild = min(current_size - 1, base * (i + 1));
	minChild = firstChild;
	for (int i = firstChild + 1; i <= lastChild; i++)
		if (elements[i] < elements[minChild])
			minChild = i;
	return minChild;
}

template<typename TData>
void THeap<TData>::popUp(int i)
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
			break;
	}
}

template<typename TData>
void THeap<TData>::dipDown(int i)
{
	int minChild = findMinChild(i);
	while ((minChild != -1) && (elements[minChild] < elements[i]))
	{
		transpose(minChild, i);
		i = minChild;
		minChild = findMinChild(i);
	}
}

template<typename TData>
void THeap<TData>::hilling()
{
	for (int i = current_size - 1; i >= 0; i--)
		dipDown(i);
}

template<typename TData>
const inline int THeap<TData>::GetCurrentSize() const
{
	return current_size;
}

template<typename TData>
TData THeap<TData>::popMin()
{
	TData min = elements[0];
	elements[0] = elements[current_size - 1];
	current_size--;
	dipDown(0);
	return min;
}

template<typename TData>
TData THeap<TData>::topMin()
{
	return elements[0];
}

template<typename TData>
bool THeap<TData>::IsFull()
{
	return max_size == current_size;
}

template<typename TData>
bool THeap<TData>::IsEmpty()
{
	return current_size == 0;
}

#endif // !_THEAP_H_