#pragma once

#include <cassert>
#include "ReverseIterator.h"

namespace lx
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{}
	};

	// ����ģ�������T�����ã�ָ��
	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> self; // ���������ⷱ��
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		// �������õ�ֵ
		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this); // ֻ��Ҫǳ����

			_node = _node->_next;

			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);

			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const self& it) const
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node; // �����ڲ��õ�

	public:
		typedef _list_iterator< T, T&, T*> iterator;
		typedef _list_iterator< T, const T&, const T*> const_iterator;

		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<iterator, const T&, const T*> const_reverse_iterator;
		// typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator; 
		// ģ������� iterator Ҳ�ԣ��൱������ͨ���������죬����const���������ɺ�������ģ����������ģ�����Ҳû��

		iterator begin()
		{
			return _head->_next; // ��ʽ����ת��
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return begin(); // ��ʽ����ת��
		}

		// q1:this->end ���õ�ǰ this �� end
		// q2:this->const_reverse_iterator(this->end()); ����������ᱻʶ��Ϊ��Ƕ���ͣ����Ͳ�������������Ա���ʱ��ʽ���Ҳ�
		// q3:����Ϊ���� + ���������Ż�Ϊһ�ι���
		// q4:������������ iterator δ���
		const_reverse_iterator rbegin() const
		{
			// return const_reverse_iterator(this->end());
			return const_reverse_iterator(iterator(_head));
		}

		// typedef ReverseIterator<iterator, const T&, const T*>
		const_reverse_iterator rend() const
		{
			// return const_reverse_iterator(this->begin()); // begin() ���õ��� const ��������
			return const_reverse_iterator(iterator(_head->_next)); // ����Ϊ��ͨ���͵ĵ�����
			// ��ģ�崫��ͬ����Ϊ��ͬ���ͣ����Ͳ�ƥ��ͱ���
		}

		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		// list(const list& lt) // �����������Գ䵱����
		list(const list<T>& lt)
		{
			// new(this)list; // ��λ new
			empty_init();

			// & ���Ч��
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		// void swap(list& lt)
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// list& operator=(const list<T>& lt)
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();

			while (it != end())
			{
				it = erase(it);
			}

			_size = 0;
		}

		void push_back(const T& val)
		{
			/*Node* newnode = new Node(val);
			Node* tail = _head->_prev;

			newnode->_prev = tail;
			tail->_next = newnode;

			newnode->_next = _head;
			_head->_prev = newnode;*/

			insert(end(), val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		// pos λ��֮ǰ����
		iterator insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;

			return newnode; // �����λ��
		}

		// ɾ�� pos λ��
		iterator erase(iterator pos)
		{
			assert(pos != end()); // ɾ���Ĳ�Ϊͷ���

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete[] cur;
			--_size;

			return next; // ɾ�����λ��
		}

		size_t size()
		{
			return _size;
		}
		
	private:
		Node* _head;
		size_t _size;
	};


	struct A
	{
		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			, _a2(a2)
		{}

		int _a1;
		int _a2;
	};

	void test_list2()
	{
		list<A> lt;
		lt.push_back(A(1, 1));
		lt.push_back(A(2, 2));
		lt.push_back(A(3, 3));
		lt.push_back(A(4, 4));

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << (*it)._a1 << " " << (*it)._a2 << endl;
			cout << it->_a1 << " " << it->_a2 << endl;

			++it;
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(5);
		lt.push_front(6);
		lt.push_front(7);
		lt.push_front(8);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_front();
		lt.pop_back();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.clear();
		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);
		lt.push_back(40);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		cout << lt.size() << endl;
	}

	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt1(lt);
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt2;
		lt2.push_back(10);
		lt2.push_back(20);
		lt2.push_back(30);
		lt2.push_back(40);

		for (auto e : lt2)
		{
			cout << e << " ";
		}
		cout << endl;

		lt1 = lt2;

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void Print(const list<int>& lt)
	{
		//list<int>::const_iterator it = lt.begin();
		//while (it != lt.end())
		//{
		//	// (*it) += 1;
		//	cout << *it << " ";
		//	++it;
		//}
		//cout << endl;

		
		list<int>::const_reverse_iterator rcit = lt.rbegin();
		while (rcit != lt.rend())
		{
			// (*it) += 1;
			cout << *rcit << " ";
			++rcit;
		}
		cout << endl;
	}

	void test_list5()
	{
		/*list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			*rit = 10;
			cout << *rit << " ";
			++rit;
		}
		cout << endl;*/

		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;

		// ReverseIterator<iterator, const T&, const T*> const_reverse_iterator
		// <_list_iterator<T, T&, T*>, const T&, const T*>
		// list<int>::const_reverse_iterator crit = lt1.rbegin();
		//while (crit != lt1.crend())
		//{
		//	// *crit = 10;

		//	cout << *crit << " ";
		//	++crit;
		//}
		//cout << endl;

		 Print(lt1);
	}

	void test_list6()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		// list<int>::const_iterator cit = lt.begin();

	}
}