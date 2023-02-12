#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>

//namespace anduin
//{
//	class string
//	{
//	public:
//		// 给一个字符串，开空间，将数据拷贝过来
//		string(const char* str)
//			:_str(new char[strlen(str) + 1]) // 一个给 \0 
//		{
//			strcpy(_str, str);
//		}
//		
//		// s2(s1)
//		string(const string& s)
//			:_str(new char[strlen(s._str) + 1])
//		{
//			strcpy(_str, s._str);
//		}
//
//		// 赋值重载
//		/*string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				delete[] _str;
//				_str = new char[strlen(s._str) + 1];
//				strcpy(_str, s._str);
//			}
//			return *this;
//		}*/
//
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				char* tmp = new char[strlen(s._str) + 1];
//				strcpy(tmp, s._str);
//				delete[] _str;
//				_str = tmp;
//			}
//			return *this;
//		}
//
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//	private:
//		char* _str;
//	};
//
//	void test_string1()
//	{
//		string s1("hello world");
//		string s2(s1);
//		string s3("cat");
//		s1 = s3;
//	}
//}

namespace anduin
{
	class string
	{
	public:
		// 迭代器
		typedef char* iterator;
		typedef const char* iterator;
		
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const iterator begin() const
		{
			return _str;
		}

		const iterator end() const
		{
			return _str + _size;
		}

		// const 迭代器

		//string() // 默认
		//	:_str(new char[1])
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	_str[0] = '\0';
		//}
		// 给一个字符串，开空间，将数据拷贝过来
		string(const char* str = "") // 默认含有 \0 
			:_size(strlen(str)) // strlen 默认往后走，解引用，不能给 nullptr
			, _capacity(_size) // 不算 \0 空间
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s2(s1)
		string(const string& s)
			:_size(s._size)
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		// 赋值重载
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}*/

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		// c_str string 首地址
		const char* c_str() const
		{
			return _str;
		}

		// 返回大小
		size_t size() const
		{
			return _size;
		}

		// [] 重载
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// const [] 重载 & 为了减少拷贝
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		// 尾插
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				// 增容
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{

		}

		string& operator+=(char ch)
		{

		}



	private:
		char* _str;
		int _size;
		int _capacity; // 有效字符空间
	};

	void test_string1()
	{
		string s1("hello world");
		string s2(s1);
		string s3("cat");
		const string s4("hello world");
		// s1 = s3;
		s3 = s3;

		s1[0] = 'x';
		std:: cout << s1.c_str() << std::endl;;

		for (size_t i = 0; i < s1.size(); i++)
		{
			std::cout << s1[i] << ' ';
		}
		std::cout << std::endl;
	
		for (size_t i = 0; i < s4.size(); i++)
		{
			std::cout << s4[i] << ' ';
		}
		std::cout << std::endl;

		string::iterator it = s1.begin();

		while (it != s1.end())
		{
			std::cout << *it << ' ';
			++it;
		}
		std::cout << std::endl;

		// 编译之后被替换为迭代器
		// 当吧 begin 的字母改掉，范围 for 就用不了了
		// 按照迭代器固定模式替换的，自己实现范围 for 就不支持
		for (auto e : s1)
		{
			std::cout << e << ' ';
		}
	} 
}