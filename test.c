//本程序进行三子棋的程序验证


#include "game.h"



void game()
{
	//使用时间戳
	srand((unsigned)time(NULL));
	char arr[ROW][COL] = {0};
	//初始化数据空间
	Init_Space(arr, ROW, COL);
	//打印棋盘
	Print_Board(arr, ROW, COL);
	
	//开始下棋
	while (1)
	{
		//玩家走棋
		Man_Play(arr, ROW, COL);
		system("cls");//清空上一次打印的东西
		Print_Board(arr, ROW, COL);
		if (Determine_Outcome(arr, ROW, COL) == 1)
		{
			printf("恭喜玩家胜利！\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 2)
		{
			printf("电脑胜利！\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 3)
		{
			printf("平局！\n");
			break;
		}
		Computer_Play(arr, ROW, COL);
		system("cls");
		Print_Board(arr, ROW, COL);
		if (Determine_Outcome(arr, ROW, COL) == 1)
		{
			printf("恭喜玩家胜利！\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 2)
		{
			printf("电脑胜利！\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 3)
		{
			printf("平局！\n");
			break;
		}
	}

}


void test()
{
	int input = 0;

	do
	{
		printf("************************\n");
		printf("******* 三子棋  ********\n");
		printf("***1. Play   0. Exit ***\n");
		printf("************************\n");
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始！\n");
			game();
			break;
		case 0:
			printf("退出程序！\n");
			break;
		default:
			printf("输入错误，请重试！\n");
			break;
		}
	} while (input);

}

int main()
{
	test();
}