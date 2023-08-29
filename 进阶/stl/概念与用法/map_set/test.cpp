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
    //itlow = myset.lower_bound(30);                //       ���� >= 30 �ĵ�һ��λ��
    //itup = myset.upper_bound(60);                 //       ���� > 60 �ĵ�һ��λ��

    //std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
    auto ret = myset.equal_range(30); // ���ص��� pair
    // �� count ���ƣ��ҵ������ڶ��ǵ��� 30 ��ֵ����û���ҵ���᷵�ش��ڵ��� 30 �ĵ�һ��ֵ
    // �� set ��ֻ��һ�� 30�����������壬����ֱ���� find ɾ��
    itlow = ret.first; // ��߽��һ������ 30���Ҳ������ش��� 30 �ĵ�һ��ֵ���ұ߽�Ϊ���� 30 �ĵ�һ��ֵ
    itup = ret.second;

    // �������䣺[25, 70)
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
    // �����ֵ���� ����
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

    auto pos = s.find(7); // ���ص� 7 ������ĵ�һ��7����ת��
    while (pos != s.end())
    {
        cout << *pos << " ";
        ++pos;
    }
    cout << endl;

    // ɾ 7 
    // �Ҳ�����first, second  ���� >= 7 ��ֵ
    // ����һ�������ڵ�����
    auto ret = s.equal_range(7); // ���ص��� pair
   
    auto itlow = ret.first; // ��߽��һ������ 30���Ҳ������ش��� 30 �ĵ�һ��ֵ���ұ߽�Ϊ���� 30 �ĵ�һ��ֵ
    auto itup = ret.second;

    // cout << *itlow << " " << *itup << endl;

    s.erase(itlow, itup);

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    // count equal_range ר�����multi
}

int main()
{
    // set �ײ��Ǻ������������ 
    // ����ʽ����������֮����ǿ�����ԣ���������������
    // ����ʽ������������Ա��������洢���ݣ�����֮��Ĺ�ϵ������
    test_set2();

    return 0;
}