#include <iostream>

using namespace std;

template<class T>

class basic_string
{
private:
	T* _str;
	// ... 
};

// typedef basic_string<char> string;

//int main()
//{
//	// string s("hello");
//
//	char str1[] = "������";
//	str1[1] += 1;
//	str1[2] += 1;
//
//	cout << sizeof(wchar_t) << endl;
//
//	return 0;
//}

//int main()
//{
//	string s2 = "hello";
//	cout << s2 << endl;
//	
//	string s3 = s2; // ��������
//	cout << s3 << endl;
//
//
//	string s4(s2, 2, 6);
//	cout << s4 << endl;
//
//	string s5(s2, 2, 100);
//	cout << s5 << endl;
//
//	string s6(s2, 0);
//	cout << s6 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1;
//
//	/*cout << s1.size() << endl;
//	cout << s1.length() << endl;*/
//
//	cout << s1.capacity() << endl;
//
//	printf("%x", s1.capacity());
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s1.size(); ++i)
//	{
//		s1[i] += 1;
//		cout << s1[i] << " ";
//	}
//
//	s1.at(100);
//
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	cout << s1.capacity() << endl;
//	s1.clear();
//	cout << s1.capacity() << endl;
//
//	cout << s1 << endl;
//}

void test_str1()
{
	string s1("hello");
	/*for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i] += 1;
	}

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << ' ';
	}*/

	/*string::iterator it = s1.begin();
	while (it != s1.end())
	{
		*it += 1;
		cout << *it << ' ';
		++it;
	}
	cout << endl;*/

	for (auto& e : s1)
	{
		e += 1;
		cout << e << ' ';
	}
}

void test_str2()
{
	string s1("hello world");
	/*string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		*rit += 1;
		cout << *rit << ' ';
		++rit;
	}*/

	//string::iterator it = s1.end() - 1;
	//while (it != s1.begin())
	//{
	//	// *it += 1;
	//	cout << *it << ' ';
	//	--it;
	//}
	//cout << *(s1.begin());
	//cout << endl;

	string cstr("hello world");
	string::const_iterator cit = cstr.begin();
	while (cit != cstr.end())
	{
		// *cit += 1;
		cout << *cit << ' ';
		++cit;
	}

}


void test_capacitygrow()
{
	string s;
	s.reserve(1000);
	size_t  sz = s.capacity();
	cout << "capacity : " << sz << endl;
	cout << "grow: " << endl;
	for (int i = 0; i < 1000; i++)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed : " << sz << endl;
		}
	}
}

void test_str3()
{
	string s1("hello");
	string s2("hello");

	s1.reserve(3);
	s2.resize(3);

}

void test_str4()
{
	string s("hello");
	cout << s << endl; // ���������������
	cout << s.c_str() << endl; // char*
}

void test_str5()
{
	/*string file("test.txt.zip");
	size_t pos = file.rfind(".");
	if (pos != string::npos)
	{
		string suf = file.substr(pos);
		cout << suf << endl;
	}*/

	// ȡ�� url �е�ÿһ����
	// http Э�� + �м���������legacy.cplusplus.com + Ψһ��Դ��λ
	string url("https://legacy.cplusplus.com/reference/string/string/?kw=string");
	
	// ȡ��Э��
	size_t pos1 = url.find(':');
	string pro = url.substr(0, pos1 - 0);
	cout << pro << endl;
	
	// ȡ������
	size_t pos2 = url.find('/', pos1 + 3);
	string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
	cout << domain << endl;

	// ȡ����Դ��λ
	size_t pos3 = pos2 + 1;
	string uri = url.substr(pos3);
	cout << uri << endl;
}
void test_str6()
{
	string s("hello");

	// ͷ�� 0(N) Ч�ʵͣ�����
	s.insert(0, 1, 'x'); // �±�
	cout << s << endl;
	s.insert(s.begin(), 'y'); // ������
	cout << s << endl;
	s.insert(0, "test"); // �����ַ���
	cout << s << endl;

	// �м�λ�ò���
	s.insert(4, "&&&&&");
	cout << s << endl;
}

void test_str7()
{
	string s("hello");

	// ͷɾβɾ
	// ��������ͷ�����м��ɾ������ΪҪŲ�����ݣ�Ч�ʵ�

	s.erase(0, 1); // ɾͷ��һ���ַ�
	cout << s << endl;
	s.erase(s.size() - 1, 1);
	cout << s << endl;
	s.erase(2);
	cout << s << endl;
}

int main()
{
	// test_str1();
	// test_str2();

	// test_capacitygrow();

	test_str7();

	return 0;
}