#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <string>
using namespace std;


#include "string.h"

void test_string1()
{
	anduin::string s1("hello world");
	anduin::string s2; // 有默认构造（带缺省）

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
	anduin::string s1("hello world");
	anduin::string::iterator it = s1.begin();
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

	const anduin::string s2("hello anduin");
	anduin::string::const_iterator it2= s2.begin();
	s2[0];
}

void test_string3()
{
	anduin::string s1("hello world");
	s1.push_back('0');

	cout << s1.c_str() << endl;

	s1.append("hello");
	cout << s1.c_str() << endl;

	s1 += '#';
	cout << s1.c_str() << endl;
	s1 += "hello";
	cout << s1.c_str() << endl;

}

void test_string4()
{
	anduin::string s1("hello world");
	s1.insert(6, 3, '0');
	cout << s1.c_str() << endl;

	/*s1.insert(0, 3, '0');
	cout << s1.c_str() << endl;

	s1.insert(5, "hello hello");
	cout << s1.c_str() << endl;*/
}

void test_string5()
{
	anduin::string s1("hello world");
	s1.erase(6, 3);
	cout << s1.c_str() << endl;

	s1.erase(2);
	cout << s1.c_str() << endl;

}

void test_string6()
{
	anduin::string s1("hello world");
	cout << s1.find('o', 6) << endl;
	cout << s1.find('o') << endl;

	cout << (int)s1.find("hel", 6) << endl;
	cout << s1.find("hel") << endl;

	cout << (s1.substr(1, 3)).c_str() << endl;
	cout << (s1.substr(1)).c_str() << endl;
}

void test_string7()
{
	anduin::string s1("hello world");
	/*s1.resize(8);
	s1.resize(13, 'x');
	s1.resize(20, 'y');*/

	s1 += '\0';
	s1 += "hello";

	cout << s1.c_str() << endl; // 打印 c 字符串，遇到 \0 就停止
	cout << s1 << endl; // 都会打印

	anduin::string s2(s1);
	cout << s2 << endl;
}

void test_string8()
{
	anduin::string s1;
	cin >> s1;
	cout << s1 << endl;

	cin >> s1;
	cout << s1;
}

void test_string9()
{
	anduin::string s1("hello");
	anduin::string s2("xxxxxxxxxxxxxxxxx");

	s1 = s2;
	cout << s1 << endl;
	cout << s2 << endl;

	cout << "******************" << endl;
	string s3("hello world");
	cout << sizeof(s3) << endl;
}

int main()
{
	//// test_string3();
	//// test_string2();

	//// test_string6();
	//

	///*char str[100];
	//scanf("%s", str);
	//printf("%s", str);*/
	//// test_string8();

	//anduin::string s1("hello");
	//anduin::string s2("hello");

	//cout << (s1 < s2) << endl;
	//cout << (s1 == s2) << endl;

	//anduin::string s3("hello");
	//anduin::string s4("helloxx");
	//cout << (s3 < s4) << endl;
	//cout << (s3 > s4) << endl;

	//
	//anduin::string s5("helloxxxx");
	//anduin::string s6("hello");
	//cout << (s5 < s6) << endl;
	//cout << (s5 > s6) << endl;

	//// test_string9();

	//anduin::string s7("hello world");
	//anduin::string s8(s7); // 拷贝构造

	//cout << s8 << endl;

	//s7 += '\0';
	//s7 += "AAAAAAAAA";

	//anduin::string s9(s7);
	//cout << s9 << endl;

	test_string4();

	return 0;
}

