#include "Date.h"

int Date::GetMonthDay(int year, int month)
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
	if (!(_year >= 0 && (month > 0 && month < 13) && (day > 0 && day <= GetMonthDay(year, month))))
	{
		cout << "非法日期：";
		Print(); // 访问成员函数
	}
}

void Date::Print()
{
	cout << _year << '-' << _month << '-' << _day << endl;
}