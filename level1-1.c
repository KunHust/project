#define _CRT_SECURE_NO_WARNINGS //scanf����ʹ��
#include<stdio.h>
struct goods
{
	char name;
	int line;
	int price;
	int number;
}g;

int main()
{
	printf("�����������������,��������ͨ�����,���ﵥ��,�������\n");
	scanf("%c", &g.name);
	scanf("%d", &g.line);
	scanf("%d", &g.price);
	scanf("%d", &g.number);
	printf("%d:", g.line);
	for (int i = 0; i < g.number; i++)
	{
		printf("%c", g.name);
	}
	printf(" %d", g.price);

	return 0;
}