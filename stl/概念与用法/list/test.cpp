// list �ײ���˫���ͷѭ������

#include <iostream>
#include <list>

using namespace std;

int main()
{
	// û�� reserve or resize ������Ҫ�������Ŀռ�
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	// ֻ���õ�����������û�� []
	// �������� [] ������������һ��Ϊ n^2

	auto it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << ' ';
	}
	cout << endl;

	return 0;
}