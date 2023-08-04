#include <iostream>
#include <set>
#include <map>

using namespace std;

void test_set1()
{
    // ����+ȥ��
    // ȥ��ԭ��һ��ֵ�Ѿ����ˣ����ǾͲ�����
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(5);

    // ���������������
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
    // ��ֹ�Ҳ����������Ҳ��� pos �����ҵ�������һ����������Ҫ�ж�
    if (pos != s.end())
        s.erase(pos);

    s.erase(4); // ���Ϊ������ find + erase(pos) ʵ��

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    // set �ײ��Ǻ������������ 
    // ����ʽ����������֮����ǿ�����ԣ���������������
    // ����ʽ������������Ա��������洢���ݣ�����֮��Ĺ�ϵ������
    test_set1();

    return 0;
}