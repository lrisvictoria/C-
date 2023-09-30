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
		// 普通迭代器也是 const 迭代器
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator; // 跑不了，因为类模板没有实例化，不敢去访问 iteraotr 因为可能是静态成员变量也可能是内嵌类型，所以加上tyname让编译器放心
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;
		
		// 加 const 修饰调用 const 的begin和 end
		// 返回写的是 iterator ，实际上是 const_iterator

		// 只写这一部分就可以满足两种迭代器
		// const_iterator begin() const
		iterator begin() const 
		{
			return _t.begin();
		}

		// const_iterator end() const
		iterator end() const
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