#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SingleLinkedListTests
{		
	TEST_CLASS(LInkedListTest)
	{
	public:
		
		TEST_METHOD(TestLinkedListInitialization)
		{
			LinkedListSingle<int> List;

			Assert::IsNotNull(&List);
		}

		TEST_METHOD(TestLinkedListContains)
		{
			LinkedListSingle<int> List;

			for (size_t i = 0; i < 10; i++)
			{
				List.AppendFirst(i);
			}

			Assert::AreEqual((unsigned)10, List.Size());
		}

		TEST_METHOD(TestLinkedListAddRemove)
		{
			LinkedListSingle<int> List;

			for (size_t i = 0; i < 10; i++)
			{
				List.AppendFirst(i);
			}

			Assert::AreEqual((unsigned)10, List.Size());

			List.Remove(5);
			List.Remove(8);

			Assert::AreEqual((unsigned)8, List.Size());
		}

		TEST_METHOD(TestLinkedListHeadHasNextAndData)
		{
			LinkedListSingle<int> List;

			List.AppendFirst(10);
			List.AppendFirst(20);
			List.AppendFirst(30);
			List.AppendFirst(40);

			Assert::AreEqual((unsigned)4, List.Size());

			Assert::IsNotNull(List.First()->Next);
			Assert::AreEqual(List.First()->Next->Data, 30);
		}

	};
}