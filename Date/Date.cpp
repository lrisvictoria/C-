#include "Date.h"

int Date::GetMonthDay(int year, int month) const
{
	// 从 1 月开始
	static int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = monthDayArr[month];

	if (month == 2 && ((year % 400 == 0) && (year % 4 == 0 && year % 100 != 0)))
	{
		day += 1;
	}

	return day;
}

// 构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	// 检查日期是否错误 
	if (!(_year > 0 && (month > 0 && month < 13) && (day > 0 && day <= GetMonthDay(year, month))))
	{
		cout << "非法日期：";
		Print(); // 访问成员函数
	}
}

// 拷贝构造
Date::Date(const Date& d)
{
	//cout << "进行拷贝构造" << endl;
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

void Date::Print() const
{
	cout << _year << '-' << _month << '-' << _day << endl;
}

// 只要实现 > 和 = 
bool Date::operator>(const Date& d) const
{
	if (_year > d._year) 
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// d1 == d2 
bool Date::operator==(const Date& d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

// 复用 == 
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

// 复用 > 和 == 
bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}

// 复用 > 
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}
	
// 复用 >= ，不大于并且不相等
bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}

Date& Date::operator+=(int day) 
{
	// 处理负数 -100
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month)) // 不合法处理
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13) // 超过一年
		{
			_year++;
			_month = 1;
		}
	}
	return *this; // 返回引用，返回时不进行拷贝，d1 = d2 += d30
}

// 复用 += 
Date Date::operator+(int day) const
{
	Date tmp(*this); // 拷贝构造
	tmp += day; // 复用 += 
	return tmp;
}

// ++d1
Date& Date::operator++()
{ 
	return *this;
}

// d1++
Date Date::operator++(int)
{
	// 返回拷贝构造前的一份
	Date ret(*this);
	*this += 1;
	return ret;
}

// 2022 1 17
//      - 20
// 日期如果不合法，往月去借，月不够了，就往年借
Date& Date::operator-=(int day)
{
	// 处理负数 - -100
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;

	// <= 0 不合法，天不够了往上个月借
	while (_day <= 0)
	{
		--_month;
		// 月不够了往年借
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}


Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

// 比较两个日期的大小，让小的累加，用变量记录，什么时候两个日期相等，此刻的变量就是相差的天数
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1; // 调整正负
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int cnt = 0;
	while (min != max)
	{
		++min;
		++cnt;
	}

	return cnt * flag;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << '-' << d._month << '-' << d._day << endl;
	return out;
}