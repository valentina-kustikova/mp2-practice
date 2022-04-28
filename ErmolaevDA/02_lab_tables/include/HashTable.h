
#include "Table.h"

// Класса Хеш-таблица
template <typename TData, typename TKey>
class HashTable : public Table<TData,TKey>
{
protected:
 TData a;
 bool DEL=0;  
 unsigned long HashFunc(const TKey& key) const;
 int HashFunc2(int pos) const;
 unsigned int hashStep;
 TabRecord<TData, TKey> *pMark;
 int freePos;
public:

 HashTable(unsigned int n = 100, int step = 1);
 ~HashTable();
 // Методы
 virtual void InsertRecord(const TData Data, const TKey Key);
 virtual void RemoveRecord(const TKey Key) ;
 virtual TData* FindRecord(const TKey Key);
 virtual void Clear();

 void SetNext();
 void Reset();


 friend ostream& operator<<(ostream& os, const HashTable<TData,TKey>& T1)
 { 
  if (T1.dataCount)
 { 
  for (int i = 0; i < T1.tabSize; i++)
   { 
  if ((T1.records[i]!=nullptr)&& (T1.records[i]->key != "deleted")) os << "Key:" << left << T1.records[i]->key << " |Polinom: " << *(T1.records[i]->data) << '\n';
  }

  }
 else
  { os << "\n\tTable is Empty\n" << endl;}
 return os;
 }
};

// Pелизация функциий для класса Хеш-таблиц
// Конструкторы, деструктор 


template <typename TData, typename TKey>
HashTable<TData, TKey>::HashTable(unsigned int n, int step): Table<TData,TKey>(n)
{
 if (n < 0) throw 1;
  this->records = new TabRecord<TData, TKey>*[this->tabSize];
 this->tabSize = n;
  hashStep = step;
 for (int i = 0; i < n; i++) {
 this->records[i] = nullptr;
 }
 this->currPos = this->dataCount;
 pMark = new TabRecord<TData, TKey>(std::string("deleted"));
}






template <typename TData, typename TKey>
HashTable<TData, TKey>::~HashTable()
{
 
}
// Методы 
template <typename TData, typename TKey>
unsigned long HashTable<TData, TKey>::HashFunc(const TKey& key) const
{
 unsigned long h = 0;
  for (int i = 0; i < key.length(); i++)
 {
 h = (h<<3)+ int(key[i]);
 }
  return h % this->tabSize;
}

template <typename TData, typename TKey>
int HashTable<TData, TKey>::HashFunc2(int pos) const
{
  return (pos + hashStep) % this->tabSize;
}

template <typename TData, typename TKey>
void HashTable<TData, TKey>::SetNext()
{
 if (!this->IsTabEnded())
 {
 while (++(this->currPos) <= this->tabSize)
  if ((this->records[this->currPos] != nullptr) && (this->records[this->currPos] != pMark))
  break;
 }
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::Reset()
{
 this->currPos = 0;
 if (!this->IsFull()) {
 while (this->currPos<this->tabSize) {
  if (this->records[this->currPos] != nullptr
  &&
  this->records[this->currPos] != pMark)
  break;
  else this->currPos++;
 }
 }
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::InsertRecord(const TData data1, const TKey key1)
{
 if (this->IsFull()) throw 1;
 else {
 freePos = -1;
 this->currPos = HashFunc(key1);
 for (int i = 0; i < this->tabSize; i++) {
  if (this->records[this->currPos] != nullptr && this->records[this->currPos]->key == key1)
  {
  break;
  }
  else if (this->records[this->currPos] == pMark && freePos < 0)
  freePos = this->currPos;
  else if ((this->records[this->currPos] == nullptr) && freePos < 0)
  {
  this->records[this->currPos] = new TabRecord<TData, TKey>(key1, data1);
  this->dataCount++;
  break;
  }
  else if (this->records[this->currPos] == nullptr && freePos > -1)
  {
  this->records[freePos] = new TabRecord<TData, TKey>(key1, data1);
  this->dataCount++;
  break;
  }
  this->currPos = HashFunc2(this->currPos);
 }
 
 }
}
template <typename TData, typename TKey>
TData* HashTable<TData, TKey>::FindRecord(const TKey key1)
{
 try {
 TData* rec = nullptr;
 if (!this->IsEmpty()) {
  freePos = -1;
  this->currPos = HashFunc(key1);
  for (int i = 0; i < this->tabSize; i++)
  {
  if (this->records[this->currPos] == nullptr) break;
  else if (this->records[this->currPos] == pMark)
  {
   if (freePos == -1) freePos = this->currPos;
  }
  else if ((this->records[this->currPos])->key == key1)
  {
   rec = this->records[this->currPos]->data;
   break;
  }
  this->currPos = HashFunc2(this->currPos);

  }
  if (rec == nullptr) {
  return rec;
  throw "Error Hash Find";
  }
  /*if (rec != nullptr)
  {
  DEL = 1;
  return rec;
  //throw "Error Hash Find"; 
  }
  else {
  DEL = 0;
  throw "Error Hash Find";
  }*/
 }
 return rec;
 }
 catch (const char* exception) {
 std::cerr << "Error: " << exception << '\n';
 }
}
template<typename TData, typename TKey>
inline void HashTable<TData, TKey>::Clear()
{
 if (!this->IsEmpty())
 {
 this->Reset();
    while (this->currPos<this->tabSize)
 {
  this->records[this->currPos] = pMark;
  //delete this->records[this->currPos];
  //this->records[this->currPos] = pMark;
  //Reset();
  //this->dataCount=;
  this->currPos++;
 }
 this->dataCount = 0;

 }
}
template <typename TData, typename TKey>
void HashTable<TData, TKey>::RemoveRecord(const TKey key1)
{

 try {
 if (FindRecord(key1) != nullptr) //&&DEL
 {
  if (this->records[this->currPos]->data != nullptr)
  this->records[this->currPos]->data = nullptr;
  delete this->records[this->currPos];
  this->records[this->currPos] = pMark;
      this->dataCount--;
 }
 else
 {
  throw "This key is not in the HashTable, it is impossible to execute RemoveRecord";
 }
 }
 catch (const char* exception)
 {
 std::cerr << "Error: " << exception << '\n';
 
 }
}
