#pragma once

namespace lx
{
	// Ref 控制 T&, const T&
	// 或者用 iterator_traits 迭代器萃取，模板特化，很复杂的机制
	// 所以使用三个模板，比较简单
	// iterator, const T&, const T*
	template<class Iterator, class Ref, class Ptr>
	struct  ReverseIterator
	{
		typedef ReverseIterator<Iterator, Ref, Ptr> self;
		Iterator _it;

		ReverseIterator(Iterator it)
			:_it(it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it; // 拷贝一份，不能对自己 -- 
			return *--tmp;
		}

		Ptr operator->()
		{
			return &(operator*()); // &(*this)
		}

		// ReverseIterator& operator++() 也对
		self& operator++()
		{
			--_it;
			return *this;
		}

		self operator++(int)
		{
			Iterator tmp = _it;
			--_it;
			return tmp;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		self operator--(int)
		{
			Iterator tmp = _it;
			++_it;
			return tmp;
		}

		bool operator!=(const self& s) const
		{
			return _it != s._it;
		}

		bool operator==(const self& s) const
		{
			return _it == s._it;
		}
	};
}