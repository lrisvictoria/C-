/*
��Ͷ���һ
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
//	cout << "class Stack �Ĵ�С : " << sizeof(Stack) << endl;
//	cout << "Sack ��Ա s �Ĵ�С : " << sizeof(s) << endl;
//
//	return 0;
//}

class ch // ��СΪ 1
{
	char c;
};

class null // ��
{
};

class nom // ֻ�г�Ա����
{
	void foo() {}
};

int main()
{
	ch a;
	null b;
	nom c;

	cout << "a: " << sizeof(a) << ' ' << "b: " << sizeof(b) << ' ' << "c: " << sizeof(c);

	return 0;
}