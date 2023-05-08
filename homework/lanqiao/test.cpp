//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//
//	int day1, day2;
//	cin >> day1 >> day2;
//
//	int sum = day1 + day2;
//	cout << (sum % 7) << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a[] = { 99, 22, 51, 63, 72, 61, 20, 88, 40, 21, 63, 30, 11, 18, 99, 12, 93, 16, 7, 53, 64, 9, 28, 84, 34, 96, 52, 82, 51, 77 };
//	long long res = 0;
//	int cnt = 0;
//	for (int i = 0; i < 30; i++)
//	{
//		for (int j = 0; j < 30; j++)
//		{
//			if (a[i] * a[j] > 2022)
//			{
//				cnt++;
//			}
//		}
//	}
//
//	cout << cnt / 2 << endl;
//	return 0;
//}


//#include <iostream>
//
//using namespace std;

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a[] = { 0, 1, 2, 3, 4, 5 };
//
//	int sum = 0;
//	for (int i = 0; i < 6; i++)
//	{
//		sum += a[i];
//	}
//
//	cout << sum / 6.0 << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int a[] = { 0, 1, 2, 3, 4, 5 };
//
//	int max = -1;
//	for (int i = 0; i < 6; i++)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//	}
//
//	cout << max << endl;
//
//	return 0;
//}

//include <iostream>

//using namespace std;
//
//int main()
//{
//	int a1[3][3] = { 0 }, a2[3][3] = { 0 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cin >> a1[i][j];
//			cin >> a2[i][j];
//		}
//	}
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << a1[i][j] - a2[i][j] << ' ';
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

// 

//#include <iostream>
//
//using namespace std;
//
//enum CMSC
//{
//	StdD1,
//	StdD2,
//	StdD3
//};
//
//int main()
//{
//	enum CMSC a;
//
//	cout << StdD1 << StdD2 << StdD3 << endl;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//	Date(int* a = nullptr, int year = 0, int month = 1, int day = 1)
//	{
//		_a = a;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		cout << "Îö¹¹" << endl;
//		_a = nullptr;
//	}
//
//private:
//	int* _a;
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1((int*)0x11223344);
//	Date d2;
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//void cutdown(int num)
//{
//	if (num == 0)
//	{
//		return;
//	}
//	cout << num << endl;
//	cutdown(num - 1);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cutdown(n);
//
//	return 0;
//}

//#include <iostream>
//#include <climits>
//
//using namespace std;
//
//template<class T>
//
//int findMin(const T& arr)
//{
//	int minNum = INT_MAX;
//	for (auto e : arr)
//	{
//		if (e < minNum)
//		{
//			minNum = e;
//		}
//	}
//	return minNum;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	cout << findMin(arr);
//
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//template<class T>
//
//int findMax(const T& num1, const T& num2)
//{
//	if (num1 > num2)
//	{
//		return num1;
//	}
//	else
//	{
//		return num2;
//	}
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//
//	cout << findMax(a, b);
//
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//
//void insertSort(int arr[], int n)
//{
//	if (n == 1)
//	{
//		return;
//	}
//
//	insertSort(arr, n - 1);
//	int last = arr[n - 1];
//	int j = n - 2;
//
//	while (j >= 0 && last < arr[j]) 
//	{
//		arr[j + 1] = arr[j];
//		j--;
//	}
//	arr[j + 1] = last;
//}
//
//int main()
//{
//	int arr[] = { 7, 1, 3, 4, 2, 6, 5, 9, 8 };
//
//	insertSort(arr, 9);
//
//	for (int i = 0; i < 9; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	
//	cout << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//void bubbleSort(string arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - j; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				swap(arr[j], arr[j + 1]);
//			}
//		}
//	}
//}
//
//int main()
//{
//	string arr[] = { "Anduin", "eric", "chovy" };
//	bubbleSort(arr, 3);
//
//	for (int i = 0; i < 3; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//
//	return 0;
//}

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[] = { 10, 2, 4, 30, 35 };
	int n = 5;
	int flag = 0;

	for (int i = 0; i < n; i++)
	{
		int* tmp = (int*)malloc(sizeof(int) * (n - 1));
		int e = arr[i];
		tmp[i] = e;
		for (int k = 0; k < 5; k++)
		{
			tmp[k] = e * arr[i];
		}
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				if (tmp[j] == arr[j])
				{
					cout << tmp[j] << endl;
					return 0;
				}
			}
		}
	}

	if (!flag)
	{
		cout << -1 << endl;
	}

	return 0;
}