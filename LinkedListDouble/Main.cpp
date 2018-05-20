#include "LinkedList.h"

int main()
{
	LinkedList<int> List;

	List.AppendLast(20);

	Node<int>* ToFind = new Node<int>(20);

	Node<int>* Ret = List.AddBefore(ToFind, 75);

	List.Traverse();

	getchar();

	return 0;
}