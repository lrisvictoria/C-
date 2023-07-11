#pragma once

#include <cassert>

namespace lx
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size(); // 先拷贝，否则计算 _finish 时，最后结果仍为上一次结果
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sz * sizeof(T));
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz; // 由于 _start 改变，所以 _finish 也需要改变
				_endofstorage = _start + n;
			}
		}

		// 加上 T，T 为模板，为了节省效率
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			// 不是定位 new ，所以可以直接复制
			*_finish = x;
			++_finish;

			// insert(end(), x);
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);

			if (_finish == _endofstorage)
			{
				size_t len = pos - _start; // 记录原先 pos 的长短

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);

				// 解决pos迭代器失效问题
				pos = _start + len; // 让开始位置加上 len
			}

			iterator end = _finish - 1; // 不用移动 \0
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;

			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void print(const vector<int>& v)
	{
		// 会报错
		for (auto e : v)
		{
			cout << e << ' ';
		}
	}

	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		for (auto e : v1)
		{
			cout << e << ' ';
		}

		for (size_t i = 0; i < v1.size(); i++)
		{
			v1[i]++;
		}
		cout << endl;

		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << ' ';
		}
		cout << endl;

		print(v1);
	}

	void test_vector2()
	{
		lx::vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		v1.push_back(5);
		v1.push_back(5);
		// v1.push_back(5);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		// 迭代器失效
		v1.insert(v1.begin(), 100);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		lx::vector<int>::iterator p = v1.begin() + 3;
		p = v1.insert(p, 300);// 接收返回值

		// 外部迭代器失效
		*p += 30;
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;
	}
}