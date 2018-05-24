#pragma once

#include "Node.h"

#include <iostream>
#include <string>

template <class T> class LinkedList
{

public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	LinkedList(LinkedList<T>&& other) noexcept;
	LinkedList<T>& operator=(LinkedList<T>&& other);
	Node<T>* AddAfter(Node<T>* node, T elem);
	void AddAfter(Node<T>* node, Node<T>* newNode);
	Node<T>* AddBefore(Node<T>* node, T elem);
	void AddBefore(Node<T>* node, Node<T>* newNode);
	Node<T>* AppendFirst(T elem);
	void AppendFirst(Node<T>* node);
	Node<T>* AppendLast(T elem);
	void AppendLast(Node<T>* node);
	Node<T>* Find(T elem);

	void Traverse();
	void TraverseReverse();

private:
	Node<T>* Head;
	Node<T>* Tail;
	int Count;

};

template<class T>
inline LinkedList<T>::LinkedList()
{
	this->Head = nullptr;
	this->Tail = nullptr;
	this->Count = 1;
}

template<class T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
	Node<T>* TempHead = other.Head;

	while (TempHead != nullptr)
	{
		this->AppendLast(TempHead->Data);
		TempHead = TempHead->Next;
	}
}

template<class T>
inline LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept
{
	Node<T>* TempHead = other.Head;
	std::cout << "move ctor called" << std::endl;
	while (TempHead != nullptr)
	{
		std::move(this->AppendLast(TempHead->Data));
		TempHead = TempHead->Next;
	}
}

template<class T>
inline LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other)
{
	// TODO: inserire l'istruzione return qui
	Node<T>* TempHead = other.Head;
	std::cout << "move ass called" << std::endl;
	while (TempHead != nullptr)
	{
		std::move(this->AppendLast(TempHead->Data));
		TempHead->Prev = nullptr;;
		TempHead = TempHead->Next;
	}

	return *this;
}

template<class T>
inline Node<T>* LinkedList<T>::AddAfter(Node<T>* node, T elem)
{
	Node<T>* ToFind = this->Find(node->Data);
	Node<T>* NewNode = new Node<T>(elem);
	Node<T>* Temp = new Node<T>();

	if (!this->Head) {
		this->Head = NewNode;
		this->Tail = NewNode;
		this->Head->Next = this->Tail;
		this->Tail->Prev = this->Head;
	}

	if (ToFind == this->Tail)
	{
		this->Tail->Next = NewNode;
		NewNode->Prev = this->Tail;
		this->Tail = NewNode;
		return NewNode;
	}
	else
	{
		Temp = ToFind->Next;
		ToFind->Next = NewNode;
		NewNode->Next = Temp;
		Temp->Prev = NewNode;
		NewNode->Prev = ToFind;
		return NewNode;
	}
}

template<class T>
inline void LinkedList<T>::AddAfter(Node<T>* node, Node<T>* newNode)
{
	Node<T>* ToFind = this->Find(node->Data);
	Node<T>* Temp = new Node<T>();

	if (!this->Head) {
		this->Head = NewNode;
		this->Tail = NewNode;
		this->Head->Next = this->Tail;
		this->Tail->Prev = this->Head;
	}

	if (ToFind == this->Tail)
	{
		this->Tail->Next = newNode;
		newNode->Prev = this->Tail;
		this->Tail = newNode;
	}
	else
	{
		Temp = ToFind->Next;
		ToFind->Next = newNode;
		newNode->Next = Temp;
		Temp->Prev = newNode;
		newNode->Prev = ToFind;
	}
}

template<class T>
inline Node<T>* LinkedList<T>::AddBefore(Node<T>* node, T elem)
{
	Node<T>* ToFind = this->Find(node->Data);
	Node<T>* ToAdd = new Node<T>(elem);
	Node<T>* Temp = new Node<T>();

	if (ToFind == this->Head) //adding before head
	{
		Temp = this->Head;
		this->Head->Prev = ToAdd;
		this->Head = ToAdd;
		ToAdd->Next = Temp;
	}
	else // in any other situation
	{
		Temp = ToFind->Prev;
		ToFind->Prev = ToAdd;
		ToAdd->Next = ToFind;
		Temp->Next = ToAdd;
		ToAdd->Prev = Temp;
	}

	return ToAdd;
}

template<class T>
inline void LinkedList<T>::AddBefore(Node<T>* node, Node<T>* newNode)
{
}

template<class T>
inline Node<T>* LinkedList<T>::AppendFirst(T elem)
{
	return NULL;
}

template<class T>
inline void LinkedList<T>::AppendFirst(Node<T>* node)
{
}

template<class T>
inline Node<T>* LinkedList<T>::AppendLast(T elem)
{
	Node<T>* Temp = new Node<T>(elem);

	if (!this->Head)
	{
		this->Head = Temp;
		this->Tail = Temp;
	}
	else if (this->Head == this->Tail)
	{
		Temp->Prev = this->Tail;
		this->Tail->Next = Temp;
		this->Tail = Temp;
	}
	else
	{
		this->Tail->Next = Temp;
		Temp->Prev = this->Tail;
		this->Tail = Temp;

	}
	this->Count++;
	return Temp;
}

template<class T>
inline void LinkedList<T>::AppendLast(Node<T>* node)
{
	Node<T>* Temp = new Node<T>(elem);

	if (!this->Head)
	{
		this->Head = Temp;
		this->Tail = Temp;
	}
	else
	{
		Temp->Prev = this->Tail;
		this->Tail->Next = Temp;
		this->Tail = Temp;
	}
	this->Count++;
}

template<class T>
inline Node<T>* LinkedList<T>::Find(T elem)
{
	//given a value find and return a copy of the found element

	Node<T>* ToFind = new Node<T>(elem);
	Node<T>* Current = new Node<T>();

	Current = this->Head;

	//iterate the linked list
	while (Current)
	{
		if (Current->Data == elem)
		{
			ToFind = Current;
			Current = nullptr;
			return ToFind;
		}

		Current = Current->Next;
	}
	return nullptr;
}

template<class T>
inline void LinkedList<T>::Traverse()
{
	Node<T>* Temp = new Node<T>();
	Temp = this->Head;

	std::cout << "------START--------" << std::endl;
	std::cout << "Head: " << this->Head->Data << std::endl;
	std::cout << "Tail: " << this->Tail->Data << std::endl;
	std::cout << "" << std::endl;

	while (Temp)
	{
		std::cout << "Element: " << Temp->Data << std::endl;
		Temp = Temp->Next;
	}
	std::cout << "------END--------" << std::endl;
	std::cout << "" << std::endl;
}

template<class T>
inline void LinkedList<T>::TraverseReverse()
{
	Node<T>* Temp = new Node<T>();
	Temp = this->Tail;

	std::cout << "------START--------" << std::endl;
	std::cout << "Head: " << this->Head->Data << std::endl;
	std::cout << "Tail: " << this->Tail->Data << std::endl;
	std::cout << "" << std::endl;

	while (Temp)
	{
		std::cout << "Element: " << Temp->Data << std::endl;
		Temp = Temp->Prev;
	}
	std::cout << "------END--------" << std::endl;
	std::cout << "" << std::endl;
}
