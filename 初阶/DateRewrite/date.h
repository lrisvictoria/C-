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
	void Print() const; // const ���� *this

	bool operator<(const Date& d) const;
	Date& operator=(const Date& d); // ��ֵ����
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
	
	// ��Ϊ Date ����Ĭ��ռ�õ�һ������������Ϊ�����������
	// д����һ��������������������ʹ��ϰ��
	// д����Ԫ����
	// void operator<<(ostream& out);
private:
	int _year;
	int _month;
	int _day;
};



/*
public:
  // ����+=����

Date& operator+=(int day);
  // ����+����

Date operator+(int day);
  // ����-����

Date operator-(int day);
   // ����-=����

Date& operator-=(int day);
  // ǰ��++

Date& operator++();
  // ����++

Date operator++(int);
  // ����--

Date operator--(int);
  // ǰ��--

Date& operator--();
  // ����-���� ��������

int operator-(const Date& d);

private:

int _year;

int _month;

int _day;

};
*/