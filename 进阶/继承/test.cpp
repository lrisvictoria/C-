#include <iostream>

using namespace std;


// ���������������֮һ

// �����Ǹ���
// ������(����)���ݼ̳з�ʽ���̳л���(����)����Ϣ

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
	//protected:
private:
	string _name = "peter"; // ����
	int _age = 18;  // ����
};

class Student : public Person
{
public:
	void func()
	{
		// ����˽�г�Ա�������ò���(����ʲô��ʽ�̳�)
		//cout << "name:" << _name << endl;
		//cout << "age:" << _age << endl;
	}
protected:
	int _stuid; // ѧ��
};

class Teacher : public Person
{
protected:
	int _jobid; // ����
};


// ������˽����Ϊ�����޶���������Ϊ��һ��

// ����ĳ�Ա�������еķ��ʷ�ʽ��ʲô����

// ���ɼ����﷨�����Ʒ��ʣ��� private Ҳ��һ����������������涼������

// class Ĭ����˽�м̳�
// struct Ĭ���ǹ��м̳�

// ˽�м̳кͱ����̳е����������ǵ������౻�̳�ʱ���������޷�����˽�м̳й�����ĳ�Ա

// �ܽ᣺
// 1. ���� private ��Ա�̳в��ɼ�
// 2. �����޶����ͼ̳з�ʽȡС
// 3. ʵ����һ�㶼�� public �̳У����б�����Ա public �̳�


int main()
{
	Student s; // �̳��˸�������ֺ����䣬print����
	Teacher t;
	s.Print();
	t.Print();

	return 0;
}