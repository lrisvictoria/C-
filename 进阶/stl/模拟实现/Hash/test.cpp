#include <iostream>

using namespace std;

#include "HashTable.h"

//int main()
//{
//	open_address::HashTable<int, int> ht;
//	int a[] = { 1, 111, 4, 7, 15, 25, 44, 9 };
//	for (auto e : a)
//	{
//		ht.Insert(make_pair(e, e));
//	}
//
//	// HashTable<string, string, StringHashFunc> dict; // key 有可能不能取模，走两层映射，不是整形想办法让它变成整形
//	open_address::HashTable<string, string> dict; // 模板特化
//	dict.Insert(make_pair("sort", "排序"));
//	dict.Insert(make_pair("left", "xxx"));
//	auto dret = dict.Find("left");
//	//dret->_kv.first = "xx";
//	dret->_kv.second = "左边";
//
//	auto ret = ht.Find(4);
//	// ret->_kv.first = 41;
//	ret->_kv.second = 400;
//
//	return 0;
//}

//int main()
//{
//	hash_bucket::HashTable<int, int> ht;
//
//	int a[] = { 1, 111, 4, 7, 15, 25, 44 ,9 };
//
//	for (auto e : a)
//	{
//		ht.Insert(make_pair(e, e));
//	}
//
//	/*ht.Print();
//
//	ht.Insert(make_pair(14, 14));
//	ht.Print();
//
//	ht.Insert(make_pair(24, 24));
//	ht.Print();
//
//	ht.Insert(make_pair(34, 34));
//	ht.Print();
//
//	ht.Erase(44);
//	ht.Erase(4);
//	ht.Erase(24);
//	*/
//
//	ht.Print();
//	
//
//	/*hash_bucket::HashTable<int, int> ht1(ht);
//	hash_bucket::HashTable<int, int> ht2;
//	ht2 = ht1;
//
//	ht1.Print();
//	ht2.Print();*/
//
//	hash_bucket::HashTable<string, string> dict; // 模板特化
//	dict.Insert(make_pair("sort", "排序"));
//	dict.Insert(make_pair("left", "xxx"));
//	auto dret = dict.Find("left");
//	//dret->_kv.first = "xx";
//	dret->_kv.second = "左边";
//	dict.Print();
//
//	return 0;
//}

#include "UnorderedMap.h"
#include "UnorderedSet.h"

int main()
{

	lx::unordered_set<int> us;
	us.insert(3);
	us.insert(1);
	us.insert(3);
	us.insert(4);
	us.insert(5);
	us.insert(0);

	lx::unordered_map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("insert", "插入"));
	dict.insert(make_pair("sort", "xxx"));

	lx::unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	/*lx::unordered_map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("left", "左边"));
	dict.insert(make_pair("insert", "插入"));
	dict.insert(make_pair("sort", "xxx"));*/


	/*dict["sort"] = "排序";
	dict["insert"] = "插入";
	dict["string"] = "字符串";
	dict["left"];*/

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}