#include <stdio.h>
int check_sys()
{
	int a = 1;
	//�����ƣ�0000 0000 0000 0000 0000 0000 0000 0001
	//ʮ�����ƣ�0x00000001
	char* p = (char*)&a;//char*ָ�������Ϊһ���ֽ�
	if (*p == 1)
		return 1;
	else
		return 0;
}
//��
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;//1�Ĵ�˻�С�˴洢����һλΪ00����01��ȡ����ֵ���ú�main�����н��յ�ֵ��ͬ��ֱ�ӷ���
//}
int main()
{
	int ret = check_sys();
	if (ret = 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}