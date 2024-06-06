#ifndef _ARRAYHASHTABLE_H_
#define _ARRAYHASHTABLE_H_

#include"Hashtable.h"

#include <iostream>
#include <functional>

using namespace std;

template<typename TKey, typename TData>
class TArrayHashTable : public THashTable<TKey, TData>
{
protected:

	size_t hash_step;
	TTabRecord<TKey, TData>** recs;
	TTabRecord<TKey, TData>* pMark;
	int _freepos_ind;

	size_t hash_func(const TKey& _key);
	size_t get_next_pos(size_t ind);

	void coprime(size_t _maxSize, size_t _hash_step);

public:

	TArrayHashTable(size_t _maxSize = 100, size_t _hashStep = 11);
	TArrayHashTable(const TArrayHashTable<TKey, TData>& aht);
	virtual ~TArrayHashTable();

	void Insert(const TKey& _key, TData* _data);
	void Remove(const TKey& _key);
	TTabRecord<TKey, TData>* Find(const TKey& _key);

	bool Reset() noexcept;
	bool Next() noexcept;

	friend std::ostream& operator<<(std::ostream& out, TArrayHashTable<TKey, TData>& aht)
	{
		if (aht.IsEmpty())
		{
			out << "table is empty" << endl;
			return out;
		}
		cout << "______________________________" << endl;
		for (int i = 0; i < aht.GetMaxSize(); i++)
		{
			if (aht.recs[i] != aht.pMark && aht.recs[i] != nullptr)
			{
				out /*<< "|" << aht.recs[i]->GetKey() << "|"*/ << *(aht.recs[i]->GetData()) << endl;
			}
		}
		return out;
	}

};

template<typename TKey, typename TData>
size_t TArrayHashTable<TKey, TData>::hash_func(const TKey& _key)
{
	std::hash<TKey> hasher;
	return hasher(_key) % (this->maxSize);
}



template<typename TKey, typename TData>
size_t TArrayHashTable<TKey, TData>::get_next_pos(size_t ind)
{
	return(ind + hash_step) % this->maxSize;
}

template<typename TKey, typename TData>
void TArrayHashTable<TKey, TData>::coprime(size_t _maxSize, size_t _hash_step)
{
	if (_maxSize <= 0)
	{
		throw "Error: _maxSize should be greater than 0";
	}

	if (_hash_step <= 0)
	{
		throw "Error: _hash_step should be greater than 0";
	}

	size_t a = _maxSize;
	size_t b = _hash_step;
	while (b != 0)
	{
		size_t tmp = b;
		b = a % b;
		a = tmp;
	}
	if (a != 1)
	{
		throw "Error: _maxSize and _hash_step are not coprime";
	}
}


template<typename TKey, typename TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(size_t _maxSize, size_t _hashStep) : THashTable<TKey, TData>(_maxSize)
{
	coprime(_maxSize, _hashStep);

	recs = new TTabRecord<TKey, TData>*[this->maxSize];
	for (int i = 0; i < this->maxSize; i++)
	{
		recs[i] = nullptr;
	}

	hash_step = _hashStep;
	pMark = new TTabRecord<TKey, TData>();
	/*_freepos_ind = 0;*/
	_freepos_ind = -1;



}

template<typename TKey, typename TData>
TArrayHashTable<TKey, TData>::TArrayHashTable(const TArrayHashTable<TKey, TData>& aht)
{
	this->maxSize = aht.maxSize;
	this->count = aht.count;
	hash_step = aht.hash_step;
	this->currPos = aht.currPos;
	_freepos_ind = aht._freepos_ind;

	recs = new TTabRecord<TKey, TData>*[this->maxSize];
	pMark = new TTabRecord<TKey, TData>();

	for (int i = 0; i < this->maxSize; i++)
	{

		TTabRecord<TKey, TData>* tmp = aht.recs[i];

		if (tmp == nullptr)
			recs[i] = tmp;
		else if (tmp == aht.pMark)
			recs[i] = pMark;
		else
			recs[i] = new TTabRecord<TKey, TData>(*tmp);

	}

}

template<typename TKey, typename TData>
TArrayHashTable<TKey, TData>::~TArrayHashTable()
{
	/*for (int i = 0; i < this->maxSize; i++)
	{
		if (recs[i] != nullptr)
		{
			delete recs[i];
		}
		if (recs[i] == pMark)
		{
			recs[i] = nullptr;
		}
	}
	if (recs) delete[] recs;
	if (pMark) delete pMark;*/
	for (int i = 0; i < this->maxSize; i++)
	{
		if (recs[i] != nullptr && recs[i] != pMark)
		{
			delete recs[i];
		}

	}
	if (recs) delete[] recs;
	if (pMark) delete pMark;
}

template<typename TKey, typename TData>
void TArrayHashTable<TKey, TData>::Insert(const TKey& _key, TData* _data)
{
	if (this->IsFull())
	{
		throw"Error";
	}
	TTabRecord<TKey, TData>* foundRecord = Find(_key);
	if (foundRecord != nullptr && foundRecord->GetKey() == _key)
	{
		throw"Error";
	}
	if (foundRecord != nullptr && _freepos_ind != -1)
	{
		this->currPos = _freepos_ind;
	}
	recs[this->currPos] = new TTabRecord<TKey, TData>(_key, _data);
	this->count++;

}

template<typename TKey, typename TData>
void TArrayHashTable<TKey, TData>::Remove(const TKey& _key)
{
	if (this->IsEmpty())
	{
		throw"Error";
	}
	TTabRecord<TKey, TData>* tmp = Find(_key);

	if (tmp == nullptr)
	{
		throw"Error";
	}
	delete tmp;
	recs[this->currPos] = pMark;
	_freepos_ind = -1;
	this->count--;
}



template<typename TKey, typename TData>
TTabRecord<TKey, TData>* TArrayHashTable<TKey, TData>::Find(const TKey& _key)
{
	this->currPos = hash_func(_key);
	for (int i = 0; i < this->maxSize; i++)
	{
		if (recs[this->currPos] == nullptr)
			return nullptr;

		else if (recs[this->currPos] == pMark && _freepos_ind == -1)
			_freepos_ind = this->currPos;

		else if (recs[this->currPos]->GetKey() == _key)
			return recs[this->currPos];

		this->currPos = get_next_pos(this->currPos);
	}
	return nullptr;
}





template<typename TKey, typename TData>
bool TArrayHashTable<TKey, TData>::Reset() noexcept
{
	this->currPos = 0;
	while (!this->IsTabEnded())
	{
		if (recs[this->currPos] != nullptr && recs[this->currPos] != pMark)
			break;
		this->currPos++;
	}
	return !this->IsTabEnded();

}

template<typename TKey, typename TData>
bool TArrayHashTable<TKey, TData>::Next() noexcept
{
	this->currPos++;
	while (!this->IsTabEnded())
	{
		if (recs[this->currPos] != nullptr && recs[this->currPos] != pMark)
			break;
		this->currPos++;
	}
	return !this->IsTabEnded();
}

















#endif // !_ARRAYHASHTABLE_H_


