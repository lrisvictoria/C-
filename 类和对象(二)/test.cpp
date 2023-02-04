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
//	~Date()
//	{
//		cout << "~Date()" << endl;
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
//	Date d1;
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a = nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//	Stack(const Date& d)
//	{
//		
//	}
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//
//int main()
//{
//	MyQueue mq;
//
//	return 0;
//}

//class A
//{
//public:
//	A() {}
//	A(const A& a)
//	{
//		cout << "A(const A&)" << endl;
//	}
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
//	~Date()
//	{
//		cout << "~Date()" << endl;
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
//	Date d2(d1);
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4) // 构造函数，缺省1参数，不传参默认给 4
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a = nullptr)
//		{
//			cout << "malloc fail" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//	void push() {}
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main()
//{
//	Stack s1;
//	Stack s2(20);
//
//	return 0;
//}

// 运算符重载

#include <iostream>

using namespace std;

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
//};
//
//bool operator>(const Date& d1, const Date& d2)
//{
//	if (d1._year > d2._year) // d1 年份 > d2 年份
//	{
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month > d2._month) // 年份相等, d1 月份 > d2 月份
//	{
//		return true;
//	} 
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day) // 年月相等, d1 日 > d2 日
//	{
//		return true;
//	}
//	else // 其他小于的情况
//	{
//		return false;
//	}
//}
//
//
//int main()
//{
//	Date d1(2023, 2, 3);
//	Date d2(2023, 3, 4);
//
//	cout << (d1 > d2) << endl; // 涉及到优先级，加一个括号
//	cout << operator>(d1, d2) << endl; // 这样也可以
//
//	return 0;
//}

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
//	Date(const Date& d)
//	{
//		cout << "进行拷贝构造" << endl;
//	}
//
//	// d1 = d3
//	Date& operator=(const Date& d)
//	{
//		if (this != &d) // this 和 d 相等 
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//
//		return *this;
//	}
//
//	bool operator>(const Date d)
//	{
//		if (_year > d._year) 
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month) 
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day)
//		{
//			return true;
//		}
//		else 
//		{
//			return false;
//		}
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1(2023, 2, 3);
//	Date d2(2023, 3, 4);
//
//	Date d3(2022, 2, 3);
//
//	d3 = d2 = d1;
//
//	return 0;
//}

//class Date
//{
//public:
//	Date()
//	{
//		_year = 100;
//	}
//	
//	void Print()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//
//private:
//	int _year; // 缺省值
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	
//	d1.Print();
//
//	return 0;
//}

//#include <cassert>
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
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	int GetMonthDay(int year, int month)
//	{
//		assert(month > 0 && month < 13);
//		int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		int day = monthDayArr[month];
//
//		if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
//		{
//			day += 1;
//		}
//
//		return day;
//	}
//
//	/*
//	* 让当前天数加上 x ，若当前天数大于本月天数，则需要进位
//	*/
//	Date GetAfterXDay(int x)
//	{
//		Date tmp = *this; // 拷贝构造一份，防止把自己改掉
//		tmp._day += x;
//		while (tmp._day > GetMonthDay(tmp._year, tmp._month)) // 32 31
//		{
//			// 进位
//			tmp._day -= GetMonthDay(tmp._year, tmp._month); // 32 - 31 = 1
//			tmp._month++; // 月份 + 1
//			if (tmp._month == 13) // 若月份超了，则进一年
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//		}
//
//		return tmp; // 返回 tmp 的年月日
//	}
//
//	/*~Date()
//	{
//		cout << "析构" << endl;
//	}*/
//
//	void Print()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
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
//	Date d1(2022, 1, 2);
//	Date d2 = d1.GetAfterXDay(100);
//
//	d1.Print();
//	d2.Print();
//
//	return 0;
//}

class Widget
{
public:
	Widget()
	{
		// cout << "Wiget(const Widget&)" << endl;
	}

	Widget(const Widget&)
	{
		cout << "Wiget(const WidGet&)" << endl;
	}
};

Widget f(Widget u)
{
	return u;
}

int main()
{
	//Widget x;
	//Widget y = f(x); // 理论三次，但是这里只有两次
	// 在一次调用中，连续构造函数，会被编译器优化，合二为一，直接拿 u 的返回值去优化了

	Widget x, y;

	y = f(x);

	return 0;
}