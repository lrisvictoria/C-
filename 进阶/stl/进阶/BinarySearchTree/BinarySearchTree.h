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