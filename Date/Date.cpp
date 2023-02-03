#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	// �� 1 �¿�ʼ
	static int monthDayArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = monthDayArr[month];

	if (month == 2 && ((year % 400 == 0) && (year % 4 == 0 && year % 100 != 0)))
	{
		day += 1;
	}

	return day;
}

// ���캯��
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	// ��������Ƿ���� 
	if (!(_year >= 0 && (month > 0 && month < 13) && (day > 0 && day <= GetMonthDay(year, month))))
	{
		cout << "�Ƿ����ڣ�";
		Print(); // ���ʳ�Ա����
	}
}

void Date::Print()
{
	cout << _year << '-' << _month << '-' << _day << endl;
}