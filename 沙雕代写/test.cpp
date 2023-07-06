#include <stdio.h>
int check_sys()
{
	int a = 1;
	//二进制：0000 0000 0000 0000 0000 0000 0000 0001
	//十六进制：0x00000001
	char* p = (char*)&a;//char*指针解引用为一个字节
	if (*p == 1)
		return 1;
	else
		return 0;
}
//简化
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;//1的大端或小端存储，第一位为00或者01，取出的值正好和main函数中接收的值相同，直接返回
//}
int main()
{
	int ret = check_sys();
	if (ret = 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
}