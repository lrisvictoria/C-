#pragma once
#include <vector>

using namespace std;

namespace lx
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_a.resize(N / 32 + 1); // �����������Ͷ࿪һ���ռ�
		}

		// x ӳ���λ�ñ�ǳ� 1
		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] |= (1 << j);
		}

		// x ӳ��ı�ǳ� 0
		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] &= ~(1 << j);
		}

		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			return _a[i] & (1 << j);
		}

	private:
		vector<int> _a; // ���Ͳ��ø���������һ�� Bit λ
	};

	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x)
		{
			// 00 -> 01
			if (!_b1.test(x) && !_b2.test(x))
			{
				_b2.set(x);
			} // 01 -> 10
			else if (!_b1.test(x) && _b2.test(x))
			{
				_b1.set(x);
				_b2.reset(x);
			}
			// 10 ����������μ����ϣ�����
		}

		// �ж��Ƿ����һ��
		bool is_once(size_t x)
		{
			return !_b1.test(x) && _b2.test(x);
		}

	private:
		bitset<N> _b1; // ������Լ��Ĺ��캯��
		bitset<N> _b2;
	};
}
