#include <iostream>
#include <vector>
#include <string>

using namespace std;

class A
{
public:
	A(char p)
		:_p(p)
	{}
	void print()
	{
		cout << _p << endl;
	}
private:
	char _p;
};

int main()
{
	// double b = 1.1;
	// A a(vector<int>());

	double p = 1;
	A a(p);

	/*a.print();*/

	return 0;
}