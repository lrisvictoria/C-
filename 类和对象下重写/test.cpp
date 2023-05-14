//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	} 
//
//	const A(const A& aa)
//		: _a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A aa1(1); // ���캯��
//	A aa2 = 2; // ��ʽ����ת��������ת�����Զ�������
//	// 2 ���ù��캯��, ���� a ���͵���ʱ����, ��ʱ�����ٿ������� aa2
//	// ���Ż�Ϊ�� 2 ֱ�ӹ���
//	// ��ͬһ�����ʽ�ڵ������Ĺ�����������������Ż�
//
//	int i = 10;
//	double d = i; // i ������ʱ���� double ����
//
//	const A& aa3 = 2; // �������г��ԣ���ʱ�������г���
//
//	return 0;
//}

// ���һ���࣬��������ֻ����ջ���߶��ϴ�������

//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	static A GetStackObj()
//	{
//		A aa;
//		return aa;
//	}
//
//	static A* GetHeapObj()
//	{
//		return new A;
//	}
//
//	// ��װ��˽�У�ֻ�������ڲ�����
//private:
//	A()
//	{}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//
//int main()
//{
//	// ���ǵ���������Ա�����ͻᱻ����ͳ�Ա���������ȼ�������
//	// ��ʱ�Ϳ���ʹ�þ�̬��Ա����
//	// static A GetStackObj();
//
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		++_cnt;
//	}
//	A(const A& aa) { ++aa._cnt; }
//
//private:
//	int _a;
//public:
//	static int _cnt;
//};
//
//int A::_cnt = 0;
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	cout << A::_cnt << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	int a()
//	{
//		return _cnt;
//	}
//	int c()
//	{
//		int tmp = 3;
//		return tmp;
//	}
//	static int b()
//	{
//
//		++_cnt;
//		_cnt = c();
//	}
//
//private:
//	static int _cnt;
//};
//
//int A::_cnt = 0;
//
//int main()
//{
//
//
//	return 0;
//}

// ʹһ������ֻ����ջ�ϴ���/���ϴ���

#include <iostream>

using namespace std;

class A
{
public:
	static A GetStackObj()
	{
		A aa;
		return aa;
	}

	static A* GetHeapObj()
	{
		return new A;
	}

	// ��װ��˽�У�ֻ�������ڲ�����
	// �����ӾͲ���ֱ�Ӵ�������
private:
	A()
	{}

private:
	int _a1 = 1;
	int _a2 = 2;
};


int main()
{
	// ���ǵ���������Ա�����ͻᱻ����ͳ�Ա���������ȼ�������
	// ��Ϊ������Ҫ��һ�����󣬵��Ƕ����ָ��������Χ��ͬ
	// ��ʱ�Ϳ���ʹ�þ�̬��Ա����
	// static A GetStackObj();

	return 0;
}