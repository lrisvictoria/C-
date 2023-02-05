#include <iostream>

using namespace std;

class Date
{
	friend void operator<<(ostream& out, const Date& d);
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << '-' << _month << '-' << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1(2022, 1, 17);
	cout << d1 << endl;

	return 0;
}