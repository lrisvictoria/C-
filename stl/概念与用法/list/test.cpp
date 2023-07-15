// list 底层是双向带头循环链表

#include <iostream>
#include <list>

using namespace std;

int main()
{
	// 没有 reserve or resize ，不需要开连续的空间
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	// 只能用迭代器遍历，没有 []
	// 可以重载 [] ，但是最后遍历一遍为 n^2

	auto it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << ' ';
	}
	cout << endl;

	return 0;
}