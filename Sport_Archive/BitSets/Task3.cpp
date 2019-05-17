/*
¬ам дан ориентированный ациклический граф с n вершинами и m ребрами. Ќазовем f(u) количество вершин, которые достижимы из вершины u(включа€ саму вершину u). ¬ыведите количество таких вершин u, что 2?*?f(u)??? n
*/
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 5 * 1e4 + 1;
vector<vector<int>> v;
vector<bitset<maxn>> mask;
vector<bool> used;

bitset<maxn> dfs(int pos)
{
	used[pos] = true;

	for (int i = 0; i < v[pos].size(); i++)
	{
		int to = v[pos][i];
		if (!used[to])
		{
			mask[pos] |= dfs(to);
		}
		else
		{
			mask[pos] |= mask[to];
		}
	}

	return mask[pos];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	v.resize(n);
	mask.resize(n);
	used.resize(n, false);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;

		v[a].push_back(b);
		mask[a][b] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (!used[i])
		{
			dfs(i);
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (2 * (mask[i].count() + 1) >= n)
			ans++;
	}

	cout << ans;
}