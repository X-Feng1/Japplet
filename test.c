//���������������ĳ�����֤


#include "game.h"



void game()
{
	//ʹ��ʱ���
	srand((unsigned)time(NULL));
	char arr[ROW][COL] = {0};
	//��ʼ�����ݿռ�
	Init_Space(arr, ROW, COL);
	//��ӡ����
	Print_Board(arr, ROW, COL);
	
	//��ʼ����
	while (1)
	{
		//�������
		Man_Play(arr, ROW, COL);
		system("cls");//�����һ�δ�ӡ�Ķ���
		Print_Board(arr, ROW, COL);
		if (Determine_Outcome(arr, ROW, COL) == 1)
		{
			printf("��ϲ���ʤ����\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 2)
		{
			printf("����ʤ����\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 3)
		{
			printf("ƽ�֣�\n");
			break;
		}
		Computer_Play(arr, ROW, COL);
		system("cls");
		Print_Board(arr, ROW, COL);
		if (Determine_Outcome(arr, ROW, COL) == 1)
		{
			printf("��ϲ���ʤ����\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 2)
		{
			printf("����ʤ����\n");
			break;
		}
		else if (Determine_Outcome(arr, ROW, COL) == 3)
		{
			printf("ƽ�֣�\n");
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
		printf("******* ������  ********\n");
		printf("***1. Play   0. Exit ***\n");
		printf("************************\n");
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ��\n");
			game();
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("������������ԣ�\n");
			break;
		}
	} while (input);

}

int main()
{
	test();
}