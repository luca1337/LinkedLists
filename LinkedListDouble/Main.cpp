#include "LinkedList.h"

int main()
{
	LinkedList<int> List;

	List.AppendLast(20);
	List.AppendLast(30);
	List.AppendLast(40);

	Node<int> find = Node<int>(30);

	List.AddAfter(&find, 35);

	LinkedList<int> List2;

	List2 = std::move(List);

	List.Traverse();

	getchar();

	return 0;
}