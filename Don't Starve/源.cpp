#include <iostream>
#include <vector>
#include <algorithm>
#include<sstream>
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

int X(int s, int e, string &re)
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
struct Food
{
	int w;
	int t;
	int c;
};

vector<Food> foods;
vector<bool> buy;

int n, m, s;

int min_price;

int price;

int weight;

int buy_count;

void get_min_price(size_t index)
{
	if (index >= foods.size())
	{
		min_price = price;
		return;
	}

	buy[index] = true;
	if (price + foods[index].c < min_price && weight + foods[index].w <= s && foods[index].t > buy_count)
	{

		price += foods[index].c;
		weight += foods[index].w;
		buy_count += 1;
		get_min_price(index + 1);
		price -= foods[index].c;
		weight -= foods[index].w;
		buy_count -= 1;
	}

	buy[index] = false;
	if (foods.size() - 1 - index + buy_count >= n)
		get_min_price(index + 1);
}

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		foods.clear();
		buy.clear();
		cin >> n >> m >> s;
		while (m-- > 0)
		{
			buy.push_back(false);
			Food food;
			cin >> food.w >> food.t >> food.c;
			bool done = false;
			for (auto it = foods.begin(); it != foods.end(); ++it)
				if (it->t > food.t)
				{
					foods.insert(it, food);
					done = true;
					break;
				}
			if (!done)
				foods.push_back(food);
		}
		min_price = INT32_MAX;
		price = 0;
		weight = 0;
		buy_count = 0;
		get_min_price(0);
		if (min_price == INT32_MAX)
			cout << -1 << endl;
		else
			cout << min_price << endl;
	}
	return 0;
}