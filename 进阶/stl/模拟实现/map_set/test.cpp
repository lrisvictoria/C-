#include <iostream>
#include <string>

using namespace std;

#include "MyMap.h"
#include "MySet.h"
#include "RBTree.h"

void func(const lx::map<int, int>& m)
{
	//auto mit = m.begin();
	lx::map<int, int>::const_iterator mit = m.begin();
	while (mit != m.end())
	{
		// �����޸�key�������޸�value
		// mit->first = 1;
		// mit->second = 2;

		cout << mit->first << ":" << mit->second << endl;
		++mit;
	}
	cout << endl;
}

int main()
{
	lx::map<int, int> m;
	m.insert(make_pair(1, 2)); 
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));

	lx::map<int, int>::iterator mit = m.begin();

	while (mit != m.end())
	{
		// �������޸� key �������޸� value
		
		// mit->first = 1;
		mit->second = 2;

		//cout << (*mit).first << " " << (*mit).second << endl;
		cout << mit->first << " " << mit->second << endl;
		++mit;
	}

	for (const auto& kv : m)
	{
		cout << kv.first << " " << kv.second << endl;
	}
	

	lx::set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(4);

	lx::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		if (*it % 2 == 0)
		{
			//s*it = 1;
			// *it = 1;
		}

		cout << *it << " ";
		++it;
	}

	lx::map<string, string> dict;
	dict.insert(make_pair("sort", "xxx"));
	dict["left"]; // ����

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
	 

	dict["left"] = "���"; // �޸�
	dict["sort"] = "����"; // �޸�
	dict["right"] = "�ұ�"; // ����+�޸�

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;

	return 0;
}
