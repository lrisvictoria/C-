#include <iostream>

using namespace std;


// ���������������֮һ

// �����Ǹ���
// ������(����)���ݼ̳з�ʽ���̳л���(����)����Ϣ

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	//protected:
//public:
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// ����˽�г�Ա�������ò���(����ʲô��ʽ�̳�)
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//int main()
//{
//	Student s; // �̳��˸����print����
//	Teacher t;
//
//	cout << s._name << endl;;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

// ������˽����Ϊ�����޶���������Ϊ��һ��

// ����ĳ�Ա�������еķ��ʷ�ʽ��ʲô����

// ���ɼ����﷨�����Ʒ��ʣ��� private Ҳ��һ����������������涼������

// class Ĭ����˽�м̳�
// struct Ĭ���ǹ��м̳�

// ˽�м̳кͱ����̳е����������ǵ������౻�̳�ʱ���������޷�����˽�м̳й�����ĳ�Ա

// �ܽ᣺
// 1. ���� private ��Ա�̳в��ɼ�
// 2. �����޶����ͼ̳з�ʽȡС
// 3. ʵ����һ�㶼�� public �̳У����С�������Ա public �̳�



//int main()
//{
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	double d = i;
//
//	Person p;
//	Student s;
//
//	// û��ת������ֵ����ת��  (�и��Ƭ)
//	// ���������ʱ����
//	p = s;
//	// ��Ϊ����������ĸ������
//	// ������������ڸ���ĳ�Ա�и����Ա����������
//
//
//	s = p; // error �����ܸ��ӣ����еĳ�Ա������û�У��������﷨���ƣ��ײ�������ⷽʽ����
//	s = (Student)p; // �޷�ǿת��ǿתֻ�м������Ϳ���ǿת
//	// �Ӹ���������ת��������
//}

//int main()
//{
//	int i = 0;
//	const double& d = i;
//
//	Person p1;
//	Student s;
//
//	Person& p2 = s; // û����˵��û�в�����ʱ����
//	// ��ʱ�������г��ԣ��޷����ã����������������
//
//	// p2 Ϊ������Ƭ�������ֵı���
//
//	Person* ptr = &s;
//	ptr->_name = "����";
//}

// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//
//// ����/�ض��壺������͸�����ͬ����Ա��ʱ������ĳ�Ա�����˸���ĳ�Ա����Ҫ���������޶������ܷ��ʵ�����
//// ������Ҫ����ͬ����Ա
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl; // �������޶��������ʸ����  _num
//		cout << " ѧ��:" << _num << endl; // �ͽ�ԭ���Ⱦֲ����ȷ�������ģ����Ҹ���ģ�����ȫ�ֵ�
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//
//int main()
//{
//	Student s;
//	s.Print(); // �����������Զ���ͬ����Ա
//}

// ��ı������ڱ����ʱ��ָ��������ȥ���ҵĹ���
// ������Ǳ���ʱ���ң�����ʱҪ����﷨,�Ҳ����������Ҫ�﷨����

// ���أ�ͬһ��������
//
// ����fun����ʲô��ϵ��
// a������/�ض���   b������   c����д/����  d�����뱨��
// �𰸣�a  (���������У���Ա��������ͬ�͹�������)
//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 	   // ���֤��
//};
//
//// ����/�ض��壺����͸�����ͬ����Ա������ĳ�Ա�����˸���ĳ�Ա
//class Student : public Person
//{
//public:
//	void fun(int i)
//	{
//		cout << "Student::func()" << endl;
//	}
//
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//
//int main()
//{
//	Student s;
//	s.Person::fun();
//	s.fun(1);
//
//	return 0;
//}
//#include <string>
//
//class Person
//{
//public:
//	Person(const char* name = "peter")
//	// Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//		delete _pstr;
//	}
//protected:
//	string _name; // ����
//
//	string* _pstr = new string("111111111");
//};
//
//class Student : public Person
//{
//public:
//	//Student(const char* name = "����", int id = 0)
//	//	:_id(0)
//	//	,_name(name)// ��ʼ���б��ܳ�ʼ�������Ա����Ҫ���ø��๹�캯����ʼ��
//	//{}
//	
//	// �ȸ�����
//	// ��������Զ������������Ĭ�Ϲ��캯������ʼ������ĳ�Ա
//	// ��дĬ�Ϲ���ᱨ���Ѹ����Ա���������Ա��ʼ��
//	// ��ʼ���б�����߸���Ĺ��캯��
//	// ��ʼ���б��ǰ���Ա������˳���ߵģ��̳еĳ�Ա������ĳ�Աǰ��
//	// ����ѹ���д��ǰ�棬�붨��˳��һ��
//
//	// �Ѹ��࿴����һ�����壬ֻ��������ù��캯����ʼ��
//	Student(const char* name = "����", int id = 0)
//		:Person(name) // ��û��Ĭ�Ϲ��캯������Ҫ����
//		,_id(0)
//	{}
//
//
//	// Ĭ�ϵ��ø���Ŀ������죬���Զ�����Ĭ�Ϲ��죨��������Ҳ�ǹ��죩�����Կ�������Ҫ�Լ�����
//	// �����Լ��Ը���ĳ�Ա��ʼ���������������Լ���
//	// ����Ŀ�������Ҫ������󣬵��ǿ���ֱ�Ӵ����࣬��Ϊ����Ķ�����Դ��������ָ������ã���Ƭ��
//	// ����sҲ���������ı������ڿ����������û����������ı�����������Զ���Ƭ�����������õĸ����Ա�и����
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			// operator=(s); // ջ�����Ĭ�ϵ�������ĸ�ֵ�����أ�
//			Person::operator=(s); // 
//			_id = s._id;
//		}
//
//		return *this;
//	}
//
//	~Student()
//	{
//		// ���ں����̬��ԭ�����������ĺ�������
//		// ���⴦���ˣ�ͳһ�����destructor��������������������������
//		// ����Ҫָ��
//
//		// ������ʾ���ø����������޷���֤���Ӻ�
//		// Ҫ��֤����˳������ĸ��ಿ���ȱ����죬���Ը���Ҫ��������Ҫ�����������Ա
//		// ������������������ɾ��Զ����ø��������������ͱ�֤�����Ӻ�
//		//Person::~Person();
//
//		// ���಻���ܷ�������ĳ�Ա������������ܷ��ʸ���ĳ�Ա
//		// Ϊ��ֹ����������������ʴ���
//		// ����Ҫ���Ӻ�
//
//		// ��Ȼ���԰Ѹ���������ʾд���������������һ�䣬��֤��������������
//		// ���Ƿ�������˳��ȷ������û��Ҫ��ʾ�����ˣ�������ֱ�Ӵ����
//		cout << *_pstr << endl;
//		cout << "~Student()" << endl;
//		delete _ptr;
//	}
//protected:
//	int _id;
//
//	int* _ptr = new int;
//};
//
//int main()
//{
//	Person p;
//	Student s1;
//	Student s2(s1);
//
//	Student s3("����", 1);
//	s1 = s3;
//
//	//Person p = s1;
//
//	return 0;
//}


//class A
//{
//public:
//	A()
//	{}
//private:
//	int _a;
//	int _b;
//};
//
//class B : private A
//{
//public:
//	int _c;
//	int _d;
//};
//
//int main()
//{
//	A a;
//
//	cout << sizeof(a) << endl;
//
//	B b;
//	cout << sizeof(b) << endl; // �����С = �����Ա + �����Ա
//}

//class Student; // person ���з������࣬����Ҫ��ǰ����
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl; 
//	cout << s._stuNum << endl; // ����ҲΪ�������Ԫ����ôҲ�ܷ��������˽�б�����Ա
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

// ��̬��Ա���ڸ����������
// ���������в��ᵥ������һ�ݣ��̳е�ʹ��Ȩ
//class Person
//{
//public:
//	Person() { ++_count; }
////protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
//
//int main()
//{
//	Person p;
//	Student s;
//	Student s2;
//
//	// cout << Person::_count << endl;
//
//	cout << &p._name << endl;
//	cout << &s._name << endl;
//
//	cout << &p._count<< endl;
//	cout << &s._count << endl;
//
//	cout << &Person::_count << endl;
//	cout << &Student::_count << endl;
//
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//	int _age;
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	Assistant as;
//	// ���ʵĶ���ͬһ�� _age
//	as._age = 19;
//	as.Student::_age = 18;
//	as.Teacher::_age = 30;
//	
//
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};

//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//	d._a = 1;
//	
//
//	D d2;
//
//	return 0;
//}
//
//int main()
//{
//	D d;
//	d._a = 1;
//
//	B b;
//	b._a = 2;
//	b._b = 3;
//
//	B* ptr = &b;
//	ptr->_a++;
//
//	ptr = &d;
//	ptr->_a++;
//
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	//protected:
//public:
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};

//class Student : public Person
//{
//public:
//	void func()
//	{
//		// ����˽�г�Ա�������ò���(����ʲô��ʽ�̳�)
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//int main()
//{
//	int i = 0;
//	const double& d = i;
//
//	Person p1;
//	Student s;
//
//	Person* ptr = &p1;
//	ptr->_name = "����";
//
//	ptr = &s;
//	ptr->_name = "����";
//}


#include<iostream>
using namespace std;
class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};

class B :virtual public A
{
public:
	B(const char* sa, const char* sb) :A(sa) { cout << sb << endl; }
};

class C :virtual public A
{
public:
	C(const char* sa, const char* sb) :A(sa) { cout << sb << endl; }
};

class D :public B, public C
{
public:
	D(const char* sa, const char* sb, const char* sc, const char* sd) 
		:B(sa, sb), C(sa, sc), A(sa)
	{
		cout << sd << endl;
	}
};

int main() {
	D* p = new D("class A", "class B", "class C", "class D");
	delete p;

	B b("class A", "class B");

	return 0;
}