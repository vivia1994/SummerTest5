/*Description
      �ɸ���� �õ� ��һ��� n*m ������ ��������������� �Ͻ�һ������ �ε�ũ�� ������ ����� ����Щ�ط� ����ʯͷ ռ�ţ��޷� ʹ�� ������ �ɸ��������� ��������� ���ܽ��ɵ�ũ�� ����� �� ��Ϊ���� ��

Input
��һ����T��ʾ��������
ÿ�� ���� һ�� ʼ������ ���� n�� m����ʾ ���� �ĳ��Ϳ�
���� ���Ǹ� n*m �ľ��� ��Ԫ�� ֻ�� 0 �� 1 ��0��ʾ ���ط� ��ʯͷ ռ�š�1��ʾ ���� ʹ�� ��

m,n<=1000

Output
��ÿ������ ��� һ�� ����ʾ ũ�� ��� �ı߳� ��

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