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

		// 否则找空 
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
				return false; // 插入失败
			}
		}

		// 到当前位置已经找到空，插入
		cur = new Node(kv);
		if (cur->first > kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur; // 不存在 == 因为 == 已经在上方返回 false
		}
		
		// 更改当前 cur 的平衡因子为 parent
		cur->_parent = parent;

		// 控制平衡因子
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

			// 不用向上更新平衡因子
			if (parent->_bf == 0)
			{
				// 更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 子树不平衡了，需要旋转 || 右边有孩子
				if (parent->_bf == 2 || cur->_bf == 1)
				{
					RotateL(parent);
				}

				// 旋转之后，子树的高度变为之前一样，不会对上层有影响，更新结束
				break;
			}
			else
			{
				assert(false); // 插入之前平衡因子就出问题了，断言
			}
		}
	}

	// 左旋 -- 根据 parent 来进行旋转
	void RotateL(Node* parent)
	{
		// parent 的右孩子
		Node* cur = parent->_right;
		Node* curleft = cur->_left; // cur 的左孩子

		// 核心步骤
		parent->_right = curleft;
		// curleft 可能为空
		if (cur)
		{
			curleft->_parent = parent;
		}
		

		cur->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		// 改变根
		// parent 是根
		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			// parent 是子树节点
			// 找 parent 的父亲，就是需要给 cur 的节点，ppnode
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
		


		parent->_bf = cur->_bf = 0; // parent 和 cur 都平衡
	}

private:
	Node* _root;
};