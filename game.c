#include "game.h"


//初始化数据空间
void Init_Space(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			arr[i][j] = ' ';
	}
}


//打印棋盘
void Print_Board(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row ; i++)
	{
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf(" %c |", arr[i][j]);
				else
					printf(" %c \n", arr[i][j]);
			}
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
		else
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf(" %c |", arr[i][j]);
				else
					printf(" %c \n", arr[i][j]);
			}
		}

	}
}


//玩家走棋
void Man_Play(char arr[ROW][COL], int row, int col)
{
	int input1 = 0;
	int input2 = 0;
	while (1)
	{
		printf("请输入坐标：>");
		scanf("%d%d", &input1, &input2);

		if (input1 > 0 && input1 <= row && input2>0 && input2 <= col) //判断输入合法性
		{
			if (arr[input1 - 1][input2 - 1] == ' ') //判断该空间中是否已含有内容
			{
				arr[input1 - 1][input2 - 1] = '*';
				break;
			}
		}
		else
			printf("输入错误！\n");
	}
}



//电脑走棋
void Computer_Play(char arr[ROW][COL], int row, int col)
{
	while (1)
	{
		int ret = 0;
		int a = rand() % 3+1;
		int b = rand() % 3+1;
		if (a > 0 && a <= row && b > 0 && b <= col) //判断输入合法性
		{
			if (arr[a - 1][b - 1] == ' ') //判断该空间中是否已含有内容
			{
				printf("电脑下棋\n");
				arr[a - 1][b - 1] = '#';
				break;
			}	
		}
	}

}



//判断胜负，玩家胜1、电脑胜2、平局3、继续0
int Determine_Outcome(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断是否有胜负
	for (i = 0; i < row; i++)
	{
		//判断行相同
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
			if (arr[i][1] == '*')
				return 1;
			else if (arr[i][1] == '#')
				return 2;
		}
		//判断列相同
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			if (arr[1][i] == '*')
				return 1;
			else if (arr[1][i] == '#')
				return 2;
		}
		//判断对角线
		if (i == row - 1)
		{
			if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] == '*')
				return 1;
			else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] == '#')
				return 2;
			if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] == '*')
				return 1;
			else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] == '#')
				return 2;
		}
	}
	//判断是否平局
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 3;

}