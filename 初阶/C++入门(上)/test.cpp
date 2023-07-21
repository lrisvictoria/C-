/*#include <iostream>

namespace lx
{
	struct Node
	{
		Node* next;
		int val;
	};
}

int main()
{
	std::cout << "hello world" << std::endl;

	return 0;
}*/

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int rand = 10;
//
//int main()
//{
//	printf("%d\n", rand);
//
//	return 0;
//}

// 域
// 局部域 / 全局域：1、使用 2、生命周期

//#include <stdio.h>
//
//int a = 2;
//
//void f1()
//{
//	int a = 0;
//	//printf("%d\n", a);
//	printf("%d\n", ::a); // :: 域作用限定符
//	// 左边的域为空，空就代表全局
//}
//
//void f2()
//{
//	int a = 1;
//}
//
//int main()
//{
//	printf("%d\n", a);
//}

//#include "Queue.h"
//#include "List.h"
//
//int main()
//{
//
//
//	return 0;
//}

//namespace anduin
//{
//	int val = 10;
//
//	int solve()
//	{
//		int returnvalue = 20;
//		return returnvalue;
//	}
//}

//namespace anduin
//{
//	int foo = 100;
//	namespace guldan
//	{
//		int fooo = 1000;
//	}
//}

//#include "test.h"
//#include "tool.h"
//
//int main()
//{
//	anduin::print(anduin::max);
//}

//#include <stdio.h>
//
//int a = 2;
//
//void f1()
//{
//	int a = 0;
//	printf("%d\n", ::a);
//}
//
//int main()
//{
//	f1();
//	return 0;
//}

//#include "List.h"
//#include "Queue.h"
//
//int main()
//{
//	struct AQueue::Node node1;
//	struct BList::Node node2;
//}


//#include <stdio.h>
//namespace anduin
//{
//	namespace guldan
//	{
//		int a = 10;
//		void print(int val)
//		{
//			printf("%d", val);
//		}
//	}
//}
//
//using namespace anduin;
//using namespace guldan;
//
//int main()
//{
//	//anduin::guldan::print(anduin::guldan::a);
//
//	print(a);
//
//	return 0;
//}

//#include <iostream>
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//
//	return 0;
//}

//#include <iostream>
//
//using std::cout;
//
//int main()
//{
//	cout << "hello world" << std::endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int num = 0;
//
//	cin >> num;
//
//	cout << num << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	cout << "hello c++" << endl;
//
//	cout << "hello c++\n";
//
//	cout << "hello c++" << '\n';
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a;
//	float b;
//	char c;
//
//	cin >> a >> b >> c; // 逐次输入 a b c
//
//	cout << a << " " << b << " " << c << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <iomanip> // cout 控制精度所需头文件
//
//using namespace std;
//
//int main()
//{
//	double num = 1.363789;
//
//	printf("%.2f\n", num);// printf
//	cout << fixed << setprecision(2) << num << endl; // cout 
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cout.tie(NULL);
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void Func(int a = 2)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	Func(1);
//	Func();
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	cout << endl;
//}
//
//int main()
//{
//	Func(1, 2, 3); // 传三个参数，不使用缺省值
//	Func(1, 2); // 传两个参数，使用 c 的缺省值
//	Func(1); // 传一个参数，使用 b, c 的缺省值
//	Func(); // 不穿参数，使用 a b c 的缺省值
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	cout << endl;
//}
//
//int main()
//{
//	Func(1, 2, 3); // 传三个参数，不使用缺省值
//	Func(1, 2); // 传两个参数，使用 c 的缺省值
//	Func(1); // 传一个参数，使用 b, c 的缺省值
//	//Func(); // 错误，由于第一个参数没有缺省值，所以至少传一个参数
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//};
//
//void StackInit(struct Stack* p, int defaultcapacity = 4)
//{
//	p->a = (int*)malloc(sizeof(int) * defaultcapacity);
//	p->top = 0;
//	p->capacity = 100;
//}
//
//int main()
//{
//	Stack st1;
//	Stack st2;
//
//	StackInit(&st1, 100);
//	StackInit(&st2); // 不传参，默认就开辟四个
//
//	return 0;
//}

//#include "test.h"
//#include <iostream>
//
//
//using namespace std;
//
//int main()
//{
//	foo();
//}

#include <iostream>

using namespace std;

int g_val = 100;

void Func(int a = g_val)
{
	cout << a << endl;
}

int main()
{
	Func();
	return 0;
}