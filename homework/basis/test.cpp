#include <iostream>

using namespace std;


// 1) Write a prorogram that prints the ASCII value of a character
//int main()
//{
//	char ch;
//	cin >> ch;
//	cout << ch << endl;
//
//	return 0;
//}

// 2) Write a program that uses a while to sum the numbers from 50 to 100
//int main()
//{
//	int sum = 0;
//	for (int i = 50; i <= 100; i++)
//	{
//		sum += i;
//	}
//
//	cout << sum << endl;
//
//	return 0;
//}

// 3) Write a program to swap the values of two ints.
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	Swap(a, b);
//
//	cout << a << ' ' << b << endl;
//
//	return 0;
//}

// 4) Write a program that displays all Factors of a Number

//int main()
//{
//	int num;
//	cin >> num;
//
//	for (int i = 1; i < num; i++)
//	{
//		if (!(num % i))
//		{
//			cout << i << endl;
//		}
//	}
//
//	return 0;
//}

// 5) Write a program to make a simple calculator to add, subtract, multiply or divide using switch...case

//int main()
//{
//	
//	int l, r;
//	char ch;
//	cin >> ch >> l >> r;
//	switch (ch)
//	{
//	case '+':
//		cout << (l + r) << endl;
//		break;
//	case '-':
//		cout << (l - r) << endl;
//		break;
//	case '*':
//		cout << (l * r) << endl;
//		break;
//	case '/':
//		cout << (l / r) << endl;
//		break;
//	}
//
//	return 0;
//}

// 6) Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

//int main()
//{
//	int l, r;
//	cin >> l >> r;
//	for (int i = l; i <= r; i++)
//	{
//		cout << i << ' ';
//	}
//
//	return 0;
//}

//7) Show that the following definitions are illegal, explain what¡¯s wrongand how to correct it.
//a.std::cin >> int input_value; -- > std::cin >> input_value;
//b. int i = { 3.14 }; -- > double i = 3.14;
//c. double salary = wage = 9999.99; -- > double salary, wage; salary = wage = 9999.99;
//d. int i = 3.14; -- > double i = 3.14;

// 8) Write a program to reverse an integer.
//#include <algorithm>
//int main()
//{
//	string s;
//	cin >> s;
//
//	reverse(s.begin(), s.end());
//
//	cout << s << endl;
//
//	return 0;
//}

// 9)

//int main()
//{
//	int num;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			cout << '*' << ' ';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	int num;
//	cin >> num;
//	for (int i = num - 1; i >= 0; i--)
//	{
//		for (int j = i; j >= 0; j--)
//		{
//			cout << '*' << ' ';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	int num = 0, cnt;
//	cin >> num;
//
//	cnt = num;
//	for (int i = 0; i < num; i++)
//	{
//		for (int j = num - 1; j > i; j--)
//		{
//			cout << ' ';
//		}
//		for (int j = 0; j < 2 * i + 1; j++)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	cin >> num;
//
//	for (int i = num - 1; i >= 0; i--)
//	{
//		for (int j = num - 1; j > i; j--)
//		{
//			cout << ' ';
//		}
//		for (int j = 2 * i + 1; j > 0; j--)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

#include <iomanip>
#define N 10

int main()
{
	int arr[N][N] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)//ÐÐ
	{
		for (j = 0; j < N - i; j++)
		{
			cout << ' ';
		}
		for (j = 0; j <= i; j++)
		{
			if ((j == 0) || (j == i))
			{
				arr[i][j] = 1;
			}
			else 
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
			cout << fixed << setprecision(2) << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}