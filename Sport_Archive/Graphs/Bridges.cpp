#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int inf = 1e9;
int n, m, t;
vector<bool> used(n, 0); 
vector<int> fup;
vector<int> tin;
vector<vector<int>> g;
vector<vector<int>> edges;
vector<int> res;

void dfs(int v, int p)
{
	tin[v] = t;
	t++;
	used[v] = true;
	fup[v] = tin[v];
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p)
			continue;
		if (used[to] == 0)
		{
			dfs(to, v);

			fup[v] = min(fup[to], fup[v]);

			if (fup[to] == tin[to])
				res.push_back(edges[v][i] + 1);
		}
		else
		{
			fup[v] = min(fup[v], tin[to]);
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	edges.resize(n);
	fup.resize(n);
	used.resize(n);
	used.assign(n, 0);
	tin.resize(n);
	tin.assign(n, inf);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;
	
		g[a].push_back(b);
		g[b].push_back(a);
		edges[a].push_back(i);
		edges[b].push_back(i);
	}
	fup[0] = 1;
	t = 1;
	dfs(0, -1);

	cout << res.size() << endl;
	
	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

}
/* Fri Feb 01 2019 11:41:41 GMT+0300 (MSK) */
