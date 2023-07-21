#include <iostream>

using namespace std;

//template<class T> // 模板参数列表 -- 参数类型
//
//void Swap(T& x1, T& x2) // 函数参数列表 -- 参数对象
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//
//	Swap(a, b);
//	cout << "a = " << a << " b = " << b << endl;
//	
//	Swap(c, d);
//	cout << "c = " << c << " d = " << d << endl;
//
//	return 0;
//}

//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	cout << Add(a1, a2) << endl; // 34 行
//
//	cout << Add(a1, d1) << endl; // 29 行
//	
//	return 0;
//}

// 写一个栈

//typedef int DataType;
//typedef double DataType;
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	DataType* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	return 0;
//}


template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
		:_top(0)
		, _capacity(capacity)
	{
		_a = new int[capacity];
	}

	~Stack()
	{
		delete[] _a;
		_a = nullptr;
		_capacity = _top = 0;
	}

private:
	T* _a;
	int _top;
	int _capacity;
};

int main()
{
	Stack<int> st1; // int
	Stack<double> st2; // double

	return 0;
}