#include "Date.h"

void Test1()
{
	Date d1;
	Date d2(2023, 2, 3);

	if (d1 < d2)
	{
		cout << "d1 < d2" << endl;
	}
	else
	{
		cout << "d1 >= d2" << endl;
	}

	d1 += 100;
	d1.Print();

	Date d3 = d1 + 100;
	d3.Print();
}

void Test2()
{
	Date d1(2023, 2, 3);
	Date d2(2023, 2, 3);

	Date ret1 = d1++; // d1.operator++(&d1, 0/balalabal); // 编译器会自己传占位参数
	Date ret2 = ++d2; // d1.operator++(&d1);

	ret1.Print();
	ret2.Print();

}

void Test3()
{
	Date d1(2023, 1, 18);
	Date d2(2022, 7, 20);

	Date d3 = d2 - 100;
	d1 -= 20;

	d3.Print();
	d1.Print();
}

void Test4()
{
	Date d1(2022, 1, 18);
	d1.Print();
	Date d3 = d1 - -100;
	d3.Print(); 
	d3 += -100;
	d3.Print();
}

void Test5()
{
	Date d1(1900, 1, 1);
	Date d2(2023, 2, 5);

	Date d3(2023, 2, 4);

	cout << (d2 - d3) << endl;
}

int main()
{
	//Test1();
	//Test2();

	// Test4();

	Test5();

	return 0;
}