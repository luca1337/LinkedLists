#include "LinkedListSingle.h"

#include <string>

int main()
{

	LinkedListSingle<int> List;

	srand((unsigned)time(NULL));

	for (size_t i = 0; i < 20; i++)
	{
		List.AppendFirst(rand() % 150);
	}

	List.Traverse();

	List.Sort(NULL);

	List.Traverse();

	getchar();

	return 0;
}