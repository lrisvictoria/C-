#include <iostream>

using namespace std;

// 对比 C/C++ 定义类别的一切区别和联系

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}



//int main()
//{
//	int* p1 = new int; // 动态申请 int 数组
//	int* p2 = new int[5]; // 申请 5 个 int 数组
//
//	delete p1; // 释放 p1
//	delete[] p2; // 释放 p2
//
//	return 0;
//}

//int main()
//{
//	int* p1 = new int(5);
//	int* p2 = new int[5];
//
//	/*cout << sizeof(p2) << endl;*/
//
//	int* p3 = new int[5] {1, 2};
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}

//int main()
//{
//	// 面向对象的语言，处理错误的方式一般是抛异常，C++中也要求错误抛异常 -- try catch
//	// 面向过程的语言，处理错误的方式是返回错误码 -- perror
//
//	char* p1 = (char*)malloc(1024u*1024u*1024u*2u);
//	if (p1 == nullptr)
//	{
//		printf("%d\n", errno);
//		perror("malloc fail");
//		exit(-1);
//	}
//	else
//	{
//		printf("%p\n", p1);
//	}
//}

//void GetMemory()
//{
//	char* p1 = new char[1024u * 1024u * 1024u * 2u - 1];
//}
//
//int main()
//{
//	try
//	{
//		GetMemory();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "进行构造" << " 我的 this 是：" << this << endl;
//	}
//	~A()
//	{
//		cout << "进行析构" << " 我的 this 是：" << this << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* a1 = new A[5];
//	delete a1;
//
//	return 0;
//}

//int main()
//{
//	char* p1 = (char*)malloc(1024u * 1024u * 1024u * 2u); // u 表示为无符号正数
//	if (p1 == nullptr)
//	{
//		printf("%d\n", errno); // 错误码
//		perror("malloc fail"); // perror 报错
//		exit(-1);
//	}
//	else
//	{
//		printf("%p\n", p1);
//	}
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//		:_top(0)
//		, _capacity(capacity)
//	{
//		_a = new int[capacity];
//	}
//
//	~Stack()
//	{
//		delete[] _a;
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//int main()
//{
//	// Stack* pst1 = new Stack;
//	Stack* pst1 = (Stack*)operator new(sizeof(Stack));
//}

//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0) // 申请不成功
//		if (_callnewh(size) == 0) // 下面在抛异常
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}

///*
//operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//free的实现
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)

//int main()
//{
//	Stack* p1 = new Stack[10]; // 
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = (A*)malloc(sizeof(A));
//	new(p)A; // 
//	new(p)A(1); // 带参初始化
//
//	A* p2 = new A(2); // operator new + 构造函数
//	// 等价于 
//	A* p3 = (A*)operator new(sizeof(A)); // operator new
//	new(p3)A(2); // 调用构造函数
//
//	p3->~A(); // 调用析构函数
//	operator delete(p3); // 释放内存
//
//	return 0;
//}

//int main()
//{
//	char* p = new char[1024u * 1024u * 1024u];
//
//	// cout << p << endl; // cout 识别 p 为字符串，一直向后打印，因为编码问题打印出来屯
//	printf("%p\n", p);
//
//	return 0;
//}

//void MemoryLeaks()
//{
//	// 1.内存申请了忘记释放
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	// 2.异常安全问题
//	int* p3 = new int[10];
//	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
//	delete[] p3;
//}

//int main()
//{
//	void* p = new char[0x7fffffff];
//	cout << "new: " << p << endl;
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = (A*)malloc(sizeof(A));
	new(p)A; 
	new(p)A(1); // 带参初始化

	return 0;
}