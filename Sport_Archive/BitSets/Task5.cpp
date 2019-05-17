/*
Дан граф из n вершин, раскрасьте его в минимально возможное число цветов так, чтобы никакие две вершины, соединенные ребром, не были одного цвета.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <iterator>

using namespace std;

vector<vector<int>> g;

const int maxn = 17;

bool check(int a)
{
	bitset<maxn> mask = a;

	bool ok = true;

	for (int i = 0; i < mask.size(); i++)
	{
		if (mask[i] == 1)
		{
			for (int j = i + 1; j < mask.size(); j++)
			{
				if (mask[j] == 1 && g[i][j] == 1)
				{
					ok = false;
				}
			}
		}
	}

	return ok;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	g.resize(n, vector<int>(n));

	int p_2 = pow(2, n);

	vector<int> dp(p_2, 1e9);

	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b; a--; b--;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	vector<int> color(n, 0);

	dp[0] = 0;
	dp[1] = 1;

	vector<int> prov(p_2, 0);

	for (int i = 0; i < p_2; i++)
	{
		if (check(i))
			prov[i] = 1;
	}

	prov[0] = 1;

	vector<int> res(p_2);

	for (int mask = 1; mask < p_2; mask++)
	{
		for (int pod_mask = mask; pod_mask > 0; pod_mask = mask & (pod_mask - 1))
		{
			if (prov[pod_mask])
			{
				int mask_1 = (~pod_mask) & mask;
				if (dp[mask_1] + 1 <= dp[mask])
				{
					dp[mask] = dp[mask_1] + 1;
					res[mask] = pod_mask;
				}
			}
		}
	}

	cout << dp[p_2 - 1] << endl;

	int now = p_2 - 1;
	int c = 1;

	while (now > 0)
	{
		bitset<maxn> a = res[now];

		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == 1)
				color[i] = c;
		}

		c++;
		now = now - res[now];
	}

	for (int i = 0; i < color.size(); i++)
		cout << color[i] << " ";

}