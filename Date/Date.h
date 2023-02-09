#pragma once

#include <iostream>

using namespace std;

class Date
{
	// 友元
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	// 公元 1 年开始
	Date(int year = 1, int month = 1, int day = 1);
	Date(const Date& d);
	void Print() const;
	int GetMonthDay(int year, int month) const; // 获取某年某月的天数
	// 实现 > 或 < 和 == 其他的复用
	// 不仅仅 Date 可以这样子，所有类实现比较，都可以用这种方式
	bool operator>(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	
	Date operator+(int day) const; // d1 + 100
	Date& operator+=(int day); // d1 += 100
	Date& operator-=(int day); // d1 += 100
	Date operator-(int day) const;

	// 默认第一个为前置 ++ ，后置 ++ 为了区分增加了一个参数占位，和前置构成函数重载
	Date& operator++(); // ++d1
	Date operator++(int); // d1++
	Date& operator--();
	Date operator--(int);
	int operator-(const Date& d) const; // paln day - today

private:
	int _year;
	int _month;
	int _day;
};

// 优化为内联
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << '-' << d._month << '-' << d._day << endl;
	return out;
}

inline istream& operator>>(istream& in, Date& d) // d 要被修改，不能加 const
{
	in >> d._year >> d._month >> d._day;
	return in;
}