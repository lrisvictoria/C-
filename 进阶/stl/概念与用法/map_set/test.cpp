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


}

void test_set2()
{

}

int main()
{
    // set 底层是红黑树，搜索树 
    // 关联式容器：数据之间有强关联性，不能随便插入数据
    // 序列式容器（类比线性表）：单纯存储数据，数据之间的关系不考虑
    test_set1();

    return 0;
}