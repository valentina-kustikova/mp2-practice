#pragma once
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class dheap
{
	vector<T> keys;
	int d;
public:
	dheap();
	dheap(vector<T> keys, int d);
	dheap(const dheap& heap) = default;
	void sink(int idx);
	void rise(int idx);
	void transpose(int idx1, int idx2);
	void hilling();
	void insert(T key);
	void remove(int idx);
	T get_min_value();
	int minchild(int idx);
	bool is_empty() const;
};

template <typename T>
dheap<T>::dheap() : d(3) {
}

template <typename T>
dheap<T>::dheap(vector<T> keys, int d) {
	this->d = d;
	this->keys = keys;
	hilling();
}

template <typename T>
void dheap<T>::sink(int idx) {
	int c = minchild(idx);
	while (c != -1 && keys[c] < keys[idx]) {
		transpose(c, idx);
		idx = c;
		c = minchild(idx);
	}
}

template <typename T>
void dheap<T>::rise(int idx) {
	int p = (idx - 1) / d;
	while (p > 0) {
		if (keys[idx] < keys[p]) {
			transpose(p, idx);
		}
		idx = p;
		p = (idx - 1) / d;
	}
}

template <typename T>
void dheap<T>::transpose(int idx1, int idx2) {
	swap(keys[idx1], keys[idx2]);
}

template <typename T>
void dheap<T>::hilling() {
	for (int i = keys.size() - 1; i >= 0; i--) {
		sink(i);
	}
}

template <typename T>
void dheap<T>::insert(T key) {
	keys.push_back(key);
	rise(keys.size() - 1);
}

template <typename T>
void dheap<T>::remove(int idx) {
	if (idx < 0 || idx >= keys.size()) throw "Index error";

	swap(keys.back(), keys[idx]);
	keys.pop_back();
	sink(idx);
}

template <typename T>
T dheap<T>::get_min_value() {
	T tmp = keys.front();
	swap(keys.front(), keys.back());
	keys.pop_back();
	sink(0);
	return tmp;
}

template <typename T>
int dheap<T>::minchild(int idx) {
	if (idx * d + 1 >= keys.size()) return -1;
	int minidx = idx * d + 1;
	int idx1 = idx * d + 1;
	int idx2 = min(idx * d + d, (int)keys.size() - 1);
	for (int i = idx1; i <= idx2; i++) {
		if (keys[i] < keys[minidx])
			minidx = i;
	}
	return minidx;
}

template <typename T>
bool dheap<T>::is_empty() const {
	return keys.empty();
}
