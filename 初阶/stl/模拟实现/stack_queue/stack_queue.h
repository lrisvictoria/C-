#pragma once

namespace lx
{
	// 容器适配器：对容器进行封装，改造，控制，适配结果
	// 模板参数和参数参数类似，能给缺省值，给 vector<T>
 	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con; // 根据模板实例化为链式 or 数组
	};

	// 队列不建议用 vector 作为缺省，因为 vector 没有头删
	// 虽然可以用 erase 强制适配，但是不建议
	// 库中没有 pop 用头删实现，所以不支持 vector
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front(); // vector 没有，库中调用的是 pop_front
			// _con.erase(_con.begin()); // 强制适配，不建议，vector 头删效率较低
		}

		T& front()
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_stack()
	{
		stack<int, vector<int>> st1;
		stack<int, list<int>> st2;

		stack<int> st3;

		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);
		while (!st1.empty())
		{
			cout << st1.top() << ' ';
			st1.pop();
		}
		cout << endl;

		st2.push(1);
		st2.push(2);
		st2.push(3);
		st2.push(4);
		while (!st2.empty())
		{
			cout << st2.top() << ' ';
			st2.pop();
		}
		cout << endl;

		st3.push(1);
		st3.push(2);
		st3.push(3);
		st3.push(4);
		while (!st3.empty())
		{
			cout << st3.top() << ' ';
			st3.pop();
		}
		cout << endl;
	}

	void test_queue()
	{
		/*std::queue<int, vector<int>> q1;
		q1.push(1);
		q1.push(2);
		q1.push(3);
		q1.push(4);

		while (!q1.empty())
		{
			cout << q1.front() << ' ';
			q1.pop();
		}
		cout << endl;*/

		std::queue<int, list<int>> q2;
		q2.push(1);
		q2.push(2);
		q2.push(3);
		q2.push(4);

		while (!q2.empty())
		{
			cout << q2.front() << ' ';
			q2.pop();
		}
		cout << endl;
	}
}