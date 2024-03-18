#pragma once

class TData {
public:
  virtual TData* copy() const = 0;

  // Сравнение по коэффициентам
  virtual bool operator<(const TData&) const = 0;
  virtual bool operator<=(const TData&) const = 0;
  virtual bool operator>(const TData&) const = 0;
  virtual bool operator>=(const TData&) const = 0;
  virtual bool operator==(const TData&) const = 0;
  virtual bool operator!=(const TData&) const = 0;

  virtual void output_data() const = 0;
};

struct TNode {
  TData* data;
  TNode* pNext;

  TNode() {
    this->data = nullptr;
    this->pNext = nullptr;
  }

  TNode(const TData* data, TNode* pNext = nullptr) {
    this->data = data->copy();
    this->pNext = pNext;
  }
};

class TList {
// protected:
public:
  TNode* pFirst;
  TNode* pLast;
  TNode* pCurr;
  TNode* pStop;

  TList();
  TList (const TList&);
  TList (TNode*);
  ~TList();
  TNode* Search (const TData&);
  void InsertFirst (const TData&);
  void InsertLast (const TData&);
  void InsertBefore (const TData&, const TData&);
  void InsertAfter (const TData&, const TData&);
  void Remove (const TData&);
  void Clear();
  void Reset();
  void Next();
  TNode* GetCurr() const;
  bool IsEnded() const;
  bool IsEmpty() const;
  bool IsFull() const;
};

class THeadRingList : public TList {
public:
  TNode* pHead;

  THeadRingList();
  THeadRingList(const THeadRingList& ringL);
  ~THeadRingList();

  void InsertFirst(const TData& data);
  void InsertLast(const TData& data);
  void InsertToSort(const TData& data);
};