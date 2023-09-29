#include <iostream>

using namespace std;

#include "MyMap.h"
#include "MySet.h"
#include "RBTree.h"

int main()
{
	lx::map<int, int> m;
	m.insert(make_pair(1, 2));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(2, 2));

	lx::map<int, int>::iterator mit = m.begin();

	while (mit != m.end())
	{
		cout << (*mit).first << " " << (*mit).second << endl;
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
		cout << *it << " ";
		++it;
	}


	return 0;
}
