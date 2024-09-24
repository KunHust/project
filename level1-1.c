#define _CRT_SECURE_NO_WARNINGS //scanf函数使用
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
	printf("请依次输入货物种类,货物所在通道标号,货物单价,货物个数\n");
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