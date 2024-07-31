﻿//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
////struct Point
////{
////	Point(int x, int y)
////		:_x(x)
////		,_y(y)
////	{
////		cout << "Point(int x, int y)" << endl;
////	}
////
////	int _x;
////	int _y;
////};
////
////// 一切皆可用 {} 初始化，并且可以不写赋值符号
////// 日常定义不要去掉 =，但是我们要能看懂
////int main()
////{
////	int x = 1;
////	int y = { 2 }; // 整形支持这样初始化
////	int z{ 3 };// right
////	int a1[] = { 1, 2,3 };
////	int a2[]{ 1, 2, 3 }; // 数组这样初始化也对
////
////	// 本质都是调用构造函数
////	Point p(1, 2);
////	Point p1 = { 1, 3 }; //会不会调用构造函数? 会 本质是多参数构造函数的隐式类型转换
////	Point p2{ 2, 2 }; // 会不会调用构造函数? 会
////
////	const Point& r = { 3, 3 }; // 临时对象具有常性
////
////	int* p1 = new int[3] {1, 2, 3};
////	Point* ptr = new Point[2]{ {1, 2}, {2, 3} }; // 当没有有名对象时虚浮了很多，不用匿名对象
////
////
////	return 0;
////}
//
////int main()
////{
////	vector<int> v1 = { 1, 2 }; // 不是列表初始化支持的，它们有不同的规则
////	// 这里本质也是一个构造
////	// 这个列表叫做 initializer_list
////	auto il = { 10, 20, 30 };
////	initializer_list<int> il = { 10, 20, 30 };
////	cout << typeid(il).name() << endl;
//// }
//
////#include <iostream>
////#include <algorithm>
////
////using namespace std;
////
////int main()
////{
////    int n;
////    cin >> n;
////
////    int res = 0;
////
////    for (int i = 2; i < n; i++)
////    {
////        int tmp = 1;
////        for (int j = 2; j <= i / 2; j++)
////        {
////            if (!(i % j))
////            {
////                tmp += j;
////            }
////        }
////
////        if (tmp == i) res++;
////    }
////
////    cout << res << endl;
////
////
////    return 0;
////}
//
////int sum(int a, int b)
////{
////	return a + b;
////}
////
////int main()
////{
////	// decltype(sum(1, 3)) a;
////
////	const char* str = "xxxxxx";
////
////	str[2] = 0x11223344;
////
////	return 0;
////}
//
////int main()
////{
////	double x = 1.1, y = 2.2;
////	// 左值引用
////	int a = 0;
////	int& r1 = a; 
////
////	// 左值引用能否给右值取别名？
////	// const 左值引用可以 
////	const int& r2 = 10;
////	const double& r3 = x + y;
////
////	// 右值引用
////	int&& r5 = 10; 
////	double&& r6 = x + y; 
////
////	// 右值引用是否能给左值取别名？
////	// 直接给不可以
////	// 强制给，特殊情况下可以用, move 一下
////	// move 以后 a 可能有一些影响（这边没影响）
////	// 总结：右值引用可以引用 move 以后的左值
////	int&& r7 = a;
////	double&& r8 = move(a);
////
////	
////
////	return 0;
////}
//
//// 左值引用的使用场景和价值是什么
//// 使用场景：1.做参数    2.做返回值     价值->减少拷贝
//// 处理不到位的：局部对象返回不能用左值引用解决
//
////string func()
////{
////	string str;
////	cin >> str;
////
////	//...
////
////	return str;
////}
////
////int main()
////{
////	return 0;
////}
//
//#include <cassert>
//
//namespace lx
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//
//		iterator end()
//		{
//			return _str + _size;
//		}
//
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			cout << "string(const char* str)" << endl;
//
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//
//		// s1.swap(s2)
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//
//		// 拷贝构造
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//
//			//string tmp(s._str);
//			//swap(tmp);
//		}
//
//		string(string&& s)
//			:_str(nullptr)
//		{
//			cout << "string(string&& s) -- 移动拷贝" << endl;
//
//			swap(s);
//		}
//
//		// 赋值重载
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- 深拷贝" << endl;
//			string tmp(s);
//			swap(tmp);
//
//			return *this;
//		}
//
//		/*string& operator=(string && s)
//		{
//			cout << "string& operator=(string && s) -- 移动拷贝" << endl;
//			swap(s);
//
//			return *this;
//		}*/
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//
//				_capacity = n;
//			}
//		}
//
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//
//		//string operator+=(char ch)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//		const char* c_str() const
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // 不包含最后做标识的\0
//	};
//}
////
////// 左值引用的使用场景和价值是什么？
////// 使用场景：1、做参数  2、做返回值  价值->减少拷贝
////lx::string func()
////{
////	lx::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
////	//cin >> str;
////	//....
////
////	return str;
////}
////
////int main()
////{
////	//lx::string ret1 = func();
////
////	lx::string ret2;
////	//...
////	ret2 = func();
////
////
////	return 0;
////}
//
//// 右值引用起作用的场景与左值引用不太一样
//// 是间接起作用的
//
//// 是否构成函数重载？是
////void func(int& r)
////{
////	cout << "void func(int& r)" << endl;
////}
////
////
////
////void func(int&& r)
////{
////	cout << "void func(int&& r)" << endl;
////}
////
////int main()
////{
////	return 0;
////}
//
////#include <iostream>
////#include <algorithm>
////#include <vector>
////
////using namespace std;
////
////int main()
////{
////    int t, n, k;
////
////    cin >> t;
////    while (t--)
////    {
////        cin >> n >> k;
////        vector<int> poker(2 * n);
////
////        for (int i = 0; i < 2 * n; i++)
////        {
////            cin >> poker[i];
////        }
////        while (k--)
////        {
////            vector<int> p1(poker.begin(), poker.begin() + n);
////            vector<int> p2(poker.begin() + n, poker.end());
////
////            int i = p1.size() - 1, j = p2.size() - 1, k = 0;
////            while (i >= 0 && j >= 0)
////            {
////                poker[k++] = p2[j--];
////                poker[k++] = p1[i--];
////            }
////        }
////
////        for (int i = 0; i < 2 * n; i++)
////        {
////            cout << poker[i] << " ";
////        }
////        cout << endl;
////    }
////
////    return 0;
////}
//
////class A
////{
////public:
////	void Drive()
////	{
////		cout << "Drive" << endl;
////	}
////};
////
////class B : public A
////{
////public:
////	/*virtual void Drive()
////	{
////		cout << "class B Drive" << endl;
////	}*/
////};
////
////int main()
////{
////	A aa;
////	//B bb;
////	// bb.B::A::Drive();
////}
//
//// 是否构成函数重载？是
////void func(int& r)
////{
////	cout << "void func(int& r)" << endl;
////}
//
//// 是否构成重载？是
//// 调用是否产生歧义？不会，调用最匹配的那个
////void func(const int& r)
////{
////	cout << "void func(const int& r)" << endl;
////}
////
////void func(int&& r)
////{
////	cout << "void func(int&& r)" << endl;
////}
////
////int main()
////{
////	int a = 0;
////	func(a);
////
////	int b = 1;
////	func(a + b);
////
////	return 0;
////}
//
////class A
////{
////public:
////	A(int a = 0)
////		:_a(a)
////	{
////		cout << "A(int a)" << endl;
////	}
////	A(const A& aa)
////		:_a(aa._a)
////	{
////		cout << "A(const A& aa)" << endl;
////	}
////	A& operator=(const A& aa)
////	{
////		cout << "A& operator=(const A& aa)" << endl;
////		if (this != &aa)
////		{
////			_a = aa._a;
////		}
////		return *this;
////	}
////	~A()
////	{
////		cout << "~A()" << endl;
////	}
////private:
////	int _a;
////};
////
////void f1(A aa)
////{}
////
////A f2()
////{
////	A aa;
////	return aa;
////}
////int main()
////{
////	// 传值传参
////	A aa1;
////
////	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
////	A aa2 = f2();
////	cout << endl;
////	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
////	aa1 = f2();
////	cout << endl;
////	return 0;
////}
//
////#include <iostream>
////
////using namespace std;
////
////int main()
////{
////	lx::string ret3("1111111111111111111");
////	lx::string copy1 = ret3;
////	move(ret3); // 资源不会被转移
////	lx::string copy2 = ret3; // 拷贝构造 
////	lx::string copy3 = move(ret3);
////
////	return 0;
////}
// 
////#include <list>
////int main()
////{
////	list<lx::string> lt;
////	lx::string s1("11111111111111111111");
////	lt.push_back(s1);
////
////	cout << endl;
////	lx::string s2("11111111111111111111");
////	lt.push_back(move(s2));
////
////	cout << endl;
////	lt.push_back("22222222222222222222"); // 一般这么写
////
////	return 0;
////}
//
////void Fun(int& x) { cout << "左值引用" << endl; }
////void Fun(const int& x) { cout << "const 左值引用" << endl; }
////void Fun(int&& x) { cout << "右值引用" << endl; }
////void Fun(const int&& x) { cout << "const 右值引用" << endl; }
////
////// 万能引用：既可以接收左值，又可以接收右值
////// 虽然这么写，但是是一个模板，类型如果这么写，就是写死的，是右值引用，模板不是写死的
////
////// 实参是左值，就是左值引用（引用折叠 -- 如果是左值，则传参，参数变为 int&，两个引用折叠了一下）
////// 实参是左值，就是左值引用
////template<typename T>
////void perfectforward(T&& t)
////{
////	// 完美转发，t 是左值引用，保持左值属性
////	// 完美转发，t 是右值引用，保持右值属性
////	Fun(forward<T>(t));
////}
////
////int main()
////{
////	perfectforward(10); // 右值
////	int a;
////	perfectforward(a); // 左值
////	perfectforward(std::move(a)); // 右值
////	const int b = 8;
////	perfectforward(b); // const 左值
////	perfectforward(std::move(b)); // const 右值
////	return 0;
////}
//
////void func(const int&& a)
////{
////	cout << "yes" << endl;
////}
////
////int main()
////{
////	int a;
////	int& r = a;
////	int&& rr = move(a);
////
////	func(rr);
////
////	cout << &r << endl;
////	cout << &rr << endl;
////
////	rr++;
////
////	return 0;
////}
//
//
////#include "list.h"
////int main()
////{
////	lx::list<lx::string> lt;
////	lx::string s1("11111111111111111111");
////	lt.push_back(s1);
////
////	cout << endl;
////	lx::string s2("11111111111111111111");
////	lt.push_back(move(s2));
////
////	cout << endl;
////	lt.push_back("22222222222222222222"); // 一般这么写
////
////	return 0;
////}
//
////#include <algorithm>
////
////using namespace std;
////
////struct Goods
////{
////	string _name; // 名字
////	double _price; // 价格
////	int _evaluate; // 评价
////	Goods(const char* str, double price, int evaluate)
////		:_name(str)
////		, _price(price)
////		, _evaluate(evaluate)
////	{}
////};
////
////int main()
////{
////	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
////	3 }, { "菠萝", 1.5, 4 } };
////	// sort(v.begin(), v.end());
////
////	// 局部的匿名函数对象
////	// 不能显示写类型，只能推 = 右边的是个对象
////	auto less = [](int x, int y)->bool {return x < y; };
////	cout << less(1, 2) << endl;
////
////	// 只要 return 了，返回值可以不写
////	//auto goodsPriceLess = [](const Goods& x, const Goods& y)->bool {return x._price < y._price;  };
////	auto goodsPriceLess = [](const Goods& x, const Goods& y){return x._price < y._price;  };
////
////	sort(v.begin(), v.end(), goodsPriceLess);
////
////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
////		return x._price < y._price; });
////
////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
////		return x._price > y._price; });
////
////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
////		return x._evaluate < y._evaluate; });
////
////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
////		return x._evaluate > y._evaluate; });
////}
//
//
////#include <iostream>
////using namespace std;
////int main(void)
////{
////	const int a = 10;
////	int* p = (int*)(&a);
////	*p = 20;
////	cout << "a = " << a << ", *p = " << *p << endl;
////	cout << a << endl;
////	return 0;
////}
//
////#include <iostream>
////
////using namespace std;
////
////class A
////{
////public:
////	A()
////	{}
////
////	~A()
////	{
////		cout << "析构" << endl;
////	}
////private:
////	int _b = 4;
////};
////
////int main()
////{
////	A a;
////
////	return 0;
////}
//
////#include <iostream>
////#include <errno.h>
////
////using namespace std;
////
////int main()
////{
////	char inbuffer[1024];
////}
//
////#include <string>
////
////using namespace std;
////
////int main(int argc, char* argv[])
////{
////	string a = "hello world";
////	string b = a;
////	if (a.c_str() == b.c_str())
////	{
////		cout << "true" << endl;
////	}
////	else cout << "false" << endl;
////	string c = b;
////	c = "";
////	if (a.c_str() == b.c_str())
////	{
////		cout << "true" << endl;
////	}
////	else cout << "false" << endl;
////	a = "";
////	if (a.c_str() == b.c_str())
////	{
////		cout << "true" << endl;
////	}
////	else cout << "false" << endl;
////	return 0;
////}
//
//
////class A
////{
////public:
////	A(int a = 0)
////		:_a(a)
////	{
////		cout << "A(int a)" << endl;
////	}
////	A(const A& aa)
////		:_a(aa._a)
////	{
////		cout << "A(const A& aa)" << endl;
////	}
////	A& operator=(const A& aa)
////	{
////		cout << "A& operator=(const A& aa)" << endl;
////		if (this != &aa)
////		{
////			_a = aa._a;
////		}
////		return *this;
////	}
////	~A()
////	{
////		cout << "~A()" << endl;
////	}
////private:
////	int _a;
////};
////void f1(A aa)
////{}
////A f2()
////{
////	A aa;
////	return aa;
////}
////int main()
////{
////	// 传值传参
////	A aa1;
////	f1(aa1);
////	cout << endl;
////
////	return 0;
////}
//
//
////class CParent
////{
////public: virtual void Intro()
////{
////	printf("I'm a Parent, "); Hobby();
////} 
////virtual void Hobby()
////{
////	printf("I like football!");
////}
////};
////class CChild : public CParent {
////public: virtual void Intro()
////{
////	printf("I'm a Child, "); Hobby();
////} 
////virtual void Hobby()
////{
////	printf("I like basketball!\n");
////}
////};
////
////int main()
////{
////	CChild* pChild = new CChild();
////	CParent* pParent = (CParent*)pChild;
////	pParent->Intro();
////	return 0;
////}
//
//int func(int a, int b);
//
//int func(int a = 0, int b = 0)
//{
//	return a + b;
//}
//
//int main()
//{
//	cout << func(1, 1) << endl;
//
//	return 0;
//}
//
//#include "test.h"
//
////void fuc1(int a = 0, int b = 0);
//void fuc1(int a = 0, int b = 0)
//{
//	cout << a << " " << b;
//}
//
//int main()
//{
//	fuc1();
//}

#include <iostream>
using namespace std;

//void func()
//{
//	cout << "func()" << endl;
//}
//
//int main()
//{
//
//	int a = 0, b = 2;
//	auto add1 = [](int x, int y)->int {return x + y; };
//	auto add2 = [](int x, int y)  {return x + y; }; // 一般都不需要写返回值
//
//	cout << add1(a, b) << endl;
//	cout << add2(a, b) << endl;
//
//	auto swap = [](int& x, int y) {
//		int tmp = x;
//		x = y;
//		y = tmp;
//
//		func();
//	};
//
//	swap(a, b);
//
//	return 0;
//}

//auto func = [] {cout << "FUNC" << endl; };
//
//int main()
//{
//	int a = 1, b = 2;
//
//	auto f3 = [](int a, int b) {
//		func();
//		return a + b; 
//	};
//
//
//	cout << f3(a, b) << endl;
//	return 0;
//}


//#include <functional>
//#include <iostream>
//
//	using namespace std;
//
//double sub1(int x, double rate, int y)
//{
//	return (x - y) * rate;
//}
//
//int main()
//{
//	function<double(int, int)> ff1 = bind(sub1, placeholders::_1, 1.5, placeholders::_2);
//
//	//在定义期间固定参数，类似与缺省值的效果。
//	cout << ff1(2, 1) << endl;
//
//	auto ff2 = bind(sub1, placeholders::_2, 1, placeholders::_1);
//	cout << ff2(3, 1) << endl;
//}
