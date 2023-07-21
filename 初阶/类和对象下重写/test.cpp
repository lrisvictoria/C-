//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	} 
//
//	const A(const A& aa)
//		: _a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1); // 构造函数
//	A aa2 = 2; // 隐式类型转换，整形转换成自定义类型
//	// 2 调用构造函数, 生成 a 类型的临时对象, 临时对象再拷贝构造 aa2
//	// 会优化为用 2 直接构造
//	// 在同一个表达式内的连续的构造编译器基本都会优化
//
//	int i = 10;
//	double d = i; // i 产生临时变量 double 类型
//
//	const A& aa3 = 2; // 常量具有常性，临时变量具有常性
//
//	return 0;
//}

// 设计一个类，在类外面只能在栈或者堆上创建对象

//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	static A GetStackObj()
//	{
//		A aa;
//		return aa;
//	}
//
//	static A* GetHeapObj()
//	{
//		return new A;
//	}
//
//	// 封装成私有，只能在类内部调用
//private:
//	A()
//	{}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//
//int main()
//{
//	// 但是调用两个成员函数就会被对象和成员函数的优先级所困扰
//	// 这时就可以使用静态成员函数
//	// static A GetStackObj();
//
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++_cnt;
//	}
//	A(const A& aa) { ++aa._cnt; }
//
//private:
//	int _a;
//public:
//	static int _cnt;
//};
//
//int A::_cnt = 0;
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	cout << A::_cnt << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	int a()
//	{
//		return _cnt;
//	}
//	int c()
//	{
//		int tmp = 3;
//		return tmp;
//	}
//	static int b()
//	{
//
//		++_cnt;
//		_cnt = c();
//	}
//
//private:
//	static int _cnt;
//};
//
//int A::_cnt = 0;
//
//int main()
//{
//
//
//	return 0;
//}

// 使一个对象只能在栈上创建/堆上创建

//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	static A GetStackObj()
//	{
//		A aa;
//		return aa;
//	}
//
//	static A* GetHeapObj()
//	{
//		return new A;
//	}
//
//	// 封装成私有，只能在类内部调用
//	// 这样子就不能直接创建对象
//private:
//	A()
//	{}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//
//int main()
//{
//	// 但是调用两个成员函数就会被对象和成员函数的优先级所困扰
//	// 因为调用需要有一个对象，但是对象的指定创建范围不同
//	// 这时就可以使用静态成员函数
//	// static A GetStackObj();
//
//	return 0;
//}
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	// A aa1();
//	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
//	// 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
//	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//	A();
//	A aa2(2);
//	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
//	Solution().Sum_Solution(10);
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
int main()
{
	// 传值传参
	A aa1;
	f1(aa1);
	cout << endl;
	// 传值返回
	f2();
	cout << endl;
	// 隐式类型，连续构造+拷贝构造->优化为直接构造
	f1(1);
	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
	f1(A(2));
	cout << endl;
	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
	A aa2 = f2();
	cout << endl;
	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
	aa1 = f2();
	cout << endl;
	return 0;
}