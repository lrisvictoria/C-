#include "Date.h"

int Date::GetMonthDay(int year, int month) const
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
	if (!(_year > 0 && (month > 0 && month < 13) && (day > 0 && day <= GetMonthDay(year, month))))
	{
		cout << "�Ƿ����ڣ�";
		Print(); // ���ʳ�Ա����
	}
}

// ��������
Date::Date(const Date& d)
{
	//cout << "���п�������" << endl;
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

void Date::Print() const
{
	cout << _year << '-' << _month << '-' << _day << endl;
}

// ֻҪʵ�� > �� = 
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

// ���� == 
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

// ���� > �� == 
bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}

// ���� > 
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}
	
// ���� >= �������ڲ��Ҳ����
bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}

Date& Date::operator+=(int day) 
{
	// ������ -100
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month)) // ���Ϸ�����
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13) // ����һ��
		{
			_year++;
			_month = 1;
		}
	}
	return *this; // �������ã�����ʱ�����п�����d1 = d2 += d30
}

// ���� += 
Date Date::operator+(int day) const
{
	Date tmp(*this); // ��������
	tmp += day; // ���� += 
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
	// ���ؿ�������ǰ��һ��
	Date ret(*this);
	*this += 1;
	return ret;
}

// 2022 1 17
//      - 20
// ����������Ϸ�������ȥ�裬�²����ˣ��������
Date& Date::operator-=(int day)
{
	// ������ - -100
	if (day < 0)
	{
		return *this += -day;
	}

	_day -= day;

	// <= 0 ���Ϸ����첻�������ϸ��½�
	while (_day <= 0)
	{
		--_month;
		// �²����������
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

// �Ƚ��������ڵĴ�С����С���ۼӣ��ñ�����¼��ʲôʱ������������ȣ��˿̵ı���������������
int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1; // ��������
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