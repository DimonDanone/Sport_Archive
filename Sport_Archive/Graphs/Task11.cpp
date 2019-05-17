/*
����� �������� � ��������� ���������� �������������� �������������. � ���������� �������� ������� ������������, ��������� ������������ ���������� �������. ��� �������, �������������� � ������ ������������ ������. ����� �������� �������, ���������� ��������� �������������� ��������, ���� ������������ �������� ���� ����������. ������ ����� ��������� ���� ������ � �����. ��� ���������, ����� ����� ������ � ����������� ��������� � ������ ������ � ������ �������� ������� �� ��������������������� �������� ����� ���������. �������, ��� ���������� ����������� ������� ��� ��� ��������. ������ ���������� ������� ����� ��������� ���������� ��������� ����� ���������, ���, ����� � ����� ������� �� ����� ����� ���� ������� �� ��������� ��������� � ��������� ��������� ��������� ���� ����������. ������ ���������, ���� �� �� ���� ���� ��������� � �����, ��� ����� �������� ����� �������� ��������� �����������. ������� ����� ����� ����� �� ����������� �� ��������� �������, � ����� ���������. ��� ����������� ������, �� ����� ������� �� �� ������ � ������� ���������� �����������.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int inf = 1e9;
vector<vector<int>> g;
vector<vector<int>> w;

int minimal(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int n, m;
	cin >> n >> m;

	g.resize(n);
	w.resize(n);
	vector<int> mass(m);
	vector<int> used(n, inf);

	for (int i = 0; i < m; i++)
	{
		int a, b, c; cin >> a >> b >> c; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		w[a].push_back(i);
		w[b].push_back(i);
		mass[i] = c;
	}

	vector<int> min(n, inf);
	min[0] = 0;

	set<pair<int, int>> q;
	q.insert(make_pair(min[0], 0));

	vector<int> min1 = min;

	while (!q.empty())
	{
		int v = q.begin()->second;
		q.erase(q.begin());
		min[v] = -inf;
		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			int ww = mass[w[v][i]];
			if (ww < min[to])
			{
				q.erase(make_pair(min[to], to));
				min[to] = ww; 
				min1[to] = minimal(min1[to], min[to]);
				used[to] = w[v][i];
				q.insert(make_pair(min[to], to));
			}

		}
	}

	int ans = 0;

	for (int i = 0; i < min1.size(); i++)
		ans += min1[i];

	cout << "Cost: " << ans << endl;
	
	ans = inf;

	for (int i = 1; i < used.size(); i++)
	{

		int back = mass[used[i]];
		mass[used[i]] = inf;

		min.assign(n, inf);
		min[0] = 0;

		q.insert(make_pair(min[0], 0));

		min1 = min;

		while (!q.empty())
		{
			int v = q.begin()->second;
			q.erase(q.begin());
			min[v] = -inf;
			for (int i = 0; i < g[v].size(); i++)
			{
				int to = g[v][i];
				int ww = mass[w[v][i]];
				if (ww < min[to])
				{
					q.erase(make_pair(min[to], to));
					min[to] = ww;
					min1[to] = minimal(min1[to], min[to]);
					q.insert(make_pair(min[to], to));
				}

			}
		}

		int res = 0;

		bool ok = true;

		for (int i = 0; i < min1.size(); i++)
		{
			if (min1[i] == inf)
			{
				ok = false;
				break;
			}
		}
			
		if (ok)
		{
			for (int i = 0; i < min1.size(); i++)
				res += min1[i];
			if (res < ans)
			{
				ans = res;
			}
		}
		mass[used[i]] = back;
	}

	if (ans == inf)
		ans = -1;
	
	cout << "Cost: " << ans;

}