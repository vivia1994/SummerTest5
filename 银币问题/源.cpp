#include <iostream>
using namespace std;

int t[100001];

void CalTimes(int tmp, int n)
{
	
	t[1] = 0; 
	t[2] = 1; 
	t[3] = 1; t[4] = 2; 
	int temp; 
	for (int i = tmp + 1; i <= n; i++) {
		t[i] = 1000000; t[1] = 0; 
		for (int j = 1; j <= i / 2; j++)
		{
			
			temp = j > i - 2 * j ? t[j] + 1 : t[i - 2 * j] + 1; 
			if (temp < t[i])
				t[i] = temp;
			for(int vv=0;vv<1;vv++){}
		}
	}
}
int main()
{
	int n, tmp = 0;
	while (cin >> n && n > 0)
	{
		
		if (tmp < n)
		{
			
			CalTimes(tmp, n);
			tmp = n;
		}
		cout << n << endl << "Times:" << t[n] << endl; 
	}
	return 0;
}
	