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
			HashTable<K, V> newHT;
			newHT._table.resize(newSize);

			// �����ɱ������ݲ��뵽�±���
			for (int i = 0; i < _table.size(); i++)
			{
				newHT.Insert(_table[i]._kv); // ��������̽����߼�
			}

			// ���ִ�д���������ɱ���±�
			_table.swap(newHT._table);
		}

		// ����̽��

		// ������ size ������ capacity
		// ��Ϊ�˿̿���û�� capacity �����ݣ�%�����Ľ�����ܴ���������������
		// ��ô���ռ� [] �Ͳ��ܷ��ʣ��ͻᱻ���Լ�鵽��
		size_t hashi = kv.first % _table.size(); // ����ʼλ��
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
		size_t hashi = key % _table.size(); // ����ʼλ��
		while (_table[hashi]._state != EMPTY)
		{
			// ���������
			// ����ɾ��������������ӵ�һ�������Ͳ����ȥ
			if (_table[hashi]._state == EXIST
				&& _table[hashi]._kv.first == key)
			{
				return (HashDate<const K, V>*) & _table[hashi];
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