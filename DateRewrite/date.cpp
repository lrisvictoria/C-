#include "date.h"

int Date::GetMonthDay(int year, int month)
{
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];

	if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
	{
		day += 1;
	}

	return day;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	// 检查日期
	if (!(_year > 0 && (month > 0 && month < 13) && (day > 0 && day < GetMonthDay(year, month))))
	{
		cout << "非法日期" << endl;
		Print();
	}
}

Date::Date(const Date& d)
{
	cout << "拷贝构造" << endl;

	_year = d._year;
	_month = d._month;
	_day = d._day;
}

void Date::Print()
{
	cout << _year << '-' << _month << '-' << _day << endl;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date& Date::operator=(const Date& d) // 引用返回减少拷贝构造
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}