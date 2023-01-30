#pragma once

class Stack
{
public:
	void Init();
	void push(int x);
	// ... 

	int* _a;
	int _capacity;
	int _top;
};