#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include "LinkedListNode.h"

#define CHECK_ERROR(x) if(!x)\
{\
	std::cout << "no elemts were found in the list" << std::endl;\
	return;\
}\

#define CHECK_ERROR_RET(x) if(!x)\
{\
	std::cout << "no elemts were found in the list" << std::endl;\
	return nullptr;\
}\

template <class T> class LinkedListSingle
{

public:
	LinkedListSingle();

	LinkedListNode<T>* AddAfter(LinkedListNode<T>* node, T elem);
	void AddAfter(LinkedListNode<T>* node, LinkedListNode<T>* newNode);
	LinkedListNode<T>* AppendLast(T elem);
	void AppendLast(LinkedListNode<T>* node);
	LinkedListNode<T>* AppendFirst(T elem);
	void AppendFirst(LinkedListNode<T>* node);
	LinkedListNode<T>* Find(T elem);
	LinkedListNode<T>* Reverse();
	LinkedListSingle<T> Shuffle();
	void Sort(bool(*Cmp)(void*, void*));
	void Remove(T elem);
	void Remove(LinkedListNode<T> node);
	void RemoveFirst();
	void RemoveLast();
	void Traverse();

	LinkedListNode<T>* First() const;
	LinkedListNode<T>* Last() const;
	unsigned Size();

private:
	static bool CompareElements(void* left, void* right)
	{
		return left > right;
	}

	LinkedListNode<T>* Head;
	LinkedListNode<T>* Tail;
	unsigned Count;

};

template<class T>
inline LinkedListSingle<T>::LinkedListSingle()
{
	this->Head = nullptr;
	this->Tail = nullptr;
	this->Count = 1;
}

template<class T>
inline LinkedListNode<T>* LinkedListSingle<T>::AddAfter(LinkedListNode<T>* node, T elem)
{
	LinkedListNode<T>* FoundNode = this->Find(node->Data);
	LinkedListNode<T>* Temp = new LinkedListNode<int>(elem);
	LinkedListNode<T>* OldNode = new LinkedListNode<int>();

	Temp->Data = elem;

	CHECK_ERROR(FoundNode);

	if (FoundNode == this->Head && FoundNode == this->Tail)
	{
		FoundNode->Next = Temp;
		this->Tail = Temp;
	}

	if (FoundNode == this->Tail)
	{
		Tail->Next = Temp;
		this->Tail = Temp;
	}

	else if (FoundNode == this->Head)
	{
		OldNode = this->Head->Next;
		this->Head->Next = Temp;
		Temp->Next = OldNode;
		delete OldNode;
		OldNode = nullptr;
	}
	else
	{
		Temp->Next = FoundNode->Next;
		FoundNode->Next = Temp;
	}

	this->Count++;

	return Temp;
}

template<class T>
inline void LinkedListSingle<T>::AddAfter(LinkedListNode<T>* node, LinkedListNode<T>* newNode)
{
	LinkedListNode<T>* FoundNode = this->Find(node->Data);
	LinkedListNode<T>* OldNode = new LinkedListNode<int>();

	if (!FoundNode)
	{
		std::cout << "no elemts were found in the list" << std::endl;
		return;
	}

	if (FoundNode == this->Head && FoundNode == this->Tail)
	{
		FoundNode->Next = newNode;
		this->Tail = newNode;
	}

	if (FoundNode == this->Tail)
	{
		Tail->Next = newNode;
		this->Tail = newNode;
	}

	else if (FoundNode == this->Head)
	{
		OldNode = this->Head->Next;
		this->Head->Next = newNode;
		newNode->Next = OldNode;
		delete OldNode;
		OldNode = nullptr;
	}
	else
	{
		newNode->Next = FoundNode->Next;
		FoundNode->Next = newNode;
	}

	this->Count++;
}

template<class T>
inline LinkedListNode<T>* LinkedListSingle<T>::AppendLast(T elem)
{
	LinkedListNode<T>* TempItem = new LinkedListNode<T>(elem);

	//create a temp item and check if the head is null, if the head is null
	//means we have no items inside the list so it's empty
	//TempItem->Next = nullptr;

	//if the head is null it means this is the first element to be added inside that list
	//this first item is both head and both tail!
	//--------------------------------------------------
	// head-> |0| <-tail (the first item is both t,h)
	//--------------------------------------------------
	if (this->Head == nullptr)
	{
		this->Head = TempItem;
		this->Tail = TempItem;
		return TempItem;
	}
	else
	{
		//if the head is not null, it means we already have 1 element inside that list
		//all we need to do is adda new element next to the previous one

		//-------------------------------------------------------------------
		//head-> |0|0| <- tail(head is the last element to be added, tail is the first one we added)
		//-------------------------------------------------------------------

		this->Tail->Next = TempItem;
		this->Tail = TempItem;
	}

	this->Count++;

	return TempItem;
}

template<class T>
inline void LinkedListSingle<T>::AppendLast(LinkedListNode<T>* node)
{
	if (!this->Head)
	{
		this->Head = node;
		this->Tail = node;
	}
	else
	{
		this->Tail->Next = node;
		this->Tail = node;
	}

	this->Count++;
}

template<class T>
inline LinkedListNode<T>* LinkedListSingle<T>::AppendFirst(T elem)
{
	LinkedListNode<T>* TempItem = new LinkedListNode<T>(elem);

	//the first added element of the list will always be the tail

	if (!this->Head)
	{
		this->Head = TempItem;
		this->Tail = TempItem;
		return TempItem;
	}
	else
	{
		//if thre is already at least 1 element we need to appent it before that element..
		//so the current head will become the new tail and the new element will become the new head
		// head-> |0|0| <-tail

		TempItem->Next = this->Head;
		this->Head = TempItem;
	}

	this->Count++;

	return TempItem;
}

template<class T>
inline void LinkedListSingle<T>::AppendFirst(LinkedListNode<T>* node)
{
	if (!this->Head)
	{
		this->Head = node;
		this->Tail = node;
	}
	else
	{
		//if thre is already at least 1 element we need to appent it before that element..
		//so the current head will become the new tail and the new element will become the new head
		// head-> |0|0| <-tail

		node->Next = this->Head;
		this->Head = node;
	}

	this->Count++;
}

template<class T>
inline LinkedListNode<T>* LinkedListSingle<T>::Find(T elem)
{
	if (!this->Head && !this->Tail)
	{
		std::cout << "list is empty" << std::endl;
	}

	LinkedListNode<T>* Temp = new LinkedListNode<T>();

	Temp = this->Head;

	while (Temp)
	{
		if (Temp->Data == elem)
		{
			return Temp;
		}

		Temp = Temp->Next;
	}

	if (!Temp)
	{
		return Temp;
	}

	return nullptr;
}

template<class T>
inline LinkedListNode<T>* LinkedListSingle<T>::Reverse()
{
	LinkedListNode<T>* Prev = nullptr;

	while (this->Head->Next)
	{
		LinkedListNode<T>* Next = this->Head->Next;
		this->Head->Next = Prev;
		Prev = Head;
		this->Head = Next;
	}

	this->Head->Next = Prev;

	return this->Head;
}

template<class T>
inline LinkedListSingle<T> LinkedListSingle<T>::Shuffle()
{
	//todo: implement shuffle 

	LinkedListSingle<T> Temp;
	srand((unsigned)time(NULL));

	for (unsigned int i = 0; i < this->Count; i++)
	{
		unsigned int random = (unsigned int)(((double)rand() / RAND_MAX) * this->Count);
		std::cout << "rand num: " << random << std::endl;
	}

	return Temp;
}

template<class T>
inline void LinkedListSingle<T>::Sort(bool(*Cmp)(void*, void*))
{
	if (this->Count < 1)
		return;

	if (!Cmp) Cmp = this->CompareElements;

	LinkedListNode<T>* First = this->Head;

	while (this->Count > 0)
	{
		this->Count--;
		if (First->Next == nullptr)
			break;

		for (unsigned i = 0; i < this->Count; i++)
		{
			int Cmp = this->CompareElements((void*)First->Data, (void*)First->Next->Data);

			if (Cmp)
			{
				T Elem = First->Data;
				First->Data = First->Next->Data;
				First->Next->Data = Elem;
			}
			First = First->Next;
		}
		First = this->Head;
	}
}

template<class T>
inline void LinkedListSingle<T>::Remove(T elem)
{
	LinkedListNode<T>* ToFind = this->Find(elem);
	LinkedListNode<T>* Temp = new LinkedListNode<T>();
	LinkedListNode<T>* Iter = new LinkedListNode<T>();

	if (!ToFind)
	{
		std::cout << "could not find the specified element.." << std::endl;
		return;
	}

	if (ToFind == this->Head && ToFind == this->Tail)
	{
		this->Head = nullptr;
		std::cout << "all elements have been removed" << std::endl;
	}
	else
	{
		if (ToFind != this->Head && ToFind != this->Tail)
		{
			Temp = ToFind->Next;
			Iter = this->Head;
			while (Iter)
			{
				if (Iter->Next == ToFind)
				{
					Iter->Next = nullptr;
					break;
				}

				Iter = Iter->Next;
			}

			Iter->Next = ToFind->Next;
		}
		else if (ToFind == this->Head)
		{
			Temp = this->Head->Next;
			this->Head = nullptr;
			this->Head = Temp;
		}
		else if (this->Head->Next != this->Tail)
		{
			Temp = this->Tail;
			this->Head = nullptr;
			this->Head = Temp;
		}
		else if (this->Head->Next == ToFind && ToFind == this->Tail)
		{
			this->RemoveLast();
		}
		else if (ToFind == this->Tail && ToFind == this->Head)
		{
			this->Head = nullptr;
			this->Tail = nullptr;
		}
	}

	this->Count--;
}

template<class T>
inline void LinkedListSingle<T>::Remove(LinkedListNode<T> node)
{
	LinkedListNode<T>* Temp = new LinkedListNode<T>();
	LinkedListNode<T>* Iter = new LinkedListNode<T>();

	if (!node)
	{
		std::cout << "could not find the specified element.." << std::endl;
		return;
	}

	if (node == this->Head && node == this->Tail)
	{
		this->Head = nullptr;
		std::cout << "all elements have been removed" << std::endl;
	}
	else
	{
		if (node != this->Head && node != this->Tail)
		{
			Temp = node->Next;
			Iter = this->Head;
			while (Iter)
			{
				if (Iter->Next == node)
				{
					Iter->Next = nullptr;
					break;
				}

				Iter = Iter->Next;
			}

			Iter->Next = node->Next;
		}
		else if (node == this->Head)
		{
			Temp = this->Head->Next;
			this->Head = nullptr;
			this->Head = this->Temp;
		}
		else if (node == this->Tail)
		{
			Temp = this->Tail;
			this->Head = nullptr;
			this->Head = this->Temp;
		}
	}
	this->Count--;
}

template<class T>
inline void LinkedListSingle<T>::RemoveFirst()
{
	LinkedListNode<T>* Temp = new LinkedListNode<T>();

	if (!this->Head && !this->Tail)
	{
		std::cout << "no elements in list" << std::endl;
		return;
	}

	Temp = this->Head->Next;
	delete this->Head;
	this->Head = nullptr;
	this->Head = Temp;
	delete Temp;
	this->Count--;
}

template<class T>
inline void LinkedListSingle<T>::RemoveLast()
{
	LinkedListNode<T>* CurrNode = new LinkedListNode<T>();
	LinkedListNode<T>* PrevNode = new LinkedListNode<T>();

	CurrNode = this->Head;

	while (CurrNode->Next)
	{
		PrevNode = CurrNode;
		CurrNode = CurrNode->Next;
	}

	this->Tail = PrevNode;
	PrevNode->Next = nullptr;
	delete CurrNode;
	this->Count--;
}

template<class T>
inline void LinkedListSingle<T>::Traverse()
{
	LinkedListNode<T>* Temp = new LinkedListNode<T>();

	Temp = this->Head; //head is first element 

	std::cout << "------START--------" << std::endl;
	std::cout << "Head: " << this->Head->Data << std::endl;
	std::cout << "Tail: " << this->Tail->Data << std::endl;
	std::cout << "" << std::endl;

	// head-> |0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|.. <-tail 
	//starting from tail we iterate the list until the "next" is nullptr

	while (Temp != nullptr)
	{
		std::cout << "Data: " << Temp->Data << std::endl;
		Temp = Temp->Next;
	}
	std::cout << "------END--------" << std::endl;
	std::cout << "" << std::endl;
}

template<class T>
inline LinkedListNode<T>* LinkedListSingle<T>::First() const
{
	return this->Head;
}

template<class T>
inline LinkedListNode<T>* LinkedListSingle<T>::Last() const
{
	return this->Tail;
}

template<class T>
inline unsigned LinkedListSingle<T>::Size()
{
	return this->Count;
}