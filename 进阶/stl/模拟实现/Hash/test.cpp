#include <iostream>

using namespace std;

#include "HashTable.h"

int main()
{
	HashTable<int, int> ht;
	int a[] = { 1, 111, 4, 7, 15, 25, 44, 9 };
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}

	//HashTable<string, string> dict; // key 有可能不能取模，走两层映射，不是整形想办法让它变成整形
	//dict.Insert(make_pair("sort", "排序"));
	//dict.Insert(make_pair("left", "xxx"));
	//auto dret = dict.Find("left");
	////dret->_kv.first = "xx";
	//dret->_kv.second = "左边";

	auto ret = ht.Find(4);
	// ret->_kv.first = 41;
	ret->_kv.second = 400;

	return 0;
}