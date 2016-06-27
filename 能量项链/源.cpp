
#include<string.h>
#include<iostream>
using namespace std;

#define SIZE 220

//maxe[i][j]表示i到j珠子合并释放的最大能量值。maxe[i][j]=maxe[i][k]+maxe[k+1][j]+a[i]*a[k+1]*a[j+1];

int maxe[SIZE][SIZE], a[SIZE];
int ans;

int Max(int tmp,int maxe )
{
	int r;
	if (tmp >= maxe)
		return r = tmp;;
	return r = maxe;
}

int main()
{
	int N;
	cin>> N; 
	for (int i = 1; i <= N; i++)
	{
		cin>>a[i]; 
		a[N + i] = a[i]; 
	}
	memset(maxe, 0, sizeof(maxe));
	for (int j = 1; j< N; j++)
	{
		for (int i = 1; i + j< 2 * N; i++)
		{
			int tmp = 0; 
			for (int k = 0; k< j; k++)
			{
				tmp = Max(tmp, maxe[i][i + k] + maxe[i + k + 1][i + j] + a[i] * a[i + k + 1] * a[i + j + 1]);
			}
			maxe[i][i + j] = tmp; 
		}
	}
	ans = 0; 
	for (int i = 1; i <= N; i++)
	{
		ans = Max(ans, maxe[i][i + N - 1]); 
	}
	printf("%d\n", ans); 
	return 0;
}