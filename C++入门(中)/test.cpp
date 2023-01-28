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
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// 传引用
void swap(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

// 传值
void swap(int x, int y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 10;
	int b = 20;

	swap(&a, &b);
	swap(a, b);

	return 0;
}