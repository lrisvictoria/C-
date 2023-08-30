#include <iostream>
#include <set>
#include <map>

using namespace std;

void test_set1()
{
    // 排序+去重
    // 去重原理：一个值已经有了，我们就不插入
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(5);

    // 迭代器是中序遍历
    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    auto pos = s.find(30);  // O(logN)
    //auto pos = find(s.begin(), s.end(), 3); // 算法库中 O(N)
    // 防止找不到崩溃，找不到 pos 就是找到最后，最后一个迭代器，要判断
    if (pos != s.end())
        s.erase(pos);

    s.erase(4); // 理解为用上面 find + erase(pos) 实现

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    // count
    // 返回值出现了几次，对于 set 没有用
    // set 只会返回 1 或 0

    // 判断在不在，效率和 set 中 find 等价
    if (s.count(5))
    {
        cout << s.count(5) << endl;
    }

    std::set<int> myset;
    std::set<int>::iterator itlow, itup;

    for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

    // 迭代器区间要求左闭右开，所以 upper_bound 找 >
    // 删除 [25, 60]
    //itlow = myset.lower_bound(30);                //       返回 >= 30 的第一个位置
    //itup = myset.upper_bound(60);                 //       返回 > 60 的第一个位置

    //std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
    auto ret = myset.equal_range(30); // 返回的是 pair
    // 和 count 类似，找到区间内都是等于 30 的值，若没有找到则会返回大于等于 30 的第一个值
    // 在 set 中只有一个 30，所以无意义，可以直接用 find 删除
    itlow = ret.first; // 左边界第一个等于 30，找不到返回大于 30 的第一个值，右边界为大于 30 的第一个值
    itup = ret.second;

    // 返回区间：[25, 70)
    cout << *itlow << " " << *itup << endl;

    myset.erase(itlow, itup);

    for (auto e : myset)
    {
        cout << e << " ";
    }
    cout << endl;


    set<pair<int, int>> s1;
    s1.insert({ 3, 1 });

    for (auto e : s1)
    {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;
}


void test_set2()
{
    // 允许键值冗余 排序
    multiset<int> s;
  
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(6);

    s.insert(7);
    s.insert(7);
    s.insert(7);
    s.insert(7);
    s.insert(7);
    s.insert(8);

    for (auto e : s)
    {
        cout << e << ' ';
    }
    cout << endl;

    auto pos = s.find(7); // 返回的 7 是中序的第一个7（旋转）
    while (pos != s.end())
    {
        cout << *pos << " ";
        ++pos;
    }
    cout << endl;

    // 删 7 
    // 找不到，first, second  返回 >= 7 的值
    // 返回一个不存在的区间
    auto ret = s.equal_range(7); // 返回的是 pair
   
    auto itlow = ret.first; // 左边界第一个等于 30，找不到返回大于 30 的第一个值，右边界为大于 30 的第一个值
    auto itup = ret.second;

    // cout << *itlow << " " << *itup << endl;

    s.erase(itlow, itup);

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    // count equal_range 专门设计multi
}

// set 不能修改值，它的迭代器都是 const 迭代器
// map 中存储数据时 piar 存储的
// pair<const key_type, mapped_type> key 不能改加 const ，会破坏接口，value 可以改 
// insert 的是一个 pair

void test_map1()
{
    map<string, string> dict;
    pair<string, string> kv1("insert", "插入");
    dict.insert(kv1);

    dict.insert(pair<string, string>("sort", "排序"));
   
    // c++98
    dict.insert(make_pair("string", "字符串"));
    dict.insert(make_pair("vector", "顺序表"));
    
    // c++98 只支持单参数构造函数隐式类型转换
    // c++11 支持多参数构造函数隐式类型转换
    dict.insert({ "erase", "删除" }); // 等价于调用 pair 的构造
}

void test_map2()
{
    map<string, string> dict;
    dict.insert(make_pair("string", "字符串"));
    dict.insert(make_pair("sort", "排序"));
    dict.insert(make_pair("apple", "苹果"));

    // make_pair 定义成内联，没有效率问题
    // make_pair 表现大约调用构造，返回；实际会有优化

    std::map<std::string, std::string>::iterator it = dict.begin();
    while (it != dict.end())
    {
        // cout << *it << " "; // error ，不支持直接打印 *it，*it 返回的是 pair
        cout << (*it).first << ":" << (*it).second << endl;
        cout << it->first << ":" << it->second << endl; // 用的多

        ++it;
    }
    cout << endl;

    // key 相同，value 不相同，stl中不插入，不覆盖；插入过程中，只比较 key
    dict.insert(make_pair("apple", "例子"));

}

void test_map3()
{
    // map 的第一个参数要支持比较大小，不支持就要自己写仿函数
    // 准确来说，map 第一个参数怎么都可以


    // 统计次数
    string arr[] = { "西瓜", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
    map<string, int> countMap;
    
    //for (auto e : arr)
    //{
    //	auto it = countMap.find(e);
    //    // 第一次出现
    //	if (it == countMap.end())
    //	{
    //		countMap.insert(make_pair(e, 1));
    //	}
    //	else
    //	{
    //		it->second++;
    //	}
    //}

    // [] 通过 key 返回 value
    for (auto e : arr)
    {
        countMap[e]++;
    }

    // 等价于
    /*mapped_type& operator[] (const key_type& k)
    {
        // insert 实现
        // insert 第二个参数给匿名对象默认值
        return (*((this->insert(make_pair(k, mapped_type()))).first)).second;

        // pair<iterator, bool> ret = insert(make_pair(k, mapped_type())));
        // return ret.first->second; // 取迭代器访问 second（value）
    }*/

    // 理解 insert 
    // pair<iterator, bool> insert(const value_type& val)
    // 1. key 已经在树里面，返回 pair<树里面 key 所在节点的 iterator, false>
    // 2. key 不在树里面，返回 pair<新插入key所在节点的 iterator, true>

    for (const auto& kv : countMap)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
}

void test_map4()
{
    map<string, string> dict;
    dict.insert(make_pair("string", "字符串"));
    dict.insert(make_pair("sort", "排序"));
    dict.insert(make_pair("insert", "插入"));

    cout << dict["sort"] << endl; // 查找和读
    dict["map"];                  // 插入
    dict["map"] = "映射,地图";     // 修改
    dict["insert"] = "xxx";       // 修改
    dict["set"] = "集合";         // 插入+修改
}

// multiple 由于数据可以多个存在，所以不提供 []
// insert 也没有 pair<iterator, bool> 这个重载

int main()
{
    // set 底层是红黑树，搜索树 
    // 关联式容器：数据之间有强关联性，不能随便插入数据
    // 序列式容器（类比线性表）：单纯存储数据，数据之间的关系不考虑
    test_map3();

    return 0;
}