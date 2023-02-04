#pragma once

#include <iostream>

using namespace std;

class Date
{
public:
	// ��Ԫ 1 �꿪ʼ
	Date(int year = 1, int month = 1, int day = 1);
	Date(const Date& d);
	void Print();
	int GetMonthDay(int year, int month); // ��ȡĳ��ĳ�µ�����
	// ʵ�� > �� < �� == �����ĸ���
	// ������ Date ���������ӣ�������ʵ�ֱȽϣ������������ַ�ʽ
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator>=(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	
	Date operator+(int day); // d1 + 100
	Date& operator+=(int day); // d1 += 100
	Date& operator-=(int day); // d1 += 100
	Date operator-(int day);

	// Ĭ�ϵ�һ��Ϊǰ�� ++ ������ ++ Ϊ������������һ��������λ����ǰ�ù��ɺ�������
	Date& operator++(); // ++d1
	Date operator++(int); // d1++
	Date& operator--();
	Date operator--(int);
	int operator-(const Date& d); // paln day - today

private:
	int _year;
	int _month;
	int _day;
};