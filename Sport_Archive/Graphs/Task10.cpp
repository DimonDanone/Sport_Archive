/*
–ебро неориентированного графа называетс€ мостом, если после его удалени€ из графа количество компонент св€зности увеличиваетс€.

ƒан св€зный неориентированный граф с n вершинами и m ребрами. ќпределите, какое минимальное количество ребер необходимо в него добавить, чтобы после их добавлени€ в графе не было ни одного моста.

¬ исходном графе могут присутствовать петли и кратные ребра. ƒобавл€ть петли и ребра, кратные какому-либо из существующих (в том числе добавленным ранее), разрешаетс€.
*/

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
vector<pair<int, int>> edges;
vector<vector<int>> AAA;
vector<bool> bridges;

int ans = 0;
vector<vector<int>> new_g;
vector<bool> last_used;
vector<int> colors;
int now_color = 1;

void dfs0(int v, int p)
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
			dfs0(to, v);

			fup[v] = min(fup[to], fup[v]);
			
			if (fup[to] == tin[to])
				bridges[AAA[v][i]] = 1;
		}
		else
		{
			fup[v] = min(fup[v], tin[to]);
		}
	}
}

void dfs1(int v)
{
	colors[v] = now_color;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (colors[g[v][i]] == 0 && bridges[AAA[v][i]] == 0)
		{
			dfs1(g[v][i]);
		}
	}
}

void last_dfs(int v, int p)
{
	used[v] = 1;
	int children = 0;

	for (int i = 0; i < new_g[v].size(); i++)
	{
		int to = new_g[v][i];
		if (used[to] == 0)
		{
			last_dfs(to, v);
			children++;
		}
	}
	if ((children == 1 && p == -1) || (children == 0))
	{
		ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("points.in", "r", stdin);
	//freopen("points.out", "w", stdout);

	cin >> n >> m;

	g.resize(n);
	edges.resize(m);
	fup.resize(n);
	used.resize(n);
	used.assign(n, 0);
	tin.resize(n);
	tin.assign(n, inf);
	AAA.resize(n);

	bridges.resize(m);
	bridges.assign(m, 0);

	for (int i = 0; i < m; i++)
	{
		int fr, to; cin >> fr >> to; 
		fr--; to--;
	
		g[fr].push_back(to);
		g[to].push_back(fr);
		edges[i] = make_pair(fr, to);
		AAA[fr].push_back(i);
		AAA[to].push_back(i);
	}

	fup[0] = 1;
	t = 1;
	dfs0(0, -1);
	
	colors.resize(n);
	colors.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		if (colors[i] == 0)
		{
			dfs1(i);
			now_color++;
		}
	}

	new_g.resize(now_color - 1);

	for (int i = 0; i < m; i++)
	{
		if (bridges[i] == 1)
		{
			new_g[colors[edges[i].first] - 1].push_back(colors[edges[i].second] - 1);
			new_g[colors[edges[i].second] - 1].push_back(colors[edges[i].first] - 1);
		}
	}

	used.resize(now_color - 1);
	used.assign(now_color - 1, 0);

	last_dfs(0, -1);
	
	if (ans == 1 || ans == 0)
		cout << 0;
	else if (ans % 2 == 1)
		cout << ans / 2 + 1;
	else
		cout << ans / 2;

}