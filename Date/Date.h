#pragma once

#include <iostream>

using namespace std;

class Date
{
	// ��Ԫ
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	// ��Ԫ 1 �꿪ʼ
	Date(int year = 1, int month = 1, int day = 1);
	Date(const Date& d);
	void Print() const;
	int GetMonthDay(int year, int month) const; // ��ȡĳ��ĳ�µ�����
	// ʵ�� > �� < �� == �����ĸ���
	// ������ Date ���������ӣ�������ʵ�ֱȽϣ������������ַ�ʽ
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

	// Ĭ�ϵ�һ��Ϊǰ�� ++ ������ ++ Ϊ������������һ������ռλ����ǰ�ù��ɺ�������
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

// �Ż�Ϊ����
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << '-' << d._month << '-' << d._day << endl;
	return out;
}

inline istream& operator>>(istream& in, Date& d) // d Ҫ���޸ģ����ܼ� const
{
	in >> d._year >> d._month >> d._day;
	return in;
}