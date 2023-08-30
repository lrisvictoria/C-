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

// set �����޸�ֵ�����ĵ��������� const ������
// map �д洢����ʱ piar �洢��
// pair<const key_type, mapped_type> key ���ܸļ� const �����ƻ��ӿڣ�value ���Ը� 
// insert ����һ�� pair

void test_map1()
{
    map<string, string> dict;
    pair<string, string> kv1("insert", "����");
    dict.insert(kv1);

    dict.insert(pair<string, string>("sort", "����"));
   
    // c++98
    dict.insert(make_pair("string", "�ַ���"));
    dict.insert(make_pair("vector", "˳���"));
    
    // c++98 ֻ֧�ֵ��������캯����ʽ����ת��
    // c++11 ֧�ֶ�������캯����ʽ����ת��
    dict.insert({ "erase", "ɾ��" }); // �ȼ��ڵ��� pair �Ĺ���
}

void test_map2()
{
    map<string, string> dict;
    dict.insert(make_pair("string", "�ַ���"));
    dict.insert(make_pair("sort", "����"));
    dict.insert(make_pair("apple", "ƻ��"));

    // make_pair �����������û��Ч������
    // make_pair ���ִ�Լ���ù��죬���أ�ʵ�ʻ����Ż�

    std::map<std::string, std::string>::iterator it = dict.begin();
    while (it != dict.end())
    {
        // cout << *it << " "; // error ����֧��ֱ�Ӵ�ӡ *it��*it ���ص��� pair
        cout << (*it).first << ":" << (*it).second << endl;
        cout << it->first << ":" << it->second << endl; // �õĶ�

        ++it;
    }
    cout << endl;

    // key ��ͬ��value ����ͬ��stl�в����룬�����ǣ���������У�ֻ�Ƚ� key
    dict.insert(make_pair("apple", "����"));

}

void test_map3()
{
    // map �ĵ�һ������Ҫ֧�ֱȽϴ�С����֧�־�Ҫ�Լ�д�º���
    // ׼ȷ��˵��map ��һ��������ô������


    // ͳ�ƴ���
    string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
    map<string, int> countMap;
    
    //for (auto e : arr)
    //{
    //	auto it = countMap.find(e);
    //    // ��һ�γ���
    //	if (it == countMap.end())
    //	{
    //		countMap.insert(make_pair(e, 1));
    //	}
    //	else
    //	{
    //		it->second++;
    //	}
    //}

    // [] ͨ�� key ���� value
    for (auto e : arr)
    {
        countMap[e]++;
    }

    // �ȼ���
    /*mapped_type& operator[] (const key_type& k)
    {
        // insert ʵ��
        // insert �ڶ�����������������Ĭ��ֵ
        return (*((this->insert(make_pair(k, mapped_type()))).first)).second;

        // pair<iterator, bool> ret = insert(make_pair(k, mapped_type())));
        // return ret.first->second; // ȡ���������� second��value��
    }*/

    // ��� insert 
    // pair<iterator, bool> insert(const value_type& val)
    // 1. key �Ѿ��������棬���� pair<������ key ���ڽڵ�� iterator, false>
    // 2. key ���������棬���� pair<�²���key���ڽڵ�� iterator, true>

    for (const auto& kv : countMap)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
}

void test_map4()
{
    map<string, string> dict;
    dict.insert(make_pair("string", "�ַ���"));
    dict.insert(make_pair("sort", "����"));
    dict.insert(make_pair("insert", "����"));

    cout << dict["sort"] << endl; // ���ҺͶ�
    dict["map"];                  // ����
    dict["map"] = "ӳ��,��ͼ";     // �޸�
    dict["insert"] = "xxx";       // �޸�
    dict["set"] = "����";         // ����+�޸�
}

// multiple �������ݿ��Զ�����ڣ����Բ��ṩ []
// insert Ҳû�� pair<iterator, bool> �������

int main()
{
    // set �ײ��Ǻ������������ 
    // ����ʽ����������֮����ǿ�����ԣ���������������
    // ����ʽ������������Ա��������洢���ݣ�����֮��Ĺ�ϵ������
    test_map3();

    return 0;
}