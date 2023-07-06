#define _CRT_SECURE_NO_WARNINGS 1 

#include "string.h"

using namespace anduin;

void test_string1()
{
	string s1("hello world");
	string s2; // 有默认构造（带缺省）

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;

	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << ' ';
	}
	cout << endl;
}

void test_string2()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it += 1;
		cout << *it << ' ';
		it++;
	}
	cout << endl;

	for (auto& e : s1)
	{
		e -= 1;
		cout << e << ' ';
	}

	const string s2("hello anduin");
	string::const_iterator it2= s2.begin();
	s2[0];
}

int main()
{
	// test_string1();
	test_string2();
	return 0;
}