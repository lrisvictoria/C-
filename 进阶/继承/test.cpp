#include <iostream>

using namespace std;


// 面向对象三大特性之一

// 本质是复用
// 派生类(子类)根据继承方式，继承基类(父类)的信息

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	//protected:
private:
	string _name = "peter"; // 姓名
	int _age = 18;  // 年龄
};

class Student : public Person
{
public:
	void func()
	{
		// 父类私有成员，子类用不了(无论什么方式继承)
		//cout << "name:" << _name << endl;
		//cout << "age:" << _age << endl;
	}
protected:
	int _stuid; // 学号
};

class Teacher : public Person
{
protected:
	int _jobid; // 工号
};


// 保护和私有作为访问限定符我们认为他一样

// 父类的成员在子类中的访问方式是什么样的

// 不可见，语法上限制访问，跟 private 也不一样，类里面和类外面都不能用

// class 默认是私有继承
// struct 默认是公有继承

// 私有继承和保护继承的最大区别就是当两个类被继承时，派生类无法访问私有继承过的类的成员

// 总结：
// 1. 基类 private 成员继承不可见
// 2. 访问限定符和继承方式取小
// 3. 实际上一般都是 public 继承：公有保护成员 public 继承


int main()
{
	Student s; // 继承了父类的名字和年龄，print函数
	Teacher t;
	s.Print();
	t.Print();

	return 0;
}