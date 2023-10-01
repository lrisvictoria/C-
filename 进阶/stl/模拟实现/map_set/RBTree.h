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

template<class T, class Ptr, class Ref>
struct _TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef _TreeIterator<T, Ptr, Ref> Self;
	typedef _TreeIterator<T, T*, T&> Iterator; // 仿照库中的方式处理普通迭代器构造 const 迭代器
	Node* _node;

	_TreeIterator(Node* node)
		:_node(node)
	{}

	_TreeIterator(const Iterator& it)
		:_node(it._node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			// 找右树的最小节点
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

			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			Node* subright = _node->_left;

			while (subright->_right)
			{
				subright = subright->_right;
			}

			_node = subright;
		}
		else
		{
			// 孩子是父亲右的那个节点
			Node* cur = _node;
			Node* parent = cur->_parent; 

			// 为了和库里的同步，因为库里的 parent 走到最后都是真
			// 有一种情况要特殊判断，见笔记，否则会死循环
			while (parent && cur == parent->_left)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			 }

			_node = parent;
		}

		return *this;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};

// map -> RBTree<K, pair<K, V>, MapKeyOfT>  _t;
// set -> RBTree<K, K, SetKeyOfT> _t;

// KeyOfT 是仿函数
template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:

	typedef _TreeIterator<T, T*, T&> iterator;
	typedef _TreeIterator<T, const T*, const T&> const_iterator;

	iterator begin()
	{
		Node* leftMin = _root;

		// 可能是空树
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

	const_iterator begin() const
	{
		Node* leftMin = _root;

		// 可能是空树
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}

		return 
			const_iterator(leftMin);
	}

	const_iterator end() const
	{
		return const_iterator(nullptr);
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
				return cur; // 找到
			}
		}

		return nullptr;
	}

	// 改成返回一个 pair ，成功插入后的迭代器，和是否插入
	pair<iterator, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		Node* cur = _root;
		Node* parent = nullptr;
		KeyOfT kot;

		while (cur)
		{
			// pair 重载了比较，但是不符合我们的需求
			// 需要自己写仿函数
			// 仿函数叫做 KeyOfValue 为的是把 value 的 key 取出来
			// 为了比较更加直观，增加仿函数 compare ，控制比较方式
			// 直接在 map 和 set 增加模板参数 Tcompare 也可以，但是会更加复杂
			// 这样在外面的比较就是根据 Tcompare 比较
			// 当然直接在内部比较也可以，但是并不直观
			// 用一个仿函数控制 map 和 set 比较方式是很复杂的
			// 且有时有多种比较方式，data 和 data ，data 和 key，要处理还是很复杂的

			// 使用时并不关心keyofT，自己设计比较方案比较好


			// 取 _data 中的 key
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
				return make_pair(iterator(cur), false);
			}
		}

		// cur 在变色的过程中可能会一直往上走，所以 cur 不一定是新插入的节点，可能是某个进行变色的节点
		// 要提前保存 cur ，之后返回
		cur = new Node(data);
		cur->_col = RED;

		Node* newnode = cur;
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

		// 父亲存在且为红色
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// 如果 uncle 存在且为红。变色旋转
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// u 不存在或存在且为黑
					if (cur == parent->_left)
					{
						// 对祖父位置进行右单旋
						RotateR(grandfather);
						// 变色
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
				// u 存在且为红
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

		_root->_col = BLACK; // BLACK 总为黑

		return make_pair(iterator(newnode), true);
	}

	// 旋转
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

	// 不用引用，就只算单条路径的长度
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

		// 不检查孩子，因为孩子分左右且可能存在可能不存在，去检查它的父亲的颜色
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "出现连续红色节点" << endl;
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

		// 每条路径黑色节点的基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++benchmark;
			}
			cur = cur->_left; // 看最左边一条路径
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