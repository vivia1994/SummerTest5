#include<iostream>
#include<string.h>
using namespace std;

int A[101][101],h[101][101];
int row, col;

int GetH(int r, int c)
{
	if (h[r][c]!=-1)
		return h[r][c];
	int max = 1;
	int tmp;
	//上边界
	if (r - 1 >= 1 && A[r - 1][c] < A[r][c])
	{
		tmp = GetH(r - 1, c)+1;
		if (tmp > max)
			max = tmp;
	}
	//左边界
	if (c - 1 >= 1 && A[r ][c-1] < A[r][c])
	{
		tmp = GetH(r, c - 1) + 1;
		if (tmp > max)
			max = tmp;
	}
	//下边界
	if (r + 1 <= row && A[r + 1][c] < A[r][c])
	{
		tmp = GetH(r + 1, c) + 1;
		if (tmp > max)
			max = tmp;
	}
	//右边界
	if (c + 1 <= col  && A[r][c + 1] < A[r][c])
	{
		tmp = GetH(r , c+1) + 1;
		if (tmp > max)
			max = tmp;
	}
	h[r][c] = max;
	return  max;
}

int MaxH()
{
	int r=0;
	memset(h, -1, sizeof(h));
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
		{
			int tmp = GetH(i, j);
			if (tmp > r)
				r = tmp;
		}
	return r;
}

int main()
{
	int h;
	cin >> row >> col;
	memset(A, -1, sizeof(A));
	for(int i=1;i<=row;i++)
		for (int j = 1; j <= col; j++)
		{
			cin >> A[i][j];
		}
	cout << MaxH() << endl;
	return 0;
}