#include "date.h"

void testDate1()
{
	Date d1(2023, 1, 1);
	Date d2(2023, 1, 1);

	d1 += 100;
	d2 += 66;

	d1.Print();
	d2.Print();

	Date ret1 = d1.operator++(0);
	Date ret2 = d2++;

	ret1.Print();
	ret2.Print();

	d1.Print();
	d2.Print();

	cout << (d2 - d1) << endl;
}

void TestDate2()
{
	Date d1(2023, 5, 5);
	d1 += 100;

	// cout << d1;
	d1 << cout;
	d1.operator<<(cout);
}

int main()
{
	/*Date d1(2023, 1, 1);
	cout << d1.GetMonthDay(2023, 1) << endl;

	Date d2;
	d2 = d1;

	d2.Print();

	d1 = d2;*/

	TestDate2();

	return 0;
}