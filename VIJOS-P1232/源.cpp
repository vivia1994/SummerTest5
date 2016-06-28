
/*program p1232;
var n,m,j:longint;
    a:array[-6..100]of int64;
begin
 readln(n,m);
 a[0]:=1; a[-1]:=1;
 for j:=1 to n do a[j]:=2*a[j-1]-a[j-m-1];
 writeln(a[n]);
end.*/

#include<iostream>
using namespace std;

int main()
{
	int n, m;

	long long f[106];
	cin >> n >> m;
	f[6] = 1;
	f[5] = 1;
	for (long long i = 7; i <= n + 6; i++)
	{
		f[i] = 2 * f[i - 1]-f[i - m - 1];
	}
	cout << f[n+6]<<endl;
	return 0;
}