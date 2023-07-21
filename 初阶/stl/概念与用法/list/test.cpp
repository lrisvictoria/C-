// list 底层是双向带头循环链表

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

void test_list1()
{
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
}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(8);
	lt.push_back(4);

	lt.push_front(100);
	lt.push_front(1200);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 第五个位置插入数据，第六个值前面
	auto it = lt.begin();
	for (size_t i = 0; i < 5; i++)
	{
		++it;
	}
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << *it << endl;
	lt.insert(it, 30);
	cout << *it << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	it = find(lt.begin(), lt.end(), 100);
	if (it != lt.end())
	{
		// 在 100 前插入 60
		lt.insert(it, 60);

		*it *= 100; // 测试迭代器失效
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	it = find(lt.begin(), lt.end(), 3);
	if (it != lt.end())
	{
		lt.erase(it);

		// *it *= 100; // 删除，迭代器失效
	}

	// erase 所有的偶数
	it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			it = lt.erase(it); // 更新
		}
		else
		{
			++it;
		}
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(8);
	lt.push_back(4);

	lt.push_front(100);
	lt.push_front(1200);
	
	reverse(lt.begin(), lt.end());
	
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.reverse();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// sort(lt.begin(), lt.end());
	lt.sort();
}

void test_op1()
{
	srand(time(0));
	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	list<int> lt1;
	list<int> lt2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		lt2.push_back(e);
		lt1.push_back(e);
	}

	// 拷贝到vector排序，排完以后再拷贝回来
	int begin1 = clock();
	// 先拷贝到vector
	for (auto e : lt1)
	{
		v.push_back(e);
	}

	// 排序
	sort(v.begin(), v.end());

	// 拷贝回去
	size_t i = 0;
	for (auto& e : lt1)
	{
		e = v[i++];
	}

	int end1 = clock();

	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	printf("vector sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}

void test_op2()
{
	srand(time(0));
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);
	list<int> lt;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		v.push_back(e);
		lt.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	lt.sort();
	int end2 = clock();

	printf("vector sort:%d\n", end1 - begin1);
	printf("list sort:%d\n", end2 - begin2);
}

// 仿函数
bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}

void test_list4()
{
	// merge，对链表进行归并
	// 先 sort 再归并，否则不对

	std::list<double> first, second;

	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	first.sort();
	second.sort();

	first.merge(second);

	// (second is now empty)

	second.push_back(2.1);

	first.merge(second, mycomparison);

	std::cout << "first contains:";
	for (std::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	// unique
	// 去重也得先排序

	// remove = find + erase
	// void remove(const value_type& val)
	// 如果不存在这个值，也不会报错
}

void test_list5()
{
	list<int> lt;
	lt.push_back(4);
	lt.push_back(13);
	lt.push_back(15);
	lt.push_back(19);

	lt.remove(13);

	for (auto e : lt)
	{
		cout << e << ' ';
	}
	cout << endl;

	lt.remove(100);
	for (auto e : lt)
	{
		cout << e << ' ';
	}
	cout << endl;

}

void test_list6()
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2

	// mylist2 全部转移到 it 之前
	//mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
	//// mylist2 (empty)
	//// "it" still points to 2 (第五个元素)
	//cout << *it << endl;

	//for (auto e : mylist1)
	//{
	//	cout << e << ' ';
	//}
	//cout << endl;

	//for (auto e : mylist2)
	//{
	//	cout << e << ' ';
	//}
	//cout << endl;

	// 把 i 转移到 it 前面
	/*mylist1.splice(it, mylist2, --mylist2.end());
	for (auto e : mylist1)
	{
		cout << e << ' ';
	}
	cout << endl;

	for (auto e : mylist2)
	{
		cout << e << ' ';
	}
	cout << endl;*/

	//std::list<int>::iterator it2 = mylist2.begin();
	//++it2;
	//++it2;
	//cout << *it2 << endl;
	//// 把迭代器区间内的值转移，迭代器左闭右开
	//mylist1.splice(it, mylist2, ++mylist2.begin(), it2);
	//for (auto e : mylist1)
	//{
	//	cout << e << ' ';
	//}
	//cout << endl;

	//for (auto e : mylist2)
	//{
	//	cout << e << ' ';
	//}
	//cout << endl;

	// 自我转移
	// 把第二个位置转移到第一个位置的前面
	mylist1.splice(mylist1.begin(), mylist1, ++mylist1.begin());
	for (auto e : mylist1)
	{
		cout << e << ' ';
	}
	cout << endl;

	// 把第二个位置开始到结尾的值，转移到第一个位置的前面
	mylist1.splice(mylist1.begin(), mylist1, ++mylist1.begin(), mylist1.end());
	for (auto e : mylist1)
	{
		cout << e << ' ';
	}
	cout << endl;

	// 重叠会死循环
}

int main()
{
	// 没有 reserve or resize ，不需要开连续的空间
	// test_list3();
	test_list6();

	return 0;
}