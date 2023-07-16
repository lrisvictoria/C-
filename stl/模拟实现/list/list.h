#pragma once

namespace lx
{
	// list_node 需要让别人访问
	template<class T>
	struct list_node
	{
		// eg: list_node<string>
		// 每一个节点上都有指向前后节点的指针，并且存放着值
		list_node<T>* _prev;
		list_node<T>* _next;
		T _val;


		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}
	};

	template<class T>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->_val;
		}

		// 只需要浅拷贝，不需要析构

		// ++ 返回迭代器，引用提高效率
		_list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		_list_iterator<T> operator++(int)
		{
			_list_iterator tmp = _node;
			_node = _node->_next;
			return tmp;
		}

		// 由于 iterator end() 返回的是临时对象，临时对象具有常性，所以需要加 const 修饰
		// 常量和 cosnt 比较就没问题了
		bool operator!=(const _list_iterator<T>& it)
		{
			return _node != it._node; // 迭代器相互比较
		}
	};

	template<class T>
	class list
	{
		// list_node<T> 为类型，为了防止写错，typedef 一下
		typedef list_node<T> Node;
	public:
		// typedef Node* iterator; 
		// typedef 这个类型只是为了和其他容器的迭代器统一
		typedef _list_iterator<T> iterator; // 是一个自定义类型

		iterator begin()
		{
			return _head->_next; // 隐式类型转换
			// return iterator(_head->_next); // 构造
		}

		// 返回调用构造函数，必定是一个临时对象
		iterator end()
		{
			return _head;
		}

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		
		void push_back(const T& val)
		{
			Node* tail = _head->_prev;
			Node* newnode = new Node(val); // 调用构造函数

			tail->_next = newnode;
			newnode->_prev = tail;

			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		Node* _head; // 哨兵位
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		// 看起来是原生指针，但是其实是自定义类型
		// 实际上这边的行为是在调用构造函数
		list<int>::iterator it= lt.begin(); // 类中的自定义类型有两方面：1.typedef 过的是内嵌类型 2.内部类
		while (it != lt.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;
	}
}