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

		// set 这里有问题，_t.insert 返回的是普通迭代器
		// 但是 pair<iterator, bool> 中 iterator 不是普通迭代器
		// 类型不匹配，报错
		// Tree::const_iterator
		pair<iterator, bool> insert(const K& key)
		{
			// pair<Tree::iterator, bool>
			// return _t.Insert(kv);

			// 仿照库里写
			// 这里直接取的 iterator 是红黑树中的普通迭代器，普通对象调用返回普通迭代器
			// 但是 return 部分的 iterator 是取的内嵌类型，被解释为 const_iterator
			// 而 ret 的 first 是普通迭代器，相当于拿普通迭代器取构造 const 迭代器
			// 类型不匹配，导致编不过
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key); // 这里的 iterator 指的是普通迭代器
			return pair<iterator, bool>(ret.first, ret.second); // 这里的 iterator 是 const 迭代器
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
	
}