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

		// 合并置下面的全缺省构造函数
		/*string()
		{
			_size = _capacity = 0;
			_str = new char[1];
			_str[0] = '\0';
		}*/

		// strcpy 可以不改，因为初始化时，遇到 \0 就是停止
		string(const char* str = "") // 缺省参数
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1]; // 开辟空间
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
			return _str; // 返回 _str 的地址
		}
		
		size_t size() const
		{
			return _size;
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size); // 检查越界
			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size); // 检查越界
			return _str[pos];
		}

		void resize(size_t n, char ch = '\0')
		{
			// 删
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else // 增
			{
				reserve(n); // reserve 会自己检查是否需要扩容
				for (size_t i = _size; i < n; i++) // 从之前的 _size 开始，移一直到 n
				{
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}



		void reserve(size_t n) // n 为容量大小
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1]; // 1 给 \0 
				// strcpy(tmp, _str);
				memcpy(tmp, _str, _size + 1); // 拷贝 \0 
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
				int newcapacity =  _size + len; // 至少扩到 _size  + len
				reserve(newcapacity);
			}
			
			// strcpy(_str + _size, str); // 会把 \0 拷贝过去
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

		void insert(size_t pos, size_t n, char ch) // pos 位置 n 个字符
		{
			assert(pos <= _size); // 断言
			if (_size + n > _capacity)
			{
				int newcapacity = _size + n; // 至少扩容到 _size + n 
				reserve(newcapacity);
			}
			// 挪动数据
			// plan 1
			size_t end = _size;
			while (end >= pos && end != npos) // 一直挪到 pos，判断是否等于 npos
			{
				_str[end + n] = _str[end];
				--end;
			}
			for (size_t i = pos; i < n + pos; i++)
			{
				_str[i] = ch;
			}
			
			// plan2: 将 end 位置改变
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
			return npos; // 没找到
		}


		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str); // 在 _str 中查找 str
			if (ptr)
			{
				return ptr - _str; // 指针 - 指针，无论 pos 在哪里，都是显示的整体位置
			}
			else
			{
				return npos;
			}
		}

		
		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			size_t n = len; // 取 len 个字符
			if (len == npos || len + pos >= _size) // 直接截完
			{
				n = _size - pos; // 实际长度
			}
			
			string tmp;
			tmp.reserve(n); // 开好空间
			for (size_t i = pos; i < n + pos; i++) 
			{
				tmp += _str[i];
			}
			return tmp; // 返回需要拷贝构造
		}

		// 拷贝构造，深拷贝 传统写法
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	// strcpy(_str, s._str);
		//	memcpy(_str, s._str, s._size + 1); // 需要完整拷贝
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}

		// 现代写法
		// 缺点：无法解决 += '\0' 的情况
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str); // 构造函数调用
			swap(tmp);
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		
		// 自己写
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
		
		// 复用
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

		// 赋值重载 传统写法
		//string& operator=(const string& s)
		//{
		//	// 防止自己给自己赋值
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

		// 现代写法 part 1
		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s); // 拷贝构造 s
		//		std::swap(_str, tmp._str); // 改变指向
		//		std::swap(_size, tmp._size);
		//		std::swap(_capacity, tmp._capacity);

		//		// err
		//		// std::swap(*this, tmp); // 无限递归调用赋值
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
		//		swap(tmp); // 调换 _str 和 tmp
		//	}
		//	return *this;
		//}

		// 现代写法 part 2
		string& operator=(string tmp) // 拷贝构造 tmp ，交换 tmp h和 _str
		{
			swap(tmp);
			return *this;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		// static size_t npos;
		// const static size_t npos = -1; // right，但是不建议这么写
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

