#define _CRT_SECURE_NO_WARNINGS //scanf����ʹ��
#include<stdio.h>

int main()
{
	int c = 0, d = 0, e = 0, f = 0;
	printf("����������ܼ�:");
	scanf("%d", &c);
	while (d < c)
	{
		while (1)
		{
			printf("��Ͷ��(��֧��һ��Ͷ��1��2��5Ԫ)");
			scanf("%d", &e);
			if (e == 1 || e == 2 || e == 5)
			{
				d += e;
				break;
			}
			else
			{
				printf("��֧��һ��Ͷ��1��2��5Ԫ��������\n");
			}
		}
	}
	f = d - c;
	printf("���㣺%d", f);

	return 0;
}