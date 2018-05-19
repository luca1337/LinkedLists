#pragma once

#include <iostream>

template <class T> struct Node
{
	T Data;
	Node* Next;
	Node* Prev;

	Node();
	Node(T elem);
};

template<class T>
inline Node<T>::Node()
{
	this->Data = NULL;
	this->Next = nullptr;
	this->Prev = nullptr;
}

template<class T>
inline Node<T>::Node(T elem)
{
	this->Data = elem;
	this->Next = nullptr;
	this->Prev = nullptr;
}
