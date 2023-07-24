#pragma once

// ΪʲôҪд�º�������Ϊ�����ñȽϵĵط�д�����в�ͬ�ıȽϷ�ʽ�������л���С�Ѹ��ӷ���
// ����ָ��ɶ��Բ�����Ҫ������ָ�룬�ڹ��캯���ĵط���Ҫ�����ñ����ڶ�����



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
		// �ṩ����Ա�����ĺ�������Ϊ˽��
		void AdjustDown(int parent)
		{
			Compare com; // ��һ�ַ��ͣ��洢���ǱȽϵ�����
			int child = 2 * parent + 1;

			while (child < _con.size())
			{
				// if (child + 1 < _con.size() && _con[child + 1] > _con[child])
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1])) // 2 > 1 ���� 1 < 2 
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

			// ����
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

	// ��Щ������֧�ְ���Ԫд�����У����ǲ�����
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

	// ƫ�ػ����ػ�ָ������
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
		
		//priority_queue<Date, vector<Date>, Greater<Date>> pq; // �º�����ȥ�����Զ������͵ıȽϣ����û�оͱ���
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

		// ���ȼ������д�ڵ��ָ��
		// ������Ҫ��ָ��ָ������ݱȽ�
		// ����ʱ�Ƚϰ���ַ�Ƚϣ��º�����Ҫ�Լ�д

		// ģ���ػ�֪ʶ
		// Ҫ���ж�αȽϣ����Ǻ�������ģ���������д����ô�죿ģ���ػ�
		// ���ż������û��Ҫд
		
		
		// priority_queue<Date*, vector<Date*>, LessDate> pq; // �º�����ȥ�����Զ������͵ıȽϣ����û�оͱ���

		// Date* �����ػ�����
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