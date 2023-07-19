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
	// �ȿ�����vector
	for (auto e : dq1)
	{
		v1.push_back(e);
	}

	// ����
	sort(v1.begin(), v1.end());

	// ������ȥ
	size_t i = 0;
	for (auto& e : dq1)
	{
		e = v1[i++];
	}

	int end1 = clock();

	int begin2 = clock();
	// sort(v2.begin(), v2.end()); // deque copy ֱ�Ӻ� vector sort �Ƚϣ������Ĵ��ۺܵͣ��������߱Ƚ�����
	sort(dq2.begin(), dq2.end());

	int end2 = clock();
	// deque������ vector sort �� deque ֱ�� sort �Ƚϣ�deque ��
	printf("deque copy vector sort:%d\n", end1 - begin1);
	printf("deque sort:%d\n", end2 - begin2);
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
	test_op();

	return 0;
}