#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//struct Point
//{
//	Point(int x, int y)
//		:_x(x)
//		,_y(y)
//	{
//		cout << "Point(int x, int y)" << endl;
//	}
//
//	int _x;
//	int _y;
//};
//
//// һ�нԿ��� {} ��ʼ�������ҿ��Բ�д��ֵ����
//// �ճ����岻Ҫȥ�� =����������Ҫ�ܿ���
//int main()
//{
//	int x = 1;
//	int y = { 2 }; // ����֧��������ʼ��
//	int z{ 3 };// right
//	int a1[] = { 1, 2,3 };
//	int a2[]{ 1, 2, 3 }; // ����������ʼ��Ҳ��
//
//	// ���ʶ��ǵ��ù��캯��
//	Point p(1, 2);
//	Point p1 = { 1, 3 }; //�᲻����ù��캯��? �� �����Ƕ�������캯������ʽ����ת��
//	Point p2{ 2, 2 }; // �᲻����ù��캯��? ��
//
//	const Point& r = { 3, 3 }; // ��ʱ������г���
//
//	int* p1 = new int[3] {1, 2, 3};
//	Point* ptr = new Point[2]{ {1, 2}, {2, 3} }; // ��û����������ʱ�鸡�˺ܶ࣬������������
//
//
//	return 0;
//}

//int main()
//{
//	vector<int> v1 = { 1, 2 }; // �����б��ʼ��֧�ֵģ������в�ͬ�Ĺ���
//	// ���ﱾ��Ҳ��һ������
//	// ����б���� initializer_list
//	auto il = { 10, 20, 30 };
//	initializer_list<int> il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
// }

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    int res = 0;
//
//    for (int i = 2; i < n; i++)
//    {
//        int tmp = 1;
//        for (int j = 2; j <= i / 2; j++)
//        {
//            if (!(i % j))
//            {
//                tmp += j;
//            }
//        }
//
//        if (tmp == i) res++;
//    }
//
//    cout << res << endl;
//
//
//    return 0;
//}

//int sum(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	// decltype(sum(1, 3)) a;
//
//	const char* str = "xxxxxx";
//
//	str[2] = 0x11223344;
//
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	// ��ֵ����
//	int a = 0;
//	int& r1 = a; 
//
//	// ��ֵ�����ܷ����ֵȡ������
//	// const ��ֵ���ÿ��� 
//	const int& r2 = 10;
//	const double& r3 = x + y;
//
//	// ��ֵ����
//	int&& r5 = 10; 
//	double&& r6 = x + y; 
//
//	// ��ֵ�����Ƿ��ܸ���ֵȡ������
//	// ֱ�Ӹ�������
//	// ǿ�Ƹ�����������¿�����, move һ��
//	// move �Ժ� a ������һЩӰ�죨���ûӰ�죩
//	// �ܽ᣺��ֵ���ÿ������� move �Ժ����ֵ
//	int&& r7 = a;
//	double&& r8 = move(a);
//
//	
//
//	return 0;
//}

// ��ֵ���õ�ʹ�ó����ͼ�ֵ��ʲô
// ʹ�ó�����1.������    2.������ֵ     ��ֵ->���ٿ���
// ������λ�ģ��ֲ����󷵻ز�������ֵ���ý��

//string func()
//{
//	string str;
//	cin >> str;
//
//	//...
//
//	return str;
//}
//
//int main()
//{
//	return 0;
//}

//#include <cassert>
//
//namespace lx
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			//cout << "string(char* str)" << endl;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		// s1.swap(s2)
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//		// ��������
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- ���" << endl;
//			string tmp(s._str);
//			swap(tmp);
//		}
//		// ��ֵ����
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- ���" << endl;
//			string tmp(s);
//			swap(tmp);
//			return *this;
//		}
//		//// �ƶ�����
//		//string(string&& s)
//		//	:_str(nullptr)
//		//	, _size(0)
//		//	, _capacity(0)
//		//{
//		//	cout << "string(string&& s) -- �ƶ�����" << endl;
//		//	swap(s);
//		//}
//		//// �ƶ���ֵ
//		//string& operator=(string&& s)
//		//{
//		//	cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
//		//	swap(s);
//		//	return *this;
//		//}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//		char& operator[](size_t pos)
//		{
//			assert(pos < _size);
//			return _str[pos];
//		}
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//				_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//		//string operator+=(char ch)
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//		const char* c_str() const
//		{
//			return _str;
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // �������������ʶ��\0
//	};
//}
//
//// ��ֵ���õ�ʹ�ó����ͼ�ֵ��ʲô��
//// ʹ�ó�����1��������  2��������ֵ  ��ֵ->���ٿ���
//lx::string func()
//{
//	lx::string str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cin >> str;
//	//....
//
//	return str;
//}
//
//int main()
//{
//	lx::string ret1 = func();
//
//	lx::string ret2;
//	//...
//	ret2 = func();
//
//	return 0;
//}

// ��ֵ���������õĳ�������ֵ���ò�̫һ��
// �Ǽ�������õ�

// �Ƿ񹹳ɺ������أ���
//void func(int& r)
//{
//	cout << "void func(int& r)" << endl;
//}
//
//
//
//void func(int&& r)
//{
//	cout << "void func(int&& r)" << endl;
//}
//
//int main()
//{
//	return 0;
//}
