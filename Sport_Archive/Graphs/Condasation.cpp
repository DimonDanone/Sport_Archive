#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> g;
vector<pair<int, int>> w;
vector<bool> used;
vector<int> res;
vector<int> colors;
vector<vector<int>> rev_g;
int now_cl;

void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
		{
			dfs(to);
		}
	}
	res.push_back(v);
}

void dfs1(int v)
{
	colors[v] = now_cl;
	for (int i = 0; i < rev_g[v].size(); i++)
	{
		if (!colors[rev_g[v][i]])
		{
			dfs1(rev_g[v][i]);
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	rev_g.resize(n);
	used.resize(n, false);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;

		g[a].push_back(b);
		rev_g[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			dfs(i);
	}

	colors.resize(n, 0);
	now_cl = 0;

	for (int i = res.size() - 1; i > -1; i--)
	{
		if (!colors[res[i]])
		{
			now_cl++;
			dfs1(res[i]);
		}
	}

	set<pair<int, int>> ans;

	for (int i = 0; i < g.size(); i++)
	{
		for (int j = 0; j < g[i].size(); j++)
			if (colors[i] != colors[g[i][j]])
			{
				ans.insert(make_pair(colors[i], colors[g[i][j]]));
			}
	}

	cout << ans.size();	
}

/* Sun Feb 03 2019 13:15:42 GMT+0300 (MSK) */
