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

	// ��ֵ
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

		Node* parent = nullptr; // ��¼���׽ڵ�
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur; // ��¼���׽ڵ�
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false; // ��ͬԪ��
			}
		}

		cur = new Node(key);
		// ���ױ� _key С���������ұߣ�������������
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

	// дѭ���ȽϺã��Ƚ��������
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
			else // �ҵ�
			{
				// ���Ϊ�գ����ж�������ø���ָ�� cur ����
				if (cur->_left == nullptr)
				{
					// ɾ��Ϊ���ڵ�
					if (_root == cur)
					{
						_root = cur->_right; // ָ��������
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
				else if(cur->_right == nullptr) // ��Ϊ�գ����жϣ��ø���ָ�� cur ����
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
				else // �滻�������Ҷ���Ϊ��
				{
					// ������ڵ㣬�����������
					Node* parent = cur; // ����ѭ����������ȥ�����
					Node* leftMax = cur->_left;
					while (leftMax->_right)
					{
						parent = leftMax; // ��¼����
						leftMax = leftMax->_right;
					}

					swap(leftMax->_key, cur->_key);

					if (parent->_left == leftMax)
					{
						parent->_left = leftMax->_left;
					}
					else
					{
						parent->_right = leftMax->_left; // Ҷ�ӽڵ����Һ��Ӷ��ǿգ�д_rightҲ����
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

	// �ݹ�汾
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
	// ��������
	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		// ǰ��
		Node* copyroot = new Node(root->_key);
		copyroot->_left = Copy(root->_left);
		copyroot->_right = Copy(root->_right);

		return copyroot;
	}

	// ����
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

	// ��Ҫ��ǰ�ڵ� root ������ֻ�� key ֵ
	bool _FindR(Node* root, const K& key)
	{
		if (root == nullptr) return false; // �ҵ���û�ҵ�

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

	// ʹ������
	bool _InsertR(Node*& root, const K& key)
	{
		// �ߵ��գ�˵���ߵ�λ����
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
			Node* del = root; // ��¼ɾ���ڵ�
			if (root->_left == nullptr)
			{
				root = root->_right; // root Ϊ���ڵ�����Һ��ӣ�root��left / right����ԭ����root���Զ�������
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

				// �˴����ܴ���leftMax����ΪleftMax��һ���ֲ��������β�����Ϊ����������
				return _EraseR(root->_left, key);
			}

			delete del;
			return true;
		}
	}

	// ������ͨ�� Node* ���ⲿ���ò���
	// ���������� _InOrder ��Ϊ�Ӻ���������Ҳ��
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