#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int inf = 1e9;
int n, m, t;
vector<bool> used; 
vector<int> fup;
vector<int> tin;
vector<vector<int>> g;
vector<vector<int>> edges;
set<int> res;

void dfs(int v, int p)
{
	int children = 0;
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

			if (fup[to] >= tin[v] && p != -1)
				res.insert(v + 1);
			children++;
		}
		else
		{
			fup[v] = min(fup[v], tin[to]);
		}
	}

	if (p == -1 && children > 1)
	{
		res.insert(v + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("points.in", "r", stdin);
	freopen("points.out", "w", stdout);

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

	for (auto i = res.begin(); i != res.end(); i++)
		cout << *i << " ";

}
/* Fri Feb 01 2019 13:46:17 GMT+0300 (MSK) */
