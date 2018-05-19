#pragma once

template <class T> struct LinkedListNode
{
	T Data;
	LinkedListNode<T>* Next;

	LinkedListNode(T elem)
	{
		this->Data = elem;
		this->Next = nullptr;
	}

	LinkedListNode()
	{
		this->Data = NULL;
		this->Next = nullptr;
	}
};