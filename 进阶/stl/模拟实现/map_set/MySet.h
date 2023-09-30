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
		// ��ͨ������Ҳ�� const ������
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator; // �ܲ��ˣ���Ϊ��ģ��û��ʵ����������ȥ���� iteraotr ��Ϊ�����Ǿ�̬��Ա����Ҳ��������Ƕ���ͣ����Լ���tyname�ñ���������
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;
		
		// �� const ���ε��� const ��begin�� end
		// ����д���� iterator ��ʵ������ const_iterator

		// ֻд��һ���־Ϳ����������ֵ�����
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