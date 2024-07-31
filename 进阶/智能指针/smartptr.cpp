#include <iostream>
#include <memory>
#include "smartptr.h"

//using namespace lx;
using namespace std;



//int main()
//{
//	//lx::auto_ptr<A> ap1(new A(1));
//	//lx::auto_ptr<A> ap2(new A(2));
//
//	//lx::auto_ptr<A> ap3(ap1); // 拷贝问题
//
//	// 崩溃
//	//ap1->_a++;
//
//	// ap3->_a++;
//	// cout << ap3->_a << endl;
//
//
//	/*lx::unique_ptr<A> up1(new A(1));
//	lx::unique_ptr<A> up2(new A(2));
//
//	lx::unique_ptr<A> up3(up1);*/
//
//	shared_ptr<A> sp1(new A(1));
//	shared_ptr<A> sp2(new A(2));
//
//	shared_ptr<A> sp3(sp1);//采取引用计数sp3与sp1共享资源，析构采取引用计数。
//	sp1->_a++;
//	sp3->_a++;
//	
//	cout << sp1->_a << endl;
//	cout << sp3->_a << endl;
//
//	return 0;
//}


struct Node
{
public:
	~Node()
	{
		cout << "~Node()" << endl;
	}
	/*shared_ptr<Node> _prev;
	shared_ptr<Node> _next;*/

	weak_ptr<Node> _next;
	weak_ptr<Node> _prev;

};

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a = 0)" << endl;
	}

	~A()
	{
		cout << this << endl;
		cout << "~A()" << endl;
	}
	// private:
	int _a;
};

template<class T>
struct DeleteArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

int main()
{
	//循环引用——关键与难点
	//画图分析
	/*lx::shared_ptr<A> sp1(new A[5], DeleteArray<A>());
	lx::shared_ptr<A> sp2((A*)malloc(sizeof(A)), [](A* ptr) {free(ptr); });*/
	lx::shared_ptr<A> sp3(new A);
	
	return 0;
}