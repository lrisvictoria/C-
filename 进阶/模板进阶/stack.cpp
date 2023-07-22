#include"Stack.h"

using namespace std;

namespace bit
{
	// 类模板的跨文件声明和定义分离
	// 不能在类外部的类模板成员上指定默认参数
	// template<class T, class Container = std::deque<T>>
	template<class T, class Container>
	void stack<T, Container>::push(const T& x)
	{
		_con.push_back(x);
	}
		
	template<class T, class Container>
	void stack<T, Container>::pop()
	{
		_con.pop_back();
	}

	void A::func1(int i)
	{}

	//void func2();

	
	// 显示实例化，template 是告诉编译器，这里是对类模板进行显示实例化
	template
		class stack<int, vector<int>>;

	template
	class stack<double, deque<double>>;

	//template
	//	class stack<double>;
}
