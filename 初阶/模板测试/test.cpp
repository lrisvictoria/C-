#include <iostream>

using namespace std;

template<class T>

class Stack
{
public:
	Stack(int capacity, int size)
		:_capacity(capacity)
		,_size(size)
	{}

	void Push(const T& data); // ©иртсц

private:
	T* _st;
	int _capacity;
	int _size;
};


void Stack<T>::Push(const T& data)
{

}