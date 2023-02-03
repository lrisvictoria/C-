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
//	Date d1; // �Զ����õ�һ�����캯��
//	Date d2(2023, 1, 31); // ���ε��õڶ������캯��
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
//	Stack(int capacity = 4) // ���캯����ȱʡ1������������Ĭ�ϸ� 4
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

// ���������

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
//	if (d1._year > d2._year) // d1 ��� > d2 ���
//	{
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month > d2._month) // ������, d1 �·� > d2 �·�
//	{
//		return true;
//	} 
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day) // �������, d1 �� > d2 ��
//	{
//		return true;
//	}
//	else // ����С�ڵ����
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
//	cout << (d1 > d2) << endl; // �漰�����ȼ�����һ������
//	cout << operator>(d1, d2) << endl; // ����Ҳ����
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
//		cout << "���п�������" << endl;
//	}
//
//	// d1 = d3
//	Date& operator=(const Date& d)
//	{
//		if (this != &d) // this �� d ��� 
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
//	int _year; // ȱʡֵ
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

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// ��ȡ������֮���һ��
	Date GetAfterDay()
	{

	}

	~Date()
	{
		cout << "����" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};