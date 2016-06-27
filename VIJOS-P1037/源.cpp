#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[105][20005];		//dp[i][j]表示前I个数字高度差为J的高塔的高度、于是YY出转移方程
int tmp[105];
int main()
{
	int n;
	
	cin >> n;
	int sum = 0; 
	for (int i = 1; i <= n; i++)
	{
		cin>>tmp[i]; 
		sum += tmp[i]; 
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0; 
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (dp[i - 1][j] > -1)
				dp[i][j] = dp[i - 1][j];
			if (tmp[i] > j && dp[i - 1][tmp[i] - j] > -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][tmp[i] - j] + j);
			if (j + tmp[i] <= sum&&dp[i - 1][j + tmp[i]] > -1)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j + tmp[i]]);  
			}
			if (j >= tmp[i] && dp[i - 1][j - tmp[i]] > -1)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - tmp[i]] + tmp[i]);
		}
	}
	if (dp[n][0] > 0)
		cout << dp[n][0] << endl; 
	else
		cout << "Impossible" << endl;
	return 0;
}