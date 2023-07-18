#include <iostream>
#include <list>

using namespace std;

#include "list.h"

void test()
{
	std::list<pair<int, int>> lt;
	// lt.push_back({ 1, 1 });
	std::list<pair<int, int>>::iterator it = lt.begin();

	printf("%p\n", it.operator->());
}

int main()
{
	//lx::test_list1();
	// test();
	lx::test_list2();

	return 0;
}