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

#include <iostream>

using namespace std;

class A
{
public:
	static A GetStackObj()
	{
		A aa;
		return aa;
	}

	static A* GetHeapObj()
	{
		return new A;
	}

	// 封装成私有，只能在类内部调用
	// 这样子就不能直接创建对象
private:
	A()
	{}

private:
	int _a1 = 1;
	int _a2 = 2;
};


int main()
{
	// 但是调用两个成员函数就会被对象和成员函数的优先级所困扰
	// 因为调用需要有一个对象，但是对象的指定创建范围不同
	// 这时就可以使用静态成员函数
	// static A GetStackObj();

	return 0;
}