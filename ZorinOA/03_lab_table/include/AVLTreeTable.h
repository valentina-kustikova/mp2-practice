#pragma once
#include "AVLTree.h"
#include "Table.h"

template <class TKey, class TData>
class TreeTable : public Table<TKey, TData>
{
protected:
	AVLTree<TKey, TData> Recs;
	TreeNode<TKey, TData>* curr;
public:
	TreeTable()
		:Table<TKey, TData>() {}
	virtual void Clear() override
	{
		Recs.Clear();
	}
	virtual bool isFull() const override
	{
		try
		{
			TreeNode<TKey, TData>* tmp = new TreeNode<TKey, TData>;
			bool b = (tmp == nullptr);
			delete tmp;
			return b;
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what() << std::endl;
			return true;
		}
	}
	virtual TData* Find(const TKey& k) override
	{
		return Recs.Find(k);
	}
	virtual bool Insert(const TKey& k, const TData& d) override
	{
		if (!isFull())
		{
			if (Recs.Insert(k, d))
			{
				this->DataCount++;
				return true;
			}
		}
		return false;
	}
	virtual bool Delete(const TKey& k) override
	{
		if (!this->isEmpty())
		{
			if (Recs.Delete(k))
			{
				this->DataCount--;
				return true;
			}
		}
		return false;
	}

	virtual void Reset() override
	{
		if (!Recs.isEmpty())
			curr = Recs.FindMin();
	}
	virtual bool isEnd() const override
	{
		return curr == nullptr;
	}
	virtual void goNext() override
	{
		curr = Recs.FindNext(curr);
	}
	virtual TKey getKey() const override
	{
		return (curr == nullptr) ? TKey() : curr->key;
	}
	virtual TData* getData() const override
	{
		return (curr == nullptr) ? nullptr : curr->data;
	}
};
