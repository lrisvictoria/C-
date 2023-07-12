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

		// ��һ��д��
		//vector(const vector<T>& v)
		//{
		//	_start = new T[v.size()]; // size �� capacity ������
		//	memcpy(_start, v._start, sizeof(T) * v.size());
		//	_finish = _start + v.size();
		//	_endofstorage = _start + v.size();
		//}

		// �ڶ���д��
		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			reserve(v.size()); // �ȳ�ʼ�����ٿ��ռ�
			for (const auto& e : v) // const auto& & Ϊ�����Ч�ʣ����� const ����Ϊ���������� const vector<T>& v���޷����޸�
			{
				push_back(e);
			}
		}


		// �ڶ���д��

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size(); // �ȿ������������ _finish ʱ���������Ϊ��һ�ν��
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sz * sizeof(T));
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz; // ���� _start �ı䣬���� _finish Ҳ��Ҫ�ı�
				_endofstorage = _start + n;
			}
		}

		// ���� T��T Ϊģ�壬Ϊ�˽�ʡЧ��
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

			// ���Ƕ�λ new �����Կ���ֱ�Ӹ���
			*_finish = x;
			++_finish;

			// insert(end(), x);
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

			*pos = x;
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

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
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

		// ������ʧЧ
		v1.insert(v1.begin(), 100);
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		lx::vector<int>::iterator p = v1.begin() + 3;
		p = v1.insert(p, 300);// ���շ���ֵ

		// �ⲿ������ʧЧ
		*p += 30;
		for (auto e : v1)
		{
			cout << e << ' ';
		}
		cout << endl;

		lx::vector<int>::iterator p1 = v1.begin() + 3;
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
}

