#pragma once

namespace lx
{
	// list_node ��Ҫ�ñ��˷���
	template<class T>
	struct list_node
	{
		// eg: list_node<string>
		// ÿһ���ڵ��϶���ָ��ǰ��ڵ��ָ�룬���Ҵ����ֵ
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

		// ֻ��Ҫǳ����������Ҫ����

		// ++ ���ص��������������Ч��
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

		// ���� iterator end() ���ص�����ʱ������ʱ������г��ԣ�������Ҫ�� const ����
		// ������ cosnt �ȽϾ�û������
		bool operator!=(const _list_iterator<T>& it)
		{
			return _node != it._node; // �������໥�Ƚ�
		}
	};

	template<class T>
	class list
	{
		// list_node<T> Ϊ���ͣ�Ϊ�˷�ֹд��typedef һ��
		typedef list_node<T> Node;
	public:
		// typedef Node* iterator; 
		// typedef �������ֻ��Ϊ�˺����������ĵ�����ͳһ
		typedef _list_iterator<T> iterator; // ��һ���Զ�������

		iterator begin()
		{
			return _head->_next; // ��ʽ����ת��
			// return iterator(_head->_next); // ����
		}

		// ���ص��ù��캯�����ض���һ����ʱ����
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
			Node* newnode = new Node(val); // ���ù��캯��

			tail->_next = newnode;
			newnode->_prev = tail;

			newnode->_next = _head;
			_head->_prev = newnode;
		}

	private:
		Node* _head; // �ڱ�λ
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		// ��������ԭ��ָ�룬������ʵ���Զ�������
		// ʵ������ߵ���Ϊ���ڵ��ù��캯��
		list<int>::iterator it= lt.begin(); // ���е��Զ��������������棺1.typedef ��������Ƕ���� 2.�ڲ���
		while (it != lt.end())
		{
			cout << *it << ' ';
			++it;
		}
		cout << endl;
	}
}