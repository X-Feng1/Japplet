#include "game.h"


//��ʼ�����ݿռ�
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


//��ӡ����
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


//�������
void Man_Play(char arr[ROW][COL], int row, int col)
{
	int input1 = 0;
	int input2 = 0;
	while (1)
	{
		printf("���������꣺>");
		scanf("%d%d", &input1, &input2);

		if (input1 > 0 && input1 <= row && input2>0 && input2 <= col) //�ж�����Ϸ���
		{
			if (arr[input1 - 1][input2 - 1] == ' ') //�жϸÿռ����Ƿ��Ѻ�������
			{
				arr[input1 - 1][input2 - 1] = '*';
				break;
			}
		}
		else
			printf("�������\n");
	}
}



//��������
void Computer_Play(char arr[ROW][COL], int row, int col)
{
	while (1)
	{
		int ret = 0;
		int a = rand() % 3+1;
		int b = rand() % 3+1;
		if (a > 0 && a <= row && b > 0 && b <= col) //�ж�����Ϸ���
		{
			if (arr[a - 1][b - 1] == ' ') //�жϸÿռ����Ƿ��Ѻ�������
			{
				printf("��������\n");
				arr[a - 1][b - 1] = '#';
				break;
			}	
		}
	}

}



//�ж�ʤ�������ʤ1������ʤ2��ƽ��3������0
int Determine_Outcome(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�ж��Ƿ���ʤ��
	for (i = 0; i < row; i++)
	{
		//�ж�����ͬ
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ')
		{
			if (arr[i][1] == '*')
				return 1;
			else if (arr[i][1] == '#')
				return 2;
		}
		//�ж�����ͬ
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ')
		{
			if (arr[1][i] == '*')
				return 1;
			else if (arr[1][i] == '#')
				return 2;
		}
		//�ж϶Խ���
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
	//�ж��Ƿ�ƽ��
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