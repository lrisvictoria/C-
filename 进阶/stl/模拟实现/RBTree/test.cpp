#include "RBTree.h"

#include <vector>
//#include <iostream>
using namespace std;

int main()
{
	const int N = 100;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	RBTree<int, int> rbt;
	for (auto e : v)
	{
		rbt.Insert(make_pair(e, e));
		cout << "Insert:" << e << "->" << rbt.IsBalance() << endl;
	}
	cout << rbt.IsBalance() << endl;
	cout << rbt.Height() << endl;
	cout << rbt._rotateCount << endl;

	// ��������ʱ avl ���Ⱥ������ת���࣬�߶Ȼ�Ⱥ����Сһ��
	// ��Ϊ����������ϸ�ƽ�⣬�ǽ���ƽ���

	// ��������������ʱ���������avl������ת����û�ж��Ĳ��죬��Ϊ��������²������ݺܶ�ʱ��������Ҫ��ת
	return 0;
}

// �ɲ�����Ч������һ���濴���������û�б� avl ������̫��
// ������� avl ����ͬһ�����ѡ��
// �ۺ϶��ԣ�������ڴ�������������£���ת������� avl ����
// ��ת�Ĵ��۲�����
// ʵ����ʹ�ú�����ĳ������� avl ���಻��

// �������ɾ�������Ǻܶ࣬���Һܶ࣬avl�е����ƣ���֮����������ţ��ȽϳԵÿ�
// avl ���Ҹ���һ�㣨�߶ȵͣ����� logN ���Ҳ����