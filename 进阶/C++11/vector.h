#pragma once

#include <cassert>
//#include "ReverseIterator.h"

namespace lx
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		//typedef ReverseIterator<iterator, const T&, const T*> const_reverse_iterator;


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

		/*reverse_iterator rbegin()
		{
			return end();
		}

		reverse_iterator rend()
		{
			return begin();
		}

		const_reverse_iterator crbegin() const
		{
			return end();
		}

		const_reverse_iterator crend() const
		{
			return begin();
		}*/
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		// 需要使用初始化列表初始化，19初始化了，但是13并没有初始化
		template<class InputIterator>
		vector(InputIterator start, InputIterator last)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			while (start != last)
			{
				push_back(*start);
				++start;
			}
		}

		// 或者复用 resize
		//vector(size_t n, const T& val = T()) // 不初始化会有随机值
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	resize(n, val);
		//}

		// n 个 val 构造
		// 半缺省函数 如果不给值，则默认调用 T 类型的默认构造
		// 所以要提供 T() 的默认构造，否则会报错
		// 这意味着，内置类型，如 int 也要有构造
		// c++有了模板后，则认为对内置类型进行了升级，也需要构造函数
		// 如 int 需要构造函数
		// 为了和自定义类型同步，都需要构造
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); // n 个 val 初始化
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		// 源码中为了解决两个 int 被模板识别的情况，所以设定了重载函数
		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); // n 个 val 初始化
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		// 第一种写法
		//vector(const vector<T>& v)
		//{
		//	_start = new T[v.size()]; // size 和 capacity 都可以
		//	// memcpy(_start, v._start, sizeof(T) * v.size()); // 内置类型可以，自定义类型不可以
		//	for (size_t i = 0; i < v.size(); i++)
		//	{
		//		_start[i] = v._start[i]; // 借助赋值重载进行深拷贝
		//	}
		//	_finish = _start + v.size();
		//	_endofstorage = _start + v.size();
		//}

		// 第二种写法
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	,_finish(nullptr)
		//	,_endofstorage(nullptr)
		//{
		//	reserve(v.size()); // 先初始化，再开空间
		//	for (const auto& e : v) // const auto& & 为了提高效率，加上 const 是因为参数给的是 const vector<T>& v，无法被修改
		//	{
		//		push_back(e);
		//	}
		//}

		// 第三种写法：现代写法
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		// 赋值重载 引用返回
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	vector<T> tmp(v); // 复用拷贝构造
		//	swap(tmp);

		//	return *this;
		//}

		vector<T>& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size(); // 先拷贝，否则计算 _finish 时，最后结果仍为上一次结果
				T* tmp = new T[n];
				if (_start)
				{
					// memcpy(tmp, _start, sz * sizeof(T)); // 当 vector<vector<int>> 时，深拷贝
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i]; // 借助赋值重载进行深拷贝
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz; // 由于 _start 改变，所以 _finish 也需要改变
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}

			// 如果 n 大于原本的 size()
			if (n > size())
			{
				// _start +n 为最后 _finish 应在位置
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n; // 否则删除数据
			}
		}

		// 加上 T，T 为模板，为了节省效率
		void push_back(const T& x)
		{
			//if (_finish == _endofstorage)
			//{
			//	size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
			//	reserve(newcapacity);
			//}

			//// 不是定位 new ，所以可以直接复制
			//*_finish = x;
			//++_finish;

			insert(end(), x);
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
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

			*pos = x; // 调用 string 的赋值重载，完成深拷贝
			++_finish;

			return pos;
		}

		// stl 规定erase 会返回删除数据的下一个位置的迭代器
		// void erase(iterator pos)
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish); // pos != _finish
			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;

			/*if (size() < capacity() / 2)
			{
				size_t len = pos - _start;
				reserve(capacity() / 2);
				pos = _start + len;
			}*/

			return pos;
		}

		T& front()
		{
			assert(size() > 0);
			return *_start;
		}

		T& back()
		{
			assert(size() > 0);
			return *(_finish - 1);
		}

	private:
		iterator _start = nullptr; // 给缺省值，可以减少初始化列表初始化
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
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
		std::vector<int> v1;
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

		std::vector<int>::iterator p = v1.begin() + 3;
		p = v1.insert(p, 300);// 接收返回值

		// 外部迭代器失效
		*p += 30;
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		std::vector<int>::iterator p1 = v1.begin() + 3;
		v1.erase(p1);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		// 外部迭代器失效
		// *p1 += 30;
		auto it = v1.begin();
		while (it != v1.end())
		{
			if (*it % 2 == 0)
			{
				v1.erase(it);
				// it = v1.erase(it);
			}
			else
			{
				++it;
			}
		}
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		cout << endl;
	}

	void test_vector3()
	{
		// 崩溃
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);


		// 要求删除所有的偶数
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			++it;

		}

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector4()
	{
		lx::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		
		lx::vector<int> v1(v);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		lx::vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);


		lx::vector<int> v1(v);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		lx::vector<int> v2;
		// v2 = v1; // v2.operator(v1)
		v2.operator=(v1);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

	}

	/*void test_vector6()
	{
		int i = 0;
		int j = int(NULL);
		int k = int(10);

		cout << i << j << k << endl;
	}*/

	void test_vector7()
	{
		vector<int> v1(10);

		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		// 报错
		// 1 会被字面量识别为 int
		vector<int> v2(10, 1); // int int 
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;

		// 不报错
		vector<char> v3(10, 'a');
		for (auto e : v3)
		{
			cout << e << ' ';
		}
	}

	void test_vector8()
	{
		vector<int> v;
		v.resize(10, 1);

		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;

		vector<int> v2;
		v2.reserve(10);
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		v2.resize(8, 8);
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;

		vector<int> v3;
		v3.reserve(10);
		v3.push_back(1);
		v3.push_back(2);
		v3.push_back(3);
		v3.push_back(4);
		v3.push_back(5);
		v3.resize(3);
		for (auto e : v3)
		{
			cout << e << ' ';
		}
		cout << endl;
	}

	//class Solution {
	//public:
	//	vector<vector<int>> generate(int numRows) {
	//		vector<vector<int>> vv;
	//		// 设定 vv 的大小：有多少行
	//		vv.resize(numRows);
	//		for (size_t i = 0; i < vv.size(); i++)
	//		{
	//			// 设定 vv[i](vector<int>) 的大小：列的大小：
	//			vv[i].resize(i + 1, 0); // 元素初始化为 0
	//			// 第一个和最后一个初始化为 0
	//			vv[i][0] = vv[i][i] = 1;
	//		}

	//		for (size_t i = 0; i < vv.size(); i++)
	//		{
	//			for (size_t j = 0; j < vv[i].size(); j++)
	//			{
	//				if (vv[i][j] == 0)
	//				{
	//					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
	//				}
	//			}
	//		}

	//		return vv;
	//	}
	//};

	class Solution {
	public:
		// vector<vector<int>> generate(int numRows)
		void generate(int numRows) 
		{
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (size_t i = 0; i < vv.size(); ++i)
			{
				vv[i].resize(i + 1, 0);
				vv[i].front() = vv[i].back() = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					cout << vv[i][j] << " ";
				}
				cout << endl;
			}

			vector<vector<int>> ret = vv;

			// return vv;
		}
	};


	void test_vector9()
	{
		vector<string> v;
		v.push_back("1111111111111111111111111");
		v.push_back("2222222222222222222222222");
		v.push_back("3333333333333333333333333");
		v.push_back("4444444444444444444444444");
		v.push_back("5555555555555555555555555");

		vector<string> v1(v);

		for (auto& e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
		// Solution().generate(5); // 匿名对象调用成员函数
	}

	void test_vector10()
	{
		vector<int> v(10, 1);

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector11()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int> v1(v);

	}

	void test_vector12()
	{
		std::vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		//v.push_back(1);

		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;

		std::vector<int>::iterator it = v.begin();
		it = v.insert(it, 3);
		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;

		*it += 10;
		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
	}

	void test_vector13()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.push_back(1);

		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;

		vector<int>::reverse_iterator rit = v.rbegin();
		while (rit != v.rend())
		{
			cout << *rit << ' ';
			++rit;
		}
		cout << endl;

		rit = v.rbegin();
		while (rit != v.rend())
		{
			*rit = 10086;
			cout << *rit << ' ';
			++rit;
		}
		cout << endl;
	}
}

