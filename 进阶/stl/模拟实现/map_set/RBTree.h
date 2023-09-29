#pragma once
#include <iostream>

using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Color _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T>
struct _TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef _TreeIterator<T> Self;
	Node* _node;

	_TreeIterator(Node* node)
		:_node(node)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			// ����������С�ڵ�
			Node* subleft = _node->_right;
			while (subleft->_left)
			{
				subleft = subleft->_left;
			}

			_node = subleft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;

			while (parent)
			{
				if (cur == parent->_left)
				{
					break;
				}
				else
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{

	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};

// map -> RBTree<K, pair<K, V>, MapKeyOfT>  _t;
// set -> RBTree<K, K, SetKeyOfT> _t;

// KeyOfT �Ƿº���
template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:

	typedef _TreeIterator<T> iterator;

	iterator begin()
	{
		Node* leftMin = _root;

		// �����ǿ���
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}

		return iterator(leftMin);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	Node* find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;

		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur; // �ҵ�
			}
		}

		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		KeyOfT kot;

		while (cur)
		{
			// pair �����˱Ƚϣ����ǲ��������ǵ�����
			// ��Ҫ�Լ�д�º���
			// �º������� KeyOfValue Ϊ���ǰ� value �� key ȡ����
			// Ϊ�˱Ƚϸ���ֱ�ۣ����ӷº��� compare �����ƱȽϷ�ʽ
			// ֱ���� map �� set ����ģ����� Tcompare Ҳ���ԣ����ǻ���Ӹ���
			// ����������ıȽϾ��Ǹ��� Tcompare �Ƚ�
			// ��Ȼֱ�����ڲ��Ƚ�Ҳ���ԣ����ǲ���ֱ��
			// ��һ���º������� map �� set �ȽϷ�ʽ�Ǻܸ��ӵ�
			// ����ʱ�ж��ֱȽϷ�ʽ��data �� data ��data �� key��Ҫ�����Ǻܸ��ӵ�

			// ʹ��ʱ��������keyofT���Լ���ƱȽϷ����ȽϺ�


			// ȡ _data �е� key
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		cur->_col = RED;
		//KeyOfT kot;
		if (kot(parent->_data) > kot(data))
		{
			parent->_left = cur;
		}
		else if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}

		cur->_parent = parent;

		// ���״�����Ϊ��ɫ
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// ��� uncle ������Ϊ�졣��ɫ��ת
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// u �����ڻ������Ϊ��
					if (cur == parent->_left)
					{
						// ���游λ�ý����ҵ���
						RotateR(grandfather);
						// ��ɫ
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);

						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else // parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				// u ������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);

						grandfather->_col = RED;
						cur->_col = BLACK;
					}

					break;
				}
			}

		}

		_root->_col = BLACK; // BLACK ��Ϊ��

		return true;
	}

	// ��ת
	void RotateL(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;
		if (curleft)
		{
			curleft->_parent = parent;
		}

		cur->_left = parent;

		Node* ppnode = parent->_parent;

		parent->_parent = cur;


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
	}


	void RotateR(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;
		if (curright)
			curright->_parent = parent;

		Node* ppnode = parent->_parent;
		cur->_right = parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
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
	}

	// �������ã���ֻ�㵥��·���ĳ���
	bool CheckColor(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
			{
				return false;
			}

			return true;
		}

		if (root->_col == BLACK)
		{
			++blacknum;
		}

		// ����麢�ӣ���Ϊ���ӷ������ҿ��ܴ��ڿ��ܲ����ڣ�ȥ������ĸ��׵���ɫ
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "����������ɫ�ڵ�" << endl;
			return false;
		}

		return CheckColor(root->_left, blacknum, benchmark)
			&& CheckColor(root->_right, blacknum, benchmark);
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}

		if (root->_col != BLACK)
		{
			return false;
		}

		// ÿ��·����ɫ�ڵ�Ļ�׼ֵ
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++benchmark;
			}
			cur = cur->_left; // �������һ��·��
		}

		return CheckColor(root, 0, benchmark);
	}

	int Height()
	{
		return Height(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

private:
	Node* _root = nullptr;

public:
	int _rotateCount = 0;
};