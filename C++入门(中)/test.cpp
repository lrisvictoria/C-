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
//	int& b = a; // ����
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
//	cout << "a = " << a << ' ' << "b = " << b << endl;// �޸�ǰ
//
//	b = 20;
//	cout << "a = " << a << ' ' << "b = " << b << endl; // �޸�b
//
//	a = 30;
//	cout << "a = " << a << ' ' << "b = " << b << endl; // �޸�a
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

// ��ַ
//void swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//// ������
//void swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//// ��ֵ
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
//// ֵ����
//A TestFunc1() { return a; } // ����
//// ���÷���
//A& TestFunc2() { return a; } // ������
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
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
	const int& b = a; // Ȩ�޲���

	int c = 10;
	const int& d = c; // Ȩ����С

	func(a);
	func(c);
	func(10);

	return 0;
}