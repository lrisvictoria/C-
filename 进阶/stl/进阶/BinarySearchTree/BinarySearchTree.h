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

	BSTree(const BSTree<K>& t)
	{
		_root = Copy(t._root);
	}

	// 赋值
	BSTree& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~BSTree()
	{
		Destory(_root);
	}

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

	// 写循环比较好，比较容易理解
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

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	// 递归版本
	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}

private:
	// 拷贝构造
	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		// 前序
		Node* copyroot = new Node(root->_key);
		copyroot->_left = Copy(root->_left);
		copyroot->_right = Copy(root->_right);

		return copyroot;
	}

	// 析构
	void Destory(Node*& root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destory(root->_left);
		Destory(root->_right);
		delete root;

		root = nullptr;
	}

	// 需要当前节点 root ，不能只有 key 值
	bool _FindR(Node* root, const K& key)
	{
		if (root == nullptr) return false; // 找到底没找到

		if (root->_key == key)
		{
			return true;
		}
		else if (root->_key > key)
		{
			_FindR(root->_left, key);
		}
		else
		{
			_FindR(root->_right, key);
		}
	}

	// 使用引用
	bool _InsertR(Node*& root, const K& key)
	{
		// 走到空，说明走到位置了
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}

		if (root->_key == key)
		{
			return false;
		}
		else if (root->_key > key)
		{
			_InsertR(root->_left, key);
		}
		else
		{
			_InsertR(root->_right, key);
		}
	}

	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
			return false;

		if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else
		{
			Node* del = root; // 记录删除节点
			if (root->_left == nullptr)
			{
				root = root->_right; // root 为父节点的左右孩子，root的left / right覆盖原来的root就自动链接上
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* leftMax = root->_left;
				while (leftMax->_right)
				{
					leftMax = leftMax->_right;
				}

				swap(leftMax->_key, root->_key);

				// 此处不能传递leftMax，因为leftMax是一个局部变量，形参以它为别名无意义
				return _EraseR(root->_left, key);
			}

			delete del;
			return true;
		}
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

private:
	Node* _root;
};

void TestBSTree1()
{
	int a[] = { 8,3,1 ,10,14,13};
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}

	//t.InOrder();

	t.EraseR(8);
	t.InOrder();


	/*t.EraseR(4);
	t.InOrder();

	t.EraseR(6);
	t.InOrder();

	t.EraseR(7);
	t.InOrder();

	for (auto e : a)
	{
		t.EraseR(e);
	}
	t.InOrder();*/
}

void TestBSTree2()
{
	int a[] = { 8,3,1 ,10,14,13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	BSTree<int> t2(t);
	t2.InOrder();
}