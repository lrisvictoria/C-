#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

//namespace �������һ����

//���c���Ե�������ͻ����
//����

//�����ھֲ�
//#include<stdio.h>
//int main()
//{	
//	//c���Զ��������ʱ�����ǹؼ���
//	//int long = 10;//����
//	
//	int scanf = 10;
//	int strlen = 10;//���ܱ����
//
//	//������ͻ
//	//C���Կ�����������������scanf��strlen����
//	//�����ҵĴ�����������������������������
//	//���﷨�Ƕȣ������������Υ��
//	
//	//��������ͻ�ˣ���������scanf�⺯����scanf������ֵ
//
//	//������Ϣ��������Ϊ�������������ĺ���
//
//	//�������з��Ͼͽ�ԭ����scanf���ᵽȫ��ȥ�ң������ҽ���
//	//���Ǿͻ����scanf����
//	
//	//C���Խ�����˳�ͻ������
//	scanf("%d", &scanf);//err
//	printf("%d\n", scanf);
//	
//
//	return 0;
//}

//������ȫ�֣������޷������
//#include<stdio.h>
//int scanf = 10;
//int strlen = 20;
//
//int main()
//{
//	return 0;
//}

//�����ں�����Ҳ���кܶ�����
//c++��Ϊ�˽��������⣬����������ռ䣬���ָ���

//����������������

//�����ռ䶨������������ռ���
//#include "List.h"
//namespace anduin
//{
//	int scanf = 10;
//	int strlen = 20;
//
//	//�����Զ��庯�����޷�ֱ�ӵ��ã���Ҫָ��
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//	//�����ռ�Ƕ�������ռ�
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//int main()
//{
//	//Ĭ�Ϸ��ʵ��Ǿֲ�����ȫ�ֵ�
//	//printf("%d", scanf);//��ӡ���ǵ�ַ
//	//�ͽ�ԭ�����ھֲ�����ȫ����
//	//��ӡ���Ǻ����ĵ�ַ
//
//	//ָ�����������ռ�anduin�е�
//	printf("%x\n", anduin::scanf);//::�������޶�����ָ���������
//	
//	//Add(3, 4);//����û��ָ����
//	printf("%d\n", anduin::Add(3, 4));
//
//	//��ε���N3�е�Sub����
//	printf("%d\n", anduin::N3::Sub(3,4));
//	
//	//�����ڲ�ͬ�ļ��ﶨ����ͬ���ֵ������ռ�,�ڰ�����Ӧ��ͷ�ļ���
//	//������������Ǻϲ���һ�������ռ���
//	anduin::ListNode* phead = NULL;
//	return 0;
//}

//Ƕ�׶�����ʵ��ҵ�������źܴ������
//�������ò�ͬҵ���е���ͬ������Ч����

#include <iostream>
//c++��Ϊ�˷�ֹ������ͻ��
//�ѱ�׼���Լ�������Ķ�����������һ��std�������ռ���

//����Ҫʹ�ñ�׼���еĶ����������ַ�ʽ
//1.ָ�������ռ� -> �鷳��ÿ���ط���Ҫָ��������������淶��

//2.��std����չ��(��Ҫ��)��������Ķ���ȫ���ϵ�ȫ���� -> 
//�����������ˣ���������Լ�����Ķ����Ϳ��ͻ�ˣ���û�취�����
//���Թ淶�Ĺ�����Ŀ���ǲ��Ƽ����ַ�ʽ�ģ��ճ���ϰ����ν

//3.�Բ��ֳ��õĿ�����Ķ���չ�� -> ���1��2���еķ���
//��Ŀ��Ҳ�ᾭ����

//using namespace std;//2

//using std::cout;//3������չ��
//using std::endl;//3
//
//int main()
//{
//	std::cout << "hello world" << std::endl;//1
//	
//	cout << "hello world" << endl;//2
//	return 0;
//}

//c++�Ŀ��ǲ���.h��
//#include <iostream.h>//��һ��ı�׼��������µı������ò��ˣ�vc6.6����
//��.h����û��std�����ռ�ģ�Ϊ�����º��ϵ����֣���ȥ���ˣ�Ҳ������c

//�������޶���::Ҳ������c������ʹ��
//int a = 10;
//int main()
//{
//	int a = 1;
//	printf("%d\n", a);//1
//	//����ȫ�ֵ�
//	printf("%d\n", ::a);//10
//	//ָ��ȥ������ߵ��򣬿հױ�ʾȫ���򣬷���ȫ��
//}


//c++����������
//c������<stdio.h>��
//c++��<iostream>�У�io�����

#include <iostream>

//cout������ʵ������������˽�һ�£���ס����ʹ��
//ostream ����ȫ�ֶ��� cout
//istream ����ȫ�ֶ��� cin
//endl ȫ�ֵĻ��з���
//int main()
//{
//	std::cout << "hello world" << std::endl;//�ַ���ͨ��<<�������
//
//	//����c����printf��scanf��������ʲô��-> �Զ�ʶ�����ͣ�ԭ���������� + ��������أ��Ժ��ٽ���
//	int a = 10;
//	int* p = &a;
//	printf("%d %p\n", a, p);
//
//	//c++���ǿ����Զ�ʶ������
//	std::cout << a << "," << p << std::endl;//","Ϊ���ӵĶ���
//
//	char str[10];
//	std::cin >> a;//�ӿ���̨�������������
//	std::cin >> str;
//
//	std::cout << a << "," << str << std::endl;
//}

//using namespace std;
//struct Person
//{
//	char name[10];
//	int age;
//};
//int main()
//{
//	int a = 0;
//	cin >> a;//�Ա�scanf("%d", & a);
//	cout << a << endl;
//
//	struct Person p = { "С��",10 };
//	//c��������������
//	printf("name:%s\n age:%d\n", p.name, p.age);//��ʽ�����
//	//c++����ͺ�ʹ��
//	cout << "name:" << p.age << "\n" << "age:" << p.age << endl;
//	//һ��coutֻ�����һ����
//	//�ۺϿ��Ի����ã��ĸ����þ����ĸ�
//
//	return 0;
//}

//ȱʡ����
//void test(int a = 0)
//{
//	std::cout << a << std::endl;
//}
//int main()
//{
//	test(10);//����ʹ��ָ����ʵ��
//
//	test();//������ʹ�ò�����Ĭ��ֵ
//	return 0;
//}

//ȱʡ��������
//ȫȱʡ���� - ȫ��������ȱʡֵ
//��ȱʡ���� - ���ֲ�����ȱʡֵ
//�����Ǵ�������ȱʡ��������������
//ʵ���Ϻ����������ף������Ǵ�����Ӧ��λ�õģ����ȱ�ٵĲ������ұߵ�ֵ
//��ô����ʱ��ָ�򴫸�ȱ�Ĳ���ʱ���ᵼ�´����������δﲻ����Ҫ��Ч��
//ֻ�д�������ȱʡ���ܰѶ�Ӧ��ֵ������Ӧ��λ��
using namespace std;
//ȫȱʡ����
//void TestFunc(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
////��ȱʡ����
////void TestFunc(int a, int b = 20, int c = 30)//void TestFunc(int a = 10, int b, int c = 30)//err
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////}
//
//int main()
//{
//	TestFunc(1, 2, 3);
//	TestFunc();
//	TestFunc(1);
//	TestFunc(1, 2);
//}

//void TestFunc(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	//���ٴ���һ��
//	TestFunc(1, 2, 3);
//	TestFunc(1);
//	TestFunc(1, 2);
//}

//ȱʡ������������ʲô�����ø����

//��������
//c���Բ�������ͬ������
//c++���� -> �������� -> ������ͬ (�������Ͳ�ͬ�����߸�����ͬ)
//ȱʡ������������(����������ͬ������������ͬ)
//int Add(int left = 10, int right = 20)
//{
//	return left + right;
//}
//char Add(char left, char right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
////��
//void f(int a, int b, int c = 1)//1
//{
//
//}
//void f(int a, int b)//2
//{
//
//}
////1,2���ɺ������أ�������ͬ
////�����������ò���ȷ���޷�ʶ��
//int main()
//{
//	cout << Add() << endl;
//	cout << Add(1, 2) << endl;//������ ��������Ĭ���㳣��
//	cout << Add('1', '2') << endl;
//	cout << Add(1.1, 2.2) << endl;
//
//	f(1, 2, 3);
//	//f(1, 2);//err
//	return 0;
//}

//�������ؽ����C�����кܶ�����

//ע��������void*��������
//void*��Ȼ���Լ�������ָ�룬���ǽ���ʱ�������Ͳ�ͳһ
//��Ҫһ���ֽ�һ���ֽڽ�����������Ҫ֪��������С����Ҫ��һ������
//void swap(int* a, int* b)
//{
//
//}
//void swap(double* a, double* b)
//{
//
//}
//int main()
//{
//	int x = 0, y = 1;
//	swap(&x, &y);
//	double m = 1.1, n = 2.2;
//	swap(&m, &n);
//	return 0;
//}

//ѧϰ��Щϸ����﷨
//1.��Щ�﷨��һ���̶���c����һЩ�����õ�������
//2.ѧϰ��Щ��Ҳ��Ϊ����ѧϰc++��Ͷ������̵�

//����
//int main()
//{
//	int a = 10;
//	//b��a������(����)
//	int& b = a;
//
//	b = 20;
//	
//	int& c = b;
//	c = 30;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	//a,b,c����һ��ռ�
//	//a,b,c��ַ��ͬ
//	return 0;
//}
void swap(int* p1, int* p2)//c����д��
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void swap(int& r1, int& r2)//���ã������int&����Ϊint
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}
int main()
{
	int a = 1, b = 2;
	swap(&a, &b);
	swap(a, b);
	return 0;
}