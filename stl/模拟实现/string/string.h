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
//		// ��һ���ַ��������ռ䣬�����ݿ�������
//		string(const char* str)
//			:_str(new char[strlen(str) + 1]) // һ���� \0 
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
//		// ��ֵ����
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
		// ������
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

		// const ������

		//string() // Ĭ��
		//	:_str(new char[1])
		//	, _size(0)
		//	, _capacity(0)
		//{
		//	_str[0] = '\0';
		//}
		// ��һ���ַ��������ռ䣬�����ݿ�������
		string(const char* str = "") // Ĭ�Ϻ��� \0 
			:_size(strlen(str)) // strlen Ĭ�������ߣ������ã����ܸ� nullptr
			, _capacity(_size) // ���� \0 �ռ�
		{
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// ��ͳд���������ַ�������
		// s2(s1)
		/*string(const string& s)
			:_size(s._size)
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}*/
		
		// ��Լ��
		// �ִ�д�� -- ȡ��
		/*string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			std::swap(_str, tmp._str);
		}*/

		// ���ڵ��ù��࣬�����Լ�дһ�� swap ��������
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		// �������ִ�д��
		string(const string& s)
			:_str(nullptr)
			, _capacity(0)
			, _size(0)
		{
			string tmp(s._str);
			this->swap(tmp);
		}

		// ��ֵ����
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

		// �Ľ�
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
		
		// ��Լ��
		// �ִ�д��
		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				std::swap(_str, tmp._str);
			}
			return *this;
		}*/

		// ����
		/*string& operator=(string s)
		{
			std::swap(_str, s._str);
			return *this;
		}*/

		// �������ִ�д��
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

		// c_str string �׵�ַ
		const char* c_str() const
		{
			return _str;
		}

		// ���ش�С
		size_t size() const
		{
			return _size;
		}

		// [] ����
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		// const [] ���� & Ϊ�˼��ٿ���
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		// �ı�����
		void reserve(size_t n)
		{
			// �� capacity �������
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // ��һ�� \0 
				strcpy(tmp, _str);
				delete[] _str;
				
				_str = tmp;
				_capacity = n;
			}
		}

		// β��
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch; // ���ַ�
			++_size;
			_str[_size] = '\0'; // �� \0
		}

		void append(const char* str)  
		{
			size_t len = strlen(str);
			if (_size + len > _capacity) // ���ռ��Ƿ��㹻
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str); // �� _str �������ַ����ոյ�ĩβλ��
			_size += len; // �� size ����
		}

		// ����
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
		int _capacity; // ��Ч�ַ��ռ�
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

		// ����֮���滻Ϊ������
		// ���� begin ����ĸ�ĵ�����Χ for ���ò�����
		// ���յ������̶�ģʽ�滻�ģ��Լ�ʵ�ַ�Χ for �Ͳ�֧��

		for (auto e : s1)
		{
			std::cout << e << ' ';
		}

		// ���������滻Ϊ������
		// ���Ծͺ͵�����������û�й�ϵ��
		// ���дɶ���� auto �Ƶ�
		// �ĵ�������������û����
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