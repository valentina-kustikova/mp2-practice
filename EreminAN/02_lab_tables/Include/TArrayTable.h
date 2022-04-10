#pragma once
#include "Table.h" 

//Собственное, данный класс определяет, как будут храниться данные в таблице (последовательно в пямяти, т.е. в массиве);

#define TabMaxSize 40
enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };




template <typename TData>
class  TArrayTable : public Table<TData>
{
protected:
	TabRecord<TData>** pRecs;      // память для записей таблицы (массив указателей);
	int TabSize;                   // макс. возм.количество записей в таблице;
	int CurrPos;                  // номер текущей записи (нумерация с 0);
public:
	TArrayTable(int Size = TabMaxSize)
	{
		if (Size <= 0)
			Size = TabMaxSize;
		pRecs = new TabRecord<TData> * [Size];
		for (int i = 0; i < Size; i++)
			pRecs[i] = nullptr;
		TabSize = Size;
		DataCount = CurrPos = 0;    //DataCount - Текущее количество записей;

	}
	~TArrayTable()
	{
		for (int i = 0; i < DataCount; i++)
			delete pRecs[i];
		delete[] pRecs;
	}

	// информационные методы
	virtual int IsFull() const { return DataCount >= TabSize; }    // заполнена?
	int GetTabSize() const { return TabSize; }                    // к-во записей

	// доступ
	virtual TableKey GetKey() const { return GetKey(CURRENT_POS); }         //получить ключ по текущей позиции;
	virtual TData* GetData() const { return GetData(CURRENT_POS); }        //получить данные по текущей позиции;
	virtual TableKey GetKey(TDataPos mode) const;                         //Получить ключ по любой позиции;
	virtual TData* GetData(TDataPos mode) const;                         // Получить данные по любой позиции;

	// основные методы
	virtual TData* FindRecord(const TableKey key_) = 0;                     // найти запись
	virtual void InsRecord(const TableKey key_, TData* data_) = 0;         // вставить
	virtual void DelRecord(const TableKey key_) = 0;                      // удалить запись

	//навигация
	virtual void Reset() { CurrPos = 0; }                        // установить на первую запись
	virtual int IsTabEnded() const;                             // таблица завершена?
	virtual void GoNext();                                     // переход к следующей записи
															  //(=1 после применения для последней записи таблицы)

	virtual int SetCurrentPos(int pos);                    // установить текущую запись
	int GetCurrentPos() const { return CurrPos; }         //получить номер текущей записи
};


template <typename TData>
TableKey TArrayTable<TData>::GetKey(TDataPos mode) const
{
	int pos = -1;
	if (IsEmpty())
	{
		throw"Error";
	}
	switch (mode)
	{
	case FIRST_POS: pos = 0; break;
	case LAST_POS: pos = DataCount - 1; break;
	default: pos = CurrPos; break;
	}

	return (pos == -1) ? std::string("") : pRecs[pos]->GetKey();   //Т.е., если pos==-1 - недопустимое состояние(пусто), возвращаем пустую строку. Иначе, возвращаем ключ;
}

template <typename TData>
TData* TArrayTable<TData>::GetData(TDataPos mode) const
{
	int pos = -1;
	if (IsEmpty())
	{
		throw"Error";
	}
	switch (mode)
	{
	case FIRST_POS: pos = 0; break;
	case LAST_POS: pos = DataCount - 1; break;
	default: pos = CurrPos; break;
	}

	return (pos == -1) ? nullptr : pRecs[pos]->GetData();
}

template <typename TData>
int TArrayTable<TData>::IsTabEnded() const
{
	return CurrPos >= DataCount;
}

template <typename TData>
void TArrayTable<TData>::GoNext()
{
	if (!IsTabEnded())
		CurrPos++;
}

template <typename TData>
int TArrayTable<TData>::SetCurrentPos(int pos)
{
	CurrPos = ((pos > -1) && (pos < DataCount)) ? pos : 0;
	return IsTabEnded();
}