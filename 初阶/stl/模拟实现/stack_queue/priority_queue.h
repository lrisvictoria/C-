#pragma once

// 为什么要写仿函数？因为不想让比较的地方写死，有不同的比较方式，这样切换大小堆更加方便
// 函数指针可读性差，且如果要传函数指针，在构造函数的地方就要传，得保存在对象中



namespace lx
{
	template<class T>
	class Less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	class Greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	private:
		// 提供给成员变量的函数，设为私有
		void AdjustDown(int parent)
		{
			Compare com; // 另一种泛型，存储的是比较的类型
			int child = 2 * parent + 1;

			while (child < _con.size())
			{
				// if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1])) // 2 > 1 就是 1 < 2 
				{
					++child;
				}

				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}

		void Adjustup(int child)
		{
			Compare com;

			int parent = (child - 1) / 2;

			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}


	public:
		priority_queue()
		{}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				++first;
			}

			// 建堆
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				AdjustDown(i);
			}
		}

		void push(const T& val)
		{
			_con.push_back(val);
			Adjustup(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		size_t size()
		{
			return _con.size();
		}

		const T& top()
		{
			return _con[0];
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	void test_priority_queue1()
	{
		priority_queue<int,vector<int>, Less<int>> pq1;
		pq1.push(3);
		pq1.push(5);
		pq1.push(1);
		pq1.push(4);

		while (!pq1.empty())
		{
			cout << pq1.top() << ' ';
			pq1.pop();
		}
		cout << endl;

		/*priority_queue<int, vector<int>, greater<int>> pq2;
		pq1.push(3);
		pq1.push(5);
		pq1.push(1);
		pq1.push(4);

		while (!pq1.empty())
		{
			cout << pq1.top() << ' ';
			pq1.pop();
		}
		cout << endl;*/
	}

	class Date
	{
		friend ostream& operator<<(ostream& _cout, const Date& d);
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			: _year(year)
			, _month(month)
			, _day(day)
		{}
		bool operator<(const Date& d)const
		{
			return (_year < d._year) ||
				(_year == d._year && _month < d._month) ||
				(_year == d._year && _month == d._month && _day < d._day);
		}
		bool operator>(const Date& d)const
		{
			return (_year > d._year) ||
				(_year == d._year && _month > d._month) ||
				(_year == d._year && _month == d._month && _day > d._day);
		}
		
	private:
		int _year;
		int _month;
		int _day;
	};

	// 有些编译器支持把友元写到类中，但是不建议
	ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}

	class LessDate
	{
	public:
		bool operator()(const Date* pd1, const Date* pd2)
		{
			return *pd1 < *pd2;
		}
	};

	/*template<>
	class Less<Date*>
	{
	public:
		bool operator()(const Date* x, const Date* y)
		{
			return *x < *y;
		}
	};*/

	// 偏特化，特化指针类型
	template<class T>
	class Less<T*>
	{
	public:
		bool operator()(const T* x, const T* y)
		{
			return *x < *y;
		}
	};

	void test_priority_queue2()
	{
		
		//priority_queue<Date, vector<Date>, Greater<Date>> pq; // 仿函数回去调用自定义类型的比较，如果没有就报错
		//pq.push({ 2023, 1, 11 });
		//pq.push({ 2022, 1, 10 });
		//pq.push({ 2010, 1, 20 });

		//pq.push(Date(1999 ,3, 11 ));
		//pq.push(Date(2028, 1, 10 ));
		//pq.push(Date(2019, 1, 20 ));

		//while (!pq.empty())
		//{
		//	cout << pq.top() << " ";
		//	pq.pop();
		//}
		//cout << endl;

		// 优先级队列中存节点的指针
		// 本意是要将指针指向的内容比较
		// 但这时比较按地址比较，仿函数就要自己写

		// 模板特化知识
		// 要进行多次比较，但是后面两个模板参数不想写，怎么办？模板特化
		// 如果偶尔用则没必要写
		
		
		// priority_queue<Date*, vector<Date*>, LessDate> pq; // 仿函数回去调用自定义类型的比较，如果没有就报错

		// Date* ，走特化的类
		lx::priority_queue<Date*> pq;
		pq.push(new Date(1999, 3, 11));
		pq.push(new Date(2028, 1, 10));
		pq.push(new Date(2019, 1, 20));

		while (!pq.empty())
		{
			cout << *pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}