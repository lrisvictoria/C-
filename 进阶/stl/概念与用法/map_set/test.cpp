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
    //auto pos = find(s.begin(), s.end(), 3); // O(N)
    // 防止找不到崩溃，找不到 pos 就是找到最后，最后一个迭代器，要判断
    if (pos != s.end())
        s.erase(pos);

    s.erase(4); // 理解为用上面 find + erase(pos) 实现

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    // set 底层是红黑树，搜索树 
    // 关联式容器：数据之间有强关联性，不能随便插入数据
    // 序列式容器（类比线性表）：单纯存储数据，数据之间的关系不考虑
    test_set1();

    return 0;
}