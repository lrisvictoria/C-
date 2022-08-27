#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//namespace 定义的是一个域

//解决c语言的命名冲突问题
//例如

//定义在局部
//#include<stdio.h>
//int main()
//{	
//	//c语言定义变量的时候不能是关键字
//	//int long = 10;//错误
//	
//	int scanf = 10;
//	int strlen = 10;//都能编译过
//
//	//命名冲突
//	//C语言库里面有两个函数用scanf和strlen名称
//	//假设我的代码里面想用这两个名称命名变量
//	//在语法角度，这个做法并不违法
//	
//	//编译器冲突了，我是想用scanf库函数给scanf变量赋值
//
//	//报错信息：项不会计算为接收两个参数的函数
//
//	//程序运行符合就近原则，用scanf不会到全局去找，而会找近的
//	//于是就会调用scanf变量
//	
//	//C语言解决不了冲突的问题
//	scanf("%d", &scanf);//err
//	printf("%d\n", scanf);
//	
//
//	return 0;
//}

//定义在全局，甚至无法编译过
//#include<stdio.h>
//int scanf = 10;
//int strlen = 20;
//
//int main()
//{
//	return 0;
//}

//并且在合作市也会有很多问题
//c++，为了解决这个问题，提出了命名空间，名字隔离

//把这两个变量隔离

//命名空间定义的是域，命名空间域
//#include "List.h"
//namespace anduin
//{
//	int scanf = 10;
//	int strlen = 20;
//
//	//还可以定义函数，无法直接调用，需要指定
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//	//命名空间嵌套命名空间
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//int main()
//{
//	//默认访问的是局部或者全局的
//	//printf("%d", scanf);//打印的是地址
//	//就近原则，现在局部域，再全局域
//	//打印的是函数的地址
//
//	//指定访问命名空间anduin中的
//	printf("%x\n", anduin::scanf);//::域作用限定符：指定访问域的
//	
//	//Add(3, 4);//错误，没有指定域
//	printf("%d\n", anduin::Add(3, 4));
//
//	//如何调用N3中的Sub函数
//	printf("%d\n", anduin::N3::Sub(3,4));
//	
//	//并且在不同文件里定义相同名字的命名空间,在包含对应的头文件后，
//	//编译器会把他们合并在一个命名空间中
//	anduin::ListNode* phead = NULL;
//	return 0;
//}

//嵌套定义在实际业务中有着很大的作用
//可以让让不同业务中的相同名字有效隔离

#include <iostream>
//c++库为了防止命名冲突，
//把标准库自己库里面的东西都定义在一个std的命名空间中

//所以要使用标准库中的东西，有三种方式
//1.指定命名空间 -> 麻烦，每个地方都要指定，但是它是最规范的

//2.把std整个展开(不要脸)，库里面的东西全整合到全局域 -> 
//看起来方便了，如果我们自己定义的东西和库冲突了，就没办法解决了
//所以规范的工程项目中是不推荐这种方式的，日常练习无所谓

//3.对部分常用的库里面的东西展开 -> 针对1和2折中的方案
//项目中也会经常用

//using namespace std;//2

//using std::cout;//3，部分展开
//using std::endl;//3
//
//int main()
//{
//	std::cout << "hello world" << std::endl;//1
//	
//	cout << "hello world" << endl;//2
//	return 0;
//}

//c++的库是不带.h的
//#include <iostream.h>//老一点的标准用这个，新的编译器用不了，vc6.6可以
//带.h的是没有std命名空间的，为了让新和老的区分，就去掉了，也区别了c

//域作用限定符::也可以再c语言中使用
//int a = 10;
//int main()
//{
//	int a = 1;
//	printf("%d\n", a);//1
//	//访问全局的
//	printf("%d\n", ::a);//10
//	//指定去访问左边的域，空白表示全局域，访问全局
//}


//c++的输入和输出
//c语言在<stdio.h>中
//c++在<iostream>中，io输出流

#include <iostream>

//cout现在其实讲不清楚，先了解一下，记住它的使用
//ostream 类型全局对象 cout
//istream 类型全局对象 cin
//endl 全局的换行符号
//int main()
//{
//	std::cout << "hello world" << std::endl;//字符串通过<<流向对象
//
//	//对于c语言printf和scanf的区别是什么？-> 自动识别类型，原理：函数重载 + 运算符重载，以后再介绍
//	int a = 10;
//	int* p = &a;
//	printf("%d %p\n", a, p);
//
//	//c++就是可以自动识别类型
//	std::cout << a << "," << p << std::endl;//","为增加的逗号
//
//	char str[10];
//	std::cin >> a;//从控制台输入流向对象中
//	std::cin >> str;
//
//	std::cout << a << "," << str << std::endl;
//}

//using namespace std;
//struct Person
//{
//	char name[10];
//	int age;
//};
//int main()
//{
//	int a = 0;
//	cin >> a;//对比scanf("%d", & a);
//	cout << a << endl;
//
//	struct Person p = { "小李",10 };
//	//c语言输出更加舒服
//	printf("name:%s\n age:%d\n", p.name, p.age);//格式化输出
//	//c++输出就很痛苦
//	cout << "name:" << p.age << "\n" << "age:" << p.age << endl;
//	//一个cout只能输出一个，
//	//综合可以混着用，哪个好用就用哪个
//
//	return 0;
//}

//缺省参数
//void test(int a = 0)
//{
//	std::cout << a << std::endl;
//}
//int main()
//{
//	test(10);//传参使用指定的实参
//
//	test();//不传参使用参数的默认值
//	return 0;
//}

//缺省参数分类
//全缺省参数 - 全部参数给缺省值
//半缺省参数 - 部分参数给缺省值
//必须是从右往左缺省，并且是连续的
//实际上很容易想明白，参数是传给对应的位置的，如果缺少的参数是右边的值
//那么传参时，指向传给缺的参数时，会导致错误发生，传参达不到想要的效果
//只有从右往左缺省才能把对应的值传到对应的位置
using namespace std;
//全缺省参数
//void TestFunc(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
////半缺省参数
////void TestFunc(int a, int b = 20, int c = 30)//void TestFunc(int a = 10, int b, int c = 30)//err
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////}
//
//int main()
//{
//	TestFunc(1, 2, 3);
//	TestFunc();
//	TestFunc(1);
//	TestFunc(1, 2);
//}

//void TestFunc(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	//至少传参一个
//	TestFunc(1, 2, 3);
//	TestFunc(1);
//	TestFunc(1, 2);
//}

//缺省参数的作用是什么？调用更灵活

//函数重载
//c语言不允许定义同名函数
//c++可以 -> 函数重载 -> 参数不同 (参数类型不同，或者个数不同)
//缺省函数不是重载(参数类型相同，返回类型相同)
//int Add(int left = 10, int right = 20)
//{
//	return left + right;
//}
//char Add(char left, char right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
////坑
//void f(int a, int b, int c = 1)//1
//{
//
//}
//void f(int a, int b)//2
//{
//
//}
////1,2构成函数重载，参数不同
////但是这样调用不明确，无法识别
//int main()
//{
//	cout << Add() << endl;
//	cout << Add(1, 2) << endl;//字面量 给的整形默认算常量
//	cout << Add('1', '2') << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	f(1, 2, 3);
//	//f(1, 2);//err
//	return 0;
//}

//函数重载解决了C语言中很多问题

//注意这里用void*并不理想
//void*虽然可以兼容所有指针，但是交换时由于类型不统一
//需要一个字节一个字节交换，并且需要知道参数大小，还要多一个参数
//void swap(int* a, int* b)
//{
//
//}
//void swap(double* a, double* b)
//{
//
//}
//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//	double m = 1.1, n = 2.2;
//	swap(&m, &n);
//	return 0;
//}

//学习这些细碎的语法
//1.这些语法在一定程度是c语言一些不好用的做补充
//2.学习这些，也在为我们学习c++类和对象做铺垫

//引用
//int main()
//{
//	int a = 10;
//	//b是a的引用(别名)
//	int& b = a;
//
//	b = 20;
//	
//	int& c = b;
//	c = 30;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	//a,b,c共用一块空间
//	//a,b,c地址相同
//	return 0;
//}
void swap(int* p1, int* p2)//c语言写法
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void swap(int& r1, int& r2)//引用，这里的int&类型为int
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}
int main()
{
	int a = 1, b = 2;
	swap(&a, &b);
	swap(a, b);
	return 0;
}