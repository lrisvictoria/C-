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
	test();

	return 0;
}