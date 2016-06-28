#include <iostream>  
#include<cmath>
using namespace std;
const int maxn = 2010;
int main()
{
	int t;
	cin >> t;
	for (int m = 0; m < t; m++)
	{
		int l, n;
		cin >> l >> n;
		int k[maxn], f[maxn];

		for (int i = 0; i < n; ++i)
			cin >> k[i];
		for (int i = 0; i < n; ++i)
			cin >> f[i]; 
		int ans = 0x3f3f3f3f, p = 0;
		
		for (int i = 0; i <= l; ++i) 
		{
			int sump = 0; 
			for (int j = 0; j < n; ++j)
			{
				int s = abs(k[j] - i); 
				if (f[j] - s < 0)
					sump += 0;
				else
					sump += (f[j] - s);
			}
			if (sump < ans) 
			{
				ans = sump; 
				p = i;
			}
		}
		cout << p << " " << ans << endl; 
	}
	return 0;
}