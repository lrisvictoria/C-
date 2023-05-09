#pragma once

#include <iostream>
 
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	int GetMonthDay(int year, int month);
	void Print() const; // const 修饰 *this

	bool operator<(const Date& d) const;
	Date& operator=(const Date& d); // 赋值重载
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<= (const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	// += + -= -
	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day) const;
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d) const;
	
	// 因为 Date 对象默认占用第一个参数，就是为了做左操作数
	// 写出来一定是下面这样，不符合使用习惯
	// 写成友元函数
	// void operator<<(ostream& out);
private:
	int _year;
	int _month;
	int _day;
};



/*
public:
  // 日期+=天数

Date& operator+=(int day);
  // 日期+天数

Date operator+(int day);
  // 日期-天数

Date operator-(int day);
   // 日期-=天数

Date& operator-=(int day);
  // 前置++

Date& operator++();
  // 后置++

Date operator++(int);
  // 后置--

Date operator--(int);
  // 前置--

Date& operator--();
  // 日期-日期 返回天数

int operator-(const Date& d);

private:

int _year;

int _month;

int _day;

};
*/