#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3



#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void Init_Space(char arr[ROW][COL], int row, int  col);
void Print_Board(char arr[ROW][COL],int row, int col);
void Man_Play(char arr[ROW][COL], int row, int col);
void Computer_Play(char arr[ROW][COL], int row, int col);
int Determine_Outcome(char arr[ROW][COL], int row, int col);