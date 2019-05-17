/*
ћежду некоторыми деревн€ми кра€ ¬асюки ход€т автобусы. ѕоскольку пассажиропотоки здесь не очень большие, то автобусы ход€т всего несколько раз в день.

ћарии »вановне требуетс€ добратьс€ из деревни d в деревню v как можно быстрее (считаетс€, что в момент времени 0 она находитс€ в деревне d).
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

	int a, b;
	cin >> a >> b;
	a--;
	b--;

	int m;
	cin >> m;

	vector<vector<int>> g(n);
	vector<vector<pair<int, int>>> w(n);

	for (int i = 0; i < m; i++)
	{
		int fr, t1, to, t2;
		cin >> fr >> t1 >> to >> t2;
		fr--;
		to--;
		
		g[fr].push_back(to);
		w[fr].push_back(mp(t1, t2));
	}

	vector<int> time(n, inf);
	time[a] = 0;

	set<pair<int, int>> q;
	
	q.insert(mp(time[a], a));

	while (!q.empty())
	{
		int v = q.begin()->second;
		q.erase(q.begin());

		for (int i = 0; i < g[v].size(); i++)
		{
			if (time[v] <= w[v][i].first)
			{
				int to = g[v][i];
				int len = w[v][i].second - w[v][i].first;
				
				if (w[v][i].first > time[v])
				{
					len += w[v][i].first - time[v];
				}

				if (time[v] + len < time[to])
				{
					q.erase(mp(time[to], to));
					time[to] = time[v] + len;
					q.insert(mp(time[to], to));
				}
			}
		}
	}

	if (time[b] == inf)
		cout << -1;
	else
		cout << time[b];
}