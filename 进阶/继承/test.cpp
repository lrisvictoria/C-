#include <iostream>

using namespace std;


// 面向对象三大特性之一

// 本质是复用
// 派生类(子类)根据继承方式，继承基类(父类)的信息

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
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
//class Student : public Person
//{
//public:
//	void func()
//	{
//		// 父类私有成员，子类用不了(无论什么方式继承)
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//int main()
//{
//	Student s; // 继承了父类的print函数
//	Teacher t;
//
//	cout << s._name << endl;;
//	s.Print();
//	t.Print();
//
//	return 0;
//}

// 保护和私有作为访问限定符我们认为他一样

// 父类的成员在子类中的访问方式是什么样的

// 不可见，语法上限制访问，跟 private 也不一样，类里面和类外面都不能用

// class 默认是私有继承
// struct 默认是公有继承

// 私有继承和保护继承的最大区别就是当两个类被继承时，派生类无法访问私有继承过的类的成员

// 总结：
// 1. 基类 private 成员继承不可见
// 2. 访问限定符和继承方式取小
// 3. 实际上一般都是 public 继承：公有、保护成员 public 继承



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
//	// 没有转换，赋值兼容转换  (切割，切片)
//	// 不会产生临时变量
//	p = s;
//	// 认为子类是特殊的父类对象
//	// 会把子类中属于父类的成员切割，将成员拷贝给父类
//
//
//	s = p; // error 父不能给子，子有的成员变量父没有，但是是语法限制，底层可以特殊方式给过
//	s = (Student)p; // 无法强转，强转只有几个类型可以强转
//	// 子给父是向上转换，可以
//}

//int main()
//{
//	int i = 0;
//	const double& d = i;
//
//	Person p1;
//	Student s;
//
//	Person& p2 = s; // 没报错，说明没有产生临时变量
//	// 临时变量具有常性，无法引用，但是这里可以引用
//
//	// p2 为子类切片出来部分的别名
//
//	Person* ptr = &s;
//	ptr->_name = "张三";
//}

// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//
//// 隐藏/重定义：当子类和父类有同名成员的时候，子类的成员隐藏了父类的成员，需要用类作用限定符才能访问到父类
//// 尽量不要定义同名成员
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl; // 域作用限定符，访问父类的  _num
//		cout << " 学号:" << _num << endl; // 就近原则，先局部域，先访问子类的，再找父类的，再找全局的
//	}
//protected:
//	int _num = 999; // 学号
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
//	s.Print(); // 父类和子类可以定义同名成员
//}

// 域的本质是在编译的时候指导编译器去查找的规则
// 这里的是编译时查找，编译时要检查语法,找不到这个函数要语法报错

// 重载：同一个作用域
//
// 两个fun构成什么关系？
// a、隐藏/重定义   b、重载   c、重写/覆盖  d、编译报错
// 答案：a  (父子类域中，成员函数名相同就构成隐藏)
//class Person
//{
//public:
//	void fun()
//	{
//		cout << "Person::func()" << endl;
//	}
//
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 	   // 身份证号
//};
//
//// 隐藏/重定义：子类和父类有同名成员，子类的成员隐藏了父类的成员
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
//		cout << " 姓名:" << _name << endl;
//		cout << _num << endl;
//		cout << Person::_num << endl;
//	}
//protected:
//	int _num = 999; // 学号
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
//	string _name; // 姓名
//
//	string* _pstr = new string("111111111");
//};
//
//class Student : public Person
//{
//public:
//	//Student(const char* name = "张三", int id = 0)
//	//	:_id(0)
//	//	,_name(name)// 初始化列表不能初始化父类成员，需要调用父类构造函数初始化
//	//{}
//	
//	// 先父后子
//	// 派生类会自动调用派生类的默认构造函数，初始化父类的成员
//	// 不写默认构造会报错，把父类成员当做对象成员初始化
//	// 初始化列表会先走父类的构造函数
//	// 初始化列表是按成员声明的顺序走的，继承的成员在子类的成员前面
//	// 建议把构造写在前面，与定义顺序一致
//
//	// 把父类看成了一个整体，只能整体调用构造函数初始化
//	Student(const char* name = "张三", int id = 0)
//		:Person(name) // 若没有默认构造函数，则要传参
//		,_id(0)
//	{}
//
//
//	// 默认调用父类的拷贝构造，会自动调用默认构造（拷贝构造也是构造），所以拷贝构造要自己调用
//	// 不能自己对父类的成员初始化，都交给父类自己做
//	// 父类的拷贝构造要父类对象，但是可以直接传子类，因为子类的对象可以传给父类的指针和引用（切片）
//	// 引用s也是子类对象的别名，在拷贝构造引用还是子类对象的别名，这里会自动切片，把子类引用的父类成员切割出来
//	Student(const Student& s)
//		:Person(s)
//		,_id(s._id)
//	{}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			// operator=(s); // 栈溢出，默认调用子类的赋值（隐藏）
//			Person::operator=(s); // 
//			_id = s._id;
//		}
//
//		return *this;
//	}
//
//	~Student()
//	{
//		// 由于后面多态的原因，析构函数的函数名被
//		// 特殊处理了，统一处理成destructor，基类和派生类的析构构成隐藏
//		// 所以要指定
//
//		// 但是显示调用父类析构，无法保证先子后父
//		// 要保证析构顺序，子类的父类部分先被构造，所以父类要后被析构，要先析构子类成员
//		// 所以子类析构函数完成就自动调用父类析构，这样就保证了先子后父
//		//Person::~Person();
//
//		// 父类不可能访问子类的成员，但是子类可能访问父类的成员
//		// 为防止父类析构后，子类访问错误
//		// 所以要先子后父
//
//		// 虽然可以把父类析构显示写在子类析构的最后一句，保证子类走完再析构
//		// 但是反正析构顺序确定，就没必要显示调用了，编译器直接处理好
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
//	Student s3("李四", 1);
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
//	cout << sizeof(b) << endl; // 基类大小 = 父类成员 + 基类成员
//}

//class Student; // person 类中访问子类，子类要提前声明
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//	friend void Display(const Person& p, const Student& s);
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl; 
//	cout << s._stuNum << endl; // 函数也为子类的友元，那么也能访问子类的私有保护成员
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

// 静态成员属于父类和派生类
// 在派生类中不会单独拷贝一份，继承的使用权
//class Person
//{
//public:
//	Person() { ++_count; }
////protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
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
//	string _name; // 姓名
//	int _age;
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	Assistant as;
//	// 访问的都是同一份 _age
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
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};

//class Student : public Person
//{
//public:
//	void func()
//	{
//		// 父类私有成员，子类用不了(无论什么方式继承)
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
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
//	ptr->_name = "李四";
//
//	ptr = &s;
//	ptr->_name = "张三";
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