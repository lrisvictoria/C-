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

	// 数据量大时 avl 树比红黑树旋转更多，高度会比红黑树小一点
	// 因为红黑树并不严格平衡，是近似平衡的

	// 当插入有序数据时，红黑树和avl数的旋转次数没有多大的差异，因为有序情况下插入数据很多时候红黑树都要旋转
	return 0;
}

// 由插入有效数据这一方面看，红黑树并没有比 avl 树优秀太多
// 红黑树和 avl 树是同一级别的选手
// 综合而言，红黑树在大多数情况的情况下，旋转次数会比 avl 更少
// 旋转的代价并不低
// 实践中使用红黑树的场景，比 avl 树多不少

// 如果插入删除并不是很多，查找很多，avl有点优势；反之，红黑树更优，比较吃得开
// avl 查找更快一点（高度低，但是 logN 差别也不大）