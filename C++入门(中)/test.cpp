#include <iostream>

using namespace std;

//int add(int left, int right)
//{
//	return left + right;
//}
//
//int add(double left, double right);
////{
////	return left + right;
////}
//
//int add(double left, double right, int mid)
//{
//	return left + right;
//}
//
//int add(int left, char right)
//{
//	return left + right;
//}
//
//int add(char right, int left)
//{
//	return left + right;
//}
//
//int main()
//{
//	cout << add(1.1, 1.2) << endl;
//	cout << add(1, 2);
//
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& b = a; // 引用
//
//	b = 10;
//	
//
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << "a = " << a << ' ' << "b = " << b << endl;// 修改前
//
//	b = 20;
//	cout << "a = " << a << ' ' << "b = " << b << endl; // 修改b
//
//	a = 30;
//	cout << "a = " << a << ' ' << "b = " << b << endl; // 修改a
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	int& c = b;
//
//	double c = 0.0;
//
//	cout << "a = " << a << ' ';
//	cout << "b = " << c << ' ';
//	cout << "c = " << c;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//
//	int c = 20;
//	b = c;
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int c = 20;
//
//	int* p = &a;
//	p = &c;
//
//	return 0;
//}

//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	cout << "a = " << a << ' ' << "b = " << b << endl;
//
//	swap(&a, &b);
//
//	cout << "a = " << a << ' ' << "b = " << b;
//
//	return 0;
//}

//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	cout << "a = " << a << ' ' << "b = " << b << endl;
//
//	swap(a, b);
//
//	cout << "a = " << a << ' ' << "b = " << b;
//
//	return 0;
//}

// 传址
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//// 传引用
//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//// 传值
//void swap(int x, int y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	swap(&a, &b);
//	swap(a, b);
//
//	return 0;
//}

//int& add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = add(1, 2);
//	cout << ret << endl;
//
//	add(10, 20);
//
//	cout << ret << endl;
//
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; } // 拷贝
//// 引用返回
//A& TestFunc2() { return a; } // 不拷贝
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestRefAndValue();
//}

void func(const int& x)
{
	cout << x << endl;
}

int main()
{
	const int a = 10;
	const int& b = a; // 权限不变

	int c = 10;
	const int& d = c; // 权限缩小

	func(a);
	func(c);
	func(10);

	return 0;
}