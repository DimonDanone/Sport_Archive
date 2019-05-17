#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

struct edge
{
	int from, to, w;
	edge() {}
	edge(int from, int to, int w) : from(from), to(to), w(w) {}
};

int main()
{
	int inf = 30000;

	int n, m;
	cin >> n >> m;

	vector<edge> edges(m);

	for (int i = 0; i < m; i++)
	{
		int from, to, w;
		cin >> from >> to >> w;
		edges[i] = edge(--from, --to, w);
	}

	vector<int> d(n, inf);

	d[0] = 0;

	for (int _ = 0; _ < n - 1; _++)
		for (int j = 0; j < m; j++)
		{
			int from = edges[j].from;;
			int to = edges[j].to;
			int w = edges[j].w;

			if (d[to] > d[from] + w && d[from] != inf)
			{
				d[to] = d[from] + w;
			}
		}

	for (int i = 0; i < n; i++)
		cout << d[i] << " ";

}
