

#include<iostream>
#include<string.h>
using namespace std;
//对于一个递归函数w(a,b,c) 如果a< =0  or  b< =0  or  c< =0就返回值1. 
//如果a> 20  or  b> 20  or  c> 20就返回w(20,20,20) 
//如果a< b并且b< c  就返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c) 
//其它别的情况就返回w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1) 
//这是个简单的递归函数，但实现起来可能会有些问题。当a,b,c均为15时，调用的次数将非常的多。你要想个办法才行.

long d[21][21][21];

long w(long a, long  b, long c)
{
	if ((a <= 0 || b <= 0 || c <= 0) && d[0][0][0] != -1)
		return d[0][0][0];
	 if ((a>20 || b>20 || c>20) && d[20][20][20] != -1)
		return d[20][20][20];
	 if (a >= 0 && a <= 20 && b >= 0 && b <= 20 && c >= 0 && c <= 20 && d[a][b][c] != -1)
		return d[a][b][c];
	// 已经计算过 直接返回值 
	if (a <= 0 || b <= 0 || c <= 0)
	{
		a = b = c = 0;
		d[a][b][c] = 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		a = b = c = 20;
		d[a][b][c] = w(20, 20, 20);
	}
	else if (a < b&&b < c)
		d[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		d[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return d[a][b][c];
}

int table[21][21][21];
int w1(int a, int b, int c)
{
	if ((a <= 0 || b <= 0 || c <= 0) && table[0][0][0] != -1)
		return table[0][0][0];
	if ((a > 20 || b > 20 || c > 20) && table[20][20][20] != -1)
		return table[20][20][20];
	if (a >= 0 && a <= 20 && b >= 0 && b <= 20 && c >= 0 && c <= 20 && table[a][b][c] != -1)
		return table[a][b][c];
	if (a <= 0 || b <= 0 || c <= 0)
	{
		a = b = c = 0;
		table[a][b][c] = 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		a = b = c = 20;
		table[a][b][c] = w1(20, 20, 20);

	}
	else if(a < b&&b < c)
		table[a][b][c] = w1(a, b, c - 1) + w1(a, b - 1, c - 1) - w1(a, b - 1, c);
	else
		table[a][b][c]= w1(a - 1, b, c) + w1(a - 1, b - 1, c) + w1(a - 1, b, c - 1) - w1(a - 1, b - 1, c - 1);
	return table[a][b][c];
}

int main()
{
	int a, b, c;
	memset(d, -1, sizeof(d));
	memset(table, -1,sizeof(table));
	while (cin >> a >> b >> c)
	{
		if (a != -1 || b != -1 || c != -1)
		{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w1(a, b, c) << endl;
		}
		else break;
	}
	return 0;
}