#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int a[51][51];
int CommonString(vector<char>x, vector<char>y)
{
	if (a[x.size()][y.size()] != -1)
	{
		return a[x.size()][y.size()];
	}
	if (x.size() == 1 && y.size() == 1)
		return  x.back() == y.back()?1:0;
	if (x.size() == 1 && y.size() != 1)
	{
		if (x.back() != y.back())
		{
			vector<char>tmp = y;
			tmp.pop_back();
			a[x.size()][y.size()] = CommonString(x, tmp);
			return a[x.size()][y.size()];
		}
		else
		{
			a[x.size()][y.size()] = 1;
			return a[x.size()][y.size()];
		}
	}
	if (x.size() != 1 && y.size() == 1)
	{
		if (x.back() != y.back())
		{
			vector<char>tmp = x;
			tmp.pop_back();
			a[x.size()][y.size()] = CommonString(tmp, y);
			return a[x.size()][y.size()];
		}
		else
		{
			a[x.size()][y.size()] = 1;
			return a[x.size()][y.size()];
		}
	}
	int max = -1;
	if (x.back() == y.back())
	{
		vector<char>tmpx = x, tmpy = y;
		tmpx.pop_back();
		tmpy.pop_back();
		int tmp = CommonString(tmpx, tmpy) + 1;
		if (tmp > max)
			max = tmp;
	}
	vector<char> tmpy = y;
	tmpy.pop_back();
	int tmp = CommonString(x, tmpy);
	if (tmp > max)
		max = tmp;

	vector<char> tmpx = x;
	tmpx.pop_back();
	tmp = CommonString(tmpx, y);
	if (tmp > max)
		max = tmp;

	a[x.size()][y.size()] = max;
	return max;
}

int main()
{
	int T;
	cin >> T;
	
	for (int i = 1; i <= T; i++)
	{
		int m, n;
		cin >> m >> n;
		vector<char>x, y;
		memset(a, -1, sizeof(a));
		for (int j = 0; j < m; j++)
		{
			char tmpx;
			cin >> tmpx;
			x.push_back(tmpx);
		}
		for (int j = 0; j < n; j++)
		{
			char tmpy;
			cin >> tmpy;
			y.push_back(tmpy);
		}
		cout << "Case " << i << endl << CommonString(x, y) << endl;
	}
	return 0;
}