#pragma once

#include "BitSet.h"
#include <string>

struct BKDRHash
{
    size_t operator()(const string& str)
    {
        size_t hash = 0;
        for (auto ch : str)
        {
            hash = hash * 131 + ch;
        }

        //cout <<"BKDRHash:" << hash << endl;
        return hash;
    }
};

struct APHash
{
    size_t operator()(const string& str)
    {
        size_t hash = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            size_t ch = str[i];
            if ((i & 1) == 0)
            {
                hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
            }
            else
            {
                hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
            }
        }

        //cout << "APHash:" << hash << endl;
        return hash;
    }
};

struct DJBHash
{
    size_t operator()(const string& str)
    {
        size_t hash = 5381;
        for (auto ch : str)
        {
            hash += (hash << 5) + ch;
        }

        //cout << "DJBHash:" << hash << endl;
        return hash;
    }
};

template<size_t N,
    class K = string,
    class Hash1 = BKDRHash,
    class Hash2 = APHash,
    class Hash3 = DJBHash>
class BloomFilter
{
public:
    void Set(const K& key)
    {
        Hash1 hashi1;
        Hash2 hashi2;
        Hash3 hashi3;

        size_t hash1 = hashi1(key) % N;
        _bs.set(hash1);

        size_t hash2 = hashi2(key) % N;
        _bs.set(hash2);

        size_t hash3 = hashi3(key) % N;
        _bs.set(hash3);

        /* cout << hash1 << endl;
         cout << hash2 << endl;
         cout << hash3 << endl << endl;*/
    }

    bool Test(const K& key)
    {
        size_t hash1 = Hash1()(key) % N;
        if (_bs.test(hash1) == false)
            return false;

        size_t hash2 = Hash2()(key) % N;
        if (_bs.test(hash2) == false)
            return false;

        size_t hash3 = Hash3()(key) % N;
        if (_bs.test(hash3) == false)
            return false;

        return true;
    }

private:
    lx::bitset<N> _bs;
};