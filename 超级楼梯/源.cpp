#include<iostream>

using namespace std;

int WalkNum(int m)
{
	int r;
	if (m == 1)
		return r = 0;
	if (m == 2)
		return r = 1;
	if (m == 3)
		return r = 2;
	return WalkNum(m - 1) + WalkNum(m - 2);

}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int M;
		cin >> M;
		cout << WalkNum(M) << endl;
	}
	return 0;
}