/*
类和对象：一
*/
#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <cstring>

using namespace std;

//struct Stu
//{
//	char _name[10];
//	int _age;
//	int _id;
//
//	void init(const char* name, int age, int id) 
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//
//	void print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};
//
//int main()
//{
//	struct Stu s1;
//	Stu s2;
//
//	s1.init("anduin", 19, 1);
//	s2.init("guldan", 20, 2);
//
//	s1.print();
//	s2.print();
//	
//	return 0;
//}

//struct Stu
//{
//public:
//	char _name[10];
//	int _age;
//	int _id;
//
//	void init(const char* name, int age, int id) 
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//protected:
//	void print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//		cout << _id << endl;
//	}
//};
//
//int main()
//{
//	Stu s;
//	s._name;
//	s.init("anduin", 19, 1);
//	s.print();
//
//	return 0;
//}

//struct Stu1
//{
//	int age1;
//};
//
//class Stu2
//{
//	int age2;
//};
//
//int main()
//{
//	Stu1 s1;
//	Stu2 s2;
//
//	s1.age1 = 1;
//	s2.age2 = 1;
//
//	return 0;
//}

//class Stack
//{
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//public:
//	void Init()
//	{
//		_a = nullptr;
//		_top = _capacity;
//	}
//	void Push() {}
//	void Pop() {}
//	void Top() {}
//};

#include "Stack.h"

//int main()
//{
//	Stack s;
//	cout << "class Stack 的大小 : " << sizeof(Stack) << endl;
//	cout << "Sack 成员 s 的大小 : " << sizeof(s) << endl;
//
//	return 0;
//}

//class ch // 大小为 1
//{
//	char c;
//};
//
//class null // 空
//{
//};
//
//class nom // 只有成员方法
//{
//	void foo() {}
//};
//
//int main()
//{
//	ch a;
//	null b;
//	nom c;
//
//	cout << "a: " << sizeof(a) << ' ' << "b: " << sizeof(b) << ' ' << "c: " << sizeof(c);
//
//	return 0;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		Date::year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date s;
//	s.Init(2023, 1, 31);
//
//	return 0;
//}

//void Init(Date* this, int year, int month, int day)
//{
//	this->_year = year;
//	this->_month = month;
//	this->_day = day;
//}

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
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
//	d1.Init(2023, 1, 31);
//	d1.Print();
//
//	Date d2;
//	d2.Init(2023, 2, 1);
//	d2.Print();
//
//	return 0;
//}



// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	p->PrintA();
	return 0;
}