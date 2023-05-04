#include "date.h"

int main()
{
	Date d1(2023, 1, 1);
	cout << d1.GetMonthDay(2023, 1) << endl;

	Date d2;
	d2 = d1;

	d2.Print();

	d1 = d2;

	return 0;
}