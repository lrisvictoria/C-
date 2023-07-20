#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

#include "stack_queue.h"
#include "priority_queue.h"

//// 仿函数/函数对象
//template<class T>
//class Less
//{
//public:
//	// 实际上就是重载了 ()
//	// 比较自定义类型的前提是重载了类型的比较符号
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};

int main()
{
	lx::test_priority_queue2();
	
	// Less<int> lessfunc;

	// 看起来像函数名，像函数指针
	// 仿函数类的类对象可以像函数一样使用
	// 有函数指针的功能却比函数指针更加完善
	// cout << lessfunc(1, 2) << endl;
	// cout << lessfunc.operator()(1, 2) << endl;
	return 0;
}