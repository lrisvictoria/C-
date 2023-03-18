#include <iostream>

using namespace std;

//int add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//	add(1, 2);
//
//	return 0;
//}

//#define ADD(x, y) ((x) + (y)) 
//

//int main()
//{
//	cout << ADD(1, 2) << endl;
//
//	return 0;
//}

//inline int add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	int ret = add(1, 2);
//	cout << ret << endl;
//
//	return 0;
//}

// F.h
//#include <iostream>
//using namespace std;
//inline void f(int i);
//// F.cpp
//#include "F.h"
//void f(int i)
//{
//	cout << i << endl;
//}
//// main.cpp
//#include "F.h"
//int main()
//{
//	f(10);
//	return 0;
//}
//// 链接错误：main.obj : error LNK2019: 无法解析的外部符号 "void __cdecl
//f(int)" (?f@@YAXH@Z)，该符号在函数 _main 中被引用

//int main()
//{
//	const int a = 0;
//	int b = 0;
//	auto c = a; // 自动推导 c 的类型
//	auto d = 'A';
//	auto e = 10.11;
//
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//
//	return 0;
//}

//#include <map>
//
//int main()
//{
//	std::map<std::string, std::string> dict = { { "apple", "苹果" }, { "orange","橙子" },{"pear","梨"} };
//	std::map<std::string, std::string>::iterator it = dict.begin();
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x; // int*
//	auto& c = x; // 让 c 变为 x 的引用，类型是 int 
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	const auto y = x;
//	cout << typeid(y).name() << endl;
//
//	return 0;
//}

//void TestAuto()
//{
//	int a[] = { 1,2,3 };
//	auto b[] = { 4，5，6 };
//}

//int main()
//{
//	int a = 10;
//	auto j;
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4,5 };
//
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) 
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4,5 };
//
//	for (auto* num : arr) 
//	{
//		num++;
//	}
//
//	for (auto num : arr)
//	{
//		cout << num << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}

//void TestFor(int array[])
//{
//	for (auto& e : array)
//		cout << e << endl;
//}

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//	 f((int*)NULL);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	auto b = &a;
//
//	cout << typeid(b).name() << endl;
//}

//#include <map>
//
//int main()
//{
//	map<string, string> dict;
//	typedef map<string, string>::iterator Dict;
//	Dict it = dict.begin();
//
//	return 0;
//}

//typedef char* pstring;
//
//int main()
//{
//	const pstring p1 = nullptr;
//	const pstring* p2;
//}

#include <map>

int main()
{
	map<string, string> dict;
	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();

	return 0;
}
