#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>

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
		typedef const char* const_iterator;
		
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const const_iterator begin() const
		{
			return _str;
		}

		const const_iterator end() const
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

		// 传统写法，本本分分完成深拷贝
		// s2(s1)
		/*string(const string& s)
			:_size(s._size)
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}*/
		
		// 简约版
		// 现代写法 -- 取巧
		/*string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			std::swap(_str, tmp._str);
		}*/

		// 由于调用过多，所以自己写一个 swap 减少冗余
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// 完整版现代写法
		string(const string& s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string tmp(s._str);
			this->swap(tmp);
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

		// 改进
		/*string& operator=(const string& s)
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
		}*/
		
		// 简约版
		// 现代写法
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				std::swap(_str, tmp._str);
			}
			return *this;
		}*/

		// 升级
		/*string& operator=(string s)
		{
			std::swap(_str, s._str);
			return *this;
		}*/

		// 完整版现代写法
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				this->swap(tmp);
			}
			return *this;
		}

		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
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

		// 改变容量
		void reserve(size_t n)
		{
			// 比 capacity 大就扩容
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // 多一个 \0 
				strcpy(tmp, _str);
				delete[] _str;
				
				_str = tmp;
				_capacity = n;
			}
		}

		// 尾插
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch; // 放字符
			++_size;
			_str[_size] = '\0'; // 填 \0
		}

		void append(const char* str)  
		{
			size_t len = strlen(str);
			if (_size + len > _capacity) // 检查空间是否足够
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str); // 将 _str 拷贝到字符串刚刚的末尾位置
			_size += len; // 让 size 自增
		}

		// 复用
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
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

		// 被编译器替换为这样：
		// 所以就和迭代器的类型没有关系了
		// 随便写啥都是 auto 推导
		// 改迭代器类型名称没问题
		auto it1 = s1.begin();
		while (it1 != s1.end())
		{
			*it1 += 1;
			++it1;
		}
	} 

	void test_string2()
	{
		string s("hello world");
		s.push_back('!');
		s.push_back('@');
		s.append("hello world too !!!");

		s += 'c';
		s += 'h';

		s += "hello hello ";

		string s2("");
		s2 += 'c';

	}
}