#include <iostream>

using namespace std;

// Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.

//int cnt = 0;
//
//int foo()
//{
//	static int n = 0;
//	++n;
//	return cnt == 0 ? 0 : n;
//}
//
//int main()
//{
//	cout << foo() << endl;
//	cnt++;
//	cout << foo() << endl;
//	cout << foo() << endl;
//
//
//	return 0;
//}

//int integerPower(int x, int y)
//{
//	int res = 1;
//	while (y--)
//	{
//		res *= x;
//	}
//	return res;
//}
//
//int main()
//{
//	int x, y;
//	cin >> x >> y;
//	cout << integerPower(x, y) << endl;
//
//	return 0;
//}

//bool foo(int x, int y)
//{
//	int max = x, min = y;
//	if (max < min)
//	{
//		max = y, min = x;
//	}
//	if (max % min == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	int a, b;
//
//	while (1)
//	{
//		cin >> a >> b;
//		if (foo(a, b))
//		{
//			cout << "yes" << endl;
//			break;
//		}
//		else
//		{
//			cout << "false" << endl;
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

//#include <cmath>
//
//bool isPrime(int x)
//{
//	for (int i = 2; i <= sqrt(x); i++)
//	{
//		if (!(x % i))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int day;
//	cin >> day;
//	if (isPrime(day))
//	{
//		cout << "yes" << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
//
//	return 0;
//}

//#include <string>
//#include <algorithm>
//
//void Reverse(string& str)
//{
//	reverse(str.begin(), str.end());
//}
//
//int main()
//{
//	string num;
//	cin >> num;
//
//	Reverse(num);
//	cout << num;
//
//	return 0;
//}

#include<stdio.h>
int main()
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double x1 = 0.0;
    double x2 = 0.0;
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        double n = (b * b) - (4 * a * c);
        if (a != 0)
        {
            if (n == 0)
            {
                x1 = -b / (2 * a);
                if (b == 0)
                    printf("x1=x2=%.2lf\n", 0);
                else
                    printf("x1=x2=%.2lf\n", x1);
            }
            else if (n > 0)
            {
                x1 = (-b - sqrt(n)) / (2 * a);
                x2 = (-b + sqrt(n)) / (2 * a);
                printf("x1=%.2lf;x2=%.2lf\n", x1, x2);
            }
            else
            {
                double real = -b / (2 * a);
                double dash = sqrt(-n) / (2 * a);
                //dash为负时，对于结果会有两个符号的错误表示
                if (dash < 0)
                    dash = -dash;
                printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n", real, dash, real, dash);
            }
        }
        else
            printf("Not quadratic equation\n");
    }
    return 0;
}