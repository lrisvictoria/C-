#pragma once
#include "RBTree.h"

namespace lx
{
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

public:
	typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
	typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

	iterator begin()
	{
		return _t.begin();
	}

	iterator end()
	{
		return _t.end();
	}

	const_iterator begin() const
	{
		return _t.begin();
	}

	const_iterator end() const
	{
		return _t.end();
	}

	V& operator[](const K& key)
	{
		return key.second;
	}

		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv) ;
		}
		
	private:
		RBTree<K, pair<const K, V>, MapkeyofT> _t; // 对于 key 加 const 修饰，pair 整体可以修改
		// RBTree<K, pair<K, V>, MapKeyOfT>  _t;
	};
} 