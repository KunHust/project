#define _CRT_SECURE_NO_WARNINGS //scanf����ʹ��
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
			printf("�����������������,��������ͨ�����,���ﵥ��,�������\n");
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
				printf("��ѡ��Ҫ�������Ʒ:");
				getchar();
				scanf("%c", &G.name);
				if (G.name != g.name)
				{
					printf("��Ʒ�����ڣ�������\n");
					continue;
				}
				break;
			}
			while (3)
			{
				printf("��������Ʒ����ͨ�����:");
				scanf("%d", &G.line);
				if (G.line != g.line)
				{
					printf("��Ʒ��������ѡ���ͨ����������\n");
					continue;
				}
				break;
			}
			while (4)
			{
				printf("�����빺������:");
				scanf("%d", &G.number);
				if (G.number > g.number)
				{
					printf("������Ʒ������������\n");
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
			printf("���㣺%d\n", f);
		}
		if (g.number == 0)
		{
			printf("�ܱ�Ǹ����ʱȱ����");
			break;
		}
		a = 2;
		continue;
	}

	return 0;
}