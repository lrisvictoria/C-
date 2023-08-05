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
    //auto pos = find(s.begin(), s.end(), 3); // �㷨���� O(N)
    // ��ֹ�Ҳ����������Ҳ��� pos �����ҵ�������һ����������Ҫ�ж�
    if (pos != s.end())
        s.erase(pos);

    s.erase(4); // ���Ϊ������ find + erase(pos) ʵ��

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    // count
    // ����ֵ�����˼��Σ����� set û����
    // set ֻ�᷵�� 1 �� 0

    // �ж��ڲ��ڣ�Ч�ʺ� set �� find �ȼ�
    if (s.count(5))
    {
        cout << s.count(5) << endl;
    }

    std::set<int> myset;
    std::set<int>::iterator itlow, itup;

    for (int i = 1; i < 10; i++) myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

    // ����������Ҫ������ҿ������� upper_bound �� >
    // ɾ�� [25, 60]
    itlow = myset.lower_bound(30);                //       ���� >= 30 �ĵ�һ��λ��
    itup = myset.upper_bound(60);                 //       ���� > 60 �ĵ�һ��λ��

    // �������䣺[25, 70)
    cout << *itlow << " " << *itup << endl;

    myset.erase(itlow, itup);

    for (auto e : myset)
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