#include <iostream>

using namespace std;

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << '-' << d._month << '-' << d._day << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//
//int main()
//{
//	Date d1(2022, 1, 17);
//	Date d2;
//
//	cin >> d1 >> d2;
//	cout << d1 << d2; 
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a) { _a = a; } // ��Ĭ�Ϲ��캯��
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day, int i)
//		:_N(10)
//		,_ref(i)
//		,_aa(-1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	const int _N;
//	int& _ref;
//	A _aa;
//};
//
//int main()
//{
//	Date d1(2023, 2, 6, 10);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 1) 
//	{
//		cout << "���й���" << endl;
//		_a = a; 
//	}
//	A(const A& a)
//	{
//		cout << "���п�������" << endl;
//		_a = a._a;
//	}
//	A& operator=(const A& a)
//	{
//		cout << "��ֵ����" << endl;
//		_a = a._a;
//		return *this;
//	}
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year, int month, int day, const A& aa)
//		:_aa(aa)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	A _aa;
//};
//
//int main()
//{
//	A aa(10); // ���ù���
//	Date d1(2023, 2, 6, aa);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() 
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main() 
//{
//	A aa(1);
//	aa.Print();
//}

//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//	{
//		cout << "���й���" << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "���п�������" << endl;
//	}
//private:
//	int _year;
//};
//int main()
//{
//	Date d1(2022);
//	Date d2 = 2022;
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a) 
//	{ ++_sCnt; }
//
//	A(const A& aa) { ++_sCnt; }
//	// û�� this ָ�룬ֻ�ܷ��ʾ�̬��Ա�����ͳ�Ա����
//	static int GetCnt()
//	{
//		return _sCnt;
//	}
//
//private:
//	int _a;
//	static int _sCnt; // ����
//};
//
//int A::_sCnt = 0; // ȫ�ֶ���
//
//int main()
//{
//	A a1;
//	A a2 = 1;
//
//	cout << a1.GetCnt() << endl;
//	cout << A::GetCnt() << endl;
//
//	return 0;
//}

class B
{
public:
	B(int b = 0)
		:_b(b)
	{}
private:
	int _b;
};

class A
{
private:
	int _a;
	B _b;
};

int main()
{
	A aa;

	return 0;
}