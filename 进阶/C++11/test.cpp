#include <iostream>
#include <vector>
#include <string>

using namespace std;

//struct Point
//{
//	Point(int x, int y)
//		:_x(x)
//		,_y(y)
//	{
//		cout << "Point(int x, int y)" << endl;
//	}
//
//	int _x;
//	int _y;
//};
//
//// 一切皆可用 {} 初始化，并且可以不写赋值符号
//// 日常定义不要去掉 =，但是我们要能看懂
//int main()
//{
//	int x = 1;
//	int y = { 2 }; // 整形支持这样初始化
//	int z{ 3 };// right
//	int a1[] = { 1, 2,3 };
//	int a2[]{ 1, 2, 3 }; // 数组这样初始化也对
//
//	// 本质都是调用构造函数
//	Point p(1, 2);
//	Point p1 = { 1, 3 }; //会不会调用构造函数? 会 本质是多参数构造函数的隐式类型转换
//	Point p2{ 2, 2 }; // 会不会调用构造函数? 会
//
//	const Point& r = { 3, 3 }; // 临时对象具有常性
//
//	int* p1 = new int[3] {1, 2, 3};
//	Point* ptr = new Point[2]{ {1, 2}, {2, 3} }; // 当没有有名对象时虚浮了很多，不用匿名对象
//
//
//	return 0;
//}

int main()
{
	vector<int> v1 = { 1, 2 }; // 不是列表初始化支持的，它们有不同的规则
	// 这里本质也是一个构造
	// 这个列表叫做 initializer_list
	auto il = { 10, 20, 30 };
	initializer_list<int> il = { 10, 20, 30 };
	cout << typeid(il).name() << endl;

}