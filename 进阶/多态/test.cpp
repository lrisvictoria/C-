#include <iostream>

using namespace std;


// �麯��
// ��Ȼ���� virtual �����麯������̳�û���κι�ϵ
// ��Ա�������ܱ���麯��
// �麯������д
// ��ͬ����ȥ���ú������в�ͬ����̬ 

// ֮ǰ���ò�ͬ�ĺ�����Ҫָ��
// ���ڵ��ò�ͬ�ĺ���ֻҪ���ݵ��õĶ������ж�


// ��������ֻ�г�Ա�����������ุ��Ĳ��ֺ͸���Ĳ���û���
// �����������ͬ���͵��ò�ͬ�麯���ģ�
//class Person {
//public:
//	virtual void BuyTicket() const { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() const { cout << "��Ʊ-���" << endl; } 
//};
//
//// ��̬����
//// 1. ���ú�������д���麯�� -- ������������д
//// 2. **����**ָ���������
//
//// ��̬����ͬ���󴫵ݹ�ȥ�����ò�ͬ����
//// ��̬���ÿ�����ָ��Ķ���
//// ��ͨ���ã�����ǰ���ö��������
//// ���紫����������У�ֻ�ῴ�������ͣ����� Person
//// ��������ȫ�� void func(const Person p)
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

// �麯����д��һЩϸ�ڣ�
// ��д�������������麯�� + ��ͬ��������һЩ����
// 1. �������� virtual��������Բ��� virtual ���಻�Ӳ��Ƕ�̬
// �����Ѿ��̳����麯������д�Ϳ���ֻ��дʵ�� -- �������
// 2. Э�䣬����ֵ���Բ�ͬ������Ҫ�󷵻�ֵ�����Ǹ��ӹ�ϵ��ָ�������

//class Person {
//public:
//	virtual void BuyTicket() const { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() const { cout << "��Ʊ-���" << endl; }
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
//		cout << "��Ʊ-ȫ��" << endl;
//		return 0;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* BuyTicket() const { 
//		cout << "��Ʊ-���" << endl;
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

//class Car {
//public:
//	virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};
//
//int main()
//{}

// ��Ʋ��뱻�̳��࣬�����ƣ�

 /*��Ʋ��뱻�̳��࣬�����ƣ�
 ����1�����๹�캯��˽��   (C++98) 1/˽�������಻�ɼ���2/�����๹�캯��������ø��๹�캯��
 ����2�������һ��final  ��C++11��*/
//class A
//{
//public:
//	// ����Ϊ��̬��Ա����������û�й��캯�����޷�����������ôҲ�޷���ӵ��ù��캯��
//	static A CreateObj()
//	{
//		return A(); // ˽�к�A ���ù��캯��
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
//	A::CreateObj(); // ���ʾ�̬��Ա����
//
//	return 0;
//}

// ������
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//
//	int _a = 1;
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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