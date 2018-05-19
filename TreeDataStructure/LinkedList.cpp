#include "LinkedList.h"

//https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

LinkedList::LinkedList()
{
	this->Head = nullptr;
	this->Tail = nullptr;
	this->Count = 0;
}

void LinkedList::AppendLast(int value)
{
	LinkedListItem* TempItem = new LinkedListItem();

	//create a temp item and check if the head is null, if the head is null
	//means we have no items inside the list so it's empty

	TempItem->Data = value;
	TempItem->Next = nullptr;

	//if the head is null it means this is the first element to be added inside that list
	//this first item is both head and both tail!
	//--------------------------------------------------
	// head-> |0| <-tail (the first item is both t,h)
	//--------------------------------------------------
	if (this->Head == nullptr)
	{
		this->Head = TempItem;
		this->Tail = TempItem;
		TempItem = nullptr;
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

}

void LinkedList::AppendFirst(int value)
{
	LinkedListItem* TempItem = new LinkedListItem();
	LinkedListItem* NewHead = new LinkedListItem();

	TempItem->Data = value;
	TempItem->Next = nullptr;

	//the first added element of the list will always be the tail

	if (!this->Head)
	{
		this->Head = TempItem;
		this->Tail = TempItem;
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
}

void LinkedList::RemoveFirst()
{
	LinkedListItem* Temp = new LinkedListItem();

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

void LinkedList::RemoveLast()
{
	LinkedListItem* CurrNode = new LinkedListItem();
	LinkedListItem* PrevNode = new LinkedListItem();

	CurrNode = this->Head;

	while (CurrNode->Next)
	{
		PrevNode = CurrNode;
		CurrNode = CurrNode->Next;
	}

	this->Tail = PrevNode;
	PrevNode->Next = nullptr;
	delete CurrNode;

}

void LinkedList::Traverse()
{
	LinkedListItem* Temp = new LinkedListItem();

	Temp = this->Head; //head is first element 

	// head-> |0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|0|.. <-tail 

	//starting from tail we iterate the list until the "next" is nullptr

	while (Temp!=nullptr) 
	{
		std::cout << "Data: " << Temp->Data << std::endl;
		Temp = Temp->Next;
	}
}
