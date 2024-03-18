#ifndef _TRINGLIST_H
#define _TRINGLIST_H

#include "TList.h"

template <typename T> class TRingList : public TList<T> {
protected:
	Node<T>* pHead;
public:
	TRingList();
	TRingList(Node<T>* pFirst);
	TRingList(const TRingList<T>& rList);
	~TRingList();

	void RecoveryDummyBlock();
};

	template<typename T>		
	TRingList<T>::TRingList():TList(){
		pHead = new Node<T>();
		pHead->pNext = GetPFirst();
		SetPStop(pHead);
	}

	template <typename T>
	TRingList<T>::TRingList(Node<T>* pFirst) : TList<T>(pFirst) {
		if (pFirst != nullptr) {
			pHead = new Node<T>();
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
		Node<T>* tmp = GetPFirst();
		while (tmp->pNext != nullptr) {
			pPrev = tmp;
			tmp = tmp->pNext;
		}
		tmp->pNext = GetPFirst();
		SetPStop(tmp);
		SetPLast(pPrev);

	}

	template<typename T>
	TRingList<T>::~TRingList() {
		pHead = nullptr;
	}

	template<typename T>
	void TRingList<T>::RecoveryDummyBlock() {
		Node<T>* tmp_pStop = GetPStop();
		if (tmp_pStop == nullptr) {
			tmp_pStop = pHead;
		}
	}

#endif