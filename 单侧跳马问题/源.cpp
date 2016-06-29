#include<iostream>
#include<set>
#include<vector>
using namespace std;


//v中是否包含8
bool ContainEight(vector<pair<int, int>> v)
{
	for (auto i : v)
	{
		if (i.first == 8 && i.second == 8)
			return true;
	}
	return false;
}

bool Check(int x,int y, set<pair<int, int>> s)
{
	
	if (x >= 1 && x <= 8 && y >= 1 && y <= 8 && s.find(pair<int, int>(x, y)) == s.end())
		return true;
	return false;
}

int main()
{
	
	
	int a, b;
	while (cin >> a >> b)
	{
		vector<pair<int, int>> v;
		set<pair<int, int>> s;
		int count = 0;
		v.push_back(pair<int, int>(a, b));
		s.insert(pair<int, int>(a, b));
		while (!v.empty() && !ContainEight(v)/*且v里面不包含（8,8)*/)
		{
			count++;
			vector<pair<int, int>> vnew;
			for (auto i : v)
			{
				if (Check(i.first - 2, i.second + 1, s))
				{
					vnew.push_back(pair<int, int>(i.first - 2, i.second + 1));
					s.insert(pair<int, int>(i.first - 2, i.second + 1));
				}
				if (Check(i.first - 1, i.second + 2, s))
				{
					vnew.push_back(pair<int, int>(i.first - 1, i.second + 2));
					s.insert(pair<int, int>(i.first - 1, i.second + 2));
				}
				if (Check(i.first + 2, i.second + 1, s))
				{
					vnew.push_back(pair<int, int>(i.first + 2, i.second + 1));
					s.insert(pair<int, int>(i.first + 2, i.second + 1));
				}
				if (Check(i.first + 1, i.second + 2, s))
				{
					vnew.push_back(pair<int, int>(i.first + 1, i.second + 2));
					s.insert(pair<int, int>(i.first + 1, i.second + 2));
				}
			}
			v = vnew;
		}
		if (v.empty())
			cout << "Impossible" << endl;
		else
			cout << count << endl;
	}
	return 0;
}