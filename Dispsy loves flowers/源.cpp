#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char mp[1005][1005];
int l[1005][1005], r[1005][1005], u[1005][1005], d[1005][1005], a[1005][1005];

int main(void)
 {
	
	int t; 
	cin>>t; 
	while (t--)
	{
		
		int max = 0; 
		int m, n; 
		cin >> m >> n; 
		memset(a, 0, sizeof(a)); 
		memset(l, 0, sizeof(l)); 
		memset(r, 0, sizeof(r)); 
		memset(d, 0, sizeof(d)); 
		memset(u, 0, sizeof(u)); 
		getchar(); 
		for (int i = 1; i <= m; i++)
		{
			
			for (int j = 1; j <= n; j++)
			{
				
				mp[i][j] = getchar(); 
				
				if (mp[i][j - 1] == '.')
					l[i][j] = l[i][j - 1] + 1;
				else
					l[i][j] = 0; 
				if (mp[i - 1][j] == '.')
					u[i][j] = u[i - 1][j] + 1;
				else
					u[i][j] = 0; 
				if (mp[i][j] == '.')
					a[i][j] += l[i][j] + u[i][j]; 
			}
			getchar(); 
		}//
		
		for (int i = m; i >= 1; i--)
			for (int j = n; j >= 1; j--)
			{
				
				if (mp[i][j + 1] == '.')
				{
					r[i][j] = r[i][j + 1] + 1; 
				}
				else
					r[i][j] = 0; 
				if (mp[i + 1][j] == '.')
					d[i][j] = d[i + 1][j] + 1;
				else
					d[i][j] = 0; 
				if (mp[i][j] == '.')
					a[i][j] += r[i][j] + d[i][j]; 
				if (max < a[i][j])
					max = a[i][j]; 
			}
		printf("%d\n", max); 
	}
	return 0;
}