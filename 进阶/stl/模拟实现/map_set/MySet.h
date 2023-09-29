#pragma once
#include "RBTree.h"

namespace lx
{
	template<class K>
	class set
	{
		// 认为 set 迁就了 map
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator; // 跑不了，因为类模板没有实例化，不敢去访问 iteraotr 因为可能是静态成员变量也可能是内嵌类型，所以加上tyname让编译器放心

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		bool insert(const K& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
	
}