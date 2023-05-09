#pragma once

#include <iostream>
 
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	int GetMonthDay(int year, int month);
	void Print();

	bool operator<(const Date& d);
	Date& operator=(const Date& d); // 赋值重载
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<= (const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	// += + -= -
	Date& operator+=(int day);
	Date operator+(int day);
	Date& operator-=(int day);
	Date operator-(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);
	
	void operator<<(ostream& out);
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