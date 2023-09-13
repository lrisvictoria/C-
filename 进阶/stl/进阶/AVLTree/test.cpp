#include "AVLTree.h"
#include <vector>

int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}

	return 0;
}

//int main()
//{
//	const int N = 10000000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(i);
//	}
//
//	//RBTree<int, int> rbt;
//	//for (auto e : v)
//	//{
//	//	rbt.Insert(make_pair(e, e));
//	//	//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
//	//}
//	//cout << rbt.IsBalance() << endl;
//	//cout << rbt.Height() << endl;
//	//cout << rbt._rotateCount << endl;
//
//
//	AVLTree<int, int> avlt;
//	for (auto e : v)
//	{
//		avlt.Insert(make_pair(e, e));
//		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
//	}
//	cout << avlt.IsBalance() << endl;
//	cout << avlt.Height() << endl;
//	//cout << avlt._rotateCount << endl;
//
//
//	return 0;
//}