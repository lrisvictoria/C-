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
			_a.resize(N / 32 + 1); // 当不能整除就多开一个空间
		}

		// x 映射的位置标记成 1
		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] |= (1 << j);
		}

		// x 映射的标记成 0
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
		vector<int> _a; // 类型不好给，给不了一个 Bit 位
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
			// 10 代表出现两次及以上，不变
		}

		// 判断是否出现一次
		bool is_once(size_t x)
		{
			return !_b1.test(x) && _b2.test(x);
		}

	private:
		bitset<N> _b1; // 会调用自己的构造函数
		bitset<N> _b2;
	};
}
