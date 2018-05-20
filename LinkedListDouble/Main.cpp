#include "LinkedList.h"

int main()
{
	LinkedList<int> List;

	List.AppendLast(20);
	List.AppendLast(30);
	List.AppendLast(40);

	Node<int>* ToFind;

	Node<int>* Ret = List.AddBefore2(ToFind, 10);

	List.Traverse();

	getchar();

	return 0;
}