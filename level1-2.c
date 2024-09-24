#define _CRT_SECURE_NO_WARNINGS //scanf函数使用
#include<stdio.h>

int main()
{
	int c = 0, d = 0, e = 0, f = 0;
	printf("请输入货物总价:");
	scanf("%d", &c);
	while (d < c)
	{
		while (1)
		{
			printf("请投币(仅支持一次投币1，2，5元)");
			scanf("%d", &e);
			if (e == 1 || e == 2 || e == 5)
			{
				d += e;
				break;
			}
			else
			{
				printf("仅支持一次投币1，2，5元，请重试\n");
			}
		}
	}
	f = d - c;
	printf("找零：%d", f);

	return 0;
}