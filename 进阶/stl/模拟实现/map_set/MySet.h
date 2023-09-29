#pragma once
#include "RBTree.h"

namespace lx
{
	template<class K>
	class set
	{
		// ��Ϊ set Ǩ���� map
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator; // �ܲ��ˣ���Ϊ��ģ��û��ʵ����������ȥ���� iteraotr ��Ϊ�����Ǿ�̬��Ա����Ҳ��������Ƕ���ͣ����Լ���tyname�ñ���������

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