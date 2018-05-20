#pragma once

#include "Node.h"

#include <iostream>
#include <string>

template <class T> class LinkedList
{

public:
	LinkedList();
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
inline Node<T>* LinkedList<T>::AddAfter(Node<T>* node, T elem)
{
	return NULL;
}

template<class T>
inline void LinkedList<T>::AddAfter(Node<T>* node, Node<T>* newNode)
{

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
