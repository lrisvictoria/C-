#pragma once

// K -- key 
template<class K>
class BSTreeNode
{
public:
	BSTreeNode(const K& key = K())
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}

	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{} 

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr; // 记录父亲节点
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur; // 记录父亲节点
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false; // 相同元素
			}
		}

		cur = new Node(key);
		// 父亲比 _key 小，插入在右边；否则插入在左边
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else 
			{
				return true;
			}
		}

		return false;
	}

	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else // 找到
			{
				// 左边为空，则判断情况，让父亲指向 cur 的右
				if (cur->_left == nullptr)
				{
					// 删除为根节点
					if (_root == cur)
					{
						_root = cur->_right; // 指向右子树
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
				
				}
				else if(cur->_right == nullptr) // 右为空，则判断，让父亲指向 cur 的左
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else // 替换法：左右都不为空
				{
					// 找替代节点，左子树的最大
					Node* parent = cur; // 避免循环根本不进去的情况
					Node* leftMax = cur->_left;
					while (leftMax->_right)
					{
						parent = leftMax; // 记录父亲
						leftMax = leftMax->_right;
					}

					swap(leftMax->_key, cur->_key);

					if (parent->_left == leftMax)
					{
						parent->_left = leftMax->_left;
					}
					else
					{
						parent->_right = leftMax->_left; // 叶子节点左右孩子都是空，写_right也可以
					}

					cur = leftMax;
				}

				delete cur;
				return true;
			}
		}

		return false;
	}

	// 中序是通过 Node* ，外部调用不了
	// 所以重命名 _InOrder 意为子函数，不加也行
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root;
};

void TestBSTree1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrder();

	t.Erase(4);
	t.InOrder();

	t.Erase(6);
	t.InOrder();

	t.Erase(7);
	t.InOrder();

	for (auto e : a)
	{
		t.Erase(e);
	}
	t.InOrder();
}