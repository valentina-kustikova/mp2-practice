#ifndef _NODE_H
#define _NODE_H

#include <iostream>

#include "Data.h"
#include "TabRecord.h"

using namespace std;

template<typename TKey,typename TData> class Node: public TTabRecord<TKey,TData> {
public:
	Node<TKey, TData>* pNext;

	//массив указателей на списки.
	//Для списков меняются только параметры TKey,TData. Добавить их.
	//Перегрузить вставку,поиск и удаление после этого
	Node();
	Node(TKey key_,const Data<TData>* data_);
	Node(const Node& Node_);
	~Node();
};

template<typename TKey,typename TData>
Node<TKey,TData>::Node() {
	key = {};
	data = {};
	pNext = nullptr;
}

template<typename TKey, typename TData>
Node<TKey, TData>::Node(TKey key_,const Data<TData>* data_) {
	key = key_;
	data = new Data<TData>(data_->key);
	pNext = nullptr;
}

template<typename TKey, typename TData>
Node<TKey, TData>::Node(const Node<TKey,TData>& Node_) {
	key = Node_.key;
	data = new Data<TData>(Node_->data);
	pNext = new Node<TKey,TData>(Node_.pNext->data);
}

template<typename TKey, typename TData>
Node<TKey, TData>::~Node() {
	delete pNext;
	key = {};
	data = {};

}


#endif
