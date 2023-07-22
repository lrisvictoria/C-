#include <iostream>
#include <vector>
#include <list>
#include <array>

using namespace std;

// 模板解决的两类问题：
// 1. 模板可以控制容器的数据类型(stl)
// 2. 控制设计逻辑，例如容器适配器，使设计更加灵活

// 只要传一个类型就可以用模板，不局限于控制容器的数据类型

// 模板可以用 class 可以用 typename，日常无区别，但是下面情况有区别

//void Print(const vector<int>& v)
//{
//	vector<int>::const_iterator it = v.begin(); // 到 vector<int> 中找 const_iterator 
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

// 针对容器类型写为泛型
//template<typename Container> // 表达意思更好，类的类型
template<class Container>
void Print(const Container& v)
{
	// class 和 typename 使用不一样的地方，这里必须加 typename，不能加 class 
	// 函数模板的参数是一个类，类container没实例化
	// const_iterator 可能是类中的静态成员，也有可能是一个内嵌类型
	// typename 就是告诉编译器它是一个类型
	// 确定类型是在实例化之后确定类型，main 中显示实例化
	// 编译不确定Container::const_iterator是类型还是对象
	// typename就是明确告诉编译器这里是类型，等模板实例化再去找
	typename Container::const_iterator it = v.begin();
	// auto it = v.begin(); // 或者 auto ，直接推导类型，明确就是类型
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// const_iterator begin 不是关键字，可以随便用
// 不能保证它们就是类型
// 函数模板在运行期间实例化(编译完成)

//class A
//{
//public:
//	int begin()
//	{
//		return 0;
//	}
//
//	static int const_iterator;
//};
//
//int A::const_iterator = 1;

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	Print(v);
//
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	for (auto e : lt)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	Print(lt);
//
//	
//	return 0;
//}

// 非类型模板参数

// #define N 100 // 控不住两个

// 静态栈
//template<class T>
//class Stack
//{
//private:
//	T _a[N]; // 需要的是常量
//	int _top;
//};
//
//int main()
//{
//	Stack<int> st1; // 容量 10
//	Stack<int> st2; // 容量 100 做不到
//
//	return 0;
//}


// 静态栈
// 非类型模板参数
// 1、常量
// 2、必须是整形（规定，double 不行）

// 之前使用的模板参数叫做类型模板参数

template<class T, size_t N = 10>
class Stack
{
public:
	void func()
	{
		// 常量，不能修改，调用会报错
		N = 0;
	}
private:
	T _a[N];
	int _top;
};



// error
//template<class T, double N>
//class BB
//{};

//int main()
//{
//	Stack<int> st;
//	Stack<int, 10> st1; // 10
//	Stack<int, 100> st2; // 100
//
//	// 按需实例化(调用了才会实例化)，不同编译器处理不同
//	// 不实例化，func 中的语法错误就检查不到
//	// st1.func();
//
//	return 0;
//}


// array 支持非类型模板参数
// 是一个定长数组，没有插入的概念
// 一初始化，空间就是开好的，可以直接 [] 访问

//int main()
//{
//	int a[10]; // 不默认初始化
//	a[0] = 0;
//	for (auto e : a)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	// c++11
//	array<int, 10> a1; //  也不初始化
//	a1[0] = 0;
//	for (auto e : a1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	// array 相比数组，检查越界很严格，越界读，写都可以
//	// [] 调用，里面会检查
//	// 普通数组不能检查越界读，少部分越界写可以检查
//
//	// 但是 vector 也能检查，所以比较鸡肋，vector 在堆上，array 在栈上
//	// 非类型模板参数为整形，因为祖师爷一开始就是想定义固定大小的数组
//
//	return 0;
//}


// 模板的特化
// 针对某些类型特殊化处理

// &a, &b 函数模板的特化
// 如果是 int* 指针，按指向内容比
//template<>
//bool Less<int*>(int* left, int* right)
//{
//	return *left < *right;
//}

// 但是针对特殊类型，只要写重载函数就行
// 模板还是就近原则
bool Less(int* left, int* right)
{
	return *left < *right;
} 


template<class T>
bool Less(T* left, T* right)
{
	return *left < *right;
}

// 但是如果想要解决所有指针的问题，还得用模板

// 普通类型按这个比较
template<class T>
bool Less(T left, T right)
{
	return left < right;
}

//int main()
//{
//	cout << Less(1, 2) << endl;
//
//	int a = 1, b = 2;
//	cout << Less(&a, &b) << endl; // 期望比较指针指向的内容，但是平常的又希望就按照大小比较
//
//	double c = 1.1, d = 2.2;
//	cout << Less(&c, &d) << endl;
//
//	return 0;
//}

// 实际上，函数模板写重载更好，也更好写

//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
//// 假设针对 int double 要进行特殊处理，特化
//// 函数对于这种情况可以重载，但是类模板
//// 全特化
//template<>
//class Data<int, double>
//{
//public:
//	Data() { cout << "Data<int, double>" << endl; }
//private:
//	int _d1;
//	double _d2;
//};
//
//// 偏特化(半特化) ： 特化部分参数
//template<class T1>
//class Data<T1, double>
//{
//public:
//	Data() { cout << "Data<T1, double>" << endl; }
//private:
//};
//
//// 偏特化 ： 可能是对某些类型的进一步限制
//// 这里限制为指针
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//};
//
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//private:
//};


//int main()
//{
//	Data<int, int> d1;
//	Data<int, double> d2;
//	Data<int*, double> d3;
//	Data<double, double> d4;
//	Data<double*, double*> d5;
//	Data<void*, int*> d6; // void 不能定义变量，所以成员不能写 void _d
//	Data<int&, double&> d7;
//
//	return 0;
//}

// 特化让我们变得更加方便，函数重载，重写类等
// 特化相当于是一个新的类，没必要把之前类中的所有东西搬进来，按需求来
// 想写什么都可以
// 全特化，不需要实例化，可以直接用，因为类型已经规定好了

// 特化严格来说不算是新的类，因为不能独立存在，在类的基础上
// 但是实例化出的是新的类型

// 实际上特化的一般都是很小的类，所以一般不会出现要搬很多东西的情况，比如仿函数

// 模板的分离编译

// 有函数定义才有地址
// 在编译过程中，头文件被包含在源文件中
// 在头文件中有定义的才有地址,否则在编译中无法确定地址

#include"Stack.h"

int main()
{
	bit::stack<int, vector<int>> st;  // call xxstackxx(0x324242) 也是链接生成汇编语言的时候
	st.push(1);  // call xxpushi(?) 链接的时候在符号表里找不到地址
	// st.pop();

	st.size();   // call xxsizexx(0xdadada) 预处理包含头文件后，链接生成汇编语言时，在链接中的 test.s 确认：有定义就有地址，包含头文件后，test.s 中有定义
	st.top();

	bit::A aa;
	aa.func1(1);   // call xxfunc1xx(?) 没有链接错误，找的到，因为定义了
	// aa.func2();  // call xxfunc2xx(?) 有链接错误，因为只有声明，链接之前是单交互的

	// 结合图来看
	// push func1 func2 在编译时无法确定地址（打问号的都没确认）
	// 编译(小过程），构造函数，size 的地址确认了
	// 其他的没确认，编译时因为有声明，声明是一种承诺
	// 检查这些函数的时候，发现函数的声明(函数名，参数，返回值）都对应，编译就能过
	// 等着链接的时候，拿着修饰后的函数名，到其他文件符号表查找
	
	// 问题：
	// 1. func1 链接查到
	// 2. func2 查不到，没定义
	// 3. push 链接查不到，但是 push 定义了

	// 3: stack.o 不能生成地址，因为不知道 T 是什么，push 和 pop 没有实例化
	// 比如 st.push(1) 地址就是 xxpushi ，但是找不到，因为没有实例化，没有生成地址。

	// 两种解决方法：
	// 1. 在 Stack.cpp 中，显示实例化，在文件命名空间内的任意位置都可以
	// 但是对于不同类型还是需要额外实例化

	// 2. size 为什么可以？因为声明定义在同一个文件中
	// 所以可以声明和定义分离放在一个文件中
	// stl 也是这么做的

	// .hpp 声明和定义在一个文件中，boost 库中就是这种命名，命名暗示

	// 有点：灵活性(适配器，仿函数 -- 不一定是类模板，比如优先级队列，我们手写的普通的lessDate类)

	bit::stack<double> st1;  // call xxstackxx(0x324242)
	st1.push(1);  // call xxpushi(?)
	st1.pop();

	return 0;
}