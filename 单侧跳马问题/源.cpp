//贪心法 
//跳马问题 
#include <iostream> 
#include <iomanip> 
#include <conio.h> 
using namespace std;
#define ROW 8 //行数，可变 
#define LINE 8 //列数，可变 
#define NUM ROW*LINE //总格数 

int board[ROW][LINE];

//两个数组存储对应的偏移量 
int stepRow[8] = { -1,-2,-2,-1,1,2,2,1 };
int stepLine[8] = { -2,-1,1,2,2,1,-1,-2 };

//求 (i,j) 的出口数，各个出口对应的号存在 a[] 中。 
//s 表示顺序选择法的开始 
int exitn(int i, int j, int s, int a[])
{
	int i1, j1, k, count;
	for (count = k = 0; k < 8; k++)
	{
		i1 = i + stepRow[(s + k) % 8];
		j1 = j + stepLine[(s + k) % 8];
		if (i1 >= 0 && i1 < ROW && j1 >= 0 && j1 < LINE && board[i1][j1] == 0)
		{
			a[count++] = (s + k) % 8;
		}
	}
	return count;
}

//判断选择下个出口，s 是顺序选择法的开始序号 
int next(int i, int j, int s)
{
	int m, kk, a[8], b[8], temp;
	m = exitn(i, j, s, a);
	if (m == 0) return -1; //没有出口的情况 
	for (int min = 9, k = 0; k < m; k++)
	{
		//逐个考虑取下一步最少的出口的出口 
		temp = exitn(i + stepRow[a[k]], j + stepLine[a[k]], s, b);
		if (temp < min)
		{
			min = temp;
			kk = a[k];
		}
	}
	return kk;
}

int main()
{
	int i, j, step, no, start;

	//对每个位置的点都进行计算得到各个点的结果 
	//如果只想算某一个点的，把循环去掉换上相应的赋值语句就可以了 
	for (int sx = 0; sx < ROW; sx++)
		for (int sy = 0; sy < LINE; sy++)
		{
			start = 0;
			do
			{
				for (i = 0; i < ROW; i++)
					for (j = 0; j < LINE; j++)
						board[i][j] = 0;
				board[sx][sy] = 1;
				i = sx; j = sy;
				for (step = 2; step <= NUM; step++)
				{
					if ((no = next(i, j, start)) == -1)
						break;
					i += stepRow[no];
					j += stepLine[no];
					board[i][j] = step;
				}
				if (step > NUM || no == -1)
					break;
				start++;
			} while (step <= NUM);
			if (no != -1)
			{
				cout << "任意键打印下个结果：" << endl;
				getch();
				for (i = 0; i < ROW; i++)
				{
					for (j = 0; j < LINE; j++)
						cout << setw(4) << board[i][j]; //打印 
					cout << endl;
				}
			}
		}
	return 0;
}