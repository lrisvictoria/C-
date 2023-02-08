#include <iostream>

using namespace std;

// �Ա� C/C++ ��������һ���������ϵ

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
//	int* p1 = new int; // ��̬���� int ����
//	int* p2 = new int[5]; // ���� 5 �� int ����
//
//	delete p1; // �ͷ� p1
//	delete[] p2; // �ͷ� p2
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
//	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	// ���������Ǽ�����һ����
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
//	// �����������ԣ��������ķ�ʽһ�������쳣��C++��ҲҪ��������쳣 -- try catch
//	// ������̵����ԣ��������ķ�ʽ�Ƿ��ش����� -- perror
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
//		cout << "���й���" << " �ҵ� this �ǣ�" << this << endl;
//	}
//	~A()
//	{
//		cout << "��������" << " �ҵ� this �ǣ�" << this << endl;
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
//	char* p1 = (char*)malloc(1024u * 1024u * 1024u * 2u); // u ��ʾΪ�޷�������
//	if (p1 == nullptr)
//	{
//		printf("%d\n", errno); // ������
//		perror("malloc fail"); // perror ����
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
//	while ((p = malloc(size)) == 0) // ���벻�ɹ�
//		if (_callnewh(size) == 0) // ���������쳣
//		{
//			// report no memory
//			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}

///*
//operator delete: �ú���������ͨ��free���ͷſռ��
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
//free��ʵ��
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
//	new(p)A(1); // ���γ�ʼ��
//
//	A* p2 = new A(2); // operator new + ���캯��
//	// �ȼ��� 
//	A* p3 = (A*)operator new(sizeof(A)); // operator new
//	new(p3)A(2); // ���ù��캯��
//
//	p3->~A(); // ������������
//	operator delete(p3); // �ͷ��ڴ�
//
//	return 0;
//}

//int main()
//{
//	char* p = new char[1024u * 1024u * 1024u];
//
//	// cout << p << endl; // cout ʶ�� p Ϊ�ַ�����һֱ����ӡ����Ϊ���������ӡ������
//	printf("%p\n", p);
//
//	return 0;
//}

//void MemoryLeaks()
//{
//	// 1.�ڴ������������ͷ�
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	// 2.�쳣��ȫ����
//	int* p3 = new int[10];
//	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
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
	new(p)A(1); // ���γ�ʼ��

	return 0;
}