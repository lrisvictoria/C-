#pragma once

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1);
	void Print();
	int GetMonthDay(int year, int month); // ��ȡĳ��ĳ�µ�����
	
private:
	int _year;
	int _month;
	int _day;
};