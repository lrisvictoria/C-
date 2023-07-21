#pragma once

namespace lx
{
	// Ref ���� T&, const T&
	// ������ iterator_traits ��������ȡ��ģ���ػ����ܸ��ӵĻ���
	// ����ʹ������ģ�壬�Ƚϼ�
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
			Iterator tmp = _it; // ����һ�ݣ����ܶ��Լ� -- 
			return *--tmp;
		}

		Ptr operator->()
		{
			return &(operator*()); // &(*this)
		}

		// ReverseIterator& operator++() Ҳ��
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