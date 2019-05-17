/*
¬ стране N городов, некоторые из которых соединены между собой дорогами. ƒл€ того, чтобы проехать по одной дороге, требуетс€ один бак бензина. ¬ каждом городе бак бензина имеет разную стоимость. ¬ам требуетс€ добратьс€ из первого города в N-ый, потратив как можно меньшее денег. ѕокупать бензин впрок нельз€.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define mp make_pair

using namespace std;

int main()
{
	int inf = 1e9;
	int n;
	cin >> n;

	vector<int> city(n);

	for (int i = 0; i < n; i++)
	{
		cin >> city[i];
	}

	vector<vector<int>> g(n);
	vector<vector<int>> w(n);
	vector<int> d(n, inf);

	d[0] = 0;

	set<pair<int, int>> q;
	q.insert(mp(d[0], 0));	

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int fr, to;
		cin >> fr >> to;
		fr--;
		to--;
		g[fr].push_back(to);
		g[to].push_back(fr);
		w[fr].push_back(city[fr]);
		w[to].push_back(city[to]);
	}
	
	while (!q.empty())
	{
		int v = q.begin() -> second;
		q.erase(q.begin());

		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			int len = w[v][i];
			if (d[v] + len < d[to])
			{
				q.erase(mp(d[to], to));
				d[to] = d[v] + len;
				q.insert(mp(d[to], to));
			}
		}
	}


	if (d[n - 1] == inf)
		cout << -1;
	else
		cout << d[n - 1];
}