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
//	return 0;
//}

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int count[26];
	memset(count, 0, sizeof(int));

	return 0;
}