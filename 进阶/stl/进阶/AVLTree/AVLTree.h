#pragma once

#include <iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// �����ҿ� 
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false; // ����ʧ��
			}
		}

		// ����ǰλ���Ѿ��ҵ��գ�����
		cur = new Node(kv);
		if (cur->first > kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur; // ������ == ��Ϊ == �Ѿ����Ϸ����� false
		}
		
		// ���ĵ�ǰ cur ��ƽ������Ϊ parent
		cur->_parent = parent;

		// ����ƽ������
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else // if (cur == parent->_right)
			{
				parent->_bf++;
			}

			// �������ϸ���ƽ������
			if (parent->_bf == 0)
			{
				// ���½���
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// �������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ������ƽ���ˣ���Ҫ��ת || �ұ��к���
				if (parent->_bf == 2 || cur->_bf == 1)
				{
					RotateL(parent);
				}

				// ��ת֮�������ĸ߶ȱ�Ϊ֮ǰһ����������ϲ���Ӱ�죬���½���
				break;
			}
			else
			{
				assert(false); // ����֮ǰƽ�����Ӿͳ������ˣ�����
			}
		}
	}

	// ���� -- ���� parent ��������ת
	void RotateL(Node* parent)
	{
		// parent ���Һ���
		Node* cur = parent->_right;
		Node* curleft = cur->_left; // cur ������

		// ���Ĳ���
		parent->_right = curleft;
		// curleft ����Ϊ��
		if (cur)
		{
			curleft->_parent = parent;
		}
		

		cur->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		// �ı��
		// parent �Ǹ�
		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			// parent �������ڵ�
			// �� parent �ĸ��ף�������Ҫ�� cur �Ľڵ㣬ppnode
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}

			cur->_parent = ppnode;
		}
		


		parent->_bf = cur->_bf = 0; // parent �� cur ��ƽ��
	}

private:
	Node* _root;
};