#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define mp make_pair

using namespace std;

int main()
{
	int inf = 1e9;
	int n, m, s, f;
	cin >> n >> m >> s >> f;

	vector<vector<int>> g(n);
	vector<vector<int>> w(n);
	vector<int> d(n, inf);
	vector<int> put(n);

	d[s] = 0;
	put[s] = 0;

	set<pair<int, int>> q;
	q.insert(mp(d[s], s));	

	for (int i = 0; i < m; i++)
	{
		int fr, to, ww;
		cin >> fr >> to >> ww;
		g[fr].push_back(to);
		g[to].push_back(fr);
		w[fr].push_back(ww);
		w[to].push_back(ww);
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
				put[to] = v;
				q.insert(mp(d[to], to));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (d[i] == inf)
			cout << -1 << " ";
		else
			cout << d[i] << " ";
	}
	cout << endl;

	if (d[f] == inf)
		cout << -1;
	else
	{
		vector<int> res;
		res.push_back(f);

		int now = put[f];

		while (now != put[s])
		{
			res.push_back(now);
			now = put[now];
		}

		cout << res.size() << endl;

		for (int i = res.size() - 1; i > -1; i--)
		{
			cout << res[i] << " ";
		}
	}
	
}