#include "Date.h"

int main()
{
	Date d1;
	Date d2(2023, 2, 3);

	Date d3(2023, 18, 3); // Ӧ�ü��
	Date d4(2022, 2, 29); // �������꣬�Ǵ����
	
	d1.Print();
	d2.Print();
	d3.Print();
	d4.Print();

	return 0;
}