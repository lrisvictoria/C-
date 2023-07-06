#pragma once

#include <iostream>
#include <cassert>

using std::cout;
using std::cin;
using std::endl;

namespace anduin
{
	class string
	{
	public:
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

		const iterator begin() const
		{
			return _str;
		}

		const iterator end() const
		{
			return _str + _size;
		}

		// �ϲ��������ȫȱʡ���캯��
		/*string()
		{
			_size = _capacity = 0;
			_str = new char[1];
			_str[0] = '\0';
		}*/

		string(const char* str = "") // ȱʡ����
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1]; // ���ٿռ�
			strcpy(_str, str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str; // ���� _str �ĵ�ַ
		}
		
		size_t size() const
		{
			return _size;
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size); // ���Խ��
			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size); // ���Խ��
			return _str[pos];
		}

		

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

	
}