#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

class HashTable : public Table {
protected:
	int hashFunc(const Tkey key);
public:
	HashTable(int n) : Table(n) {}
};

#endif