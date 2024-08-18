//#define _CRT_SECURE_NO_WARNINGS 1
////
////#include <iostream>
////#include <vector>
////#include <string>
////
////using namespace std;
////
//////struct Point
//////{
//////	Point(int x, int y)
//////		:_x(x)
//////		,_y(y)
//////	{
//////		cout << "Point(int x, int y)" << endl;
//////	}
//////
//////	int _x;
//////	int _y;
//////};
//////
//////// 一切皆可用 {} 初始化，并且可以不写赋值符号
//////// 日常定义不要去掉 =，但是我们要能看懂
//////int main()
//////{
//////	int x = 1;
//////	int y = { 2 }; // 整形支持这样初始化
//////	int z{ 3 };// right
//////	int a1[] = { 1, 2,3 };
//////	int a2[]{ 1, 2, 3 }; // 数组这样初始化也对
//////
//////	// 本质都是调用构造函数
//////	Point p(1, 2);
//////	Point p1 = { 1, 3 }; //会不会调用构造函数? 会 本质是多参数构造函数的隐式类型转换
//////	Point p2{ 2, 2 }; // 会不会调用构造函数? 会
//////
//////	const Point& r = { 3, 3 }; // 临时对象具有常性
//////
//////	int* p1 = new int[3] {1, 2, 3};
//////	Point* ptr = new Point[2]{ {1, 2}, {2, 3} }; // 当没有有名对象时虚浮了很多，不用匿名对象
//////
//////
//////	return 0;
//////}
////
//////int main()
//////{
//////	vector<int> v1 = { 1, 2 }; // 不是列表初始化支持的，它们有不同的规则
//////	// 这里本质也是一个构造
//////	// 这个列表叫做 initializer_list
//////	auto il = { 10, 20, 30 };
//////	initializer_list<int> il = { 10, 20, 30 };
//////	cout << typeid(il).name() << endl;
////// }
////
//////#include <iostream>
//////#include <algorithm>
//////
//////using namespace std;
//////
//////int main()
//////{
//////    int n;
//////    cin >> n;
//////
//////    int res = 0;
//////
//////    for (int i = 2; i < n; i++)
//////    {
//////        int tmp = 1;
//////        for (int j = 2; j <= i / 2; j++)
//////        {
//////            if (!(i % j))
//////            {
//////                tmp += j;
//////            }
//////        }
//////
//////        if (tmp == i) res++;
//////    }
//////
//////    cout << res << endl;
//////
//////
//////    return 0;
//////}
////
//////int sum(int a, int b)
//////{
//////	return a + b;
//////}
//////
//////int main()
//////{
//////	// decltype(sum(1, 3)) a;
//////
//////	const char* str = "xxxxxx";
//////
//////	str[2] = 0x11223344;
//////
//////	return 0;
//////}
////
//////int main()
//////{
//////	double x = 1.1, y = 2.2;
//////	// 左值引用
//////	int a = 0;
//////	int& r1 = a; 
//////
//////	// 左值引用能否给右值取别名？
//////	// const 左值引用可以 
//////	const int& r2 = 10;
//////	const double& r3 = x + y;
//////
//////	// 右值引用
//////	int&& r5 = 10; 
//////	double&& r6 = x + y; 
//////
//////	// 右值引用是否能给左值取别名？
//////	// 直接给不可以
//////	// 强制给，特殊情况下可以用, move 一下
//////	// move 以后 a 可能有一些影响（这边没影响）
//////	// 总结：右值引用可以引用 move 以后的左值
//////	int&& r7 = a;
//////	double&& r8 = move(a);
//////
//////	
//////
//////	return 0;
//////}
////
////// 左值引用的使用场景和价值是什么
////// 使用场景：1.做参数    2.做返回值     价值->减少拷贝
////// 处理不到位的：局部对象返回不能用左值引用解决
////
//////string func()
//////{
//////	string str;
//////	cin >> str;
//////
//////	//...
//////
//////	return str;
//////}
//////
//////int main()
//////{
//////	return 0;
//////}
////
////#include <cassert>
////
////namespace lx
////{
////	class string
////	{
////	public:
////		typedef char* iterator;
////		iterator begin()
////		{
////			return _str;
////		}
////
////		iterator end()
////		{
////			return _str + _size;
////		}
////
////		string(const char* str = "")
////			:_size(strlen(str))
////			, _capacity(_size)
////		{
////			cout << "string(const char* str)" << endl;
////
////			_str = new char[_capacity + 1];
////			strcpy(_str, str);
////		}
////
////		// s1.swap(s2)
////		void swap(string& s)
////		{
////			::swap(_str, s._str);
////			::swap(_size, s._size);
////			::swap(_capacity, s._capacity);
////		}
////
////		// 拷贝构造
////		string(const string& s)
////			:_str(nullptr)
////		{
////			cout << "string(const string& s) -- 深拷贝" << endl;
////
////			//string tmp(s._str);
////			//swap(tmp);
////		}
////
////		string(string&& s)
////			:_str(nullptr)
////		{
////			cout << "string(string&& s) -- 移动拷贝" << endl;
////
////			swap(s);
////		}
////
////		// 赋值重载
////		string& operator=(const string& s)
////		{
////			cout << "string& operator=(string s) -- 深拷贝" << endl;
////			string tmp(s);
////			swap(tmp);
////
////			return *this;
////		}
////
////		/*string& operator=(string && s)
////		{
////			cout << "string& operator=(string && s) -- 移动拷贝" << endl;
////			swap(s);
////
////			return *this;
////		}*/
////
////		~string()
////		{
////			delete[] _str;
////			_str = nullptr;
////		}
////
////		char& operator[](size_t pos)
////		{
////			assert(pos < _size);
////			return _str[pos];
////		}
////
////		void reserve(size_t n)
////		{
////			if (n > _capacity)
////			{
////				char* tmp = new char[n + 1];
////				strcpy(tmp, _str);
////				delete[] _str;
////				_str = tmp;
////
////				_capacity = n;
////			}
////		}
////
////		void push_back(char ch)
////		{
////			if (_size >= _capacity)
////			{
////				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
////				reserve(newcapacity);
////			}
////
////			_str[_size] = ch;
////			++_size;
////			_str[_size] = '\0';
////		}
////
////		//string operator+=(char ch)
////		string& operator+=(char ch)
////		{
////			push_back(ch);
////			return *this;
////		}
////
////		const char* c_str() const
////		{
////			return _str;
////		}
////	private:
////		char* _str;
////		size_t _size;
////		size_t _capacity; // 不包含最后做标识的\0
////	};
////}
//////
//////// 左值引用的使用场景和价值是什么？
//////// 使用场景：1、做参数  2、做返回值  价值->减少拷贝
//////lx::string func()
//////{
//////	lx::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//////	//cin >> str;
//////	//....
//////
//////	return str;
//////}
//////
//////int main()
//////{
//////	//lx::string ret1 = func();
//////
//////	lx::string ret2;
//////	//...
//////	ret2 = func();
//////
//////
//////	return 0;
//////}
////
////// 右值引用起作用的场景与左值引用不太一样
////// 是间接起作用的
////
////// 是否构成函数重载？是
//////void func(int& r)
//////{
//////	cout << "void func(int& r)" << endl;
//////}
//////
//////
//////
//////void func(int&& r)
//////{
//////	cout << "void func(int&& r)" << endl;
//////}
//////
//////int main()
//////{
//////	return 0;
//////}
////
//////#include <iostream>
//////#include <algorithm>
//////#include <vector>
//////
//////using namespace std;
//////
//////int main()
//////{
//////    int t, n, k;
//////
//////    cin >> t;
//////    while (t--)
//////    {
//////        cin >> n >> k;
//////        vector<int> poker(2 * n);
//////
//////        for (int i = 0; i < 2 * n; i++)
//////        {
//////            cin >> poker[i];
//////        }
//////        while (k--)
//////        {
//////            vector<int> p1(poker.begin(), poker.begin() + n);
//////            vector<int> p2(poker.begin() + n, poker.end());
//////
//////            int i = p1.size() - 1, j = p2.size() - 1, k = 0;
//////            while (i >= 0 && j >= 0)
//////            {
//////                poker[k++] = p2[j--];
//////                poker[k++] = p1[i--];
//////            }
//////        }
//////
//////        for (int i = 0; i < 2 * n; i++)
//////        {
//////            cout << poker[i] << " ";
//////        }
//////        cout << endl;
//////    }
//////
//////    return 0;
//////}
////
//////class A
//////{
//////public:
//////	void Drive()
//////	{
//////		cout << "Drive" << endl;
//////	}
//////};
//////
//////class B : public A
//////{
//////public:
//////	/*virtual void Drive()
//////	{
//////		cout << "class B Drive" << endl;
//////	}*/
//////};
//////
//////int main()
//////{
//////	A aa;
//////	//B bb;
//////	// bb.B::A::Drive();
//////}
////
////// 是否构成函数重载？是
//////void func(int& r)
//////{
//////	cout << "void func(int& r)" << endl;
//////}
////
////// 是否构成重载？是
////// 调用是否产生歧义？不会，调用最匹配的那个
//////void func(const int& r)
//////{
//////	cout << "void func(const int& r)" << endl;
//////}
//////
//////void func(int&& r)
//////{
//////	cout << "void func(int&& r)" << endl;
//////}
//////
//////int main()
//////{
//////	int a = 0;
//////	func(a);
//////
//////	int b = 1;
//////	func(a + b);
//////
//////	return 0;
//////}
////
//////class A
//////{
//////public:
//////	A(int a = 0)
//////		:_a(a)
//////	{
//////		cout << "A(int a)" << endl;
//////	}
//////	A(const A& aa)
//////		:_a(aa._a)
//////	{
//////		cout << "A(const A& aa)" << endl;
//////	}
//////	A& operator=(const A& aa)
//////	{
//////		cout << "A& operator=(const A& aa)" << endl;
//////		if (this != &aa)
//////		{
//////			_a = aa._a;
//////		}
//////		return *this;
//////	}
//////	~A()
//////	{
//////		cout << "~A()" << endl;
//////	}
//////private:
//////	int _a;
//////};
//////
//////void f1(A aa)
//////{}
//////
//////A f2()
//////{
//////	A aa;
//////	return aa;
//////}
//////int main()
//////{
//////	// 传值传参
//////	A aa1;
//////
//////	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//////	A aa2 = f2();
//////	cout << endl;
//////	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//////	aa1 = f2();
//////	cout << endl;
//////	return 0;
//////}
////
//////#include <iostream>
//////
//////using namespace std;
//////
//////int main()
//////{
//////	lx::string ret3("1111111111111111111");
//////	lx::string copy1 = ret3;
//////	move(ret3); // 资源不会被转移
//////	lx::string copy2 = ret3; // 拷贝构造 
//////	lx::string copy3 = move(ret3);
//////
//////	return 0;
//////}
//// 
//////#include <list>
//////int main()
//////{
//////	list<lx::string> lt;
//////	lx::string s1("11111111111111111111");
//////	lt.push_back(s1);
//////
//////	cout << endl;
//////	lx::string s2("11111111111111111111");
//////	lt.push_back(move(s2));
//////
//////	cout << endl;
//////	lt.push_back("22222222222222222222"); // 一般这么写
//////
//////	return 0;
//////}
////
//////void Fun(int& x) { cout << "左值引用" << endl; }
//////void Fun(const int& x) { cout << "const 左值引用" << endl; }
//////void Fun(int&& x) { cout << "右值引用" << endl; }
//////void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//////
//////// 万能引用：既可以接收左值，又可以接收右值
//////// 虽然这么写，但是是一个模板，类型如果这么写，就是写死的，是右值引用，模板不是写死的
//////
//////// 实参是左值，就是左值引用（引用折叠 -- 如果是左值，则传参，参数变为 int&，两个引用折叠了一下）
//////// 实参是左值，就是左值引用
//////template<typename T>
//////void perfectforward(T&& t)
//////{
//////	// 完美转发，t 是左值引用，保持左值属性
//////	// 完美转发，t 是右值引用，保持右值属性
//////	Fun(forward<T>(t));
//////}
//////
//////int main()
//////{
//////	perfectforward(10); // 右值
//////	int a;
//////	perfectforward(a); // 左值
//////	perfectforward(std::move(a)); // 右值
//////	const int b = 8;
//////	perfectforward(b); // const 左值
//////	perfectforward(std::move(b)); // const 右值
//////	return 0;
//////}
////
//////void func(const int&& a)
//////{
//////	cout << "yes" << endl;
//////}
//////
//////int main()
//////{
//////	int a;
//////	int& r = a;
//////	int&& rr = move(a);
//////
//////	func(rr);
//////
//////	cout << &r << endl;
//////	cout << &rr << endl;
//////
//////	rr++;
//////
//////	return 0;
//////}
////
////
//////#include "list.h"
//////int main()
//////{
//////	lx::list<lx::string> lt;
//////	lx::string s1("11111111111111111111");
//////	lt.push_back(s1);
//////
//////	cout << endl;
//////	lx::string s2("11111111111111111111");
//////	lt.push_back(move(s2));
//////
//////	cout << endl;
//////	lt.push_back("22222222222222222222"); // 一般这么写
//////
//////	return 0;
//////}
////
//////#include <algorithm>
//////
//////using namespace std;
//////
//////struct Goods
//////{
//////	string _name; // 名字
//////	double _price; // 价格
//////	int _evaluate; // 评价
//////	Goods(const char* str, double price, int evaluate)
//////		:_name(str)
//////		, _price(price)
//////		, _evaluate(evaluate)
//////	{}
//////};
//////
//////int main()
//////{
//////	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,
//////	3 }, { "菠萝", 1.5, 4 } };
//////	// sort(v.begin(), v.end());
//////
//////	// 局部的匿名函数对象
//////	// 不能显示写类型，只能推 = 右边的是个对象
//////	auto less = [](int x, int y)->bool {return x < y; };
//////	cout << less(1, 2) << endl;
//////
//////	// 只要 return 了，返回值可以不写
//////	//auto goodsPriceLess = [](const Goods& x, const Goods& y)->bool {return x._price < y._price;  };
//////	auto goodsPriceLess = [](const Goods& x, const Goods& y){return x._price < y._price;  };
//////
//////	sort(v.begin(), v.end(), goodsPriceLess);
//////
//////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//////		return x._price < y._price; });
//////
//////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//////		return x._price > y._price; });
//////
//////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//////		return x._evaluate < y._evaluate; });
//////
//////	sort(v.begin(), v.end(), [](const Goods& x, const Goods& y) {
//////		return x._evaluate > y._evaluate; });
//////}
////
////
//////#include <iostream>
//////using namespace std;
//////int main(void)
//////{
//////	const int a = 10;
//////	int* p = (int*)(&a);
//////	*p = 20;
//////	cout << "a = " << a << ", *p = " << *p << endl;
//////	cout << a << endl;
//////	return 0;
//////}
////
//////#include <iostream>
//////
//////using namespace std;
//////
//////class A
//////{
//////public:
//////	A()
//////	{}
//////
//////	~A()
//////	{
//////		cout << "析构" << endl;
//////	}
//////private:
//////	int _b = 4;
//////};
//////
//////int main()
//////{
//////	A a;
//////
//////	return 0;
//////}
////
//////#include <iostream>
//////#include <errno.h>
//////
//////using namespace std;
//////
//////int main()
//////{
//////	char inbuffer[1024];
//////}
////
//////#include <string>
//////
//////using namespace std;
//////
//////int main(int argc, char* argv[])
//////{
//////	string a = "hello world";
//////	string b = a;
//////	if (a.c_str() == b.c_str())
//////	{
//////		cout << "true" << endl;
//////	}
//////	else cout << "false" << endl;
//////	string c = b;
//////	c = "";
//////	if (a.c_str() == b.c_str())
//////	{
//////		cout << "true" << endl;
//////	}
//////	else cout << "false" << endl;
//////	a = "";
//////	if (a.c_str() == b.c_str())
//////	{
//////		cout << "true" << endl;
//////	}
//////	else cout << "false" << endl;
//////	return 0;
//////}
////
////
//////class A
//////{
//////public:
//////	A(int a = 0)
//////		:_a(a)
//////	{
//////		cout << "A(int a)" << endl;
//////	}
//////	A(const A& aa)
//////		:_a(aa._a)
//////	{
//////		cout << "A(const A& aa)" << endl;
//////	}
//////	A& operator=(const A& aa)
//////	{
//////		cout << "A& operator=(const A& aa)" << endl;
//////		if (this != &aa)
//////		{
//////			_a = aa._a;
//////		}
//////		return *this;
//////	}
//////	~A()
//////	{
//////		cout << "~A()" << endl;
//////	}
//////private:
//////	int _a;
//////};
//////void f1(A aa)
//////{}
//////A f2()
//////{
//////	A aa;
//////	return aa;
//////}
//////int main()
//////{
//////	// 传值传参
//////	A aa1;
//////	f1(aa1);
//////	cout << endl;
//////
//////	return 0;
//////}
////
////
//////class CParent
//////{
//////public: virtual void Intro()
//////{
//////	printf("I'm a Parent, "); Hobby();
//////} 
//////virtual void Hobby()
//////{
//////	printf("I like football!");
//////}
//////};
//////class CChild : public CParent {
//////public: virtual void Intro()
//////{
//////	printf("I'm a Child, "); Hobby();
//////} 
//////virtual void Hobby()
//////{
//////	printf("I like basketball!\n");
//////}
//////};
//////
//////int main()
//////{
//////	CChild* pChild = new CChild();
//////	CParent* pParent = (CParent*)pChild;
//////	pParent->Intro();
//////	return 0;
//////}
////
////int func(int a, int b);
////
////int func(int a = 0, int b = 0)
////{
////	return a + b;
////}
////
////int main()
////{
////	cout << func(1, 1) << endl;
////
////	return 0;
////}
////
////#include "test.h"
////
//////void fuc1(int a = 0, int b = 0);
////void fuc1(int a = 0, int b = 0)
////{
////	cout << a << " " << b;
////}
////
////int main()
////{
////	fuc1();
////}
//
//#include <iostream>
//#include <map>
//using namespace std;
//
////void func()
////{
////	cout << "func()" << endl;
////}
////
////int main()
////{
////
////	int a = 0, b = 2;
////	auto add1 = [](int x, int y)->int {return x + y; };
////	auto add2 = [](int x, int y)  {return x + y; }; // 一般都不需要写返回值
////
////	cout << add1(a, b) << endl;
////	cout << add2(a, b) << endl;
////
////	auto swap = [](int& x, int y) {
////		int tmp = x;
////		x = y;
////		y = tmp;
////
////		func();
////	};
////
////	swap(a, b);
////
////	return 0;
////}
//
////auto func = [] {cout << "FUNC" << endl; };
////
////int main()
////{
////	int a = 1, b = 2;
////
////	auto f3 = [](int a, int b) {
////		func();
////		return a + b; 
////	};
////
////
////	cout << f3(a, b) << endl;
////	return 0;
////}
//
//
////#include <functional>
////#include <iostream>
////
////	using namespace std;
////
////double sub1(int x, double rate, int y)
////{
////	return (x - y) * rate;
////}
////
////int main()
////{
////	function<double(int, int)> ff1 = bind(sub1, placeholders::_1, 1.5, placeholders::_2);
////
////	//在定义期间固定参数，类似与缺省值的效果。
////	cout << ff1(2, 1) << endl;
////
////	auto ff2 = bind(sub1, placeholders::_2, 1, placeholders::_1);
////	cout << ff2(3, 1) << endl;
////}
//
//
////定义
////MemoryPool MemoryPool::_inst;
//
////class MemoryPool
////{
////public:
////
////	// 提供获取单例对象的接口函数
////	static MemoryPool* GetInstance()
////	{
////		return _pinst;
////	}
////
////	void* Alloc(size_t n)
////	{
////		void* ptr = nullptr;
////		// ....
////		return ptr;
////	}
////
////	void Dealloc(void* ptr)
////	{
////		// ...
////	}
////
////	// 防止拷贝
////	MemoryPool(MemoryPool& my) = delete;
////	MemoryPool& operator= (MemoryPool& my) = delete;
////private:
////	// 构造函数私有化
////	MemoryPool()
////	{}
////
////	char* _ptr = nullptr;
////	// ...
////
////	static MemoryPool* _pinst; // 声明
////};
////
////// 定义
////MemoryPool* MemoryPool::_pinst = new MemoryPool;
////
////int main()
////{
////	//MemoryPool pool1;
////	//MemoryPool pool2;
////
////	void* ptr1 = MemoryPool::GetInstance()->Alloc(10);
////	MemoryPool::GetInstance()->Dealloc(ptr1);
////}
//
////#include <map>
////
////
////namespace lazy
////{
////	class Singleton
////	{
////	public:
////		// 2、提供获取单例对象的接口函数
////		static Singleton& GetInstance()
////		{
////			if (_psinst == nullptr)
////			{
////				// 第一次调用GetInstance的时候创建单例对象
////				_psinst = new Singleton;
////			}
////
////			return *_psinst;
////		}
////
////		// 一般单例不用释放。
////		// 特殊场景：1、中途需要显示释放  2、程序结束时，需要做一些特殊动作（如持久化）
////		static void DelInstance()
////		{
////			if (_psinst)
////			{
////				delete _psinst;
////				_psinst = nullptr;
////			}
////		}
////
////		void Add(const pair<string, string>& kv)
////		{
////			_dict[kv.first] = kv.second;
////		}
////
////		void Print()
////		{
////			for (auto& e : _dict)
////			{
////				cout << e.first << ":" << e.second << endl;
////			}
////			cout << endl;
////		}
////
////		class GC
////		{
////		public:
////			~GC()
////			{
////				lazy::Singleton::DelInstance();
////			}
////		};
////
////	private:
////		// 1、构造函数私有
////		Singleton()
////		{
////			// ...
////		}
////
////		~Singleton()
////		{
////			cout << "~Singleton()" << endl;
////
////			// map数据写到文件中
////			FILE* fin = fopen("map.txt", "w");
////			for (auto& e : _dict)
////			{
////				fputs(e.first.c_str(), fin);
////				fputs(":", fin);
////				fputs(e.second.c_str(), fin);
////				fputs("\n", fin);
////			}
////		}
////
////		// 3、防拷贝
////		Singleton(const Singleton& s) = delete;
////		Singleton& operator=(const Singleton& s) = delete;
////
////		map<string, string> _dict;
////		// ...
////
////		static Singleton* _psinst;
////		static GC _gc;
////	};
////
////	Singleton* Singleton::_psinst = nullptr;
////	Singleton::GC Singleton::_gc;
////}
////
//////class GC
//////{
//////public:
//////	~GC()
//////	{
//////		lazy::Singleton::DelInstance();
//////	}
//////};
//////
//////GC gc;
////
////int main()
////{
////	//Singleton s1;
////	//Singleton s2;
////
////	cout << &lazy::Singleton::GetInstance() << endl;
////	cout << &lazy::Singleton::GetInstance() << endl;
////	cout << &lazy::Singleton::GetInstance() << endl;
////
////	//Singleton copy(Singleton::GetInstance());
////
////	lazy::Singleton::GetInstance().Add({ "xxx", "111" });
////	lazy::Singleton::GetInstance().Add({ "yyy", "222" });
////	lazy::Singleton::GetInstance().Add({ "zzz", "333" });
////	lazy::Singleton::GetInstance().Add({ "abc", "333" });
////
////	lazy::Singleton::GetInstance().Print();
////
////	//lazy::Singleton::DelInstance();
////
////	lazy::Singleton::GetInstance().Add({ "abc", "444" });
////	lazy::Singleton::GetInstance().Print();
////
////	//lazy::Singleton::DelInstance();
////
////	return 0;
////}
//
////int main()
////{
////	int a = 0;
////	int* p = &a;
////
////	int address =(int)p;
////
////	cout << address << endl;
////
////	return 0;
////}
//
////int main()
////{
////	volatile const int a = 2;
////	int* p = const_cast<int*>(&a);
////	*p = 4;
////	cout << a << endl;
////	cout << *p << endl;
////	return 0;
////}
//
////class A
////{
////public:
////	virtual void f() {}
////
////	int _a = 0;
////};
////
////class B :public A
////{
////public:
////	int _b = 0;
////};
////void Func(A* ptr) // 子类指针传过来，父 = 子，向上转换，切片，支持
////{
////	B* bptr = (B*)ptr;
////	bptr->_a++;
////	bptr->_b++;
////		
////}
////int main()
////{
////	B bb;
////	Func(&bb);
////	return 0;
////}
//
////class A
////{
////public:
////	virtual void f() {}
////
////	int _a = 0;
////};
////
////class B :public A
////{
////public:
////	int _b = 0;
////};
////void Func(A* ptr)
////{
////	//直接转换是不安全的
////   // B* bptre = (B*)ptr
////
////	// dynamic_cast<B*>(ptr)
////	// bptr 是指向子类对象 B 的，转换可以成功，正常返回地址
////	// bptr 指向父类对象 A 的，转换失败，返回空指针（这里就是之前的向下转换）
////	B* bptr = dynamic_cast<B*>(ptr);
////	cout << bptr << endl;
////	if (bptr)
////	{
////		cout << "转化成功" << endl;
////		bptr->_a++;
////		bptr->_b++;
////		cout << bptr->_a << endl;
////		cout << bptr->_b << endl;
////	}
////	else
////	{
////		cout << "转化失败" << endl;
////	}
////	cout << endl;
////}
////int main()
////{
////	A aa;
////	B bb;
////	Func(&aa);
////	Func(&bb);
////	return 0;
////}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
////class A
////{
////public:
////	//explicit A(int a)
////	A(int a)
////		:_a(a)
////	{}
////private:
////	int _a;
////};
////
////class B
////{
////public:
////	B(const A& a)
////	{}
////private:
////	//...
////};
////
////void insert(size_t pos, char ch)
////{
////	int end = 10;
////	while (end >= pos)
////	{
////		cout << end << endl;
////		//...
////		--end;
////	}
////}
//
////int main()
////{
////    int i = 1;
////    // 隐式类型转换
////    double d = i;
////    printf("%d, %.2f\n", i, d);
////
////    A aa1 = 1;
////    B bb1 = aa1;
////
////    int* p = &i;
////    // 显示的强制类型转换
////    int address = (int)p;
////
////    printf("%p, %d\n", p, address);
////
////    //vector<int> v;
////    //string s;
////    //v = (vector<int>)s;
////
////    insert(3, 'x');
////    insert(0, 'x');
////
////
////    return 0;
////}
//
////int main()
////{
////	// volatile 修饰的变量，每次都要去内存取
////	volatile const int n = 10;
////	//n = 11;
////	// 转换有安全隐患的
////	int* p = (int*)&n;
////	(*p)++;
////
////	cout << n << endl;
////	cout << *p << endl;
////
////	cout << p << endl;
////
////	return 0;
////}
//
////int main()
////{
////	// 相关类型/相近类型
////	double d = 12.34;
////	int a = static_cast<int>(d);
////	cout << a << endl;
////
////	// 不相关类型
////	int* p1 = &a;
////	int address = reinterpret_cast<int>(p1);
////
////	// 去掉const属性
////	volatile const int n = 10;
////	int* p2 = const_cast<int*>(&n);
////
////	// 
////
////
////	return 0;
////}
//
////class A
////{
////public:
////	virtual void f() {}
////
////	int _x = 0;
////};
////
////class B : public A
////{
////public:
////	int _y = 0;
////};
////
////void fun(A* pa)
////{
////	// pa是指向子类对象B的，转换可以成功，正常返回地址
////	// pa是指向父类对象A的，转换失败，返回空指针
////	B* pb = dynamic_cast<B*>(pa);
////	if (pb)
////	{
////		cout << "转换成功" << endl;
////		pb->_x++;
////		pb->_y++;
////	}
////	else
////	{
////		cout << "转换失败" << endl;
////	}
////}
//
////int main()
////{
////	A aa;
////	fun(&aa);
////
////	B bb;
////	fun(&bb);
////
////	return 0;
////}
//
////int main()
////{
////	string str;
////	while (cin >> str) // operator>>(cin, str).operator bool()
////	{
////		cout << str << endl;
////	}
////
////	return 0;
////}
//
////class A
////{
////public:
////	A(int a)
////		:_a(a)
////	{}
////
////	//explicit operator int()
////	operator int ()
////	{
////		return _a;
////	}
////
////	operator bool()
////	{
////		return _a;
////	}
////
////	int _a;
////};
////
////int main()
////{
////	//// 自定义类型<-内置类型
////	//A aa1 = 100;
////
////	//// 内置类型<-自定义类型
////	//int i = aa1;
////	//cout << i << endl;
////
////	////double d = aa1;
////	////int* ptr = aa1;
////
////	//bool ret = aa1;
////	//cout << ret << endl;
////
////	int a, b;
////	while (cin>>a>>b)  // cin.operator>>(a).operator>>(b).operator bool()
////	{
////		cout << a << endl;
////		cout << b << endl;
////	}
////
////	return 0;
////}
//
//class Date
//{
//	friend ostream& operator << (ostream& out, const Date& d);
//	//friend istream& operator >> (istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	/*operator string()
//	{
//		string str;
//		str += to_string(_year);
//		str += ' ';
//		str += to_string(_month);
//		str += ' ';
//		str += to_string(_day);
//		return str;
//	}*/
//
//	operator bool()
//	{
//		// 这里是随意写的，假设输入_year为0，则结束
//		if (_year == 0)
//			return false;
//		else
//			return true;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////istream& operator >> (istream& in, Date& d)
////{
////	in >> d._year >> d._month >> d._day;
////	return in;
////}
//
//ostream& operator << (ostream& out, const Date& d)
//{
//	out << d._year << " " << d._month << " " << d._day;
//	return out;
//}
//
//#include<fstream>
//
////int main()
////{
////	Date d(2023, 10, 14);
////	//FILE* fin = fopen("file.txt", "w");
////	/*fwrite(&d, sizeof(Date), 1, fin);
////	fclose(fin);*/
////	//string str = d;
////	//fputs(str.c_str(), fin);
////
////	// 17:15继续
////	//ofstream ofs("file.txt", ios_base::out | ios_base::binary);
////	ofstream ofs("file.txt");
////	// 二进制的方式
////	//ofs.write((const char*)&d, sizeof(d));
////	// 
////	// 文本的方式
////	ofs << d;
////
////	return 0;
////}
//
//struct ServerInfo
//{
//	char _address[32];
//	// 二进制读写不能用string vector这样的对象存数据
//	// 否则写出去就是一个指针，进程结束就是野指针，另一个进程再读进来进坑了
//	//string _address;
//	int _port;
//
//	Date _date;
//};
//
//struct ConfigManager
//{
//public:
//	ConfigManager(const char* filename = "file.txt")
//		:_filename(filename)
//	{}
//
//	// 二进制读写 -- 简单高效，缺点：写到文件中的内容看不懂
//	void WriteBin(const ServerInfo& info)
//	{
//		ofstream ofs(_filename, ios_base::out | ios_base::binary);
//		ofs.write((const char*)&info, sizeof(info));
//	}
//
//	void ReadBin(ServerInfo& info)
//	{
//		ifstream ifs(_filename, ios_base::in | ios_base::binary);
//		ifs.read((char*)&info, sizeof(info));
//	}
//
//	void WriteText(const ServerInfo& info)
//	{
//		ofstream ofs(_filename);
//		ofs << info._address << " " << info._port << " " << info._date;
//	}
//
//	/*void ReadText(ServerInfo& info)
//	{
//		ifstream ifs(_filename);
//		ifs >> info._address >> info._port >> info._date;
//	}*/
//private:
//	string _filename; // 配置文件
//};
//
////int main()
////{
////	ServerInfo winfo = { "192.0.0.1111111111111111111", 80, { 2022, 4, 10 } };
////	ConfigManager cm("test.bin");
////	cm.WriteBin(winfo);
////
////	return 0;
////}
//
////int main()
////{
////	ConfigManager cf_bin("test.bin");
////	ServerInfo rbinfo;
////	cf_bin.ReadBin(rbinfo);
////	cout << rbinfo._address << "  " << rbinfo._port << "  " << rbinfo._date << endl;
////
////	return 0;
////}
////
////int main()
////{
////	ServerInfo winfo = { "192.0.0.1111111111111111111", 80, { 2022, 4, 10 } };
////	ConfigManager cm("test.txt");
////	cm.WriteText(winfo);
////
////	return 0;
////}
//
////int main()
////{
////	ConfigManager cf_bin("test.txt");
////	ServerInfo rbinfo;
////	cf_bin.ReadText(rbinfo);
////	cout << rbinfo._address << "  " << rbinfo._port << "  " << rbinfo._date << endl;
////
////	return 0;
////}
//
////int main()
////{
////	ifstream ifs("Test.cpp");
////	char ch;
////	while (ifs.get(ch))
////	{
////		cout << ch;
////	}
////
////	return 0;
////}
//
//#include<sstream>
//
//
//
////struct ChatInfo
////{
////	string _name; // 名字
////	int _id;      // id
////	Date _date;   // 时间
////	string _msg;  // 聊天信息
////};
//
////int main()
////{
////	ChatInfo winfo = { "张三", 135246, { 2023, 10, 16 }, "晚上一起看电影吧" };
////	stringstream oss;
////	oss << winfo._name << " " << winfo._id << " " << winfo._date << " " << winfo._msg;
////	string str = oss.str();
////
////	//send(str);
////	cout << str << endl;
////
////	// json xml 
////	ChatInfo rInfo;
////	stringstream iss(str);
////	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
////	cout << "-------------------------------------------------------" << endl;
////	cout << "姓名：" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
////	cout << rInfo._name << ":>" << rInfo._msg << endl;
////	cout << "-------------------------------------------------------" << endl;
////	return 0;
////}
//
//
