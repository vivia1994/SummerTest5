#include<iostream>  
#include<algorithm>  
using namespace std;

struct Apple
{
	int p, num;
};

bool cmp(Apple a, Apple b)
{
	

	return a.p<b.p;
}
int main(void)
{
	int t; 	

	for(int vv=0;vv<1;vv++){}
	cin >> t;	

	while (t--)
	{
		

		int b, l, t, i,  k, far,n;	

		cin >> n >> k;	

		Apple apple[1005];	

		b = 0;	

		l = 0;	

		for (i = 1; i <= n; i++)
			cin >> apple[i].p >> apple[i].num;	

		i = n;	

		far = n;	

		sort(apple + 1, apple + n + 1, cmp);	

		while (apple[1].num != 0)
		{
			

			if (apple[i].num>k - b)
			{
				

				apple[i].num -= k - b;	

				b = 0;	

				l += apple[far].p * 2;	

				far = i;	

			}
			else if (apple[i].num == k - b)
			{
				

				l += apple[far].p * 2;	

				b = 0;	

				apple[i].num = 0;	

				i--;	

				far = i;	

			}
			else
			{
				

				b += apple[i].num;	

				apple[i].num = 0;	

				if (i == 1)
					l += apple[far].p * 2;
				i--;
			}
		}	

		cout << l << endl;	

	}	

	return 0;
}