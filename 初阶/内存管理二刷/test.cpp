//#include <iostream>
//
//using namespace std;
//
//class A
//{
//public:
//	A(int a, int b)
//		:_a(a) 
//		,_b(b)
//	{}
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	A* a1 = new A(1, 2);
//	A* a2 = new A[4]{ {1, 2}, {1, 2}, {1, 2}, {1, 2} };
//
//
//
//	return 0;
//}

#include <iostream>

using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = new A(4);

	delete p;

	return 0;
}