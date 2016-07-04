#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int mr[21][21];
string rr[21][21];

vector<int> input;

int GMTTM(int s, int e, string &re)
{
	
	if (s == e)
	{
		
		stringstream sstr; 
		sstr << "A" << s + 1; 
		sstr >> re; 
		return 0; 
	}

	if (mr[s][e] != -1)
	{
		
		re = rr[s][e]; 
		return mr[s][e]; 
	}
	
	int min = INT32_MAX;
	
	for (int i = s; i < e; ++i)
	{
		
		string ts1, ts2; 
		int tnp = input[s] * input[i + 1] * input[e + 1] + GMTTM(s, i, ts1) + GMTTM(i + 1, e, ts2);
		if (min > tnp)
		{
			
			re = ts1 + ts2; 
			min = tnp; 
		}
		
	}
	re = "(" + re + ")"; 
	mr[s][e] = min; 
	rr[s][e] = re; 
	return min; 
}


int GMT(string &re)
{
	int r = GMTTM(0, input.size() - 2, re); 
	if (re.length() > 2)
	{
		
		re.erase(0, 1); 
		re.erase(re.length() - 1, 1); 
	}
	return r;
}


int main()
{
	
	int n; 
	int count = 0; 
	while (cin >> n)
	{
		
		++n; 
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				
				mr[i][j] = -1; 
				rr[i][j] = ""; 
			}
		
		input.clear(); 
		while (n-- > 0)
		{
			
			int tnp; 
			cin >> tnp; 
			input.push_back(tnp); 
		}
		string re; 
		cout << "Case " << ++count << endl; 
		cout << GMT(re) << " " << re << endl; 
		
		
	}
	return 0;
}