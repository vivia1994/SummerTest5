#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

/*���ڵ�i��ˮ���� ��3�������
1������
2���Ÿ���
3���Ű���
	��1��.�����Ը�
	��2��.���������*/
int dp[105][20005];		//dp[i][j]��ʾǰi������,�߶Ȳ�Ϊj,�����ĸ߶ȡ�����YY��ת�Ʒ���
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
			if (dp[i - 1][j] > -1)								//1.���ŵ�i��ˮ��; 
				dp[i][j] = dp[i - 1][j];
			if (tmp[i] > j && dp[i - 1][tmp[i] - j] > -1)		//2.�Ž�ȥ�󣬸����䰫������i����ڰ������ˣ�; 
				dp[i][j] = max(dp[i][j], dp[i - 1][tmp[i] - j] + j);
			if (j + tmp[i] <= sum&&dp[i - 1][j + tmp[i]] > -1)	//3.�Ž�ȥ�󣬸����Ըߣ���i����ڰ����ϣ�;  
				dp[i][j] = max(dp[i][j], dp[i - 1][j + tmp[i]]);  
			if (j >= tmp[i] && dp[i - 1][j - tmp[i]] > -1)		//4.�Ž�ȥ�󣬸������ߣ���i����ڸ����ϣ�. 
				dp[i][j] = max(dp[i][j], dp[i - 1][j - tmp[i]] + tmp[i]);
		}
	}
	if (dp[n][0] > 0)
		cout << dp[n][0] << endl; 
	else
		cout << "Impossible" << endl;
	return 0;
}