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
	typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;
	iterator begin()
	{
		return _t.begin();
	}

	iterator end()
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
		RBTree<K, pair<K, V>, MapKeyOfT>  _t;
	};
} 