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
	int _bf; // balance factor ʵ�� avl ����û��ƽ�����ӣ�������������Ϊ������������ֱ��

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
				else if (parent->_bf == -2 || cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_b == 2 || cur->_bf == -1)
				{
					RotateRL(parent); // ����˫��
				}
				else if (parent->_bf == -2 || cur->_bf == 1)
				{
					RotateLR(parent); // ����˫��
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
		if (curleft)
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

	// �ҵ���
	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curRight = cur->_right;

		parent->_left = curRight;

		if (curRight)
		{
			curRight->_parent = parent;
		}
		
		cur->_right = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = cur;
		// �ı��
		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
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

		parent->_bf = cur->_bf = 0;
	}

	// ����˫��
	void RotateRL(Node* parent)
	{
		// �������ƽ������
		// �������ӵ����Ƿ��ƽ�����ӣ���֤����
		Node* cur = parent->_right;
		Node* curleft = parent->_left;
		int bf = curleft->_bf; // ��¼ƽ������

		RotateR(parent->_right);
		RotateL(parent->_left);
		if (bf == 0)
		{
			cur->_bf = 0;
			curleft->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			cur->_bf = 0;
			curleft->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			cur->_bf = 1;
			curleft->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false); 
		}

	}

	void RotateRL(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;

		int bf = curright->_bf;

		RotateL(parent->_left);
		RotateL(parent);

		if (bf == 0)
		{
			cur->_bf = 0;
			curright->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			cur->_bf = 0;
			curright->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == -1)
		{	
			cur->_bf = -1;
			curright->_bf = 0;
			parent->_bf = 0; 
		}
		else
		{
			assert(false);
		}
	}

private:
	Node* _root;
};