#pragma once
#include "arrayHash .h"

template<typename TData, typename TKey>
class HashTable : public ArrayHash<TData, TKey>
{
protected:
	int hashFunc(const TKey& Key);
	int hashFunc2(int pos);
public:
	HashTable(int maxSize = 10, int step = 1) : ArrayHash<TData, TKey>(maxSize)
	{
		hashStep = step;
		pMark = new char[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			pMark[i] = 0; // пусто
		}
	};

	void Insert(const TData Data, const TKey Key);
	TData* Search(const TKey Key);
	void Delete(const TKey Key);
	void Clear();
	//template <class TData> friend ostream& operator<<(ostream& os, HashTable<TData, TKey>& T1)
	//{
	//	if (T1.count)
	//	{
	//		int i = 0;
	//		for (T1.Reset(); !T1.IsTabEnded(); T1.Next())
	//		{
	//			if (T1.pMark[i] && T1.pMark[i] != -1)
	//			{
	//				os << "\t" << T1.GetKey() << " | " << *(T1.GetData()) << '\n';
	//				
	//			}
	//			i++;
	//		}
	//	}
	//	else
	//	{
	//		os << "\n\tTable is Empty\n" << endl;
	//	}
	//	return os;
	//	/*int i = 0;
	//	for (Tab.Reset(); !Tab.IsTabEnded(); Tab.Next())
	//	{
	//			os << "\t" << left << Tab.GetKey() << " | " << *(Tab.GetData()) << '\n';

	//	}
	//	return os;
	//}*/
	//}

	template <class TData> friend ostream& operator<<(ostream& os, HashTable<TData, TKey>& T1) {
		if (T1.count)
		{
			
			for (int i = 0; i < T1.maxSize; i++)
			{
				if (T1.pMark[i] && T1.pMark[i] != -1)
				{
					os << "\t" << T1.rec[i]->GetKey() << " | " << *(T1.rec[i]->GetData()) << '\n';
					
				}
			}
		}
		else
		{
			os << "\n\tTable is Empty\n" << endl;
		}
		return os;
	}

};

template<typename TData, typename TKey>
inline int HashTable<TData, TKey>::hashFunc(const TKey& Key)
{
	int result = 0;
	for (int i = 0; i < Key.length(); i++) {
		result = result + int(Key[i]);
	}
	return result % maxSize;
}

template<typename TData, typename TKey>
inline int HashTable<TData, TKey>::hashFunc2(int pos)
{
	return (pos + hashStep) % this->maxSize;
}


template<typename TData, typename TKey>
inline void HashTable<TData, TKey>::Insert(const TData Data, const TKey Key)
{
	if (IsFull()) {
		throw 1;
	}
	

	index = hashFunc(Key);
		if (pMark[index] != 1) {
			rec[index] = new TabRecord<TData, TKey>(Key, Data);
			count++;
			pMark[index] = 1;
		}
		else {
			while (pMark[index] != 0) {
				index = hashFunc2(index);
			}
			rec[index] = new TabRecord<TData, TKey>(Key, Data);
			count++;
			pMark[index] = 1;
		}
}


template<typename TData, typename TKey>
inline void HashTable<TData, TKey>::Clear()
{
	if (!IsEmpty())
	{
		Reset();
		while (index < maxSize)
		{
			rec[index] = new TabRecord<TData, TKey>;
			index++;
			pMark[index] = -1;
		}
	     count = 0;

	}

}

template<typename TData, typename TKey>
inline TData* HashTable<TData, TKey>::Search(const TKey Key)
{
	Reset();
	if (count != 0) {
		index = hashFunc(Key);
		int tmp = index;
		if (pMark[index] != 0 && rec[index]->GetKey() == Key) {
			return rec[index]->GetData();
		}
		else {
			while ((index < count) && pMark[index] != 0 && rec[index]->GetKey() != Key  && (index + hashStep != tmp)) {
				index = hashFunc2(index);
			}
			if (pMark[index] != 0 && rec[index]->GetKey() == Key) {
				return rec[index]->GetData();
			}else
				return nullptr;
		}
	}
	else {
		return nullptr;
	}


}

template<typename TData, typename TKey>
inline void HashTable<TData, TKey>::Delete(const TKey Key)
{
	if (Search(Key) != nullptr) {

		
		rec[index] = new TabRecord<TData, TKey>(std::string("delete"), *GetData());
		pMark[index] = -1;
		count--;

	}
	else {
		throw "the element does not exist";
	}
}


