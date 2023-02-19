#include <iostream>
#include <string>

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
//	char str1[] = "吃了吗";
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
//	string s3 = s2; // 拷贝构造
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
	cout << s << endl; // 流插入运算符重载
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

	// 取出 url 中的每一部分
	// http 协议 + 中间是域名：legacy.cplusplus.com + 唯一资源定位
	string url("https://legacy.cplusplus.com/reference/string/string/?kw=string");
	
	// 取出协议
	size_t pos1 = url.find(':');
	string pro = url.substr(0, pos1 - 0);
	cout << pro << endl;
	
	// 取出域名
	size_t pos2 = url.find('/', pos1 + 3);
	string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
	cout << domain << endl;

	// 取出资源定位
	size_t pos3 = pos2 + 1;
	string uri = url.substr(pos3);
	cout << uri << endl;
}
void test_str6()
{
	string s("hello");

	// 头插 0(N) 效率低，少用
	s.insert(0, 1, 'x'); // 下标
	cout << s << endl;
	s.insert(s.begin(), 'y'); // 迭代器
	cout << s << endl;
	s.insert(0, "test"); // 插入字符串
	cout << s << endl;

	// 中间位置插入
	s.insert(4, "&&&&&");
	cout << s << endl;
}

void test_str7()
{
	string s("hello");

	// 头删尾删
	// 尽量少用头部和中间的删除，因为要挪动数据，效率低

	s.erase(0, 1); // 删头部一个字符
	cout << s << endl;
	s.erase(s.size() - 1, 1);
	cout << s << endl;
	s.erase(2);
	cout << s << endl;
}


//int main()
//{
//	// test_str1();
//	// test_str2();
//
//	// test_capacitygrow();
//
//	// test_str7();
//
//	//string s1;
//	// 
//	//char ch = cin.get();
//	//while (ch != '\n')
//	//{
//	//	s1 += ch;
//	//	ch = cin.get(); // cin 的成员函数，一个字符一个字符拿
//	//}
//
//	//cout << s1 << endl;
//	
//	string s;
//	getline(cin, s);
//
//	cout << s << endl;
//
//	return 0;
//}

//int main()
//{
//	string a = "hello world";
//
//	string b = a;
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	string c = b;
//
//	c = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str())
//
//	{
//
//		cout << "true" << endl;
//
//	}
//
//	else cout << "false" << endl;
//
//	return 0;
//
//}

//int main(int argc, char* argv[])
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//	int size_pos = 0;
//	int size_prev_pos = 0;
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//		size_prev_pos = ++size_pos;
//
//	}
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//
//}

//int main()
//
//{
//
//	string s1 = "hello world";
//
//	string s2 = "change world";
//
//	string::iterator it = s1.begin();
//
//	swap(s1, s2);
//
//	while (it != s1.end())
//
//		cout << *it;
//
//	cout << endl;
//
//}

//#include <climits>
//
//class Solution {
//public:
//	typedef long long ll;
//	int StrToInt(string str) {
//		ll res = 0, k = 0;
//		while (k < str.size() && str[k] == ' ') {
//			k++;
//		}
//		int minus = 1;
//		if (k < str.size() && str[k] == '-') {
//			minus = -1;
//			k++;
//		}
//		else if (k < str.size() && str[k] == '+') {
//			k++;
//		}
//
//		while (k < str.size() && (str[k] >= '0' && str[k] <= '9')) {
//			res = res * 10 + str[k] - '0';
//			k++;
//			if (res > INT_MAX || !(str[k] >= '0' && str[k] <= '9')) {
//				return 0;
//			}
//		}
//		res *= minus;
//		return res;
//	}
//};
//
//int main()
//{
//	Solution foo;
//	string s;
//	cin >> s;
//	cout << foo.StrToInt(s) << endl;
//}

//int main()
//{
//	string s1("hello world"), s2("string");
//	cout << (s1 < s2) << endl;
//	cout << ("hhh" < s2) << endl;
//
//	return 0;
//}

//int main()
//{
//	string a("+123456");
//	cout << stoi(a) << endl;
//
//	return 0;
//}

// stoi example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi
//
//int main()
//{
//	std::string str_dec = "2001, A Space Odyssey";
//	std::string str_hex = "40c3";
//	std::string str_bin = "-10010110001";
//	std::string str_auto = "0x7f";
//
//	std::string::size_type sz;   // alias of size_t
//
//	int i_dec = std::stoi(str_dec, &sz);
//	int i_hex = std::stoi(str_hex, nullptr, 16);
//	int i_bin = std::stoi(str_bin, nullptr, 2);
//	int i_auto = std::stoi(str_auto, nullptr, 0);
//
//	std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
//	std::cout << str_hex << ": " << i_hex << '\n';
//	std::cout << str_bin << ": " << i_bin << '\n';
//	std::cout << str_auto << ": " << i_auto << '\n';
//
//	return 0;
//}

//int main()
//{
//	int a = 1234;
//	cout << to_string(a) << endl;
//
//	double b = 3.14;
//	cout << to_string(b) << endl;
//
//	return 0;
//}
