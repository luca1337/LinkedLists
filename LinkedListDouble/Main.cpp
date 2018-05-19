#include "LinkedList.h"

int main()
{
	LinkedList<int> List;

	List.AppendLast(10);
	List.AppendLast(20);
	List.AppendLast(30);

	List.Traverse();

	getchar();

	return 0;
}