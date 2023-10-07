#pragma once

#include <iostream>
#include <vector>

// 给 bucket 用
template<class K>
struct DefaultHashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 写法1：写一个类
//struct StringHashFunc
//{
//	size_t operator()(const string& str)
//	{
//		return (size_t)str[0];
//	}
//};

// 写法2：针对 string 写模板特化
template<>
struct DefaultHashFunc<string>
{
	size_t operator()(const string& str)
	{
		// return (size_t)str[0]; // 第一个字母相同的都冲突，不好
		// 把所有的 ascii 码值加起来
		
		/*size_t hash = 0;
		for (auto ch : str)
		{
			hash += ch;
		}*/

		// 但是这样也有问题 bacd abcd abbe 都是冲突的
		// 所以要字符串哈希
		// 使用 the c programming language 中的 BKDR 哈希算法

		// 这样可以有效避免冲突
		// 但字符串的组合是无限的，不同的字符串仍可能映射计算出相同的整形 
		// 因为 size_t 只有 2^32 个，是一个多对一的关系

		// 若字符串溢出，就截断，插入查找都一样
		size_t hash = 0;
		for (auto ch : str)
		{
			hash *= 131;
			hash += ch;
		}

		return hash;
	}
};

// 增加仿函数
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
			// 控制 _size 和 capacity 保持一致
			_table.resize(10); // resize 可以
		}

		bool Insert(const pair<K, V>& kv)
		{
			// 扩容
			// >= 0.7 因为有时候可能算不到 0.7
			// if ((double)_n / (double)_table.size() >= 0.7)
			if (_n * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() * 2;
				vector<HashData<K, V>> newtable;
				newtable.resize(newSize);

				// 遍历旧表，重新映射到新表
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(newSize);

				// 遍历旧表，将数据插入到新表中
				for (int i = 0; i < _table.size(); i++)
				{
					newHT.Insert(_table[i]._kv); // 复用线性探测的逻辑
				}

				// 类现代写法，交换旧表和新表
				_table.swap(newHT._table);
			}

			HashFunc hf;

			// 线性探测

			// 这里用 size 而不是 capacity
			// 因为此刻可能没有 capacity 个数据，%出来的结果可能大于现在已有数据
			// 那么这块空间 [] 就不能访问，就会被断言检查到，
			size_t hashi = hf(kv.first) % _table.size(); // 算起始位置
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size(); // 越界之后拐回来，平常不变
			}

			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}

		// 返回数据这边加 const ，因为 key 不支持修改
		HashData<const K, V>* Find(const K& key)
		{
			HashFunc hf;
			size_t hashi = hf(key) % _table.size(); // 算起始位置
			while (_table[hashi]._state != EMPTY)
			{
				// 存在且相等
				// 避免删除的情况，这样子第一个条件就不会进去
				if (_table[hashi]._state == EXIST
					&& _table[hashi]._kv.first == key)
				{
					return (HashData<const K, V>*) & _table[hashi];
				}

				++hashi;
				hashi %= _table.size(); // 越界之后拐回来，平常不变
			}

			return nullptr;
		}

		// 按需编译
		// 这块没编译，如果上面返回值是 pair<K, V> 这边会报错
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
		vector<HashData<K, V>> _table; // 放的是 pair 和 状态
		size_t _n; // vector 有 size 为什么定义 n，因为数据是分散存储，不是集中存储的
		// 存储有效数据的个数，快满了，或到一定条件要扩容
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

	// 前置声明哈希表（可以不给缺省）
	// 告诉编译器是定义了的
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
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size(); // 这里访问了哈希表的成员，所以迭代器要成为哈希表的友元
				
				// 从下一个位置查找下一个不为空的桶
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
				
				// 走到这里说明所有桶都走完了
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
	
		// 声明迭代器是哈希表的友元 -- 模板友元
		// 类模板声明时要把模板参数带上
		template<class K, class T, class KeyOfT, class HashFunc>
		friend struct HTIterator;

	public:
		typedef HTIterator<K, T, KeyOfT, HashFunc> iterator;

		iterator begin()
		{
			// 找第一个桶
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

		// 对于该哈希表，析构，拷贝构造都要自己写
		// 上面的开放寻址法，会用他们自己生成的拷贝构造
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

		// 赋值重载
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
			// 负载因子到 1 就扩容
			if (_n == _table.size())
			{
				size_t newSize = _table.size() * 2;
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);

				
				// 遍历旧表，把旧表中数据挂到新表
				for (int i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i]; // 取表头
					while (cur)
					{
						Node* next = cur->_next;

						// 头插到新表
						size_t hashi = hf(kot(cur->_data)) % newSize;
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next; // 迭代
					}

					_table[i] = nullptr; // 将旧表置空
				}

				_table.swap(newTable); // 退出后，vector 会 delete[]，但是对于指针并不会处理，所以指针指向的链表节点并没有被释放
			}

			
			size_t hashi = hf(kot(data)) % _table.size();
			Node* newnode = new Node(data);
			// 头插	
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
					// 头删
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
