#pragma once

#include <iostream>
#include <vector>

// �� bucket ��
template<class K>
struct DefaultHashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// д��1��дһ����
//struct StringHashFunc
//{
//	size_t operator()(const string& str)
//	{
//		return (size_t)str[0];
//	}
//};

// д��2����� string дģ���ػ�
template<>
struct DefaultHashFunc<string>
{
	size_t operator()(const string& str)
	{
		// return (size_t)str[0]; // ��һ����ĸ��ͬ�Ķ���ͻ������
		// �����е� ascii ��ֵ������
		
		/*size_t hash = 0;
		for (auto ch : str)
		{
			hash += ch;
		}*/

		// ��������Ҳ������ bacd abcd abbe ���ǳ�ͻ��
		// ����Ҫ�ַ�����ϣ
		// ʹ�� the c programming language �е� BKDR ��ϣ�㷨

		// ����������Ч�����ͻ
		// ���ַ�������������޵ģ���ͬ���ַ����Կ���ӳ��������ͬ������ 
		// ��Ϊ size_t ֻ�� 2^32 ������һ�����һ�Ĺ�ϵ

		// ���ַ���������ͽضϣ�������Ҷ�һ��
		size_t hash = 0;
		for (auto ch : str)
		{
			hash *= 131;
			hash += ch;
		}

		return hash;
	}
};

// ���ӷº���
namespace open_address
{
	enum STATE
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		STATE _state = EMPTY;
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			// ���� _size �� capacity ����һ��
			_table.resize(10); // resize ����
		}

		bool Insert(const pair<K, V>& kv)
		{
			// ����
			// >= 0.7 ��Ϊ��ʱ������㲻�� 0.7
			// if ((double)_n / (double)_table.size() >= 0.7)
			if (_n * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() * 2;
				vector<HashData<K, V>> newtable;
				newtable.resize(newSize);

				// �����ɱ�����ӳ�䵽�±�
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(newSize);

				// �����ɱ������ݲ��뵽�±���
				for (int i = 0; i < _table.size(); i++)
				{
					newHT.Insert(_table[i]._kv); // ��������̽����߼�
				}

				// ���ִ�д���������ɱ���±�
				_table.swap(newHT._table);
			}

			HashFunc hf;

			// ����̽��

			// ������ size ������ capacity
			// ��Ϊ�˿̿���û�� capacity �����ݣ�%�����Ľ�����ܴ���������������
			// ��ô���ռ� [] �Ͳ��ܷ��ʣ��ͻᱻ���Լ�鵽��
			size_t hashi = hf(kv.first) % _table.size(); // ����ʼλ��
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size(); // Խ��֮��ջ�����ƽ������
			}

			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}

		// ����������߼� const ����Ϊ key ��֧���޸�
		HashData<const K, V>* Find(const K& key)
		{
			HashFunc hf;
			size_t hashi = hf(key) % _table.size(); // ����ʼλ��
			while (_table[hashi]._state != EMPTY)
			{
				// ���������
				// ����ɾ��������������ӵ�һ�������Ͳ����ȥ
				if (_table[hashi]._state == EXIST
					&& _table[hashi]._kv.first == key)
				{
					return (HashData<const K, V>*) & _table[hashi];
				}

				++hashi;
				hashi %= _table.size(); // Խ��֮��ջ�����ƽ������
			}

			return nullptr;
		}

		// �������
		// ���û���룬������淵��ֵ�� pair<K, V> ��߻ᱨ��
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;

				return true;
			}

			return false;
		}

	private:
		vector<HashData<K, V>> _table; // �ŵ��� pair �� ״̬
		size_t _n; // vector �� size Ϊʲô���� n����Ϊ�����Ƿ�ɢ�洢�����Ǽ��д洢��
		// �洢��Ч���ݵĸ����������ˣ���һ������Ҫ����
	};
}

namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		
		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	// ǰ��������ϣ�����Բ���ȱʡ��
	// ���߱������Ƕ����˵�
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, KeyOfT, HashFunc> Self;
		Node* _node;
		HashTable<K, T, KeyOfT, HashFunc>* _pht;

		HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
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
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size(); // ��������˹�ϣ��ĳ�Ա�����Ե�����Ҫ��Ϊ��ϣ�����Ԫ
				
				// ����һ��λ�ò�����һ����Ϊ�յ�Ͱ
				++hashi;
				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi]; 
						return *this;
					}
					else
					{
						++hashi;
					}
				}
				
				// �ߵ�����˵������Ͱ��������
				_node = nullptr;
			}
			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};

	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashNode< T> Node;
	
		// �����������ǹ�ϣ�����Ԫ -- ģ����Ԫ
		// ��ģ������ʱҪ��ģ���������
		template<class K, class T, class KeyOfT, class HashFunc>
		friend struct HTIterator;

	public:
		typedef HTIterator<K, T, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			// �ҵ�һ��Ͱ
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i])
				{
					return iterator(_table[i], this);
				}
			}

			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		// ���ڸù�ϣ���������������춼Ҫ�Լ�д
		// ����Ŀ���Ѱַ�������������Լ����ɵĿ�������
		HashTable()
		{
			_table.resize(10, nullptr);
		}

		HashTable(const HashTable& ht)
			:_n(0)
		{
			_table.resize(ht._table.size());

			for (auto e : ht._table)
			{
				Node* cur = e;
				while (cur)
				{
					Insert(cur->_kv);
					cur = cur->_next;
				}
			}
		}

		// ��ֵ����
		HashTable& operator=(HashTable ht)
		{
			_table.swap(ht._table);
			_n = ht._n;

			return *this;
		}

		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}

		bool Insert(const T& data)
		{
			KeyOfT kot;

			if (Find(kot(data)))
			{
				return false;
			}

			HashFunc hf;
			// �������ӵ� 1 ������
			if (_n == _table.size())
			{
				size_t newSize = _table.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);

				
				// �����ɱ��Ѿɱ������ݹҵ��±�
				for (int i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i]; // ȡ��ͷ
					while (cur)
					{
						Node* next = cur->_next;

						// ͷ�嵽�±�
						size_t hashi = hf(kot(cur->_data)) % newSize;
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next; // ����
					}

					_table[i] = nullptr; // ���ɱ��ÿ�
				}

				_table.swap(newTable); // �˳���vector �� delete[]�����Ƕ���ָ�벢���ᴦ������ָ��ָ�������ڵ㲢û�б��ͷ�
			}

			
			size_t hashi = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);
			// ͷ��	
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return true;
		}
		
		Node* Find(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;

			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return cur;
				}

				cur = cur->_next;
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;

			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;

			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					// ͷɾ
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;

					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			--_n;
			return false;
		}

		void Print()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				printf("[%zu]->", i);
				Node* cur = _table[i];
				while (cur)
				{
					cout << cur->_kv.first << ":" << cur->_kv.second << "->";
					cur = cur->_next;
				}
				cout << "NULL" << endl;
			}
			cout << endl;
		}

	private:
		vector<Node*> _table;
		size_t _n = 0;
	};
}
