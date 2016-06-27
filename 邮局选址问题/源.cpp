#include<iostream>
#include<list>
#include<vector>
#include<cmath>
using namespace std;


//求中位数

int MiddleNum(list<int> tmp)
{
	auto n = tmp.size();
	auto i = tmp.begin();
	int count = 0;
	if (n % 2==1)		//奇数
	{
		for (; i != tmp.end(); i++) 
		{
			++count;
			if (count == n / 2)
				return  *(++i);
		}
	}

	if (n % 2==0)		//偶数
	{
		for (; i != tmp.end(); i++)
		{
			++count;
			if (count == n / 2)
				return  (*i+*(++i))/2;
		}
	}
	return -1;
}

int MinDis(int x, int y, list<int>tmp1, list<int>tmp2)
{
	int r = 0;
	auto i = tmp1.begin();
	auto j = tmp2.begin();
	for (; i != tmp1.end()&&j!=tmp2.end(); i++)
	{
		r += abs(x - *i) + abs(y - *j);
			j++;
	}
	return r;
}

int main()
{
	int n;
	list<int> tmp1,tmp2;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int tmpx, tmpy;
		cin >> tmpx>> tmpy;
		//从大到小排序
		auto k = tmp1.begin();
		for (; k != tmp1.end(); k++)
		{
			if (tmpx > *k)
			{
				tmp1.insert(k, tmpx);
				break;
			}
		}
		if(k==tmp1.end())
			tmp1.push_back(tmpx);

		auto j = tmp2.begin();
		for (; j != tmp2.end(); j++)
		{
			if (tmpy > *j)
			{
				tmp2.insert(j, tmpy);	
				break;
			}
		}
		if (j == tmp2.end())
			tmp2.push_back(tmpy);
	}

	//cout << MiddleNum(tmp1) << " " << MiddleNum(tmp2) << endl;
	cout << MinDis(MiddleNum(tmp1), MiddleNum(tmp2), tmp1, tmp2) << endl;
	return 0;
}