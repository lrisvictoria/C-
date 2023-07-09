#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void test_vector1()
{
	vector<char> strv;
	// string str
	// string 要求有 \0 ，兼容 c 
	// string 有其他的专用接口函数
	
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;

	for (auto e : v1)
	{
		cout << e << ' ';
	}
	cout << endl;

}

void test_vector2()
{
	vector<string> v;

	// 1
	string name1("张三");
	v.push_back(name1);
	// 2
	v.push_back(string("张三"));
	// 3
	v.push_back("张三");

	// allocator 空间配置器
	// value_type T
}

void test_vector3()
{
	vector<int> v1(10, 1); // 10 个 1

	for (auto e : v1)
	{
		cout << e << ' ';
	}
	cout << endl;
}

void test_vector4()
{
	// 迭代器初始化的 InputIterator
	// 是模板，是通用的，不一定是 vector 的迭代器
	
	// 自己类型的迭代器
	vector<int> v1(10, 1);
	vector<int> v2(v1.begin(), v1.end());

	for (auto e : v1)
	{
		cout << e << ' ';
	}
	cout << endl;

	// 其他类型的迭代器
	string str("hello world");
	vector<char> v3(str.begin(), str.end()); //使用 string 的迭代器初始化

	for (auto e : v3)
	{
		cout << e << ' ';
	}
	cout << endl;

	// 指针
	int a[] = { 16, 2, 77, 29 };
	vector<int> v4(a, a + 4);

	for (auto e : v4)
	{
		cout << e << ' ';
	}
	cout << endl;

	// sort 使用迭代器访问数据
	// 升序 < 
	// 默认使用 less
	sort(v4.begin(), v4.end());
	for (auto e : v4)
	{
		cout << e << ' ';
	}
	cout << endl;

	// 降序
	// Compare comp
	// c 回调函数用函数指针
	// c++ 用仿函数
	// c++ 库自带 greater 使用就可以排降序
	// 降序 >
	greater<int> g;
	sort(v4.begin(), v4.end(), g);
	// sort(v4.begin(), v4.end(), greater<int>());
	for (auto e : v4)
	{
		cout << e << ' ';
	}
	cout << endl;

	// 反向迭代器排降序
	sort(v4.rbegin(), v4.rend());
	for (auto e : v4)
	{
		cout << e << ' ';
	}
	cout << endl;

	// cbegin 的一个参数是和异常有关系的，现在不用管
}

void test_vector5()
{
	vector<int> v;
	cout << v.max_size() << endl;

	vector<int> v1;
	// v1.reserve(10); // 减少扩容，提高效率

	// 越界 size = 0, capacity = 10
	/*for (size_t i = 0; i < 10; i++)
	{
		v1[i] = i;
	}*/

	v1.resize(10);
	for (size_t i = 0; i < 10; i++)
	{
		v1[i] = i;
	}
	for (size_t i = 0; i < 10; i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;

	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
}

void test_vector6()
{
	// push_back() 插入一个数据
	// 没有提供头插头删
	// 可以用 insert 代替

	int a[] = { 16,2,77,29,3,33,43,3,2,3,3,2 };
	vector<int> v1(a, a + sizeof(a) / sizeof(int)); // 指针初始化
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	// 头删
	v1.erase(v1.begin());
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	// 头插 
	v1.insert(v1.begin(), 100);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除第3个数据
	v1.erase(v1.begin() + 2);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.insert(v1.begin() + 2, 3);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	// 删除 3 ，但是 vector 没有 find
	// 但是可以用 algorithm 中的 find
	// 找到 3
	// find 找不到返回的是 last ，就是 end()
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	// 屏蔽掉，否则会迭代器失效
	/*if (pos != v1.end())
	{
		v1.erase(pos);
	}
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;*/

	// 循环删除 3
	while (pos != v1.end())
	{
		v1.erase(pos);
		pos = find(v1.begin(), v1.end(), 3);
		// pos = find(pos + 1, v1.end(), 3); 不能这么写，会迭代器失效
	}

	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << v1.capacity() << endl;


	// assign : 区间赋值
	v1.assign(1, 1); // 第一个参数会改变容量
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.clear();
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
}

// 测试扩容逻辑
void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

//int main()
//{
//	test_vector6();
//	// at() 是抛异常
//	// [] 是断言
//	// assert 只在 debug 下有效
//
//	// data 和 c_str 很像，返回指向数组的指针
//
//	TestVectorExpand();
//
//	return 0;
//}

//#include <iostream>
//
//#include <vector>
//
//using namespace std;
//
//int main(void)
//
//{
//
//	vector<int>array;
//
//	array.push_back(100);
//
//	array.push_back(300);
//
//	array.push_back(300);
//
//	array.push_back(300);
//
//	array.push_back(300);
//
//	array.push_back(500);
//
//	vector<int>::iterator itor;
//
//	for (itor = array.begin(); itor != array.end(); itor++)
//
//	{
//
//		if (*itor == 300)
//
//		{
//
//			itor = array.erase(itor);
//
//		}
//
//	}
//
//	for (itor = array.begin(); itor != array.end(); itor++)
//
//	{
//
//		cout << *itor << " ";
//
//	}
//
//	return 0;
//
//}

#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sizeof(ar) / sizeof(int);

	vector<int> v(ar, ar + n); // 指针初始化

	cout << v.size() << ":" << v.capacity() << endl; // 10, 10

	v.reserve(100); // 100

	v.resize(20); // 20

	cout << v.size() << ":" << v.capacity() << endl; // 10 20

	v.reserve(50); // 100

	v.resize(5); // 5

	cout << v.size() << ":" << v.capacity() << endl;

}