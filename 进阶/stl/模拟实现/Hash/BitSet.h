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
}
