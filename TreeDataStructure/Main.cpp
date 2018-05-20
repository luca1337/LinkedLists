#include "LinkedListSingle.h"

#include <string>

int main()
{

	LinkedListSingle<int> List;

	srand((unsigned)time(NULL));

	List.AppendFirst(10);
	List.AppendFirst(20);
	List.AppendFirst(30);
	List.AppendFirst(40);

	List.Traverse();

	List.Sort(NULL);

	List.Traverse();

	getchar();

	return 0;
}