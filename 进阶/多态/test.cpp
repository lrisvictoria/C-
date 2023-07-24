#include <iostream>

using namespace std;


// 虚函数
// 虽然都用 virtual 但是虚函数和虚继承没有任何关系
// 成员函数才能变成虚函数
// 虚函数的重写
// 不同的人去调用函数就有不同的形态 

// 之前调用不同的函数需要指定
// 现在调用不同的函数只要根据调用的对象来判断


// 对象里面只有成员变量，派生类父类的部分和父类的部分没差别
// 如何做到？不同类型调用不同虚函数的？
//class Person {
//public:
//	virtual void BuyTicket() const { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() const { cout << "买票-半价" << endl; } 
//};
//
//// 多态条件
//// 1. 调用函数是重写的虚函数 -- 两个都必须重写
//// 2. **基类**指针或者引用
//
//// 多态，不同对象传递过去，调用不同函数
//// 多态调用看的是指向的对象
//// 普通调用，看当前调用对象的类型
//// 例如传到这个函数中，只会看参数类型，就是 Person
//// 所以两个全价 void func(const Person p)
//void func(const Person* p)
//{
//	p->BuyTicket();
//}
//
//int main()
//{
//	Person pp;
//	func(&pp);
//
//	Student st;
//	func(&st);
//
//	return 0;
//}

// 虚函数重写的一些细节：
// 重写的条件本来是虚函数 + 三同，但是有一些例外
// 1. 父类必须加 virtual，子类可以不加 virtual 父类不加不是多态
// 子类已经继承了虚函数，重写就可以只重写实现 -- 建议加上
// 2. 协变，返回值可以不同，但是要求返回值必须是父子关系的指针和引用

//class Person {
//public:
//	virtual void BuyTicket() const { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() const { cout << "买票-半价" << endl; }
//};
//
//void func(const Person p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person pp;
//	func(pp);
//
//	Student st;
//	func(st);
//
//	return 0;
//}

//class A
//{};
//
//class B : public A
//{};
//
//class Person {
//public:
//	virtual	A* BuyTicket() const { 
//		cout << "买票-全价" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket() const { 
//		cout << "买票-半价" << endl;
//		return 0;
//	}
//};
//
//int main()
//{
//
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	virtual ~Student() {
//		cout << "~Student()" << endl;
//		delete[] ptr;
//	}
//
//protected:
//	int* ptr = new int[10];
//};
//int main()
//{
//	Person* p = new Person;
//	delete p;
//
//	p = new Student;
//	delete p; 
//
//	return 0;
//}

//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{}

// 设计不想被继承类，如何设计？

 /*设计不想被继承类，如何设计？
 方法1：基类构造函数私有   (C++98) 1/私有在子类不可见，2/派生类构造函数必须调用父类构造函数
 方法2：基类加一个final  （C++11）*/
//class A
//{
//public:
//	// 设置为静态成员函数，否则没有构造函数，无法创建对象，那么也无法间接调用构造函数
//	static A CreateObj()
//	{
//		return A(); // 私有后，A 调用构造函数
//	}
//private:
//	A()
//	{}
//};
//
//class B : public A
//{};
//
//int main()
//{
//	// B bb;
//	A::CreateObj(); // 访问静态成员函数
//
//	return 0;
//}

// 最终类
//class A final
//{
//public:
//private:
//};
//
//class B : public A
//{};
//
//int main()
//{
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Func2()" << endl;
//	}
//
//
//private:
//	char _b = 1;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//
//	Base b1;
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	int _a = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	int _b = 1;
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//
//	Student Johnson;
//	Func(Johnson);
//
//	return 0;
//}

class A 
{ 
public: 
	void test(float a) 
	{ 
		cout << a;
	} 
}; 
class B :public A 
{ 
public: 
	void test(int b) 
	{ cout << b; } 
}; 
void main() 
{ 
	A* a = new A;
	B* b = new B; 
	a = b;
	a->test(1.1); 
}