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

		// set ���������⣬_t.insert ���ص�����ͨ������
		// ���� pair<iterator, bool> �� iterator ������ͨ������
		// ���Ͳ�ƥ�䣬����
		// Tree::const_iterator
		pair<iterator, bool> insert(const K& key)
		{
			// pair<Tree::iterator, bool>
			// return _t.Insert(kv);

			// ���տ���д
			// ����ֱ��ȡ�� iterator �Ǻ�����е���ͨ����������ͨ������÷�����ͨ������
			// ���� return ���ֵ� iterator ��ȡ����Ƕ���ͣ�������Ϊ const_iterator
			// �� ret �� first ����ͨ���������൱������ͨ������ȡ���� const ������
			// ���Ͳ�ƥ�䣬���±಻��
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key); // ����� iterator ָ������ͨ������
			return pair<iterator, bool>(ret.first, ret.second); // ����� iterator �� const ������
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
	
}