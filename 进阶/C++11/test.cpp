#include <iostream>
#include <vector>
#include <string>

using namespace std;

//struct Point
//{
//	Point(int x, int y)
//		:_x(x)
//		,_y(y)
//	{
//		cout << "Point(int x, int y)" << endl;
//	}
//
//	int _x;
//	int _y;
//};
//
//// һ�нԿ��� {} ��ʼ�������ҿ��Բ�д��ֵ����
//// �ճ����岻Ҫȥ�� =����������Ҫ�ܿ���
//int main()
//{
//	int x = 1;
//	int y = { 2 }; // ����֧��������ʼ��
//	int z{ 3 };// right
//	int a1[] = { 1, 2,3 };
//	int a2[]{ 1, 2, 3 }; // ����������ʼ��Ҳ��
//
//	// ���ʶ��ǵ��ù��캯��
//	Point p(1, 2);
//	Point p1 = { 1, 3 }; //�᲻����ù��캯��? �� �����Ƕ�������캯������ʽ����ת��
//	Point p2{ 2, 2 }; // �᲻����ù��캯��? ��
//
//	const Point& r = { 3, 3 }; // ��ʱ������г���
//
//	int* p1 = new int[3] {1, 2, 3};
//	Point* ptr = new Point[2]{ {1, 2}, {2, 3} }; // ��û����������ʱ�鸡�˺ܶ࣬������������
//
//
//	return 0;
//}

int main()
{
	vector<int> v1 = { 1, 2 }; // �����б��ʼ��֧�ֵģ������в�ͬ�Ĺ���
	// ���ﱾ��Ҳ��һ������
	// ����б���� initializer_list
	auto il = { 10, 20, 30 };
	initializer_list<int> il = { 10, 20, 30 };
	cout << typeid(il).name() << endl;

}