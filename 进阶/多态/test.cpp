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

//class A 
//{ 
//public: 
//	void test(float a) 
//	{ 
//		cout << a;
//	} 
//}; 
//class B :public A 
//{ 
//public: 
//	void test(int b) 
//	{ cout << b; } 
//}; 
//void main() 
//{ 
//	A* a = new A;
//	B* b = new B; 
//	a = b;
//	a->test(1.1); 
//}

//class A
//{
//public:
//	virtual void func(int val = 3) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int bbb = 0) { std::cout << "B->" << bbb << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	virtual void Func1() 
//	{
//		cout << "Person::Func1()" << endl;
//	}
//
//	virtual void Func2() 
//	{
//		cout << "Person::Func2()" << endl;
//	}
//
//public:
//	int _a = 0;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	virtual void func3() {}
//protected:
//	int _b = 1;
//};

//void func(Person& p)
//{
//	p.BuyTicket();
//}
//
// 
// 
//int main()
//{
//	Person ps;
//	Student st;
//	st._a = 10;
//
//	ps = st;
//	Person* ptr = &st;
//	Person& ref = st;
//
//	return 0;
//}

//int main()
//{
//	Person ps;
//	Student st;
//
//	int a = 0;
//	printf("栈：%p\n", &a);
//
//	static int b = 0;
//	printf("静态区：%p\n", &b);
//
//	int* p = new int;
//	printf("堆：%p\n", p);
//
//	const char* str = "hello world";
//	printf("常量区：%p\n", str);
//
//	printf("虚表1：%p\n", (int*)*((int*)&ps));
//	printf("虚表2：%p\n", (int*)*((int*)&st));
//
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	virtual void Func1() 
//	{
//		cout << "Person::Func1()" << endl;
//	}
//
//	virtual void Func2() 
//	{
//		cout << "Person::Func2()" << endl;
//	}
//
//protected:
//	int _a = 0;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//private:
//	virtual void Func3()
//	{
//		// _b++;
//		cout << "Student::Func3()" << endl; // 调用时打印，看地址是否和内存中一样
//	}
//protected:
//	int _b = 1;
//};
//
//typedef void(*FUNC_PTR) ();
//
//// 打印函数指针数组
//void PrintVFT(FUNC_PTR* table)
//{
//	// 结尾时 \0
//	for (size_t i = 0; table[i] != nullptr; i++)
//	{
//		printf("[%d]:%p->", i, table[i]);
//		FUNC_PTR f = table[i];
//
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	// 取前四个字节
//	int vft1 = *(int*)&ps;
//	PrintVFT((FUNC_PTR*)vft1);
//
//	int vft2 = *(int*)&st;
//	PrintVFT((FUNC_PTR*)vft2);
//
//	return 0;
//}

typedef void(*FUNC_PTR) ();

// 打印函数指针数组
void PrintVFT(FUNC_PTR* table)
{
	// 结尾时 \0
	for (size_t i = 0; table[i] != nullptr; i++)
	{
		printf("[%d]:%p->", i, table[i]);
		FUNC_PTR f = table[i];

		f();
	}
	cout << endl;
}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

//int main()
//{
//	Derive d;
//	cout << sizeof(d) << endl;
//
//	int vft1 = *((int*)&d);
//	//int vft2 = *((int*)((char*)&d+sizeof(Base1)));
//	Base2* ptr = &d; // 切片
//	int vft2 = *((int*)ptr);
//
//	PrintVFT((FUNC_PTR*)vft1);
//	PrintVFT((FUNC_PTR*)vft2);
//
//	return 0;
//}

int main()
{
	Derive d;
	Base1* ptr1 = &d;
	ptr1->func1();

	Base2* ptr2 = &d;
	ptr2->func1();

	return 0;
}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//
//	virtual void Func1() 
//	{
//		cout << "Person::Func1()" << endl;
//	}
//
//	virtual void Func2() 
//	{
//		cout << "Person::Func2()" << endl;
//	}
//
//protected:
//	int _a = 0;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//
//	virtual void Func3()
//	{
//		// _b++;
//		cout << "Student::Func3()" << endl; // 调用时打印，看地址是否和内存中一样
//	}
//protected:
//	int _b = 1;
//};
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Person* ptr = &ps;
//	ptr->BuyTicket();
//
//	ptr = &st;
//	ptr->BuyTicket();
//}

//class A
//{
//public:
//  A() :m_iVal(0) { test(); }
//  virtual void func() { std::cout << m_iVal << ' '; }
//  void test() { func(); }
//public:
//  int m_iVal;
//};
//
//class B : public A
//{
//public:
//    B() { test(); }
//    virtual void func()
//    {
//        ++m_iVal;
//        std::cout << m_iVal << ' ';
//    }
//
//};
//
//int main(int argc, char* argv[])
//{
//    A* p = new B;
//    p->test();
//    return 0;
//}