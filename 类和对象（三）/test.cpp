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
//	A(int a) { _a = a; } // 非默认构造函数
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

class A
{
public:
	A(int a = 1) 
	{
		cout << "进行构造" << endl;
		_a = a; 
	}
	A(const A& a)
	{
		cout << "进行拷贝构造" << endl;
		_a = a._a;
	}
	A& operator=(const A& a)
	{
		cout << "赋值重载" << endl;
		_a = a._a;
		return *this;
	}
private:
	int _a;
};

class Date
{
public:
	Date(int year, int month, int day, const A& aa)
	// 默认调用 _aa 的构造
	{
		_aa = aa;
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
	A _aa;
};

int main()
{
	A aa(10); // 调用构造
	Date d1(2023, 2, 6, aa);

	return 0;
}

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
//		cout << "进行构造" << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "进行拷贝构造" << endl;
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
//	// 没有 this 指针，只能访问静态成员变量和成员函数
//	static int GetCnt()
//	{
//		return _sCnt;
//	}
//
//private:
//	int _a;
//	static int _sCnt; // 声明
//};
//
//int A::_sCnt = 0; // 全局定义
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

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//
//class A
//{
//public:
//	A() {}
//private:
//	int _a = 0; // 声明，不是初始化
//	B _b;
//	int* p = (int*)malloc(4 * 10);
//	static int _sCnt = 0; // err
//};
//
//int main()
//{
//	A aa;
//
//	return 0;
//}

//class Time
//{
//	// 日期类想要经常访问 Time ，让 Date 变为 Time 的友元类
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//	void Func(Date d);
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//	friend class Time;
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//void Time::Func(Date d) // Date 和 Time 两者互为友元，所以 Time 中现在可以访问 Date 
//{
//	cout << d._year << endl;
//}
//
//
//int main()
//{
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 1)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//	friend class C;
//};
//class C
//{
//public:
//	void f(A a)
//	{
//		cout << a._a << endl;
//	}
//private:
//	int _c;
//};
//int main()
//{
//	C c1;
//	A a1;
//
//	c1.f(a1);
//
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int h;
//	
//public:
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl; // ok，内部类可以访问外部类的私有
//			cout << a.h << endl; // ok
//		}
//	private:
//		int _b;
//	};
//
//	void f(B b)
//	{
//		// cout << b._b << endl; // err ，外部类不能访问内部类的私有
//	}
//};
//int A::k = 1;
//int main()
//{
//	A::B b; // 内部类的定义
//	
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int m;
//class Date {
//public:
//    friend istream& operator>>(istream& in, Date& d);
//    int GetMonthDay(int year, int month) {
//        static int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        int day = monthDayArr[month];
//        if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
//            day += 1;
//        }
//        return day;
//    }
//    Date& operator+=(int& add) {
//        _day += add;
//        while (_day > GetMonthDay(_year, _month)) {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//            if (_month == 13) {
//                _year++;
//                _month = 1;
//            }
//        }
//        return *this;
//    }
//    void Print() {
//        printf("%d-%02d-%02d\n", _year, _month, _day);
//    }
//private:
//    int _year = 0;
//    int _month = 0;
//    int _day = 0;
//public:
//    int _add = 0;
//};
//istream& operator>>(istream& in, Date& d) {
//    in >> d._year >> d._month >> d._day >> d._add;
//    return in;
//}
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
//    cin >> m;
//    for (int i = 0; i < m; i++) {
//        Date d;
//        cin >> d;
//        d += d._add;
//        d.Print();
//    }
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//    friend istream& operator>>(istream& in, Date& d);
//public:
//    Date(int year = 1, int month = 1, int day = 0) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    int GetMonthDay(int year, int month) {
//        int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        int day = monthDayArr[month];
//        if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
//            day += 1;
//        }
//        return day;
//    }
//    Date& operator+=(int& add) {
//        _day += add;
//        while (_day > GetMonthDay(_year, _month)) {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//            if (_month == 13) {
//                _year++;
//                _month = 1;
//            }
//        }
//        return *this;
//    }
//    void Print() { printf("%d-%02d-%02d\n", _year, _month, _day); }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//public:
//    int _normal; // 天数
//};
//
//istream& operator>>(istream& in, Date& d)
//{
//    d._year = d._normal = d._day = 0;
//    d._month = 1;
//    in >> d._year >> d._normal;
//    return in;
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
//
//    Date d;
//    while (cin >> d) {
//        d += d._normal;
//        d.Print();
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Date {
//public:
//    Date(string& s) {
//        _year = stoi(s.substr(0, 4));
//        _month = stoi(s.substr(4, 2));
//        _day = stoi(s.substr(6));
//    }
//    bool operator<(const Date& d) const {
//        if (_year < d._year) {
//            return true;
//        }
//        else if (_year == d._year && _month < d._month) {
//            return true;
//        }
//        else if (_year == d._year && _month == d._month && _day < d._day) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//    bool operator!=(const Date& d) const {
//        return (_year != d._year) || (_month != d._month) || (_day != d._day);
//    }
//    int GetMonthDay(int year, int month) const {
//        static int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        int day = monthDayArr[month];
//        if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
//            day += 1;
//        }
//        return day;
//    }
//    Date& operator+=(int day) {
//        _day += day;
//        while (_day > GetMonthDay(_year, _month)) {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//            if (_month == 13) {
//                _year++;
//                _month = 1;
//            }
//        }
//        return *this;
//    }
//    Date& operator++() {
//        *this += 1;
//        return *this;
//    }
//
//    int operator-(const Date& d) const {
//        Date max = *this, min = d;
//        if (*this < d) {
//            max = d, min = *this;
//        }
//        int cnt = 0;
//        while (min != max) {
//            ++min;
//            ++cnt;
//        }
//        return cnt + 1;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    string a, b;
//    cin >> a >> b;
//    Date d1(a);
//    Date d2(b);
//    cout << (d1 - d2) << endl;
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//    friend istream& operator>>(istream& in, Date& d);
//public:
//    Date(int year, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    int GetMonthDay(int year, int month) const {
//        static int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        int day = monthDayArr[month];
//        if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
//            day += 1;
//        }
//        return day;
//    }
//    bool operator!=(const Date& d) const {
//        return (_year != d._year) || (_month != d._month) || (_day != d._day);
//    }
//    Date& operator+=(int day) {
//        _day += day;
//        while (_day > GetMonthDay(_year, _month)) {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//            if (_month == 13) {
//                _year++;
//                _month = 1;
//            }
//        }
//        return *this;
//    }
//    Date& operator++() {
//        *this += 1;
//        return *this;
//    }
//    int operator-(const Date& d)
//    {
//        // *this 大，d 为小
//        Date max = *this, min = d;
//        int cnt = 1;
//        while (max != min)
//        {
//            ++min;
//            ++cnt;
//        }
//        return cnt;
//    }
//public:
//    int _year;
//private:
//    int _month;
//    int _day;
//};
//
//istream& operator>>(istream& in, Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//
//int main()
//{
//    Date d1(1); // 输入
//    cin >> d1;
//
//    Date d2(d1._year);
//
//    cout << (d1 - d2) << endl;
//}

//class A
//{
//	class B
//	{
//	private:
//		int _c;
//		int _d;
//	};
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	
//
//	return 0;
//}