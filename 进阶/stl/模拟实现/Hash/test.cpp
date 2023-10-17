#include <iostream>

using namespace std;

//#include "HashTable.h"

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

//#include "UnorderedMap.h"
//#include "UnorderedSet.h"
//
//int main()
//{
//
//	lx::unordered_set<int> us;
//	us.insert(3);
//	us.insert(1);
//	us.insert(3);
//	us.insert(4);
//	us.insert(5);
//	us.insert(0);
//
//	lx::unordered_map<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert(make_pair("left", "左边"));
//	dict.insert(make_pair("insert", "插入"));
//	dict.insert(make_pair("sort", "xxx"));
//
//	lx::unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		// *it += 10;
//
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	lx::unordered_map<string, string>::iterator dit = dict.begin();
//	while (dit != dict.end())
//	{
//		// dit->first += 'x';
//		dit->second += 'x';
//
//		++dit;
//	}
//	cout << endl;
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	lx::unordered_set<int> us;
//	us.insert(1);
//
//	return 0;
//}

#include"BitSet.h"

//int main()
//{
//	lx::bitset<1000> bs;
//	bs.set(1);
//	bs.set(10);
//	bs.set(100);
//
//	cout << bs.test(1) << endl;
//	cout << bs.test(10) << endl;
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl<<endl;
//
//	bs.set(999);
//	bs.reset(10);
//
//	cout << bs.test(1) << endl;
//	cout << bs.test(10) << endl;
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl << endl;
//
//	//getchar();
//	
//	//lx::bitset<-1> bs1;
//	//bit::bitset<0xffffffff> bs2;
//
//	//getchar();
//
//	return 0;
//}

//int main()
//{
//	int a1[] = { 1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9 };
//	int a2[] = { 8,4,8,4,1,1,1,1 };
//
//	lx::bitset<10> bs1;
//	lx::bitset<10> bs2;
//
//	// 去重
//	for (auto e : a1)
//	{
//		bs1.set(e);
//	}
//
//	// 去重
//	for (auto e : a2)
//	{
//		bs2.set(e);
//	}
//
//	// 9：03继续
//	for (int i = 0; i < 10; i++)
//	{
//		if (bs1.test(i) && bs2.test(i))
//		{
//			cout << i << " ";
//		}
//	}
//	cout << endl;
//}

//#include <bitset>
//
//using namespace std;
//
//
//
//int main()
//{
//	bitset<15> b;
//	cout << sizeof(b) << endl;
//
//
//	return 0;
//}

#include"BloomFilter.h"

void TestBloomFilter()
{
	BloomFilter<11> bf;
	bf.Set("孙悟空");
	bf.Set("猪八戒");
	bf.Set("牛魔王");
	bf.Set("二郎神");

	cout << bf.Test("孙悟空") << endl;
	cout << bf.Test("猪八戒") << endl;
	cout << bf.Test("沙悟净") << endl;
}


void TestBloomFilter2()
{
	srand(time(0));
	const size_t N = 100000;
	BloomFilter<N * 8> bf;

	std::vector<std::string> v1;
	//std::string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	std::string url = "猪八戒";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(i));
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	// v2跟v1是相似字符串集（前缀一样），但是不一样
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string urlstr = url;
		urlstr += std::to_string(9999999 + i);
		v2.push_back(urlstr);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str)) // 误判
		{
			++n2;
		}
	}
	cout << "相似字符串误判率:" << (double)n2 / (double)N << endl;

	// 不相似字符串集
	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		//string url = "zhihu.com";
		string url = "孙悟空";
		url += std::to_string(i + rand());
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "不相似字符串误判率:" << (double)n3 / (double)N << endl;
}

int main()
{
	TestBloomFilter2();

	return 0;
}
