#include <iostream>
#include <vector>
#include <list>
#include <array>

using namespace std;

// ģ�������������⣺
// 1. ģ����Կ�����������������(stl)
// 2. ��������߼�������������������ʹ��Ƹ������

// ֻҪ��һ�����;Ϳ�����ģ�壬�������ڿ�����������������

// ģ������� class ������ typename���ճ������𣬵����������������

//void Print(const vector<int>& v)
//{
//	vector<int>::const_iterator it = v.begin(); // �� vector<int> ���� const_iterator 
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}

// �����������дΪ����
//template<typename Container> // �����˼���ã��������
template<class Container>
void Print(const Container& v)
{
	// class �� typename ʹ�ò�һ���ĵط����������� typename�����ܼ� class 
	// ����ģ��Ĳ�����һ���࣬��containerûʵ����
	// const_iterator ���������еľ�̬��Ա��Ҳ�п�����һ����Ƕ����
	// typename ���Ǹ��߱���������һ������
	// ȷ����������ʵ����֮��ȷ�����ͣ�main ����ʾʵ����
	// ���벻ȷ��Container::const_iterator�����ͻ��Ƕ���
	// typename������ȷ���߱��������������ͣ���ģ��ʵ������ȥ��
	typename Container::const_iterator it = v.begin();
	// auto it = v.begin(); // ���� auto ��ֱ���Ƶ����ͣ���ȷ��������
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

// const_iterator begin ���ǹؼ��֣����������
// ���ܱ�֤���Ǿ�������
// ����ģ���������ڼ�ʵ����(�������)

//class A
//{
//public:
//	int begin()
//	{
//		return 0;
//	}
//
//	static int const_iterator;
//};
//
//int A::const_iterator = 1;

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	Print(v);
//
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	for (auto e : lt)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	Print(lt);
//
//	
//	return 0;
//}

// ������ģ�����

// #define N 100 // �ز�ס����

// ��̬ջ
//template<class T>
//class Stack
//{
//private:
//	T _a[N]; // ��Ҫ���ǳ���
//	int _top;
//};
//
//int main()
//{
//	Stack<int> st1; // ���� 10
//	Stack<int> st2; // ���� 100 ������
//
//	return 0;
//}


// ��̬ջ
// ������ģ�����
// 1������
// 2�����������Σ��涨��double ���У�

// ֮ǰʹ�õ�ģ�������������ģ�����

template<class T, size_t N = 10>
class Stack
{
public:
	void func()
	{
		// �����������޸ģ����ûᱨ��
		N = 0;
	}
private:
	T _a[N];
	int _top;
};



// error
//template<class T, double N>
//class BB
//{};

//int main()
//{
//	Stack<int> st;
//	Stack<int, 10> st1; // 10
//	Stack<int, 100> st2; // 100
//
//	// ����ʵ����(�����˲Ż�ʵ����)����ͬ����������ͬ
//	// ��ʵ������func �е��﷨����ͼ�鲻��
//	// st1.func();
//
//	return 0;
//}


// array ֧�ַ�����ģ�����
// ��һ���������飬û�в���ĸ���
// һ��ʼ�����ռ���ǿ��õģ�����ֱ�� [] ����

//int main()
//{
//	int a[10]; // ��Ĭ�ϳ�ʼ��
//	a[0] = 0;
//	for (auto e : a)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	// c++11
//	array<int, 10> a1; //  Ҳ����ʼ��
//	a1[0] = 0;
//	for (auto e : a1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	// array ������飬���Խ����ϸ�Խ�����д������
//	// [] ���ã��������
//	// ��ͨ���鲻�ܼ��Խ������ٲ���Խ��д���Լ��
//
//	// ���� vector Ҳ�ܼ�飬���ԱȽϼ��ߣ�vector �ڶ��ϣ�array ��ջ��
//	// ������ģ�����Ϊ���Σ���Ϊ��ʦүһ��ʼ�����붨��̶���С������
//
//	return 0;
//}


// ģ����ػ�
// ���ĳЩ�������⻯����

// &a, &b ����ģ����ػ�
// ����� int* ָ�룬��ָ�����ݱ�
//template<>
//bool Less<int*>(int* left, int* right)
//{
//	return *left < *right;
//}

// ��������������ͣ�ֻҪд���غ�������
// ģ�廹�Ǿͽ�ԭ��
bool Less(int* left, int* right)
{
	return *left < *right;
} 


template<class T>
bool Less(T* left, T* right)
{
	return *left < *right;
}

// ���������Ҫ�������ָ������⣬������ģ��

// ��ͨ���Ͱ�����Ƚ�
template<class T>
bool Less(T left, T right)
{
	return left < right;
}

//int main()
//{
//	cout << Less(1, 2) << endl;
//
//	int a = 1, b = 2;
//	cout << Less(&a, &b) << endl; // �����Ƚ�ָ��ָ������ݣ�����ƽ������ϣ���Ͱ��մ�С�Ƚ�
//
//	double c = 1.1, d = 2.2;
//	cout << Less(&c, &d) << endl;
//
//	return 0;
//}

// ʵ���ϣ�����ģ��д���ظ��ã�Ҳ����д

//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
//// ������� int double Ҫ�������⴦���ػ�
//// ����������������������أ�������ģ��
//// ȫ�ػ�
//template<>
//class Data<int, double>
//{
//public:
//	Data() { cout << "Data<int, double>" << endl; }
//private:
//	int _d1;
//	double _d2;
//};
//
//// ƫ�ػ�(���ػ�) �� �ػ����ֲ���
//template<class T1>
//class Data<T1, double>
//{
//public:
//	Data() { cout << "Data<T1, double>" << endl; }
//private:
//};
//
//// ƫ�ػ� �� �����Ƕ�ĳЩ���͵Ľ�һ������
//// ��������Ϊָ��
//template<class T1, class T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//};
//
//template<class T1, class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//private:
//};


//int main()
//{
//	Data<int, int> d1;
//	Data<int, double> d2;
//	Data<int*, double> d3;
//	Data<double, double> d4;
//	Data<double*, double*> d5;
//	Data<void*, int*> d6; // void ���ܶ�����������Գ�Ա����д void _d
//	Data<int&, double&> d7;
//
//	return 0;
//}

// �ػ������Ǳ�ø��ӷ��㣬�������أ���д���
// �ػ��൱����һ���µ��࣬û��Ҫ��֮ǰ���е����ж������������������
// ��дʲô������
// ȫ�ػ�������Ҫʵ����������ֱ���ã���Ϊ�����Ѿ��涨����

// �ػ��ϸ���˵�������µ��࣬��Ϊ���ܶ������ڣ�����Ļ�����
// ����ʵ�����������µ�����

// ʵ�����ػ���һ�㶼�Ǻ�С���࣬����һ�㲻�����Ҫ��ܶණ�������������º���

// ģ��ķ������

// �к���������е�ַ
// �ڱ�������У�ͷ�ļ���������Դ�ļ���
// ��ͷ�ļ����ж���Ĳ��е�ַ,�����ڱ������޷�ȷ����ַ

#include"Stack.h"

int main()
{
	bit::stack<int, vector<int>> st;  // call xxstackxx(0x324242) Ҳ���������ɻ�����Ե�ʱ��
	st.push(1);  // call xxpushi(?) ���ӵ�ʱ���ڷ��ű����Ҳ�����ַ
	// st.pop();

	st.size();   // call xxsizexx(0xdadada) Ԥ�������ͷ�ļ����������ɻ������ʱ���������е� test.s ȷ�ϣ��ж�����е�ַ������ͷ�ļ���test.s ���ж���
	st.top();

	bit::A aa;
	aa.func1(1);   // call xxfunc1xx(?) û�����Ӵ����ҵĵ�����Ϊ������
	// aa.func2();  // call xxfunc2xx(?) �����Ӵ�����Ϊֻ������������֮ǰ�ǵ�������

	// ���ͼ����
	// push func1 func2 �ڱ���ʱ�޷�ȷ����ַ�����ʺŵĶ�ûȷ�ϣ�
	// ����(С���̣������캯����size �ĵ�ַȷ����
	// ������ûȷ�ϣ�����ʱ��Ϊ��������������һ�ֳ�ŵ
	// �����Щ������ʱ�򣬷��ֺ���������(������������������ֵ������Ӧ��������ܹ�
	// �������ӵ�ʱ���������κ�ĺ��������������ļ����ű����
	
	// ���⣺
	// 1. func1 ���Ӳ鵽
	// 2. func2 �鲻����û����
	// 3. push ���Ӳ鲻�������� push ������

	// 3: stack.o �������ɵ�ַ����Ϊ��֪�� T ��ʲô��push �� pop û��ʵ����
	// ���� st.push(1) ��ַ���� xxpushi �������Ҳ�������Ϊû��ʵ������û�����ɵ�ַ��

	// ���ֽ��������
	// 1. �� Stack.cpp �У���ʾʵ���������ļ������ռ��ڵ�����λ�ö�����
	// ���Ƕ��ڲ�ͬ���ͻ�����Ҫ����ʵ����

	// 2. size Ϊʲô���ԣ���Ϊ����������ͬһ���ļ���
	// ���Կ��������Ͷ���������һ���ļ���
	// stl Ҳ����ô����

	// .hpp �����Ͷ�����һ���ļ��У�boost ���о�������������������ʾ

	// �е㣺�����(���������º��� -- ��һ������ģ�壬�������ȼ����У�������д����ͨ��lessDate��)

	bit::stack<double> st1;  // call xxstackxx(0x324242)
	st1.push(1);  // call xxpushi(?)
	st1.pop();

	return 0;
}