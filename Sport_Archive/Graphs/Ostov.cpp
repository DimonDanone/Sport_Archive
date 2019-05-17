/*
От вас требуется определить вес минимального остовного дерева для неориентированного взвешенного связного графа.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<int> p, r;

struct edge
{
	int fr, to, w;
	edge() {}
	edge(int fr, int to, int w) : fr(fr), to(to), w(w) {}
};

void build(int n)
{
	p.resize(n);
	r.resize(n);
	for (int i = 0; i < n; i++)
	{

		p[i] = i;
		r[i] = 1;
	}
}

int color(int i)
{
	if (i == p[i])
		return i;
	return p[i] = color(p[i]);
}

void unite(int i, int j)
{
	i = color(i);
	j = color(j);
	if (i == j)
		return;

	if (r[i] < r[j])
		swap(i, j);
	p[j] = i;
	r[i] += r[j];
}

int main()
{
	int n, m;
	cin >> n;

	vector<bool> check(n);
	vector<pair<int, int>> g(n);

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		g[i].first = x;
		g[i].second = y;
	}

	build(n);

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			if (g[i].first == g[j].first || g[i].second == g[j].second && i != j)
			{
				unite(i, j);
			}
		}

	set<int> res;

	for (int i = 0; i < n; i++)
	{
		res.insert(color(i));
	}

	cout << res.size() - 1;

	cin >> n;
}
/* Wed Jan 30 2019 16:32:35 GMT+0300 (MSK) */
