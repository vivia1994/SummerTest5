#include <iostream>
#include <vector>
using namespace std;

int m[1000][1000];
int r, c;

int CanBeBigger(pair<int, int> p, int size)
{
	
	if (p.first + size + 1 > r || p.second + size + 1 > c)
		return false; 
	for (int i = 0; i < size + 1; ++i)
		if (m[p.first + i][p.second + size] != 1 || m[p.first + size][p.second + i] != 1)
			return false; 
	return true;
}

int MaxSize()
{
	
	vector<pair<int, int>> sp; 
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (m[i][j] == 1)
				sp.push_back(pair<int, int>(i, j)); 
	int MaxSize = 0; 
	while (!sp.empty())
	{
		++MaxSize; 
		vector<pair<int, int>> nsp; 
		for (auto it : sp)
			if (CanBeBigger(it, MaxSize))
				nsp.push_back(it); 
		sp = nsp; 
	}
	return MaxSize;
}

int main()
{
	int t; 
	cin >> t; 
	while (t-- > 0)
	{
		
		
		cin >> r >> c; 
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				cin >> m[i][j]; 
		cout << MaxSize() << endl; 
	}
	return 0;
}