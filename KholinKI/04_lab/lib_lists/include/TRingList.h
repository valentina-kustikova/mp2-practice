#ifndef _TRINGLIST_H
#define _TRINGLIST_H

#include "TList.h"

template <typename T> class TRingList : public TList<T> {
	//pHead как поле и тогда можно сделать метод создания pHead
public:
	TRingList();
	TRingList(Node<T>* pFirst);
	TRingList(const TRingList<T>& rList);
};

	template<typename T>		
	TRingList<T>::TRingList():TList(){
		Node<T>* pHead = new Node<T>();
		pHead->pNext = pHead;
		SetPStop(pHead);
	}

	template <typename T>
	TRingList<T>::TRingList(Node<T>* pFirst) : TList<T>(pFirst) {
		if (pFirst != nullptr) {
			Node<T>* pHead = new Node<T>();
			pHead->pNext = GetPFirst();
			SetPStop(pHead);
			Node<T>* tmp = GetPFirst();

			while (tmp->pNext != nullptr) {
				tmp = tmp->pNext;
			}

			tmp->pNext = pHead;
			SetPLast(tmp);
		}
	}

	template <typename T>
	TRingList<T>::TRingList(const TRingList<T>& rList) : TList<T>(rList) {
		Node<T>* pPrev = nullptr;
		Node<T>* tmp = GetCurrent();
		while (tmp->pNext != nullptr) {
			pPrev = tmp;
			tmp = tmp->pNext;
		}
		tmp->pNext = GetPFirst();
		SetPStop(tmp);
		SetPLast(pPrev);

	}


#endif