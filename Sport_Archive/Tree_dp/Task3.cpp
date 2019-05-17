/*
Многие знают страну Берляндию, уже десяток лет описываемую на соревнованиях в Саратове. Но в данной задаче речь пойдет о другой стране — Бирляндии (англ. Beerland). В Бирляндии n
городов и n-1 двусторонних дорог, расположенных таким образом, что из любого города можно добраться до любого другого, а расстояние между соединенными дорогой городами можно преодолеть
за один день.
Вопреки названию страны, ее новый президент решил издать сухой закон. Ясно, что после этого
в городах накалилась обстановка и начались волнения. Чтобы предотвратить восстание, президент
решил разместить в некоторых городах военные полки таким образом, что в любой город, если в
нем вспыхнет восстание, сможет попасть хотя бы один полк не более чем за один день. Разумеется,
президент заботится о бюджете страны, поэтому количество полков должно быть минимально.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> dp;
vector<int> res;
vector<vector<int>> g;

void dfs(int pos, int pr = -1)
{
	for (int i = 0; i < g[pos].size(); i++)
	{
		int to = g[pos][i];
		if (to != pr)
		{
			if (g[to].size() == 1)
			{
				res[pos] = 1;
				dp[pos] = true;
				dp[to] = true;
			}
			else
			{
				dfs(to, pos);
				if (dp[to] == false)
				{
					res[pos] = 1;
					dp[pos] = true;
					dp[to] = true;
				}
				else if (res[to] == 1)
				{
					dp[pos] = true;
				}
			}
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; cin >> n;

	dp.resize(n, false);
	res.resize(n, 0);
	g.resize(n);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b; a--; b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0);

	if (n == 1)
	{
		cout << 1;
	}
	else
	{
		for (int i = 0; i < dp.size(); i++)
		{
			if (!dp[i])
				res[i] = 1;
		}

		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << " ";
		}
	}

}

/* Thu Mar 21 2019 18:58:25 GMT+0300 (MSK) */
