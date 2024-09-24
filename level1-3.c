#define _CRT_SECURE_NO_WARNINGS //scanf函数使用
#include<stdio.h>
struct goods
{
	char name;
	int line;
	int price;
	int number;
}g, G;
int main()
{
	int a = 1, c = 0, d = 0, e = 0, f = 0;
	while (1)
	{
		switch (a)
		{
		case 1:
			printf("请依次输入货物种类,货物所在通道标号,货物单价,货物个数\n");
			scanf("%c", &g.name);
			scanf("%d", &g.line);
			scanf("%d", &g.price);
			scanf("%d", &g.number);

		case 2:
			printf("%d:", g.line);
			for (int i = 0; i < g.number; i++)
			{
				printf("%c", g.name);
			}
			printf(" %d\n", g.price);
			while (2)
			{
				printf("请选择要购买的商品:");
				getchar();
				scanf("%c", &G.name);
				if (G.name != g.name)
				{
					printf("商品不存在，请重试\n");
					continue;
				}
				break;
			}
			while (3)
			{
				printf("请输入商品所在通道标号:");
				scanf("%d", &G.line);
				if (G.line != g.line)
				{
					printf("商品不在您所选择的通道，请重试\n");
					continue;
				}
				break;
			}
			while (4)
			{
				printf("请输入购买数量:");
				scanf("%d", &G.number);
				if (G.number > g.number)
				{
					printf("超过商品数量，请重试\n");
					continue;
				}
				break;
			}
			c = g.price * G.number;
			g.number -= G.number;
			while (d < c)
			{
				while (5)
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
			printf("找零：%d\n", f);
		}
		if (g.number == 0)
		{
			printf("很抱歉，暂时缺货中");
			break;
		}
		a = 2;
		continue;
	}

	return 0;
}