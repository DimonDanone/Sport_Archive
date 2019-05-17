/*
Once upon a time there was a king. One day the king counted up the collected taxes and decided to spend the money for the road maintenance. There were N cities in that kingdom and M two-way roads connected them in such way that one could travel from a city to others using these roads. The road network was catastrophic without repairing, so the king made up his mind to repair as many roads as possible during the summer, before the money depreciated. The inhabitants of the kingdom were shocked to know that all the ways they used to go would be blocked for summer. So the king promised that at most one road from a city would be blocked. Help the king to fulfil his plan without displeasing the citizens.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> dp;
vector<pair<int, int>> res;
vector<vector<int>> g;

void dfs(int pos, int pr = -1)
{
	for (int i = 0; i < g[pos].size(); i++)
	{
		int to = g[pos][i];

		if (to != pr)
		{
			dfs(to, pos);

			if (!dp[pos] && !dp[to])
			{
				dp[pos] = true;
				res.push_back(make_pair(pos, to));
			}
		}
	}
}


int main()
{
	int n, m; cin >> n >> m;

	dp.resize(n, false);
	g.resize(n);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);

	cout << res.size() << endl;

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].first + 1 << " " << res[i].second + 1 << endl;

	}
}
