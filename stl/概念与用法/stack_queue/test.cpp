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

	// ������������
	// ȡջ������ջ��

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
	 ջΪ�����������еĶ���ת������Ҫ�Ķ���
	
	 ջ�Ͷ���ʹ����ȫ�µ�ʵ�ַ�ʽ
	 ������������ʵ��
	 ��װ���������������ݴ���������
	 ����Ҫ��ʵ�ֳ���ؽӿ�
	 �������ı�����һ�ָ���
	 ������˼������һ�����ģʽ*/

	// û�е���������֧��������

	//test_stack_queue();
	test();

	return 0;
}