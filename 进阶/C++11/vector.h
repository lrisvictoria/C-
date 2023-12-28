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

		// ��Ҫʹ�ó�ʼ���б��ʼ����19��ʼ���ˣ�����13��û�г�ʼ��
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

		// ���߸��� resize
		//vector(size_t n, const T& val = T()) // ����ʼ���������ֵ
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _endofstorage(nullptr)
		//{
		//	resize(n, val);
		//}

		// n �� val ����
		// ��ȱʡ���� �������ֵ����Ĭ�ϵ��� T ���͵�Ĭ�Ϲ���
		// ����Ҫ�ṩ T() ��Ĭ�Ϲ��죬����ᱨ��
		// ����ζ�ţ��������ͣ��� int ҲҪ�й���
		// c++����ģ�������Ϊ���������ͽ�����������Ҳ��Ҫ���캯��
		// �� int ��Ҫ���캯��
		// Ϊ�˺��Զ�������ͬ��������Ҫ����
		vector(size_t n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); // n �� val ��ʼ��
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		// Դ����Ϊ�˽������ int ��ģ��ʶ�������������趨�����غ���
		vector(int n, const T& val = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(n); // n �� val ��ʼ��
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

		// ��һ��д��
		//vector(const vector<T>& v)
		//{
		//	_start = new T[v.size()]; // size �� capacity ������
		//	// memcpy(_start, v._start, sizeof(T) * v.size()); // �������Ϳ��ԣ��Զ������Ͳ�����
		//	for (size_t i = 0; i < v.size(); i++)
		//	{
		//		_start[i] = v._start[i]; // ������ֵ���ؽ������
		//	}
		//	_finish = _start + v.size();
		//	_endofstorage = _start + v.size();
		//}

		// �ڶ���д��
		//vector(const vector<T>& v)
		//	:_start(nullptr)
		//	,_finish(nullptr)
		//	,_endofstorage(nullptr)
		//{
		//	reserve(v.size()); // �ȳ�ʼ�����ٿ��ռ�
		//	for (const auto& e : v) // const auto& & Ϊ�����Ч�ʣ����� const ����Ϊ���������� const vector<T>& v���޷����޸�
		//	{
		//		push_back(e);
		//	}
		//}

		// ������д�����ִ�д��
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

		// ��ֵ���� ���÷���
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	vector<T> tmp(v); // ���ÿ�������
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
				size_t sz = size(); // �ȿ������������ _finish ʱ���������Ϊ��һ�ν��
				T* tmp = new T[n];
				if (_start)
				{
					// memcpy(tmp, _start, sz * sizeof(T)); // �� vector<vector<int>> ʱ�����
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i]; // ������ֵ���ؽ������
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz; // ���� _start �ı䣬���� _finish Ҳ��Ҫ�ı�
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n > capacity())
			{
				reserve(n);
			}

			// ��� n ����ԭ���� size()
			if (n > size())
			{
				// _start +n Ϊ��� _finish Ӧ��λ��
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
			else
			{
				_finish = _start + n; // ����ɾ������
			}
		}

		// ���� T��T Ϊģ�壬Ϊ�˽�ʡЧ��
		void push_back(const T& x)
		{
			//if (_finish == _endofstorage)
			//{
			//	size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
			//	reserve(newcapacity);
			//}

			//// ���Ƕ�λ new �����Կ���ֱ�Ӹ���
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
				size_t len = pos - _start; // ��¼ԭ�� pos �ĳ���

				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);

				// ���pos������ʧЧ����
				pos = _start + len; // �ÿ�ʼλ�ü��� len
			}

			iterator end = _finish - 1; // �����ƶ� \0
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x; // ���� string �ĸ�ֵ���أ�������
			++_finish;

			return pos;
		}

		// stl �涨erase �᷵��ɾ�����ݵ���һ��λ�õĵ�����
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
		iterator _start = nullptr; // ��ȱʡֵ�����Լ��ٳ�ʼ���б��ʼ��
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};

	void print(const vector<int>& v)
	{
		// �ᱨ��
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

		// ������ʧЧ
		v1.insert(v1.begin(), 100);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		std::vector<int>::iterator p = v1.begin() + 3;
		p = v1.insert(p, 300);// ���շ���ֵ

		// �ⲿ������ʧЧ
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

		// �ⲿ������ʧЧ
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
		// ����
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);


		// Ҫ��ɾ�����е�ż��
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

		// ����
		// 1 �ᱻ������ʶ��Ϊ int
		vector<int> v2(10, 1); // int int 
		for (auto e : v2)
		{
			cout << e << ' ';
		}
		cout << endl;

		// ������
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
	//		// �趨 vv �Ĵ�С���ж�����
	//		vv.resize(numRows);
	//		for (size_t i = 0; i < vv.size(); i++)
	//		{
	//			// �趨 vv[i](vector<int>) �Ĵ�С���еĴ�С��
	//			vv[i].resize(i + 1, 0); // Ԫ�س�ʼ��Ϊ 0
	//			// ��һ�������һ����ʼ��Ϊ 0
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
		// Solution().generate(5); // ����������ó�Ա����
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

