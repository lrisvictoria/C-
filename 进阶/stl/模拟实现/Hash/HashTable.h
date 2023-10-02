#pragma once

#include <iostream>
#include <vector>

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

template<class K, class V>
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
			HashTable<K, V> newHT;
			newHT._table.resize(newSize);

			// 遍历旧表，将数据插入到新表中
			for (int i = 0; i < _table.size(); i++)
			{
				newHT.Insert(_table[i]._kv); // 复用线性探测的逻辑
			}

			// 类现代写法，交换旧表和新表
			_table.swap(newHT._table);
		}

		// 线性探测

		// 这里用 size 而不是 capacity
		// 因为此刻可能没有 capacity 个数据，%出来的结果可能大于现在已有数据
		// 那么这块空间 [] 就不能访问，就会被断言检查到，
		size_t hashi = kv.first % _table.size(); // 算起始位置
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
		size_t hashi = key % _table.size(); // 算起始位置
		while (_table[hashi]._state != EMPTY)
		{
			// 存在且相等
			// 避免删除的情况，这样子第一个条件就不会进去
			if (_table[hashi]._state == EXIST
				&& _table[hashi]._kv.first == key)
			{
				return (HashDate<const K, V>*) & _table[hashi];
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