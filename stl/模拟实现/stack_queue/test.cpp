#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

#include "stack_queue.h"
#include "priority_queue.h"

//// �º���/��������
//template<class T>
//class Less
//{
//public:
//	// ʵ���Ͼ��������� ()
//	// �Ƚ��Զ������͵�ǰ�������������͵ıȽϷ���
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};

int main()
{
	lx::test_priority_queue2();
	
	// Less<int> lessfunc;

	// ������������������ָ��
	// �º������������������һ��ʹ��
	// �к���ָ��Ĺ���ȴ�Ⱥ���ָ���������
	// cout << lessfunc(1, 2) << endl;
	// cout << lessfunc.operator()(1, 2) << endl;
	return 0;
}