#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> w;
vector<bool> used;
vector<int> res;

void dfs(int v)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		if (!used[w[v][i]])
		{
			used[w[v][i]] = true;
			dfs(g[v][i]);
			res.push_back(w[v][i] + 1);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	w.resize(n);
	used.resize(m, false);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;

		g[a].push_back(b);
		g[b].push_back(a);
		w[a].push_back(i);
		w[b].push_back(i);
	}

	int start = 0;

	for (int i = 0; i < n; i++)
	{
		if (g[i].size() % 2 == 1)
		{
			start = i;
			break;
		}
	}

	dfs(start);

	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	cin >> n;
}