#define _CRT_SECURE_NO_WARNINGS //scanf函数使用
#include<stdio.h>
#include <stdlib.h>//exit函数使用
//1.添加货物时，输入不正确的通道标号，会提示并重试
//2.添加货物时,输入货品数量超过50，会提示并重试
//3.输入了售货机不存在的商品，会提示并重试
//4.输入通道标号时，若输入不正确的通道标号，会提示并重试
//5.输入通道标号时，若与所选择的商品名称不匹配，会提示并重试
//6.输入购买数量时，若超过了所选商品的数量，会提示并重试
//7.在确认购买信息时，购物车(五个位置)满了以后会提示，并且无法继续购买
//8.某次购物选择完货架上所有货物后，在确认购买信息时，会提示无法继续购买
//9.投币时选择的金额不是1，2，5，会提示并重试
//10.若所有商品都缺货的话，会提示并停机

struct goods
{
	char name;
	int line;
	int price;
	int number;
};

int main()
{
	int b = 1, d = 0, e = 0, f = 0, n = 0, h = 1, m = 0, j = 1, L = 0;
	struct goods g[5] = { '0',0,0,0 }; struct goods G[5] = { '0',0,0,0 };//设置两个结构体数组，g来储存货架上的商品信息，G来储存购物车里的商品信息
	while (1)
	{
		while (2)//用户输入不合理标号的处理
		{
			printf("----------------------------------------------------\n");
			printf("请选择通道以添加货物(输入0查看摆放情况)\n");
			scanf("%d", &b);//b代表选择的通道标号
			if (b > 5)
			{
				printf("提示：请正确输入通道标号\n");
				continue;
			}
			printf("----------------------------------------------------\n");
			break;
		}

		if (b == 0)
		{
			for (int i = 0; i < 5; i++)
			{
				L = i + 1;//1号通道的商品信息由g[0]来储存,L表示通道标号
				if (g[i].number != 0)
				{
					printf("%d:货物种类： %c 单价： %d元 数量： %d件\n", L, g[i].name, g[i].price, g[i].number);
				}
				else
				{
					printf("%d:暂未摆放商品\n", L);
				}
			}
			continue;
		}

		for (int i = b - 1;;)
		{
			switch (j)
			{
			case 1:
				printf("%d：请输入货物种类:", b);
				getchar();
				scanf("%c", &g[i].name);
			case 2:
				printf("%d：请输入货物单价(元)(输入0返回上一步):", b);
				scanf("%d", &g[i].price);
				if (g[i].price == 0)
				{
					j = 1;
					continue;
				}
			case 3:
				printf("%d：请输入货物数量(件)(输入0返回上一步):", b);
				scanf("%d", &g[i].number);
				if (g[i].number == 0)
				{
					j = 2;
					continue;
				}
				if (g[i].number > 50)
				{
					printf("提示：超过上限50(件),请重试\n");
					j = 3;
					continue;
				}
			case 4:
				printf("%d：请确认通道放置的货品信息(输入0返回上一步,输入1停止添加货物,输入除0,1以外的数字继续添加货物)\n%d：名称：%c 单价：%d 数量：%d\n", b, b, g[i].name, g[i].price, g[i].number);
				scanf("%d", &j);//单纯不想再引入变量
				if (j == 0)
				{
					j = 3;
					continue;
				}
			}
			break;
		}
		if (j == 1)
		{
			break;
		}
		else
		{
			j = 1;//初始化j，确保再次添加货物时switch(j)从case 1开始
			continue;
		}
	}
	printf("\n提示：摆放完毕,下面进入购买模式\n\n");
	for (int t = 0;;)//t++放在上面的话，到确认购买信息那步时一直返回到初始再选货物，(即后面的continue不能跳过放在开头的t++)，再到确认购买信息那里会显示之前撤销的选择
	{
		switch (h)
		{
		case 1:
			printf("----------------------------------------------------\n");
			for (int i = 0; i < 5; i++)
			{
				L = i + 1;
				printf("%d：", L);
				if (g[i].number == 0)
				{
					printf("已售罄\n");
				}
				else
				{
					for (int k = 0; k < g[i].number; k++)
					{
						printf("%c", g[i].name);
					}
					printf(" 单价:%d(元) 剩余:%d(件)\n", g[i].price, g[i].number);
				}
			}
			printf("----------------------------------------------------\n");
			printf("请选择购买的的货物名称：");
			getchar();//清除缓冲区里的\n
			scanf("%c", &G[t].name);
			for (int i = 0;; i++)
			{
				if (G[t].name == g[i].name)
				{
					break;
				}
				if (i == 5)
				{
					printf("提示：商品不存在，请重试\n");
					G[t].name = '0';//单纯不想再引入变量
					break;
				}
			}
			if (G[t].name == '0')
			{
				h = 1;
				continue;
			}
		case 2:
			printf("请选择要购买的商品所在通道标号(输入0返回上一步)：");//选择通道标号理解成同一商品可能占用了多个通道
			scanf("%d", &G[t].line);
			if (G[t].line == 0)
			{
				h = 1;
				continue;
			}
			if (G[t].line > 5)
			{
				printf("提示：请正确输入通道标号\n");
				h = 2;
				continue;
			}
			if (G[t].name != g[G[t].line - 1].name)
			{
				printf("提示：商品不在您所选择的通道，请重试\n");
				h = 2;
				continue;
			}
		case 3:
			printf("请输入购买数量(输入0返回上一步)：");
			scanf("%d", &G[t].number);
			if (G[t].number == 0)
			{
				h = 2;
				continue;
			}
			if (G[t].number > g[G[t].line - 1].number)
			{
				printf("提示：超过商品数量，请重试\n");
				h = 3;
				continue;
			}
			G[t].price = g[G[t].line - 1].price * G[t].number;//G[t].price表示此次选择的商品总价
			g[G[t].line - 1].number -= G[t].number;//放到后面再减的话，那么如果继续购买同一商品可能总数量会超过该商品原本的数量
		case 4:printf("请确认商品信息(输入0返回上一步,输入1继续添加商品,输入2清空购物车,输入0,1,2以外的数字开始支付)：\n");
			for (int i = 0; i < 5; i++)
			{
				if (G[i].number != 0)
				{
					printf("商品：%c 通道：%d 数量：%d 总价：%d\n", G[i].name, G[i].line, G[i].number, G[i].price);
				}
			}
			if (G[4].number != 0)//G[4].number如果都不为零，那购物车肯定满了
			{
				printf("购物车已满\n");
			}
			scanf("%d", &f);
			if (f == 0)
			{
				g[G[t].line - 1].number += G[t].number;//不加的话，一直返回，显示货架信息时有的商品没有买也减少了
				h = 3;
				continue;
			}
			if (G[4].number != 0 && f == 1)//处理购物车满以后还想继续购买的情况
			{
				printf("提示：购物车已满,无法继续添加商品\n");
				h = 4;
				continue;
			}
			if (f == 1)
			{
				for (int i = 0; i < 5; i++)//处理购买到货架变空还想继续购买的情况，没有的话，后面会显示所有通道“已售罄”,没办法继续购买，而商品都到购物车里去了
				{
					if (g[i].number != 0)
					{
						break;
					}
					if (g[4].number == 0 && i == 4)
					{
						printf("提示：货架已空,无法继续添加商品\n");
						f = 0;
					}
				}
				if (f == 0)
				{
					h = 4;
					continue;
				}
				m += G[t].price;//m表示要支付的总价
				t++;//来到购物车的下一个位置
				h = 1;
				continue;
			}
			if (f == 2)
			{
				for (int i = 0; i < 5; i++)
				{
					g[G[i].line - 1].number += G[i].number;//货架的商品数量初始化
					G[i].number = 0;//这里可以偷懒一下，只让数量变为零，因为确认商品信息时，是否打印信息由数量是否为零决定
				}
				m = 0;
				t = 0;//回到购物车的第一个位置
				h = 1;
				continue;
			}
			m += G[t].price;
		}
		printf("----------------------------------------------------\n");
		printf("请支付%d元\n", m);
		while (d < m)//d表示投入的总金额
		{
			printf("请投币(仅支持一次投币1元，2元或5元):");
			scanf("%d", &e);
			if (e == 1 || e == 2 || e == 5)
			{
				d += e;
			}
			else
			{
				printf("提示：仅支持一次投币1元，2元或5元，请重试\n");
				continue;
			}
		}
		n = d - m;//g表示找回的钱
		printf("找零：%d\n", n);
		printf("谢谢惠顾，欢迎下次光临！\n");
		for (int i = 0; i < 5; i++)
		{
			if (g[i].number != 0)
			{
				break;
			}
			if (g[4].number == 0 && i == 4)
			{
				printf("----------------------------------------------------\n");
				printf("很抱歉，暂时缺货中\n");
				exit(0);
			}
		}
		d = 0; m = 0; h = 1; t = 0;//d和m初始化,h=1确保下一次购买从输入商品名称开始
		for (int i = 0; i < 5; i++)
		{
			G[i].number = 0;//初始化，假设上一个人买了3样，下一个人只买了2样，如果不初始化的话，打印购买信息时会显示上一个人买的第三项
		}
	}

	return 0;
}