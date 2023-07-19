#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

using namespace std;

void test_stack_queue()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	// 不能随便出数据
	// 取栈顶，出栈顶

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void test()
{
	stack<int, list<int>> st;

	st.push(1);
	st.push(1);
	st.push(1);
	st.push(1);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test_op()
{
	srand(time(0));
	const int N = 1000000;
	vector<int> v1;
	vector<int> v2;
	v1.reserve(N);
	v2.reserve(N);

	deque<int> dq1;
	deque<int> dq2;


	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		dq1.push_back(e);
		dq2.push_back(e);
		// v2.push_back(e);
	}

	int begin1 = clock();
	// 先拷贝到vector
	for (auto e : dq1)
	{
		v1.push_back(e);
	}

	// 排序
	sort(v1.begin(), v1.end());

	// 拷贝回去
	size_t i = 0;
	for (auto& e : dq1)
	{
		e = v1[i++];
	}

	int end1 = clock();

	int begin2 = clock();
	// sort(v2.begin(), v2.end()); // deque copy 直接和 vector sort 比较，拷贝的代价很低，所以两者比较相差不大
	sort(dq2.begin(), dq2.end());

	int end2 = clock();
	// deque拷贝到 vector sort 和 deque 直接 sort 比较，deque 慢
	printf("deque copy vector sort:%d\n", end1 - begin1);
	printf("deque sort:%d\n", end2 - begin2);
}

int main()
{
	/* Container adaptor
	 栈为适配器：现有的东西转换成想要的东西
	
	 栈和队列使用了全新的实现方式
	 让其他容器来实现
	 封装了其他容器，数据存在其他里
	 根据要求实现出相关接口
	 适配器的本质是一种复用
	 适配器思想上是一种设计模式*/

	// 没有迭代器，不支持随便遍历

	//test_stack_queue();
	test_op();

	return 0;
}