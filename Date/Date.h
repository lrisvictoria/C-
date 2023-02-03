#pragma once

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1);
	void Print();
	int GetMonthDay(int year, int month); // 获取某年某月的天数
	
private:
	int _year;
	int _month;
	int _day;
};