/*Description
      飞哥最近 得到 了一大块 n*m 的土地 ，他想在这块土地 上建一个正方 形的农场 ，但是 这块土 地有些地方 被大石头 占着，无法 使用 ，于是 飞哥想来问你 在这块土地 上能建成的农场 的最大 边 长为多少 ？

Input
第一个数T表示数组组数
每组 数据 一开 始有两个 整数 n和 m，表示 土地 的长和宽。
接下 来是个 n*m 的矩阵 ，元素 只有 0 和 1 ，0表示 这块地方 被石头 占着。1表示 可以 使用 。

m,n<=1000

Output
对每组数据 输出 一行 ，表示 农场 最大 的边长 。

Sample Input
1
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1
Sample Output
2*/

#include<iostream>
#include<string.h>
using namespace std;

#define ll long long

struct Matrix
{
	ll a[6][6];
};

Matrix origin, tmp,re;

Matrix MatrixMul(Matrix x, Matrix y,int n,int m)
{
	memset(tmp.a, 0, sizeof(tmp.a));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
			{
				tmp.a[i][j] += (x.a[i][k] * y.a[k][j]);
			}
	return tmp;
}

Matrix IsMax(Matrix origin,int n,int m)
{
	memset(re.a, 0, sizeof(re.a));


	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{

		}
}
int main()
{
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int n, m;
		Matrix origin;
		cin >> n >> m;
		memset(origin.a, 0, n*m);
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				int tmp;
				cin >> tmp;
				origin.a[i][j] = tmp;
			}
		MatrixMul(origin, origin, n, m);
		for (int i = 0; i<n; i++)
			for (int j = 0; j < m; j++)
			{
				cout << origin.a[i][j] << "  ";
				if (j == m - 1)
					cout << endl;
			}
	}
	return 0;
}