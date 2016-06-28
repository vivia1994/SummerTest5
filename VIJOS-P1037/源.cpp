#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

/*对于第i个水晶， 有3种情况。
1、不放
2、放高塔
3、放矮塔
	（1）.高塔仍高
	（2）.矮塔变高塔*/
int dp[105][20005];		//dp[i][j]表示前i个数字,高度差为j,高塔的高度、于是YY出转移方程
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
			if (dp[i - 1][j] > -1)								//1.不放第i块水晶; 
				dp[i][j] = dp[i - 1][j];
			if (tmp[i] > j && dp[i - 1][tmp[i] - j] > -1)		//2.放进去后，高塔变矮塔（第i块放在矮塔上了）; 
				dp[i][j] = max(dp[i][j], dp[i - 1][tmp[i] - j] + j);
			if (j + tmp[i] <= sum&&dp[i - 1][j + tmp[i]] > -1)	//3.放进去后，高塔仍高（第i块放在矮塔上）;  
				dp[i][j] = max(dp[i][j], dp[i - 1][j + tmp[i]]);  
			if (j >= tmp[i] && dp[i - 1][j - tmp[i]] > -1)		//4.放进去后，高塔更高（第i块放在高塔上）. 
				dp[i][j] = max(dp[i][j], dp[i - 1][j - tmp[i]] + tmp[i]);
		}
	}
	if (dp[n][0] > 0)
		cout << dp[n][0] << endl; 
	else
		cout << "Impossible" << endl;
	return 0;
}