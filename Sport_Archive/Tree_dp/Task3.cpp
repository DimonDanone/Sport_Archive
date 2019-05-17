/*
������ ����� ������ ���������, ��� ������� ��� ����������� �� ������������� � ��������. �� � ������ ������ ���� ������ � ������ ������ � ��������� (����. Beerland). � ��������� n
������� � n-1 ������������ �����, ������������� ����� �������, ��� �� ������ ������ ����� ��������� �� ������ �������, � ���������� ����� ������������ ������� �������� ����� ����������
�� ���� ����.
������� �������� ������, �� ����� ��������� ����� ������ ����� �����. ����, ��� ����� �����
� ������� ���������� ���������� � �������� ��������. ����� ������������� ���������, ���������
����� ���������� � ��������� ������� ������� ����� ����� �������, ��� � ����� �����, ���� �
��� �������� ���������, ������ ������� ���� �� ���� ���� �� ����� ��� �� ���� ����. ����������,
��������� ��������� � ������� ������, ������� ���������� ������ ������ ���� ����������.
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
