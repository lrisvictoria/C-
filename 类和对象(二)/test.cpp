/*
date : 2022.1.31
author : anduin
lanuage : cpulusplus
*/

#include <iostream>

using namespace std;

//class Date
//{
//public:
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1; // 自动调用第一个构造函数
//	Date d2(2023, 1, 31); // 传参调用第二个构造函数
//
//	return 0;
//}


//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _aa;
//};
//
//int main()
//{
//	Date d1;
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _aa;
//};
//
//int main()
//{
//	Date d1;
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	~Date()
	{
		// Date 类没有资源需要清理，所以 Date 类不识闲析构函数都可以
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;

	return 0;
}