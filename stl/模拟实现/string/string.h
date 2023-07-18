#pragma once

#include <assert.h>


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

		// strcpy ���Բ��ģ���Ϊ��ʼ��ʱ������ \0 ����ֹͣ
		string(const char* str = "") // ȱʡ����
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1]; // ���ٿռ�
			// strcpy(_str, str);
			memcpy(_str, str, _size + 1);
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = _capacity = 0;
			}
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

		void resize(size_t n, char ch = '\0')
		{
			// ɾ
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else // ��
			{
				reserve(n); // reserve ���Լ�����Ƿ���Ҫ����
				for (size_t i = _size; i < n; i++) // ��֮ǰ�� _size ��ʼ����һֱ�� n
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}



		void reserve(size_t n) // n Ϊ������С
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // 1 �� \0 
				// strcpy(tmp, _str);
				memcpy(tmp, _str, _size + 1); // ���� \0 
				delete[] _str;
				_str = tmp;
				_capacity = n;
				cout << "reserve -> " << _capacity << endl;
			}
		}

		void push_back(char ch)
		{
			if (_size + 1 > _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : (2 * _capacity);
				reserve(newcapacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				int newcapacity =  _size + len; // �������� _size  + len
				reserve(newcapacity);
			}
			
			// strcpy(_str + _size, str); // ��� \0 ������ȥ
			memcpy(_str + _size, str, len + 1); 
			_size += len;
		}
		
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

		void insert(size_t pos, size_t n, char ch) // pos λ�� n ���ַ�
		{
			assert(pos <= _size); // ����
			if (_size + n > _capacity)
			{
				int newcapacity = _size + n; // �������ݵ� _size + n 
				reserve(newcapacity);
			}
			// Ų������
			// plan 1
			size_t end = _size;
			while (end >= pos && end != npos) // һֱŲ�� pos���ж��Ƿ���� npos
			{
				_str[end + n] = _str[end];
				--end;
			}
			for (size_t i = pos; i < n + pos; i++)
			{
				_str[i] = ch;
			}
			
			// plan2: �� end λ�øı�
			/*size_t end = _size + n;
			while (end > pos)
			{
				_str[end] = _str[end - n];
				--end;
			}
			for (size_t i = pos; i < n + pos; i++)
			{
				_str[i] = ch;
			}
			*/

			_size += n;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				int newcapacity = _size + len;
				reserve(newcapacity);
			}

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}

			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t  end = pos + len;
				while (end <= _size)
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}
		

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			} 
			return npos; // û�ҵ�
		}


		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str); // �� _str �в��� str
			if (ptr)
			{
				return ptr - _str; // ָ�� - ָ�룬���� pos �����������ʾ������λ��
			}
			else
			{
				return npos;
			}
		}

		
		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			size_t n = len; // ȡ len ���ַ�
			if (len == npos || len + pos >= _size) // ֱ�ӽ���
			{
				n = _size - pos; // ʵ�ʳ���
			}
			
			string tmp;
			tmp.reserve(n); // ���ÿռ�
			for (size_t i = pos; i < n + pos; i++) 
			{
				tmp += _str[i];
			}
			return tmp; // ������Ҫ��������
		}

		// �������죬��� ��ͳд��
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	// strcpy(_str, s._str);
		//	memcpy(_str, s._str, s._size + 1); // ��Ҫ��������
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}

		// �ִ�д��
		// ȱ�㣺�޷���� += '\0' �����
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str); // ���캯������
			swap(tmp);
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		
		// �Լ�д
		//bool operator<(const string& s)
		//{
		//	size_t i1 = 0, i2 = 0;
		//	while (i1 < _size && i2 < s._size)
		//	{
		//		if (_str[i1] < _str[i2])
		//		{
		//			return true;
		//		}
		//		else if (_str[i1] > s._str[i2])
		//		{
		//			return false;
		//		}
		//		else
		//		{
		//			i1++, i2++;
		//		}
		//	}

		//	// hello hello
		//	// helloxx hello
		//	// hello helloxx
		//	return i1 == _size && i2 != s._size;
		//	return _size < s._size;
		//}
		
		// ����
		bool operator<(const string& s) const
		{
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			return ret == 0 ? _size < s._size : ret < 0;
		}

		bool operator==(const string& s) const
		{
			return _size == s._size && memcmp(_str, s._str, _size) == 0;
		}

		bool operator<=(const string& s) const
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s) const
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s) const
		{
			return !(*this < s);
		}

		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		// ��ֵ���� ��ͳд��
		//string& operator=(const string& s)
		//{
		//	// ��ֹ�Լ����Լ���ֵ
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		memcpy(tmp, s._str, s._capacity + 1);
		//		delete[] _str;

		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}

		//	return *this;
		//}

		// �ִ�д�� part 1
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s); // �������� s
		//		std::swap(_str, tmp._str); // �ı�ָ��
		//		std::swap(_size, tmp._size);
		//		std::swap(_capacity, tmp._capacity);

		//		// err
		//		// std::swap(*this, tmp); // ���޵ݹ���ø�ֵ
		//	}
		//	return *this;
		//}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(tmp); // ���� _str �� tmp
		//	}
		//	return *this;
		//}

		// �ִ�д�� part 2
		string& operator=(string tmp) // �������� tmp ������ tmp h�� _str
		{
			swap(tmp);
			return *this;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		// static size_t npos;
		// const static size_t npos = -1; // right�����ǲ�������ôд
		// const static double x = 1.1; // error
		// const static long y = 1; // right

	public:
		const static size_t npos;
	};
	const size_t string::npos = -1;
	// size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		/*for (size_t i = 0; i < s.size(); i++)
		{
			out << s[i];
		}*/

		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}

		char buf[128];
		int i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buf[i++] = ch;
			if (i == 127)
			{
				buf[i] = '\0';
				s += buf;
				i = 0;
			}
			ch = in.get();
		}
		if (i != 0)
		{
			buf[i] = '\0';
			s += buf;
		}

		return in;
	}
};

